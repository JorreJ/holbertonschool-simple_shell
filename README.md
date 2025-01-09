# Simple Shell
A basic UNIX command-line interpreter implemented in C.

## Features
- Executes commands from the PATH.
- Handles built-in commands like `exit` and `env`.
- Supports interactive and non-interactive modes.

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh