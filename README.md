# C Programming Codes

[![C Build CI](https://github.com/chinmaymusale123/C-programming-codes/actions/workflows/ci.yml/badge.svg)](https://github.com/chinmaymusale123/C-programming-codes/actions/workflows/ci.yml)
[![Language: C99](https://img.shields.io/badge/Language-C99-00599C?style=flat&logo=c)](https://en.wikipedia.org/wiki/C99)
[![Compiler: GCC](https://img.shields.io/badge/Compiler-GCC-green.svg)](https://gcc.gnu.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A structured collection of C programming lab codes, algorithms, and exercises covering core computer science concepts including data structures, pointer manipulation, dynamic memory allocation, and file systems.

---

## Repository Structure

```
C-programming-codes/
├── .github/
│   └── workflows/
│       └── ci.yml               # Automated syntax verification workflow
├── LEVEL-1-CODES/               # Foundational C implementations
│   ├── max_value_array_#1.c
│   ├── cmp_area_rect_#2.c
│   ├── Arrayofstruc_recarea_#3.c
│   ├── flight_search_systems_#4.c
│   ├── swapping_arrays_#5.c
│   ├── dynamic_memory_allocation_#6.c
│   ├── cmp_strings_#7.c
│   ├── concat_strings_#8.c
│   ├── reading_writing_file_#9.c
│   └── reading_writing_binary_file_#10.c
├── LEVEL-2-CODES/               # Intermediate & applied C programs
│   ├── #1_String_pattern_matching.c
│   ├── #2_movie_sorting.c
│   └── #3_search_movie.c
├── .gitignore                   # Ignore binary executables & object files
└── README.md
```

---

## Level 1 Codes Overview

| # | Program | Key Concept | Description |
|---|---|---|---|
| **1** | [`max_value_array_#1.c`](LEVEL-1-CODES/max_value_array_%231.c) | Array Traversal | Computes the largest element in an integer array using linear scanning. |
| **2** | [`cmp_area_rect_#2.c`](LEVEL-1-CODES/cmp_area_rect_%232.c) | C Structures | Computes and compares areas of rectangles modeled with `struct`. |
| **3** | [`Arrayofstruc_recarea_#3.c`](LEVEL-1-CODES/Arrayofstruc_recarea_%233.c) | Array of Structs | Manages multiple rectangle records using structured arrays. |
| **4** | [`flight_search_systems_#4.c`](LEVEL-1-CODES/flight_search_systems_%234.c) | Record Searching | Simulates a flight search query engine with string matching. |
| **5** | [`swapping_arrays_#5.c`](LEVEL-1-CODES/swapping_arrays_%235.c) | Array Manipulation | Swaps elements between two arrays using temporary storage. |
| **6** | [`dynamic_memory_allocation_#6.c`](LEVEL-1-CODES/dynamic_memory_allocation_%236.c) | Dynamic Memory | Allocates and releases heap memory using `malloc` and `free`. |
| **7** | [`cmp_strings_#7.c`](LEVEL-1-CODES/cmp_strings_%237.c) | String Algorithms | Custom character-by-character string comparison without library helpers. |
| **8** | [`concat_strings_#8.c`](LEVEL-1-CODES/concat_strings_%238.c) | Pointer Manipulation | Pointer-based string concatenation and buffer management. |
| **9** | [`reading_writing_file_#9.c`](LEVEL-1-CODES/reading_writing_file_%239.c) | Text File I/O | Reads and writes formatted records using `fopen`, `fprintf`, and `fscanf`. |
| **10** | [`reading_writing_binary_file_#10.c`](LEVEL-1-CODES/reading_writing_binary_file_%2310.c) | Binary File I/O | Serializes and deserializes structured binary data using `fread` and `fwrite`. |

---

## Level 2 Codes Overview

| # | Program | Key Concept | Description |
|---|---|---|---|
| **1** | [`#1_String_pattern_matching.c`](LEVEL-2-CODES/%231_String_pattern_matching.c) | Pattern Matching & Replacement | Scans an input string for a target sub-pattern and replaces all occurrences with custom replacement text without library shortcuts. |
| **2** | [`#2_movie_sorting.c`](LEVEL-2-CODES/%232_movie_sorting.c) | Dynamic Struct Array & CSV Sorting | Dynamically allocates an array of `Movie` structs, parses an IMDb CSV file, sorts records by rating and year, writes output, and frees heap memory. |
| **3** | [`#3_search_movie.c`](LEVEL-2-CODES/%233_search_movie.c) | Structured File Parsing & Linear Search | Parses comma-separated values using `sscanf` formatting `[%99[^,],...]`, performs linear searches for movie titles, and manages memory. |

---

## Build & Run Guide

### Prerequisites
- GCC compiler installed (`gcc --version`)

### Compilation

You can compile any program using GCC:

**Linux / macOS:**
```bash
# Example: Compile Program #1
gcc "LEVEL-1-CODES/max_value_array_#1.c" -o max_value
./max_value
```

**Windows (PowerShell / Command Prompt):**
```powershell
# Example: Compile Program #1
gcc "LEVEL-1-CODES\max_value_array_#1.c" -o max_value.exe
.\max_value.exe
```

---

## Automated Verification

The repository includes a GitHub Actions CI pipeline that automatically tests the compilation and syntax of all programs on push:

```bash
# Test compile all programs locally
for file in LEVEL-1-CODES/*.c; do gcc -fsyntax-only "$file"; done
```

---

## Author

**Chinmay Musale**  
GitHub: [@chinmaymusale123](https://github.com/chinmaymusale123) | [LinkedIn](https://www.linkedin.com/in/chinmay-musale-97b23432a)

---

## License

This project is licensed under the [MIT License](LICENSE).
