*This activity has been created as part of the 42 curriculum by raaalali.*

✨ Description 🌟

Welcome to get_next_line 🌟, a flagship 42 project designed to master reading files line by line 📄. Each call returns a full line, including the newline character 🔤, while managing memory like a pro 💪.

The challenge hones your skills in dynamic memory management 🧠, partial reads 📖, and buffer manipulation using low-level system calls 🔧. This implementation is clean 🧹, robust 🛡️, and tailored for 42 Next — precision guaranteed! 🎯
🚀 Instructions 📋
Compilation 🔨

Compile your project alongside a test file:
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

Or set a custom buffer size at compile time:
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
Usage 🛠️

Include the header:
#include "get_next_line.h"

Read lines in a loop:
char *line;
while ((line = get_next_line(fd))) {
    printf("%s", line);
    free(line);
}

    Returns a dynamically allocated string 🧵

    Returns NULL at EOF or on errors ❌

🌐 Resources 📚

    42 Subject PDF: get_next_line 📄

    man 2 read / man 3 malloc 📖

    GNU C Library Docs 📚

AI Assistance 🤖

AI helped review logic, memory management, and structure of this README, but all code was manually implemented by the student. 👨‍💻

📚 Library Overview 🔍

This mini-library supports get_next_line with clean utilities for memory and buffer handling 🧽. Here's a deep dive:
Core Functions ⚙️
char *get_next_line(int fd) 📥

    Public API for line reading 📖

    Maintains static buffer for leftover content 📦

    Handles EOF and read errors gracefully 😌

    Returns lines with \n if present 🌈

static char *fill_buffer(int fd, char *read_buffer) 📥

    Reads chunks from fd until newline or EOF 🔄

    Allocates temporary memory for reads 💾

    Appends data with ft_strjoin 🔗

    Cleans up on errors 🧹

static char *retreive_line(char *str) 📤

    Extracts one complete line ✂️

    Allocates memory safely 🔒

    Returns NULL if buffer is empty 📭

static char *shift_buffer(char *str) 🔄

    Removes the returned line from buffer 🗑️

    Preserves leftover content 💾

    Frees memory if empty ✨

static size_t line_len(char *str, size_t i) 📏

    Computes line length including newline 📐

    Supports extraction and buffer shift 🔄

Utility Functions 🛠️
size_t ft_strlen(const char *str) 📏

    Returns string length safely 🔒

char *ft_strchr(const char *str, int c) 🔍

    Locates a character in a string 🕵️‍♂️

    Detects newlines efficiently 🔍

char *ft_strdup(const char *s) 📋

    Duplicates a string into new memory 🧬

    Used for buffer initialization and shifting 🔄

char *ft_strjoin(char *buffer, char *content) 🔗

    Concatenates two strings safely 🛡️

    Frees old buffer automatically 💥

char *free_all(char *buffer1, char *buffer2) 🗑️

    Frees two memory blocks simultaneously 🧹

    Simplifies error handling 😎

This library is robust 🛡️, efficient ⚡, and visually intuitive — your reliable sidekick for reading files line by line. ✨📄
