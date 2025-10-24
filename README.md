# Mini-Libc

A minimal implementation of the C standard library that provides basic system call wrappers and fundamental C library functions.

## Overview

This project implements a subset of the C standard library, focusing on essential functionality including:

- System call wrappers
- Basic I/O operations
- Memory management
- Process control
- String manipulation
- File operations
- Error handling

## Project Structure

```
.
├── crt/                    # C Runtime initialization
│   ├── __libc_start_main.c
│   └── start.asm
├── include/               # Header files
│   ├── internal/         # Internal implementation headers
│   └── sys/             # System-specific headers
├── io/                   # Input/Output operations
├── mm/                   # Memory management
├── process/             # Process control functions
├── stat/                # File status operations
├── string/              # String manipulation functions
├── errno.c              # Error number handling
├── syscall.c            # System call implementation
└── Makefile            # Build configuration
```

## Features

### System Calls

- Basic system call infrastructure for x86_64 architecture
- System call number definitions and architecture-specific implementations

### Memory Management

- `malloc()` implementation
- Memory mapping (`mmap`) support
- Memory list management

### I/O Operations

- File operations (open, close, read, write)
- File seeking (lseek)
- File truncation
- Basic output (puts)

### Process Control

- Process exit
- Sleep functions (sleep, nanosleep)

### File Status

- File status checking (stat, fstat, fstatat)

### String Operations

- Basic string manipulation functions

## Building

To build the library, simply run:

```bash
make
```

## Usage

This library can be used as a minimal replacement for the standard C library in embedded systems or minimal environments. Link against it instead of the standard C library when building your programs.

## Architecture Support

Currently supports:

- x86_64 architecture

## Notes

- This is a minimal implementation and doesn't include all standard C library functions
- Focused on providing basic system call wrappers and essential functionality
- Suitable for educational purposes and minimal runtime environments
