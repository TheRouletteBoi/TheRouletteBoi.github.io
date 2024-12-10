let jsonData;
let funcInfos = new Map();
let nameLookupMap = new Map();
let nativesModTime = 0;

function trackEvent(category, action, name, value) {
	_paq.push(["trackEvent", category, action, name, value]);
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function loadNativeInfo() {
    if (jsonData !== undefined) return;

    const file = new XMLHttpRequest();

    file.overrideMimeType("application/json");
    file.open("GET", `https://raw.githubusercontent.com/TheRouletteBoi/rdr-nativedb-data/master/natives.json`, true);
	file.onreadystatechange = function () {
		if (file.readyState === 4 && file.status === 200) {
			jsonData = JSON.parse(file.responseText);
			
			for (let ns in jsonData) {
				for (let native in jsonData[ns]) {
					const name = jsonData[ns][native].name;
					nameLookupMap.set(native, {namespace: ns, name: name});
				}
			}
		}
	};

    file.send(null);
}

// [============= Namespace Functions =============]
function getNamespaces() {
    let i = 0, v = [];

    for (let ns in jsonData) {
        v[i++] = ns;
    }

    return v;
}

function getNamespaceObjectFromName(namespace) {
    return jsonData[namespace.toUpperCase()];
}

function getNamespaceObjects() {
    let i = 0, v = [];

    for (let ns in jsonData) {
        v[i++] = getNamespaceObjectFromName(ns);
    }

    return v;
}

function getNativeCount(namespace) {
    let i = 0;

    for (let n in getNativeObjects(namespace)) {
        i++;
    }

    return i;
}

function getNativeObjects(namespace) {
    const nsObj = getNamespaceObjectFromName(namespace);
    let i = 0, v = [];

    for (let n in nsObj) {
        v[i++] = nsObj[n];
    }

    return v;
}

function isNamespaceTabOpened(namespace) {
    return document.getElementById("na-" + namespace.toUpperCase()) !== null;
}

// [============= Native Functions =============]

function hasComment(native) {
    return native["comment"] !== "";
}

function isNameKnown(native) {
    return !native["name"].startsWith("_");
}

function isNativeNamed(native) {
    return !native["name"].startsWith("_0x");
}

function getNameFromHash(hash) {
	let entry = nameLookupMap.get(hash);
	return entry === undefined ? null : entry.name;
}

function getNamespaceFromHash(hash) {
	let entry = nameLookupMap.get(hash);
	return entry === undefined ? null : entry.namespace;
}

function closeNamespaceTab(namespace) {
	collapseAllNativesInNamespace(namespace);

	const ele = document.getElementById("ns-" + namespace).parentElement;
	const c = ele.innerHTML.split("<ul")[0];
	ele.innerHTML = c;

	document.getElementById("ns-" + namespace).addEventListener("click", function () {
		openNamespaceTab(namespace);
		trackEvent("namespace", "open", namespace);
	});
	
	let e = document.getElementById(namespace + "-expand-all");
	e.hidden = true;
	e.text = " (expand all)";
	
	e.removeEventListener("click", onExpandAllNativesInNamespace);
	e.removeEventListener("click", onCollapseAllNativesInNamespace);
}

function onExpandAllNativesInNamespace(evt) {
	expandAllNativesInNamespace(evt.currentTarget.namespace);
	
	let e = document.getElementById(evt.currentTarget.namespace + "-expand-all");
	e.text = " (collapse all)";
	e.addEventListener("click", onCollapseAllNativesInNamespace, { once: true });
	e.namespace = evt.currentTarget.namespace;

	trackEvent("namespace", "expand_all_natives", evt.currentTarget.namespace);
}

function onCollapseAllNativesInNamespace(evt) {
	collapseAllNativesInNamespace(evt.currentTarget.namespace);
	
	let e = document.getElementById(evt.currentTarget.namespace + "-expand-all");
	e.text = " (expand all)";
	e.addEventListener("click", onExpandAllNativesInNamespace, { once: true });
	e.namespace = evt.currentTarget.namespace;

	//trackEvent("namespace", "collapse_all_natives", evt.currentTarget.namespace);
}

function expandAllNativesInNamespace(namespace) {
	for (let n in jsonData[namespace]) {
		let info = funcInfos.get(n);	
		if (!info.isOpen) info.open();
	}
}

function collapseAllNativesInNamespace(namespace) {
	for (let n in jsonData[namespace]) {
		let info = funcInfos.get(n);	
		if (info.isOpen) info.close();
	}
}

async function openNamespaceTab(namespace) {
    const ele = document.getElementById("ns-" + namespace);
	
	if (ele == null || ele == undefined)
		return;
	
    const natives = getNativeObjects(namespace);

    let htmlCode = ele.parentElement.innerHTML + "<ul id='na-" + namespace + "' class='natives'>";

    let i = 0;

    for (let n in jsonData[namespace]) {
        const native = natives[i++];

        const name = native.name;
        const comment = native.comment;
        const params = native.params;
        const returnType = native.return_type;

        htmlCode += "<li><a class='nativeName' id='func-" + n + "'>" + " 	•  " +
            "<span class='datatype'>" + returnType + " </span>" +
            name + "(";

        for (let para = 0; para < params.length; para++) {
            const parameter = params[para];

            const type = parameter.type;
            const name = parameter.name;

            htmlCode += "<span class='datatype'>" + type + "  </span>" +
                "<span class='parameterName'>" + name + (para !== params.length - 1 ? ", " : "") + "</span>";
        }

        htmlCode += ")  ";
        htmlCode += "<span class='hash'>//  " + n + "</span>";
    }

    htmlCode += "</ul>";

    ele.parentElement.innerHTML = htmlCode;

    for (let n in jsonData[namespace]) {
	let info = funcInfos.get(n);
        if (funcInfos.get(n) === undefined) {
            info = new FunctionInfo(namespace, n);
            funcInfos.set(n, info);
	}

	info.init();
    }

    document.getElementById("ns-" + namespace).addEventListener("click", function () {
        closeNamespaceTab(namespace);
		//trackEvent("namespace", "close", namespace);
    });
	
	let e = document.getElementById(namespace + "-expand-all");
	
	e.hidden = false;
	
	e.addEventListener("click", onExpandAllNativesInNamespace, { once: true });
	e.namespace = namespace;
}

class FunctionInfo
{
	constructor(namespace, hash)
	{
		this.namespace = namespace;
		this.hash = hash;
		this.name = getNameFromHash(hash);
		
		let elem = document.getElementById("func-" + this.hash);
		
		let newHTML = "<div style='padding-left: 1%;'><div class='funcbox'>" +
		"<p style='font-weight: bold; font-size: 20px;'>" + this.namespace + "::" + this.name + "</p><hr>" +
		elem.innerHTML.substring(3) + "<hr>";

		newHTML += "<p style='white-space: pre-wrap; display: inline;'><br>";
	
		let unused = false;
		
		const nativeObj = jsonData[this.namespace][this.hash];
	
		if (nativeObj.unused != null && nativeObj.unused != undefined) {
			unused = nativeObj.unused;	   
			if (unused) {
				newHTML += "This native is not used in the scripts.";
			}
		}

		const hasCmt = hasComment(nativeObj);

		if (hasCmt) {
			newHTML += (unused ? "<br><br>" : "") + nativeObj.comment.replaceAll(/&/g, "&amp;").replaceAll('<', '&lt;').replaceAll('>', '&gt;').replace(/(https?:\/\/[^\s]+)/g, "<a href=\"$1\" target=\"_blank\" class=\"externlink\">$1</a>");
		} else if (!unused) newHTML += "<i>No comment available</i>";

		newHTML += "<br><br></p><div id='cph-" + this.name + "' class='buttonbox' style='margin-right: 9%;'>Copy Hash</div><div id='cpl-" + this.name + "' class='buttonbox'>Copy Link</div></div></div>";
		
		this.html = newHTML;
		
		this.isOpen = false;
		
		this.onClick = function (evt) {			
			if (!evt.currentTarget.funcInfo.isOpen) {
				evt.currentTarget.funcInfo.open();
				trackEvent("native", "open", evt.currentTarget.funcInfo.hash);
			}
			else {
				evt.currentTarget.funcInfo.close();
				//trackEvent("native", "close", evt.currentTarget.funcInfo.hash);
			}
		};
		
		this.onCopyHash = function (evt) {
			copyTextToClipboard(evt.currentTarget.funcHash);
			trackEvent("native", "copy_hash", evt.currentTarget.funcHash);
		};
		
		this.onCopyLink = function (evt) {
			copyTextToClipboard(window.location.origin + window.location.pathname + "?n=" + evt.currentTarget.funcHash);
			trackEvent("native", "copy_link", evt.currentTarget.funcHash);
		};
		
		elem.addEventListener("click", this.onClick, { once: true });
		elem.funcInfo = this;
	}
	
	open()
	{
		if (this.isOpen) return;
		
		this.isOpen = true;
		
		const ele = document.getElementById("func-" + this.hash);
		
		ele.removeEventListener("click", this.onClick);
		
		ele.parentElement.innerHTML += this.html;
		
		const newEle = document.getElementById("func-" + this.hash);
		newEle.addEventListener("click", this.onClick);
		newEle.funcInfo = this;

		document.getElementById("cph-" + this.name).addEventListener("click", this.onCopyHash);
		document.getElementById("cph-" + this.name).funcHash = this.hash;
		
		document.getElementById("cpl-" + this.name).addEventListener("click", this.onCopyLink);
		document.getElementById("cpl-" + this.name).funcHash = this.hash;
	}
	
	close()
	{
		if (!this.isOpen) return;
		
		this.isOpen = false;
		
		const ele = document.getElementById("func-" + this.hash);
		
		ele.removeEventListener("click", this.onClick);
		
		document.getElementById("cph-" + this.name).removeEventListener("click", this.onCopyHash);
		document.getElementById("cpl-" + this.name).removeEventListener("click", this.onCopyLink);
		
		ele.parentElement.innerHTML = ele.parentElement.innerHTML.split("<div")[0];
		
		const newEle = document.getElementById("func-" + this.hash);
		
		newEle.addEventListener("click", this.onClick);
		newEle.funcInfo = this;
	}

	init()
	{
		const elem = document.getElementById("func-" + this.hash);	
		elem.addEventListener("click", this.onClick);
		elem.funcInfo = this;
	}
};

function copyTextToClipboard(text) {
	navigator.clipboard.writeText(text).catch(console.error);
}

// [============= Native Downloading =============]
function download(filename, text) {
    var element = document.createElement('a');
    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', filename);
	element.setAttribute('class', 'matomo_ignore');

    element.style.display = 'none';
    document.body.appendChild(element);

    element.click();

    document.body.removeChild(element);
}

async function onClickGenerateNativesFile()
{
	let options = {};

	Swal.fire({
		title: 'natives.h options',
		html: `
            <div class="form-check">
                <input class="form-check-input" type="checkbox" value="" id="includecomments" style="float: left; position: relative; top: 2px">
                <label class="form-check-label" for="includecomments" style="float: left;">
                    Include comments
                </label>
            </div>
			<br><br>
            <div class="form-check">
                <input class="form-check-input" type="checkbox" value="" id="supportsvoid" style="float: left; position: relative; top: 2px">
                <label class="form-check-label" for="supportsvoid" style="float: left;">
                    Invoker supports 'void'
                </label>
            </div>
			<br><br>
            <div class="form-check">
                <input class="form-check-input" type="checkbox" value="" id="usereferences" style="float: left; position: relative; top: 2px">
                <label class="form-check-label" for="usereferences" style="float: left;">
                    Use references instead of pointers
                </label>
            </div>
			<br><br>
            <div class="form-check">
                <input class="form-check-input" type="checkbox" value="" id="vectoroverloads" style="float: left; position: relative; top: 2px" checked>
                <label class="form-check-label" for="vectoroverloads" style="float: left;">
                    Vector overloads
                </label>
            </div>
    	`,
    	preConfirm: () => {
			options.bWithComments = document.getElementById('includecomments').checked;
			options.maxCommentLength = 5000;
			options.bSupportsVoid = document.getElementById('supportsvoid').checked;
			options.bUseReferences = document.getElementById('usereferences').checked;
			options.bVectorOverloads = document.getElementById('vectoroverloads').checked;
    	},
		confirmButtonText: 'Generate',
		showCloseButton: true
	}).then((result) => {
		if (result.isConfirmed)
			generateNativesFile(options);
	});
}

function shouldParamBeAReference(param)
{
	return param.type[param.type.length-1] === "*"
		&& param.type !== "Any*"
		&& param.type !== "const char*"
		&& param.type !== "char*";
}

// vvv mostly copied from GTAV-NativeDB
function splitCamelCaseString(str) {
	return str.replace(/([A-Z0-9])/g, '_$1').toLowerCase().split('_');
}

function getParamGroup(params) {
    if (params[0].name.includes("_"))
        return [1, params[0].name];

    const set = ['x', 'y', 'z', 'w'];

    let group = splitCamelCaseString(params[0].name)
        .join('');

    // Check for a special case where the first parameter is a Vector2 and the second is a float for RDR1 PC Vector3 support
    if (
        params.length >= 2 && 
        params[0].type === 'Vector2' && 
        params[1].type === 'float') 
    {
        return [2, group];
    }

    const selected = _.takeWhile(params, ({ name, type }, index) => {
        const split = splitCamelCaseString(name);

        return (
            split.includes(set[index]) &&
            split.filter(g => g !== set[index]).join('') === group &&
            type === 'float'
        );
    });

    return [selected.length, group];
}


  function getParamNameForParamGroup(groupName) {
    let defaultName = 'vec';

    return groupName
      ? `${groupName.replace(/^(\d)$/, `${defaultName}$1`)}`
      : defaultName;
  }

  function compactParams(params, compactVectors) {
	if (!compactVectors) {
		return {params: params, hasCompactVector: false};
	}

	let result = {params: [], hasCompactVector: false};

    for (let i = 0; i < params.length; ++i) {
      const [groupLength, groupName] = getParamGroup(params.slice(i));

//    if (groupLength >= 2) {
	  if (groupLength == 2) {
		if (!result.hasCompactVector) result.hasCompactVector = true;
		  result.params.push({
          type: `Vector3`,
          name: getParamNameForParamGroup(groupName)
        })
        i += groupLength - 1;
      }
      else {
        result.params.push(params[i]);
      }
    }

    return result;
  }

  function formatInvokeParam(param, bUseReferences = false) {
	switch (param.type)
	{
        // RDR1 PC Vector3 support
		case 'Vector3':
			return `Vector2(${param.name}.x, ${param.name}.y), ${param.name}.z`;
	}

	if (bUseReferences && shouldParamBeAReference(param))
	{
		return `&${param.name}`;
	}

	return param.name;
  }
// ^^^ mostly copied from GTAV-NativeDB

function writeNativeDeclLine(native, nativeObj, bSupportsVoid = false, bUseReferences = false, bIsVectorOverload = false)
{
	let resultString = "";

	let p = compactParams(nativeObj["params"], bIsVectorOverload);

	if (bIsVectorOverload && !p.hasCompactVector)
	{
		return "";
	}

	resultString += "\tstatic " + nativeObj.return_type + " " + nativeObj.name + "(";	

	for (let i = 0; i < p.params.length; i++) {
		let param = p.params[i];
		if (bUseReferences && shouldParamBeAReference(param))
			resultString += param.type.substring(0, param.type.length-1) + "& " + param.name;
		else
			resultString += param.type + " " + param.name;

		resultString +=	(i != p.params.length - 1 ? ", " : "");
	}

	if (nativeObj.return_type == "void")
	{
		if (bSupportsVoid)
			resultString += ") { invoke<void>(";
		else
			resultString += ") { invoke<Void>(";
	}
	else
	{
		resultString += ") { return invoke<" + nativeObj.return_type + ">(";
	}

	resultString += native + (p.params.length != 0 ? ", " : "");

	resultString += [...p.params.map((param) => { return formatInvokeParam(param, bUseReferences) })].join(', ');

	resultString += "); } // " + native.toString() + endl;

	return resultString;
}

const endl = "\r\n";
function generateNativesFile(options)
{
    let resultString = "";

    let date = new Date();
    resultString += "#pragma once" + endl + endl
    + "// Generated " + date.toUTCString() + endl
	+ "// https://therouletteboi.github.io/rdr/nativedb/" + endl + endl;

    for (let namespace in jsonData) {
        resultString += "namespace " + namespace + endl +
            "{" + endl;

        let nsObj = jsonData[namespace];
        for (let native in nsObj) {
            let nativeObj = nsObj[native];
			
            if (options.bWithComments && nativeObj.comment !== "" && nativeObj.comment.length <= options.maxCommentLength)
            {
                let commentStr = nativeObj.comment;
                let lines = commentStr.split(/\r?\n/);
                for (let i = 0; i < lines.length; i++)
                {
                    resultString += "\t// " + lines[i] + endl;
                }
            }
			
			resultString += writeNativeDeclLine(native, nativeObj, options.bSupportsVoid, options.bUseReferences);

			if (options.bVectorOverloads)
				resultString += writeNativeDeclLine(native, nativeObj, options.bSupportsVoid, options.bUseReferences, true);
        }

        resultString += "}" + endl + endl;
    }

    download("natives.h", resultString);

	const json = {
		options: options,
		queryParams: window.location.search,
		referrer: document.referrer
	};

	trackEvent("natives_header", "generate", JSON.stringify(json));
}

function getUrlParam(param) {
	return new URLSearchParams(window.location.search).get(param);
}

async function init() {
	//const startTime = performance.now();

	nativesModTime = 0; // args.nativesModTime;

    loadNativeInfo();

    while (jsonData === undefined) {
        await sleep(1);
    }

    let namespaces = "";
    let nsCount = 0, nCount = 0, cCount = 0, kCount = 0, namedCount = 0;
    const v = getNamespaces();

    for (let i = 0; i < v.length; i++) {
        const nC = getNativeCount(v[i]);
        const nObjs = getNativeObjects(v[i]);

        for (let j = 0; j < nObjs.length; j++) {
            if (hasComment(nObjs[j])) {
                cCount++;
            }
            if (isNameKnown(nObjs[j])) {
                kCount++;
            }
            if (isNativeNamed(nObjs[j])) {
                namedCount++;
            }
        }

        nCount += nC;
        nsCount++;
        namespaces += "<li><a class='namespace' id='ns-" + v[i] + "'>" + v[i] + " [" + nC + "]</a>" + "<a class='nsexpand' id='" + v[i] + "-expand-all' hidden> (expand all)</a>" + "</li>\n";
    }

    document.getElementById("nname").innerHTML = namespaces;

    for (let i = 0; i < v.length; i++) {
        document.getElementById("ns-" + v[i]).addEventListener("click", function () {
            openNamespaceTab(v[i]);
			trackEvent("namespace", "open", v[i]);
        })
    }

    const infobox = document.getElementById("infobox");
    infobox.innerHTML = "<a class='nohover' style='float: left'>Namespaces: " + nsCount + " | " + "Natives: " + nCount + " | " + "Comments: " + cCount + " | " + "Known names: " + kCount + " (" + namedCount + ")" + " | " + "</a>" +
                        "&nbsp;<a onclick='onClickGenerateNativesFile()'>Generate natives.h</a> " + infobox.innerHTML;

    document.getElementById("expand").addEventListener("click", function () {
        const c = getNamespaces();

        for (let ns in c) {
            let name = c[ns];

            if (!isNamespaceTabOpened(name)) {
                openNamespaceTab(name);
            }
        }

		trackEvent("namespace", "expand_all");
    });

    document.getElementById("collapse").addEventListener("click", function () {
        const c = getNamespaces();

        for (let ns in c) {
            let name = c[ns];

            if (isNamespaceTabOpened(name)) {
                closeNamespaceTab(name);
            }
        }

		//trackEvent("namespace", "collapse_all");
    });

    document.getElementById("loading").innerHTML = "";
	
	let ns = getUrlParam("ns");
	
	if (ns !== null)
	{
		ns = ns.toUpperCase();
		
		if (ns === "ALL")
		{
			let c = getNamespaces();
			
			for (let _ns in c)
			{
				let name = c[_ns];

				if (!isNamespaceTabOpened(name))
					openNamespaceTab(name);
			}
		}
		else if (ns in jsonData)
		{
			if (!isNamespaceTabOpened(ns))
				openNamespaceTab(ns);
			
			document.getElementById("ns-" + ns).scrollIntoView();
		}
		else
		{
			trackEvent("init", "namespace_not_found", ns);
		}
	}
	else
	{
		let n = getUrlParam("n");
	
		if (n !== null)
		{
			n = n.substr(0, 18);

			let ns = getNamespaceFromHash(n);
			
			if (ns !== null)
			{
				if (!isNamespaceTabOpened(ns))
					openNamespaceTab(ns);
				
				funcInfos.get(n).open();
				
				document.getElementById("func-" + n).scrollIntoView({block: "center"});
			}
			else
			{
				trackEvent("init", "native_not_found", n);
			}
		}
	}

	//const endTime = performance.now();
	//const elapsed = endTime - startTime;
	//trackEvent("init", "elapsed_time_ms", "", elapsed);
}
