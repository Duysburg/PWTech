import os
import re

# Define the file extensions to search for
extensions = [".ino", ".h", ".cpp"]
current_path = os.path.dirname(os.path.dirname(__file__))
is_first_class = True
variable_uses = {}

# Functions
def begins_with(begin_str, line_str) -> bool:
    return re.search(r"\s*" + re.escape(begin_str), line_str)!= None

with open(os.path.join(current_path, "mermaid_class_diagram_generated.txt"), "w") as write_file:
    write_file.write("classDiagram\n")

    # Recursively search for files with the given extensions
    for root, dirs, files in os.walk(current_path):
        for name in files:
            if any(name.endswith(ext) for ext in extensions):
                # important code structures to be remembered over multiple lines
                current_class_struct = ""
                current_brace_level = 0
                is_class_not_struct = True
                members_currently_private = True
                multiline_string = False
                multiline_comment = False

                # Get the full path to the file
                file_path = os.path.join(root, name)
            
                # Open the file and read its contents
                with open(file_path, "r") as file:
                    contents = file.read()
            
                print("\n" + name)
                # Print the contents of the file line by line
                lines = contents.splitlines()
                for line in lines:
                    # check if line is commented out
                    if begins_with("/*", line) and not "*/" in line:
                        multiline_comment = True
                        continue
                    elif "*/" in line and not "/*" in line:
                        multiline_comment = False
                        continue
                    if begins_with("//", line) or begins_with("*", line):
                        continue
                    if multiline_comment:
                        continue

                    # Check for strings and remove them
                    line = re.sub(r'\".*\"', r"", line)

                    # Check if there is a multiline string and remove it
                    if re.search(r'\"', line) != None:
                        if not multiline_string:
                            line = re.sub(r'\".*', r"", line)
                            multiline_string = True
                        else:
                            line = re.sub(r'.*\"', r"", line)
                            multiline_string = False
                    elif multiline_string:
                        continue

                    # check for curly braces (only safe variables and functions in the first level)
                    current_brace_level += len(re.findall(r"\{", line))
                    current_brace_level -= len(re.findall(r"\}", line))

                    if current_brace_level <= -1:
                        print("ERROR: brace level too low")
                    elif current_brace_level == 2 and re.search(r"\{", line) != None:
                        line = line.split("{")[0]
                    elif current_brace_level >= 3:
                        continue

                    # Check for class or struct
                    if begins_with("class", line) or begins_with("struct", line):
                        if is_first_class:
                            is_first_class = False
                        else:
                            write_file.write(f"\t}}\n")

                        current_class_struct = re.search(r"\s*(class|struct) ([^\{]+)", line).group(2).strip()
                        if current_class_struct[0] == "_":
                            current_class_struct = current_class_struct[1:]
                        write_file.write(f"\tclass {current_class_struct} {{\n")

                        print("current class: " + current_class_struct)
                        if re.search(r"\s*class ", line):
                            members_currently_private = True
                        else:
                            members_currently_private = False

                        # Create a dictionary key
                        variable_uses[current_class_struct] = []
                        
                        continue
                    
                    # nothing out of the scope of classes should be in the class diagram
                    if current_class_struct == "":
                        continue

                    # Check for public or private
                    if begins_with("public:", line):
                        members_currently_private = False
                        print("+public")
                    elif begins_with("private:", line):
                        members_currently_private = True
                        print("-private")
                    
                    # line without semicolon
                    line_for_methods = re.sub(r".*;", "", line)

                    # Check for methods
                    if re.search(r"\s*\w+\s[a-zA-Z0-9_]+\s*\(", line_for_methods) and not re.search(r"\belse\b", line_for_methods) and not re.search(r"\bif\b", line_for_methods):
                        #get method name
                        method_regex = re.search(r"\s*(?P<type>\w+)\s(?P<name>[a-zA-Z0-9_]+)\s*\((?P<parameters>.*)\)", line_for_methods)
                        write_file.write(f"\t\t{'-' if members_currently_private else '+'}{method_regex.group('name')}({method_regex.group('parameters')}) : {method_regex.group('type')}\n")
                        
                        print(f"method ({current_class_struct}): {method_regex.group('name')}")
                        print(f"metho param ({current_class_struct}): {method_regex.group('parameters')}")
                        print(f"method type ({current_class_struct}): {method_regex.group('type')}")
                        continue

                    # Check for constructors
                    constructor_regex = re.search(r"\s*" + re.escape(current_class_struct) + r" *\((?P<constructorParam>.*)\)", line_for_methods)
                    if constructor_regex != None:
                        constructor_parameters = constructor_regex.group("constructorParam")
                        write_file.write(f"\t\t{current_class_struct}({constructor_parameters})\n")
                        continue
                    
                    # Check for variables
                    variable_regex = re.search(r"(?P<variableType>[a-zA-Z0-9_]+\*?\&?)\s+(?P<variableName>[a-zA-Z0-9_]+)\s*(;|\s*=.*;)", line)                    
                    if variable_regex != None:
                        variable_type = variable_regex.group("variableType")
                        variable_name = variable_regex.group("variableName")
                        write_file.write(f"\t\t{'-' if members_currently_private else '+'}{variable_name} : {variable_type}\n")

                        # safe variable to dictionary
                        if not current_class_struct in variable_uses:
                            variable_uses[current_class_struct] = [variable_type]
                            print("ERROR: This should not happen. A dictionary key for this class has not been created.")
                        else:
                            variable_uses[current_class_struct].append(variable_type)
                        continue

    write_file.write("\t}")

    # Write class relations
    for class_name in variable_uses:
        for variable_name in variable_uses[class_name]:
            # check if variable is already in the class diagram
            if variable_name in variable_uses:
                write_file.write(f'\n\t{class_name} "" --> "" {variable_name}')