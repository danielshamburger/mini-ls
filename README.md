# Mini `ls`

A light implementation of the *nix `ls` command.

## Build

Any C compiler should work, but I use:
```bash
clang -Wall main.c
```

## Usage

[EXECUTABLE] [OPTIONS] [DIRECTORY]

### Options

- `-n`: show user and group
- `-i`: show inode number
- `-s`: show the of size (in bytes) and blocks
