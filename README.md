# Bitwise Command Line Toolkit

A command-line toolkit for learning and exploring binary and bitwise operations in C++.
It reinforces core concepts through intuitive input and clean, beginner-friendly output.

![C++](https://img.shields.io/badge/language-C++20-blue)

---
Built by **Sauel Almonte**  
[LinkedIn Profile](https://www.linkedin.com/in/your-linkedin-handle)
---

## Features

- Evaluate expressions using:
    - Bitwise AND (`&`)
    - Bitwise OR (`|`)
    - Bitwise XOR (`^`)
    - Bitwise NOT / Negate (`~`)
    - Left Shift (`<<`)
    - Right Shift (`>>`)
- View binary output in 8-bit format with `0b` prefix (e.g., `0b00001010`)
- Set, clear, toggle, and check individual bits by position
- Accepts programmer-style expressions (e.g., `4 << 1`, `~5`)
- Modular codebase using header/source separation
- Built using CMake — compatible with CLion, Visual Studio, VSCode, and terminal builds

---

## Getting Started

### Requirements

- **C++20-compliant compiler**  
  (e.g., GCC 10+, Clang 11+, MSVC 2019 or later)
- **CMake** 3.20 or newer
- **Git** (optional, for cloning the repository)
- **One of the following development environments:**
    - [CLion (JetBrains)](https://www.jetbrains.com/clion/)
    - [Visual Studio](https://visualstudio.microsoft.com/) with CMake support
    - [Visual Studio Code](https://code.visualstudio.com/) with:
        - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
        - [C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
    - Terminal with a supported build system (e.g., `make`, `ninja`)

---

### Build Instructions

#### Option 1: **CLion (JetBrains)**

1. Open CLion.
2. Choose **Open** and select the project root folder.
3. CLion will automatically detect the `CMakeLists.txt`.
4. Click **Run** or **Build** to compile and launch the program.

#### Option 2: **Visual Studio (Windows)**

1. Open Visual Studio.
2. Select **Open a Local Folder**, choose the project root.
3. Ensure CMake support is enabled.
4. Visual Studio will configure and generate the CMake targets automatically.
5. Click **Run** or **Build All**.

#### Option 3: **VSCode + CMake Tools**

1. Install the following VSCode extensions:
    - CMake Tools
    - C++ by Microsoft
2. Open the project root in VSCode.
3. Use the command palette (`Ctrl+Shift+P`) → **CMake: Configure**.
4. Then run: **CMake: Build** and **CMake: Run Without Debugging**.

#### Option 4: **Terminal (Cross-platform)**

```
git clone https://github.com/yourusername/bitwise-toolkit.git
cd bitwise-toolkit
cmake -B build
cmake --build build
./build/BitwiseCommandLineToolkit
```

### Expression Examples

Evaluate bitwise expressions directly:

```text
> 5 & 7
Decimal: 5
Binary : 0b00000101

> 12 | 3
Decimal: 15
Binary : 0b00001111

> 10 ^ 6
Decimal: 12
Binary : 0b00001100

> ~4
Decimal: 251
Binary : 0b11111011

> 8 << 2
Decimal: 32
Binary : 0b00100000

> 16 >> 1
Decimal: 8
Binary : 0b00001000


```

### Keyword Commands
```text
> bin 10
0b00001010

> set 4 1
Decimal: 6
Binary : 0b00000110

> clear 6 1
Decimal: 4
Binary : 0b00000100

> toggle 4 2
Decimal: 0
Binary : 0b00000000

> check 5 0
Set

> help
(Displays available commands)

> exit
(Exits the program)

```

---
### Directory Structure

```text
BitwiseCommandLineToolkit/
├── main.cpp
├── CMakeLists.txt
├── BitwiseOperations/
│   ├── bitwise_operations.h
│   └── bitwise_operations.cpp
├── CommandParser/
│   ├── command_parser.h
│   └── command_parser.cpp
├── core/
│   ├── utils.h
│   └── utils.cpp

```

---

## License
This project is licensed under the MIT License. See LICENSE for details.

---

## Disclaimer
This software is provided for educational purposes only.  
It is offered "as is", without warranty of any kind — express or implied — including but not limited to the warranties of merchantability, fitness for a particular purpose, or non-infringement.  
Use of this toolkit is at your own discretion and risk.
