"""
Known limitations:
- variables do not work with direct variable declarations like: Plant testPlant(1);
    - they will be recognised as methods
"""

import os
import re

# Define the file extensions to search for
extensions = [".h"]

searching_path = os.path.join(os.path.dirname(os.path.dirname(__file__)), "RobotMain")
writing_path = os.path.dirname(__file__)
print(searching_path)

is_first_class = True
variable_uses = {}

# Functions
def begins_with(begin_str, line_str) -> bool:
    return re.search(r"\s*" + re.escape(begin_str), line_str)!= None

# Main program
with open(os.path.join(writing_path, "mermaid_class_diagram_generated.txt"), "w") as write_file:
    write_file.write("classDiagram\n")

    # Recursively search for files with the given extensions
    for root, dirs, files in os.walk(searching_path):
        for name in files:
            if any(name.endswith(ext) for ext in extensions):
                # important code structures to be remembered over multiple lines
                current_class_struct = ""
                is_class_not_struct = True
                members_currently_private = True

                # Get the full path to the file
                file_path = os.path.join(root, name)
            
                # Open the file and read its contents
                with open(file_path, "r") as file:
                    contents = file.read()
            
                print("\n" + name)
                # Print the contents of the file line by line
                lines = contents.splitlines()
                for line in lines:
                    # detect class
                    if begins_with("class", line):
                        if is_first_class:
                            is_first_class = False
                        else:
                            write_file.write(f"\t}}\n")

                        # get class name
                        current_class_struct = re.search(r"\s*class (?P<class>[^\{]+)", line).group("class").strip()
                        # remove potential underscore in front of class
                        if current_class_struct[0] == "_":
                            current_class_struct = current_class_struct[1:]

                        # members private by default
                        members_currently_private = True

                        # write to file
                        write_file.write(f"\tclass {current_class_struct} {{\n")
                        print("current class: " + current_class_struct)

                        # Create a dictionary key
                        variable_uses[current_class_struct] = []
                    
                    # detect struct
                    elif begins_with("struct", line):
                        if is_first_class:
                            is_first_class = False
                        else:
                            write_file.write(f"\t}}\n")

                        # get struct name
                        current_class_struct = re.search(r"\s*struct (?P<struct>[^\{]+)", line).group("struct").strip()
                        # remove potential underscore in front of struct
                        if current_class_struct[0] == "_":
                            current_class_struct = current_class_struct[1:]

                        # members public by default
                        members_currently_private = False

                        # write to file
                        write_file.write(f"\tclass {current_class_struct} {{\n")

                        print("current struct: " + current_class_struct)
                    
                    # detect methods
                    elif re.search(r"\w+\s+\w+\s*\(.*\)\s*;", line):
                        # get method name
                        method_regex = re.search(r"\s*(?P<type>\w+)\s+(?P<name>[a-zA-Z0-9_]+)\s*\((?P<parameters>.*)\)", line)
                        method_type = method_regex.group("type")
                        if method_type.strip("*") != method_type:
                            method_type = "*" + method_type.strip("*")
                        elif method_type.strip("&") != method_type:
                            method_type = "&" + method_type.strip("&")
                        
                        # write method to file
                        write_file.write(f"\t\t{'-' if members_currently_private else '+'}{method_regex.group('name')}({method_regex.group('parameters')}) {method_regex.group('type')}\n")
                        print(f"method: {method_regex.group('name')}({method_regex.group('parameters')}) : {method_regex.group('type')}")
                    
                    # detect constructors
                    constructor_regex = re.search(r"^\s*" + re.escape(current_class_struct) + r"\s*\((?P<constructorParam>.*)\)", line)
                    if constructor_regex != None:
                        # write constructor to file
                        write_file.write(f"\t\t{current_class_struct}({constructor_regex.group('constructorParam')})\n")
                        print(f"constructor: {current_class_struct}({constructor_regex.group('constructorParam')})")

                    # detect variables
                    #! does not work with direct variable declarations like: Plant testPlant(1);
                    variable_regex = re.search(r"(?P<variableType>[a-zA-Z0-9_]+\*?\&?)\s+(?P<variableName>[a-zA-Z0-9_]+)\s*(;|\s*=.*;)", line)                    
                    if variable_regex != None:
                        # get varible data
                        variable_type = variable_regex.group("variableType")
                        if variable_type.strip("*") != variable_type:
                            variable_type = "*" + variable_type.strip("*")
                        elif variable_type.strip("&") != variable_type:
                            variable_type = "&" + variable_type.strip("&")
                        variable_name = variable_regex.group("variableName")

                        # write to file
                        write_file.write(f"\t\t{'-' if members_currently_private else '+'}{variable_name} : {variable_type}\n")
                        print(f"variable: {variable_regex.group('variableName')} : {variable_regex.group('variableType')}")

                        # safe variable to dictionary (without pointer stuff)
                        if not current_class_struct in variable_uses:
                            variable_uses[current_class_struct] = [variable_type.strip("*&")]
                            print("ERROR: This should not happen. A dictionary key for this class has not been created.")
                        else:
                            variable_uses[current_class_struct].append(variable_type.strip("*&"))
                    
                    # detect private and public
                    if re.search(r"private:", line) != None:
                        members_currently_private = True
                    elif re.search(r"public:", line) != None:
                        members_currently_private = False

    write_file.write("\t}")

    # Write class relations
    for class_name in variable_uses:
        for variable_name in variable_uses[class_name]:
            # check if variable is already in the class diagram
            if variable_name in variable_uses:
                write_file.write(f'\n\t{class_name} "" --> "" {variable_name}')