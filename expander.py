import sys
import os
import re

# This automatically sets the root to where expander.py is located
WORKSPACE_DIR = os.path.dirname(os.path.abspath(__file__))
included_files = set()

def expand(file_path):
    # Prevent infinite loops if files include each other
    if file_path in included_files:
        return []
    
    included_files.add(file_path)
    out_lines = []
    
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            for line in f:
                # Look for local includes using quotes: #include "..."
                match = re.match(r'^\s*#include\s*"(.*)"', line)
                
                if match:
                    include_name = match.group(1)
                    
                    # 1st attempt: Look for the file starting from the workspace root
                    # (e.g., "algorithms/data-structures/Union-Find.cpp")
                    lib_path = os.path.join(WORKSPACE_DIR, include_name)
                    
                    # 2nd attempt: Look for the file relative to the current file being processed
                    rel_path = os.path.join(os.path.dirname(file_path), include_name)
                    
                    if os.path.exists(lib_path):
                        out_lines.extend(expand(lib_path))
                    elif os.path.exists(rel_path):
                        out_lines.extend(expand(rel_path))
                    else:
                        # If the file isn't found, leave the include statement exactly as it is
                        out_lines.append(line)
                
                # Strip out #pragma once to avoid compiler warnings on Codeforces
                elif line.strip() == "#pragma once":
                    continue 
                else:
                    out_lines.append(line)
                    
    except FileNotFoundError:
        print(f"Warning: Could not open file {file_path}")
        
    return out_lines

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 expander.py <path_to_cpp_file>")
        sys.exit(1)

    source_file = sys.argv[1]
    
    if not source_file.endswith('.cpp'):
        print("Error: The provided file is not a .cpp file.")
        sys.exit(1)

    # Generate the expanded file
    expanded_lines = expand(source_file)

    # Create the output filename (e.g., codeforces_submit.cpp)
    out_file = source_file.replace(".cpp", "_submit.cpp")
    
    with open(out_file, 'w', encoding='utf-8') as f:
        f.writelines(expanded_lines)
        
    print(f"Success! Expanded file generated: {out_file}")