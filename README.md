# Simple Shell

## Description

**Simple Shell** is a basic implementation of a UNIX command-line interpreter. This project was completed as part of the Holberton School program by **Jade Jorré** and **Kévin Martins De Castro**.

The shell provides an interface to execute commands in interactive and non-interactive modes, mimicking the behavior of `/bin/sh`. This project applies key concepts of UNIX system programming, such as process management, system calls, environment manipulation, and more.

---

## Features

### Version 1.0

- **Execute basic UNIX commands**:
  - Interactive mode: Displays a prompt and waits for user input.
  - Non-interactive mode: Executes commands provided via a file or input redirection.
- **PATH searching**: Executes commands by locating programs in directories specified by the `PATH` environment variable.
- **Error handling**: Displays an error message when a command is invalid or not found.
- **Supports commands with arguments**.
- **Built-in commands**:
  - `exit`: Closes the shell.
  - `env`: Displays the current environment.

---

## Requirements

- **Operating System**: Ubuntu 20.04 LTS.
- **Compiler**: `gcc` with the following options:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```
- **Code Style**: Adheres to the Betty coding standard.

---

## Installation

1. Clone the GitHub repository:
   ```bash
   git clone https://github.com/JorreJ/holbertonschool-simple_shell.git
   ```

2. Compile the project:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```

3. Run the shell:
   - Interactive mode:
     ```bash
     ./hsh
     ```
   - Non-interactive mode:
     ```bash
     echo "command" | ./hsh
     ```

---

## Usage

### Interactive Mode
```bash
$ ./hsh
($) /bin/ls
file1 file2 file3
($) exit
```

### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
file1 file2 file3
```

---

## Main Files

| **File**            | **Role**                                    |
|---------------------|---------------------------------------------|
| `shell.c`           | Contains the main logic of the shell.       |
| `shell_func.c`      | Implementation of the `execve` call.        |
| `rewrited_func.c`   | Manages PATH searching.                     |

---

## Command Examples

- **List files**:
  ```bash
  ($) /bin/ls
  ```

- **Display environment**:
  ```bash
  ($) env
  ```

- **Exit the shell**:
  ```bash
  ($) exit
  ```

---

## Authors

Project contributors:

- **Jade Jorré** - https://github.com/JorreJ
- **Kévin Martin De Castro** - https://github.com/Kevindecastro
