"""
Compile automatically the project
"""

import os


def run():
    executable_name: str = "main"
    files_to_compile: list[str] = []

    for dirpath, _, filenames in os.walk("."):
        for filename in filenames:
            if filename.endswith(".cpp") and dirpath.startswith(".\\src"):
                files_to_compile.append(f"{dirpath.replace('\\', '/')}/{filename}")
    
    os.system(f"g++ {' '.join(files_to_compile)} -o {executable_name}")


if __name__ == "__main__":
    run()
