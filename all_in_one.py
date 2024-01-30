# the easiest way to get rid of circular imports (i know)
import os
import re

# Define the file extensions to search for
extensions = [".h"]
current_path = os.path.dirname(__file__)

# Functions
def begins_with(begin_str, line_str) -> bool:
    return re.search(r"\s*" + re.escape(begin_str), line_str)!= None

with open(os.path.join(current_path, "allUnits.h"), "w") as write_file:
    write_file.write("// auto generated file\n")

    for root, dirs, files in os.walk(current_path):
        for name in files:
            if any(name.endswith(ext) for ext in extensions):
                # go through all lines in the file to check for circular imports

                # Get the full path to the file
                file_path = os.path.join(root, name)
            
                # Open the file and read its contents
                with open(file_path, "r") as file:
                    contents = file.read()

                # write all lines that don't contain an include from another file in the write_file
                lines = contents.splitlines()
                for line in lines:
                    if begins_with('#include', line) and "Unit" in line:
                        continue
                    write_file.write(line + "\n")