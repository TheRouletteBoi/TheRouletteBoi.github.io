import json

embedJsonFile = """

"""

# BUG: parsing will use comment hex value instead of invoke<> value. Search for 'Unused' in json and manually fix
# BUG: fix random '//' comments
# BUG: will parse const char* incorrectly
# BUG: this function is broken 0x6B8E4CDD
# BUG: this function is broken _0xD7BB1792
# BUG: search for "{" invalid native names

# Initialize a dictionary to store all function details
all_functions_dict = {}

# Split the code by namespaces
code_namespaces = embedJsonFile.strip().split("\n\n")

# Iterate through each namespace
for namespace_code in code_namespaces:
    # Split the namespace code by lines
    code_lines = namespace_code.strip().splitlines()

    # Initialize variables to store function details
    namespace_name = None
    functions = []

    # Iterate through each line of code
    for line in code_lines:
        if line.strip().startswith("namespace "):
            # Extract the namespace name
            namespace_name = line.strip().split()[1]
        elif line.strip().startswith("static "):
            # Extract function details using a simpler approach
            function_parts = line.strip().split()
            return_type = function_parts[1]
            function_signature = " ".join(function_parts[2:]).split("//")[0]  # Remove comments
            function_name = function_signature.split("(")[0]
            parameters = function_signature.split("(")[1].split(")")[0].split(",") if "(" in function_signature else []

            # Extract parameter types and names
            param_info = []
            for param in parameters:
                param_parts = param.strip().split()
                if len(param_parts) == 2:
                    param_type, param_name = param_parts
                    param_info.append({"Type": param_type, "Name": param_name})

            comment_hex_value = function_parts[-1]

            functions.append({
                "Namespace": namespace_name,
                "Return Type": return_type,
                "Function Name": function_name,
                "Parameters": param_info,
                "Comment Hexadecimal Value": comment_hex_value,
            })

    # Add functions from the current namespace to the dictionary
    all_functions_dict[namespace_name] = functions

# Write all the function details to a single text file
output_file_path = "natives.json"
with open(output_file_path, "w") as output_file:

    output_file.write('{')

    for namespace, functions in all_functions_dict.items():
        output_file.write(f'"{namespace}": {{')

        for i, func in enumerate(functions):
            output_file.write(f'"{func["Comment Hexadecimal Value"]}": {{')
            output_file.write(f'"name": "{func["Function Name"]}",')
            output_file.write(f'"comment": "",')
            output_file.write('"params": [')
                
            total_params = len(func['Parameters'])
            for j, param in enumerate(func['Parameters']):
                output_file.write('{')
                output_file.write(f'"type": "{param["Type"]}",')
                output_file.write(f'"name": "{param["Name"]}"')
                if j < total_params - 1:
                    output_file.write('},')
                else:
                    output_file.write('}')
                        
            output_file.write('],')
            output_file.write(f'"return_type": "{func["Return Type"]}"')
            if i < len(functions) - 1:
                output_file.write('},')
            else:
                output_file.write('}')
            
        output_file.write('},')

    output_file.write('}')

print(f"natives saved to {output_file_path}.")
