# Mini `ls`

A light implementation of the POSIX `ls` command.

## Build

Any C compiler should work, but I use:
```bash
clang -Wall main.c
```

## Usage

```bash
[EXECUTABLE] [OPTIONS] [DIRECTORY]
```

### Options

- `-n`: show user and group
- `-i`: show inode number
- `-s`: show the of size (in bytes) and blocks
