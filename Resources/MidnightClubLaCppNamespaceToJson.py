import json
import re

embedJsonFile = """

"""

# BUG: lowcase namespaces

# Define a regex pattern to match function definitions
pattern = r'static\s+(.*?)\s+(.*?)\((.*?)\)\s+\{[^\}]*invoke<.*?>\((0x[0-9A-Fa-f]+)(?:,\s*(.*?))?\);\s+\}'

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
            # Extract function details using the regex pattern
            function_match = re.search(pattern, line.strip())
            if function_match:
                return_type = function_match.group(1)
                function_name = function_match.group(2)
                parameters = function_match.group(3).split(',')  # Split multiple parameters
                hex_value = function_match.group(4)
                parameter_name = function_match.group(5) if function_match.group(5) else None

                # Extract only parameter types
                param_info = []
                for param in parameters:
                    param_parts = param.strip().split()
                    if len(param_parts) == 2:
                        param_type, param_name = param_parts
                        param_info.append({"Type": param_type, "Name": param_name})

                functions.append({
                    "Namespace": namespace_name,
                    "Return Type": return_type,
                    "Function Name": function_name,
                    "Parameters": param_info,
                    "Hexadecimal Value": hex_value,
                })

    # Add functions from the current namespace to the dictionary
    all_functions_dict[namespace_name] = functions

# Print the number of function matches found
total_function_matches = sum(len(functions) for functions in all_functions_dict.values())
print(f"Number of function matches found: {total_function_matches}")

# Write all the function details to a single text file
output_file_path = "natives.json"
with open(output_file_path, "w") as output_file:
    output_file.write('{')

    for namespace, functions in all_functions_dict.items():
        output_file.write(f'"{namespace}": {{')

        for i, func in enumerate(functions):
            output_file.write(f'"{func["Hexadecimal Value"]}": {{')
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
