# get_next_line

[한국어 버전](README.md.kr)

## Overview
`get_next_line` is a project that focuses on reading a line from a file or standard input, one line at a time. The objective is to implement a function that can read a line, handle memory allocation efficiently, and manage multiple file descriptors.

- **Objective:** Implement a function that reads a line from a file descriptor.
- **Key Features:**
  - Reads a line from any file descriptor (supports standard input, files, etc.).
  - Handles dynamic memory allocation efficiently.
  - Works with multiple file descriptors.

## Features
- **Line Reading:**
  - Reads one line at a time, including the newline character.
- **Memory Management:**
  - Allocates memory dynamically for the line buffer.
  - Frees memory after reading a line.
- **File Descriptors:**
  - Supports multiple file descriptors and correctly handles reading from different files.

## Requirements
- **Operating System:** Linux or macOS.
- **Dependencies:**
  - None, uses only standard C libraries.

## Installation and Execution
### Clone the Repository
```bash
git clone [repository URL]
cd get_next_line
```

## File Structure
- `get_next_line.c`: The main implementation of the get_next_line function.
- `get_next_line.h`: Header file with function prototypes.
- `get_next_line_utils.c`: Utility functions for managing the buffer and memory.

## Example Usage
```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;
    
    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
```

## How It Works
- The function get_next_line reads a file descriptor and returns one line at a time.
- Memory is dynamically allocated for the line buffer, and it is freed after the line is printed.

## References
get_next_line tutorial