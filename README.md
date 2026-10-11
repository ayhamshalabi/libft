# Libft — Custom C Standard Library

Engineered and developed by [Ayham Shalabi](https://github.com/ayhamshalabi)  

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

> A modular static C library (`libft.a`) providing high-performance re-implementations of standard C library (`libc`) routines, BSD string utilities, memory management primitives, and singly linked list data structures.

---

## Table of Contents

- [Overview](#overview)
- [About the Author](#about-the-author)
- [Library Architecture & Description](#library-architecture--description)
  - [Part 1: Libc & System Re-implementations](#part-1-libc--system-re-implementations)
  - [Part 2: Additional String & Numerical Utilities](#part-2-additional-string--numerical-utilities)
  - [Part 3: Singly Linked List Data Structures](#part-3-singly-linked-list-data-structures)
- [Quick Navigation Index](#quick-navigation-index)
- [Instructions](#instructions)
  - [Prerequisites](#prerequisites)
  - [Compilation & Makefile Targets](#compilation--makefile-targets)
  - [Linking Libft in Your Project](#linking-libft-in-your-project)
  - [Running the Built-in Test Suite](#running-the-built-in-test-suite)
- [Detailed Function Breakdown](#detailed-function-breakdown)
  - [Character Classification & Conversion](#character-classification--conversion)
  - [Memory Manipulation Functions](#memory-manipulation-functions)
  - [String Inspection & Copying Functions](#string-inspection--copying-functions)
  - [Dynamic Allocation & String Duplication](#dynamic-allocation--string-duplication)
  - [Advanced String & Numerical Utilities](#advanced-string--numerical-utilities)
  - [File Descriptor Output Functions](#file-descriptor-output-functions)
  - [Singly Linked List Functions](#singly-linked-list-functions)
- [Resources & References](#resources--references)
- [License](#license)

---

## Overview

**Libft** is a comprehensive, standalone C utility library built from the ground up without relying on standard library helper wrappers. In low-level systems programming, mastering manual memory management, pointer arithmetic, and algorithmic edge cases is essential. This project delivers an optimized, robust set of tools packaged as a static library archive (`libft.a`).

### Engineering Highlights
- **Direct Memory & Pointer Arithmetic:** Implements byte-level memory operations, bounds-checked string manipulation, buffer overlap handling, and heap-allocated data structures.
- **Defensive Error Handling:** Built-in safeguards against `NULL` pointer dereferences, integer wrap-arounds (`SIZE_MAX` multiplication overflow guards), and boundary truncation.
- **Zero-Leak Memory Cleanup:** Cascaded rollback deallocation logic across multi-step allocation routines (such as string splitting and functional list mapping) ensuring complete leak freedom.
- **Modular Design:** Pure ANSI C / C99 compliance with zero external runtime dependencies beyond core system calls (`write`, `malloc`, `free`).

---

## About the Author

Developed and maintained by **Ayham Shalabi** (`ayhshala`).

- **GitHub Profile:** [https://github.com/ayhamshalabi](https://github.com/ayhamshalabi)
- **Project Repository:** [https://github.com/ayhamshalabi/libft](https://github.com/ayhamshalabi/libft)

---

## Library Architecture & Description

The project compiles into a single reusable static archive named `libft.a`. It contains **43 functions** organized into three core modules:

```
libft/
├── libft.h                     # Central header declaring all prototypes & t_list struct
├── Makefile                    # Automated build script with dependency tracking
├── main.c                      # Complete 43-function unit testing harness
├── ft_*.c                      # 43 standalone C implementation source files
└── README.md                   # Comprehensive technical documentation
```

### Part 1: Libc & System Re-implementations
Faithful, optimized reconstructions of standard ANSI C (`<ctype.h>`, `<string.h>`, `<stdlib.h>`) and BSD libc extensions:
- **Character Classification & Mutation:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`.
- **Memory Manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.
- **String Examination & Sizing:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi`.
- **Dynamic Allocation:** `ft_calloc`, `ft_strdup`.

### Part 2: Additional String & Numerical Utilities
High-level utility routines designed to simplify modern C development:
- **String Slicing & Joining:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`.
- **Numerical Formatting:** `ft_itoa` (converts signed integer to decimal ASCII string).
- **Higher-Order String Iterators:** `ft_strmapi` (maps with index), `ft_striteri` (in-place mutation with index).
- **I/O Stream Output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` (stream writers targeting arbitrary file descriptors).

### Part 3: Singly Linked List Data Structures
A complete dynamic singly linked list implementation centered around the `t_list` node structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Functions include: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

---

## Quick Navigation Index

| Function | Prototype | Category | Summary |
| :--- | :--- | :--- | :--- |
| [`ft_isalpha`](#ft_isalpha) | `int ft_isalpha(int c);` | Character | Checks if character is alphabetic (`A-Z`, `a-z`) |
| [`ft_isdigit`](#ft_isdigit) | `int ft_isdigit(int c);` | Character | Checks if character is a decimal digit (`0-9`) |
| [`ft_isalnum`](#ft_isalnum) | `int ft_isalnum(int c);` | Character | Checks if character is alphanumeric |
| [`ft_isascii`](#ft_isascii) | `int ft_isascii(int c);` | Character | Checks if character fits in 7-bit ASCII (0–127) |
| [`ft_isprint`](#ft_isprint) | `int ft_isprint(int c);` | Character | Checks if character is printable (32–126) |
| [`ft_toupper`](#ft_toupper) | `int ft_toupper(int c);` | Character | Converts lowercase letter to uppercase |
| [`ft_tolower`](#ft_tolower) | `int ft_tolower(int c);` | Character | Converts uppercase letter to lowercase |
| [`ft_strlen`](#ft_strlen) | `size_t ft_strlen(const char *s);` | String | Calculates length of string excluding null byte |
| [`ft_memset`](#ft_memset) | `void *ft_memset(void *s, int c, size_t n);` | Memory | Fills memory area with a constant byte |
| [`ft_bzero`](#ft_bzero) | `void ft_bzero(void *s, size_t n);` | Memory | Erases memory block by setting bytes to zero |
| [`ft_memcpy`](#ft_memcpy) | `void *ft_memcpy(void *dest, const void *src, size_t n);` | Memory | Copies memory area (non-overlapping) |
| [`ft_memmove`](#ft_memmove) | `void *ft_memmove(void *dest, const void *src, size_t n);` | Memory | Safely copies memory area with overlap handling |
| [`ft_memchr`](#ft_memchr) | `void *ft_memchr(const void *s, int c, size_t n);` | Memory | Scans memory block for matching unsigned byte |
| [`ft_memcmp`](#ft_memcmp) | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Memory | Compares two memory blocks byte-by-byte |
| [`ft_strlcpy`](#ft_strlcpy) | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);` | String | Size-bounded string copy with null termination |
| [`ft_strlcat`](#ft_strlcat) | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);` | String | Size-bounded string concatenation |
| [`ft_strchr`](#ft_strchr) | `char *ft_strchr(const char *s, int c);` | String | Locates first occurrence of character in string |
| [`ft_strrchr`](#ft_strrchr) | `char *ft_strrchr(const char *s, int c);` | String | Locates last occurrence of character in string |
| [`ft_strncmp`](#ft_strncmp) | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | String | Compares two strings up to `n` characters |
| [`ft_strnstr`](#ft_strnstr) | `char *ft_strnstr(const char *big, const char *little, size_t len);` | String | Locates substring in string with bounded search |
| [`ft_atoi`](#ft_atoi) | `int ft_atoi(const char *nptr);` | String | Converts initial substring of string to `int` |
| [`ft_calloc`](#ft_calloc) | `void *ft_calloc(size_t nmemb, size_t size);` | Memory | Allocates zero-initialized memory with overflow guard |
| [`ft_strdup`](#ft_strdup) | `char *ft_strdup(const char *s1);` | String | Allocates heap duplicate of null-terminated string |
| [`ft_substr`](#ft_substr) | `char *ft_substr(char const *s, unsigned int start, size_t len);` | String Util | Extracts substring from specified index |
| [`ft_strjoin`](#ft_strjoin) | `char *ft_strjoin(char const *s1, char const *s2);` | String Util | Concatenates two strings into a new heap allocation |
| [`ft_strtrim`](#ft_strtrim) | `char *ft_strtrim(char const *s1, char const *set);` | String Util | Trims prefix and suffix set characters |
| [`ft_split`](#ft_split) | `char **ft_split(char const *s, char c);` | String Util | Splits string into array of strings by delimiter |
| [`ft_itoa`](#ft_itoa) | `char *ft_itoa(int n);` | Conversion | Converts integer to null-terminated string |
| [`ft_strmapi`](#ft_strmapi) | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Iteration | Creates new string by applying `f` to each char |
| [`ft_striteri`](#ft_striteri) | `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Iteration | Modifies string in place by applying `f` to chars |
| [`ft_putchar_fd`](#ft_putchar_fd) | `void ft_putchar_fd(char c, int fd);` | I/O Stream | Outputs single char to specified file descriptor |
| [`ft_putstr_fd`](#ft_putstr_fd) | `void ft_putstr_fd(char *s, int fd);` | I/O Stream | Outputs string to specified file descriptor |
| [`ft_putendl_fd`](#ft_putendl_fd) | `void ft_putendl_fd(char *s, int fd);` | I/O Stream | Outputs string followed by newline to file descriptor |
| [`ft_putnbr_fd`](#ft_putnbr_fd) | `void ft_putnbr_fd(int n, int fd);` | I/O Stream | Outputs signed integer to file descriptor |
| [`ft_lstnew`](#ft_lstnew) | `t_list *ft_lstnew(void *content);` | Linked List | Allocates and initializes new list node |
| [`ft_lstadd_front`](#ft_lstadd_front) | `void ft_lstadd_front(t_list **lst, t_list *new);` | Linked List | Adds node to beginning of linked list |
| [`ft_lstsize`](#ft_lstsize) | `unsigned int ft_lstsize(t_list *lst);` | Linked List | Counts number of nodes in linked list |
| [`ft_lstlast`](#ft_lstlast) | `t_list *ft_lstlast(t_list *lst);` | Linked List | Returns pointer to final node in linked list |
| [`ft_lstadd_back`](#ft_lstadd_back) | `void ft_lstadd_back(t_list **lst, t_list *new);` | Linked List | Appends node to end of linked list |
| [`ft_lstdelone`](#ft_lstdelone) | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Linked List | Deletes single node using custom deleter |
| [`ft_lstclear`](#ft_lstclear) | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Linked List | Deletes and frees entire list from head |
| [`ft_lstiter`](#ft_lstiter) | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Linked List | Iterates list applying function `f` to contents |
| [`ft_lstmap`](#ft_lstmap) | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Linked List | Maps list into new linked list with leak rollback |

---

## Instructions

### Prerequisites
- Compiler: `cc`, `gcc`, or `clang` (supporting C99 or later)
- Archiver: `ar`
- Build System: GNU `make`
- Operating System: Linux, macOS, or Windows (via WSL2 or MinGW)

### Compilation & Makefile Targets

Clone the repository and enter the project directory:
```bash
git clone https://github.com/ayhamshalabi/libft.git
cd libft
```

The provided `Makefile` manages compilation and static archive packaging with strict warning flags (`-Wall -Wextra -Werror`):

```bash
# Build libft.a from source files
make

# Clean up intermediate object files (*.o)
make clean

# Remove all object files and the compiled archive (libft.a)
make fclean

# Perform a complete rebuild from scratch
make re
```

### Linking Libft in Your Project

To integrate `libft.a` into another C application:

1. Include the header in your C source files:
   ```c
   #include "libft.h"
   ```

2. Link against the compiled archive during compilation:
   ```bash
   # Option 1: Direct archive path
   cc main.c libft.a -o my_project

   # Option 2: Using linker search flags
   cc main.c -L. -lft -o my_project
   ```

### Running the Built-in Test Suite

The repository includes a comprehensive unit testing harness in [`main.c`](main.c) that exercises all 43 functions across standard scenarios and boundary edge cases:

```bash
# 1. Compile the library
make

# 2. Compile test runner with libft.a
cc main.c libft.a -o test_runner

# 3. Execute the tests
./test_runner
```

Test output preview:
```text
========================================
     LIBFT COMPREHENSIVE TEST SUITE     
         Author: Ayham Shalabi          
========================================

=== PART 1: Libc Functions ===
  [OK] ft_isalpha
  [OK] ft_isdigit
  ...
=== PART 2: Additional Functions ===
  [OK] ft_substr
  [OK] ft_split
  ...
=== PART 3: Linked List Functions ===
  [OK] ft_lstnew
  [OK] ft_lstmap
  ...
========================================
   ALL 43 FUNCTIONS TEST SUITE DONE!    
========================================
```

---

## Detailed Function Breakdown

---

### Character Classification & Conversion

#### `ft_isalpha`
```c
int ft_isalpha(int c);
```
- **Parameters:** `c` — Character represented as an `int`.
- **Return Value:** `1` if character is alphabetic (`A-Z` or `a-z`), `0` otherwise.
- **Approach:** Tests whether `c` falls in range `['A', 'Z']` or `['a', 'z']`.
- **Tricks & Optimizations:** Evaluates ASCII character literals directly without auxiliary function calls, allowing compiler branch prediction to optimize evaluation.

#### `ft_isdigit`
```c
int ft_isdigit(int c);
```
- **Parameters:** `c` — Character represented as an `int`.
- **Return Value:** `1` if character is a digit (`0-9`), `0` otherwise.
- **Approach:** Direct range comparison `c >= '0' && c <= '9'`.
- **Tricks & Optimizations:** Branchless boolean return value minimizing instruction count.

#### `ft_isalnum`
```c
int ft_isalnum(int c);
```
- **Parameters:** `c` — Character code.
- **Return Value:** `1` if alphanumeric, `0` otherwise.
- **Approach:** Composes previously defined checks: `return (ft_isalpha(c) || ft_isdigit(c));`.
- **Tricks & Optimizations:** High code reusability following modular design principles.

#### `ft_isascii`
```c
int ft_isascii(int c);
```
- **Parameters:** `c` — Character code.
- **Return Value:** `1` if `c` is within the 7-bit ASCII range (0–127), `0` otherwise.
- **Approach:** Verifies `c >= 0 && c <= 127`.
- **Tricks & Optimizations:** Explicit lower-bound check prevents negative integer values from misclassifying.

#### `ft_isprint`
```c
int ft_isprint(int c);
```
- **Parameters:** `c` — Character code.
- **Return Value:** `1` if printable including space (ASCII 32–126), `0` otherwise.
- **Approach:** Verifies range `c >= 32 && c <= 126`.
- **Tricks & Optimizations:** Excludes control characters (0–31) and `DEL` (127) cleanly in a single expression.

#### `ft_toupper`
```c
int ft_toupper(int c);
```
- **Parameters:** `c` — Character code.
- **Return Value:** Converted uppercase character if lowercase; original character otherwise.
- **Approach:** If `c >= 'a' && c <= 'z'`, subtracts `32` (ASCII offset between `'a'` and `'A'`).
- **Tricks & Optimizations:** In-place mutation of argument `c` eliminates local variable allocations.

#### `ft_tolower`
```c
int ft_tolower(int c);
```
- **Parameters:** `c` — Character code.
- **Return Value:** Converted lowercase character if uppercase; original character otherwise.
- **Approach:** If `c >= 'A' && c <= 'Z'`, adds `32`.
- **Tricks & Optimizations:** Direct arithmetic translation with zero overhead.

---

### Memory Manipulation Functions

#### `ft_memset`
```c
void *ft_memset(void *s, int c, size_t n);
```
- **Parameters:** `s` — Buffer pointer; `c` — Byte value to set; `n` — Number of bytes to fill.
- **Return Value:** Pointer to memory block `s`.
- **Approach:** Casts `s` to `unsigned char *ptr` and writes `(unsigned char)c` sequentially.
- **Tricks & Optimizations:** Idiomatic post-decrement loop `while (n--) *ptr++ = (unsigned char)c;` minimizes loop instructions and produces ultra-concise code.

#### `ft_bzero`
```c
void ft_bzero(void *s, size_t n);
```
- **Parameters:** `s` — Memory buffer pointer; `n` — Number of bytes to zero.
- **Return Value:** None (`void`).
- **Approach:** Directly sets `*ptr++ = 0` for `n` bytes using an `unsigned char *` pointer.
- **Tricks & Optimizations:** Implemented via direct pointer manipulation rather than a call to `memset`, eliminating function call stack overhead.

#### `ft_memcpy`
```c
void *ft_memcpy(void *dest, const void *src, size_t n);
```
- **Parameters:** `dest` — Destination buffer; `src` — Source buffer; `n` — Byte count.
- **Return Value:** Pointer to `dest`.
- **Approach:** Casts pointers to `unsigned char *` and performs forward byte-by-byte copying.
- **Tricks & Optimizations:** Includes edge case check `if (!dest && !src) return (NULL);` ensuring standard behavior when both pointers are `NULL`.

#### `ft_memmove`
```c
void *ft_memmove(void *dest, const void *src, size_t n);
```
- **Parameters:** `dest` — Destination buffer; `src` — Source buffer; `n` — Byte count.
- **Return Value:** Pointer to `dest`.
- **Approach:** Resolves the classic **memory overlap hazard**:
  - If `dest < src`: Copies forward from beginning to end.
  - If `dest > src`: Offsets pointers to the end (`d += n - 1`, `s += n - 1`) and copies backward toward 0.
- **Tricks & Optimizations:** Bidirectional pointer stepping eliminates the need to allocate intermediate heap buffers while guaranteeing full data integrity during overlapping transfers.

#### `ft_memchr`
```c
void *ft_memchr(const void *s, int c, size_t n);
```
- **Parameters:** `s` — Buffer to scan; `c` — Byte value to search; `n` — Byte limit.
- **Return Value:** Pointer to matching byte in `s`, or `NULL` if not found.
- **Approach:** Inspects `s` as `const unsigned char *`, comparing each byte against `(unsigned char)c`.
- **Tricks & Optimizations:** Explicit cast to `unsigned char` guarantees correct matching for unsigned values (`0..255`).

#### `ft_memcmp`
```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```
- **Parameters:** `s1`, `s2` — Memory buffers to compare; `n` — Number of bytes.
- **Return Value:** Difference between first differing pair of bytes `(*first - *last)`, or `0` if equal.
- **Approach:** Steps through both buffers as `unsigned char *`, returning immediately on the first difference.
- **Tricks & Optimizations:** Unsigned byte subtraction ensures correct ASCII lexical comparison without signed integer underflow/overflow bugs.

---

### String Inspection & Copying Functions

#### `ft_strlen`
```c
size_t ft_strlen(const char *s);
```
- **Parameters:** `s` — Null-terminated string.
- **Return Value:** Character count before `'\0'`.
- **Approach:** Advances counter `len` until `s[len] == '\0'`.
- **Tricks & Optimizations:** Minimal loop body easily vectorized by modern compilers.

#### `ft_strlcpy`
```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```
- **Parameters:** `dst` — Destination buffer; `src` — Source string; `dstsize` — Total capacity of `dst`.
- **Return Value:** Total length of `src` (the length of the string it attempted to copy).
- **Approach:** Measures `src_len`. If `dstsize > 0`, copies up to `dstsize - 1` characters and appends terminating `'\0'`.
- **Tricks & Optimizations:** Guarantees null-termination as long as `dstsize > 0`, and returns `src_len` to allow callers to easily detect truncation (`return >= dstsize`).

#### `ft_strlcat`
```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```
- **Parameters:** `dst` — Destination buffer; `src` — Source string; `dstsize` — Total buffer capacity.
- **Return Value:** Initial length of `dst` plus length of `src`.
- **Approach:** Measures existing `dst_len` up to `dstsize`. If `dstsize <= dst_len`, returns `dstsize + src_len`. Otherwise, appends characters from `src` until `dstsize - 1` bytes are filled, then null-terminates.
- **Tricks & Optimizations:** Decrements remaining space counter to eliminate index calculation overhead and prevent buffer overflow.

#### `ft_strchr`
```c
char *ft_strchr(const char *s, int c);
```
- **Parameters:** `s` — String to search; `c` — Target character.
- **Return Value:** Pointer to first occurrence of `c`, or `NULL`.
- **Approach:** Traverses string checking `*s == (char)c`.
- **Tricks & Optimizations:** Explicit post-loop check `if ((char)c == '\0') return ((char *)s);` ensures matching the terminating null byte, as required by the C standard.

#### `ft_strrchr`
```c
char *ft_strrchr(const char *s, int c);
```
- **Parameters:** `s` — String to search; `c` — Target character.
- **Return Value:** Pointer to last occurrence of `c`, or `NULL`.
- **Approach:** Scans forward through the string, updating pointer `last_occ` whenever a match is encountered.
- **Tricks & Optimizations:** Forward scanning avoids an upfront `strlen` call and finds the terminating `'\0'` naturally if `c == '\0'`.

#### `ft_strncmp`
```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```
- **Parameters:** `s1`, `s2` — Strings to compare; `n` — Maximum characters to compare.
- **Return Value:** Difference between first differing characters as unsigned char, or `0`.
- **Approach:** Steps through both strings while `--n`, characters match, and strings are not exhausted.
- **Tricks & Optimizations:** Casting compared characters to `(unsigned char)` prevents negative difference errors on non-ASCII characters (> 127).

#### `ft_strnstr`
```c
char *ft_strnstr(const char *big, const char *little, size_t len);
```
- **Parameters:** `big` — Haystack string; `little` — Needle string; `len` — Search boundary.
- **Return Value:** Pointer to first character of substring match, or `NULL`.
- **Approach:** If `little` is empty, returns `(char *)big`. Slides a window across `big` within bounds `i + j < len`.
- **Tricks & Optimizations:** Evaluating `i + j < len` within the inner loop avoids pre-computing needle length and avoids out-of-bounds reads.

#### `ft_atoi`
```c
int ft_atoi(const char *nptr);
```
- **Parameters:** `nptr` — String containing numerical representation.
- **Return Value:** Converted integer value.
- **Approach:**
  1. Skips leading ASCII whitespace characters (9 through 13, and 32).
  2. Evaluates an optional single sign character (`+` or `-`).
  3. Accumulates numeric digits into `dest = dest * 10 + (*nptr - '0')`.
  4. Returns `dest * is_negative`.
- **Tricks & Optimizations:** Accumulates intermediate values in a `long dest` variable, avoiding 32-bit signed overflow when parsing edge cases like `INT_MIN` (`-2147483648`).

---

### Dynamic Allocation & String Duplication

#### `ft_calloc`
```c
void *ft_calloc(size_t nmemb, size_t size);
```
- **Parameters:** `nmemb` — Element count; `size` — Size of each element.
- **Return Value:** Pointer to zero-initialized allocated memory block, or `NULL`.
- **Approach:** Multiplies count and size, allocates with `malloc`, and clears using `ft_bzero`.
- **Tricks & Optimizations:** **Multiplication Overflow Guard:**
  ```c
  if (nmemb != 0 && size > SIZE_MAX / nmemb)
      return (NULL);
  ```
  Prevents integer wrap-around vulnerabilities where large values wrap to small allocations.

#### `ft_strdup`
```c
char *ft_strdup(const char *s1);
```
- **Parameters:** `s1` — String to duplicate.
- **Return Value:** Newly allocated copy of `s1`, or `NULL`.
- **Approach:** Measures length with `ft_strlen`, allocates `len + 1`, copies characters via pointer increments, and null-terminates.
- **Tricks & Optimizations:** Stores starting pointer (`dst_start = dst`) and increments `dst` directly, avoiding array indexing overhead.

---

### Advanced String & Numerical Utilities

#### `ft_substr`
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```
- **Parameters:** `s` — Source string; `start` — Starting index; `len` — Maximum substring length.
- **Return Value:** Allocated substring, or empty string if `start >= strlen(s)`.
- **Approach:** If `start >= ft_strlen(s)`, returns `ft_strdup("")`. Clamps `len` to `s_len - start` if `len` exceeds the remaining characters. Allocates clamped `len + 1` bytes and copies characters.
- **Tricks & Optimizations:** Clamping `len` prevents over-allocating heap memory when callers pass arbitrarily large lengths (e.g. `SIZE_MAX`).

#### `ft_strjoin`
```c
char *ft_strjoin(char const *s1, char const *s2);
```
- **Parameters:** `s1` — Prefix string; `s2` — Suffix string.
- **Return Value:** Newly allocated concatenated string, or `NULL`.
- **Approach:** Allocates `ft_strlen(s1) + ft_strlen(s2) + 1` bytes, copies `s1` then `s2` sequentially, and appends `'\0'`.
- **Tricks & Optimizations:** Sequential pointer copying `while (*s1) *ptr++ = *s1++;` avoids double-scanning indices.

#### `ft_strtrim`
```c
char *ft_strtrim(char const *s1, char const *set);
```
- **Parameters:** `s1` — String to trim; `set` — Delimiter character set.
- **Return Value:** Trimmed string copy, or `NULL`.
- **Approach:**
  1. Counts leading characters matching `set` (`front_count`).
  2. If all characters are trimmed, sets `back = 0`; otherwise counts trailing characters matching `set` (`back_count`).
  3. Allocates exact required length `strlen(s1) - (front + back) + 1` and copies the slice.
- **Tricks & Optimizations:** Prevents underflow and out-of-bounds reads when processing strings composed entirely of set characters.

#### `ft_split`
```c
char **ft_split(char const *s, char c);
```
- **Parameters:** `s` — String to split; `c` — Delimiter character.
- **Return Value:** Null-terminated array of strings, or `NULL`.
- **Approach:**
  1. Counts words skipping consecutive delimiters (`word_count`).
  2. Allocates `(words + 1) * sizeof(char *)`.
  3. Allocates each word substring using `word_len` and `ft_strlcpy`.
- **Tricks & Optimizations:** **Rollback Freeing Mechanism:** If any inner word allocation fails, helper `free_res(res, i)` iterates backward freeing previously allocated strings and the array itself:
  ```c
  static void free_res(char **res, int i)
  {
      while (i--)
          free(res[i]);
      free(res);
  }
  ```
  Guarantees zero memory leaks on partial failure.

#### `ft_itoa`
```c
char *ft_itoa(int n);
```
- **Parameters:** `n` — Signed integer.
- **Return Value:** Formatted ASCII string representation, or `NULL`.
- **Approach:**
  1. Computes digit count via helper `num_len(long n)`.
  2. Allocates `len + 1` bytes and places `'\0'` at `res[len]`.
  3. Fills string from right to left using modulo: `res[--len] = (nb % 10) + '0'; nb /= 10;`.
  4. Prepends `'-'` if `n < 0`.
- **Tricks & Optimizations:** Storing `n` in a `long nb` variable cleanly resolves the `INT_MIN` (`-2147483648`) negation trap without special-case branches.

#### `ft_strmapi`
```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```
- **Parameters:** `s` — Base string; `f` — Function pointer applied to each character and its index.
- **Return Value:** Newly allocated mapped string, or `NULL`.
- **Approach:** Allocates `ft_strlen(s) + 1`, iterates through characters calling `f(i, s[i])`, and null-terminates.
- **Tricks & Optimizations:** Implements functional mapping over immutable C strings.

#### `ft_striteri`
```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```
- **Parameters:** `s` — Mutable string; `f` — Function taking character address and index.
- **Return Value:** None (`void`).
- **Approach:** Steps through index `i`, invoking `f(i, &s[i])` for in-place mutation.
- **Tricks & Optimizations:** Direct pointer passing `&s[i]` enables in-place mutation without memory reallocations.

---

### File Descriptor Output Functions

#### `ft_putchar_fd`
```c
void ft_putchar_fd(char c, int fd);
```
- **Parameters:** `c` — Character; `fd` — File descriptor.
- **Return Value:** None.
- **Approach:** Calls system write `write(fd, &c, 1);`.
- **Tricks & Optimizations:** Direct unbuffered atomic write.

#### `ft_putstr_fd`
```c
void ft_putstr_fd(char *s, int fd);
```
- **Parameters:** `s` — String to write; `fd` — File descriptor.
- **Return Value:** None.
- **Approach:** Checks `if (!s) return;`, then writes string sequentially with `write(fd, &s[i++], 1)`.
- **Tricks & Optimizations:** Defensive `NULL` check protects against segmentation faults.

#### `ft_putendl_fd`
```c
void ft_putendl_fd(char *s, int fd);
```
- **Parameters:** `s` — String to write; `fd` — File descriptor.
- **Return Value:** None.
- **Approach:** Outputs string followed by a newline byte `write(fd, "\n", 1);`.
- **Tricks & Optimizations:** Guarantees line ending flush.

#### `ft_putnbr_fd`
```c
void ft_putnbr_fd(int n, int fd);
```
- **Parameters:** `n` — Signed integer; `fd` — File descriptor.
- **Return Value:** None.
- **Approach:** Casts `n` to `long nb`. Writes `'-'` if negative and multiplies by `-1`. Recursively calls `ft_putnbr_fd(nb / 10, fd)` until `nb < 10`, then outputs current digit `(nb % 10) + '0'`.
- **Tricks & Optimizations:** Recursive stack division eliminates intermediate heap string allocations and handles `INT_MIN` cleanly.

---

### Singly Linked List Functions

#### `ft_lstnew`
```c
t_list *ft_lstnew(void *content);
```
- **Parameters:** `content` — Pointer to node payload.
- **Return Value:** Newly allocated `t_list` node, or `NULL`.
- **Approach:** Allocates `sizeof(t_list)`, assigns `node->content = content`, and sets `node->next = NULL`.
- **Tricks & Optimizations:** Guarantees initialization of `next` pointer preventing uninitialized pointer dereferencing.

#### `ft_lstadd_front`
```c
void ft_lstadd_front(t_list **lst, t_list *new);
```
- **Parameters:** `lst` — Pointer to head pointer; `new` — Node to insert.
- **Return Value:** None.
- **Approach:** Sets `new->next = *lst` and updates `*lst = new`.
- **Tricks & Optimizations:** $O(1)$ constant time prepending.

#### `ft_lstsize`
```c
unsigned int ft_lstsize(t_list *lst);
```
- **Parameters:** `lst` — List head pointer.
- **Return Value:** Count of nodes in list.
- **Approach:** Traverses `lst = lst->next`, incrementing counter until reaching `NULL`.
- **Tricks & Optimizations:** Non-destructive traversal (head pointer passed by value).

#### `ft_lstlast`
```c
t_list *ft_lstlast(t_list *lst);
```
- **Parameters:** `lst` — List head pointer.
- **Return Value:** Pointer to the final node, or `NULL` if list is empty.
- **Approach:** Traverses `while (lst->next)` until reaching the final node.
- **Tricks & Optimizations:** Stops traversal on `lst->next == NULL` rather than advancing past it.

#### `ft_lstadd_back`
```c
void ft_lstadd_back(t_list **lst, t_list *new);
```
- **Parameters:** `lst` — Pointer to head pointer; `new` — Node to append.
- **Return Value:** None.
- **Approach:** If `*lst == NULL`, assigns `*lst = new`. Otherwise traverses to `ft_lstlast(*lst)` and updates `last->next = new`.
- **Tricks & Optimizations:** Automatically handles empty list initialization without special preconditions.

#### `ft_lstdelone`
```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```
- **Parameters:** `lst` — Node to delete; `del` — Deleter function for payload.
- **Return Value:** None.
- **Approach:** Calls `del(lst->content)` to free payload, then frees `lst` node itself.
- **Tricks & Optimizations:** Leaves surrounding list link pointers intact for caller-managed isolation.

#### `ft_lstclear`
```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```
- **Parameters:** `lst` — Pointer to head pointer; `del` — Deleter function.
- **Return Value:** None.
- **Approach:** Loops through nodes: preserves `next = temp->next`, calls `del(temp->content)`, frees `temp`, advances. Sets `*lst = NULL`.
- **Tricks & Optimizations:** Setting `*lst = NULL` at the end eliminates dangling pointers in the calling scope.

#### `ft_lstiter`
```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```
- **Parameters:** `lst` — List head pointer; `f` — Transformer function applied to node payloads.
- **Return Value:** None.
- **Approach:** Traverses list calling `f(lst->content)` on each node.
- **Tricks & Optimizations:** Higher-order functional iterator over dynamic generic payloads.

#### `ft_lstmap`
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
- **Parameters:** `lst` — Source list; `f` — Transformer function; `del` — Cleanup deleter function.
- **Return Value:** Newly allocated mapped list, or `NULL` if allocation fails.
- **Approach:**
  1. Iterates through `lst`, mapping content: `content = f(lst->content)`.
  2. Allocates new node `new = ft_lstnew(content)`.
  3. Appends `new` to `head`.
- **Tricks & Optimizations:** **Complete Cascade Rollback:** If any node allocation fails midway:
  ```c
  if (!new)
  {
      del(content);
      ft_lstclear(&head, del);
      return (NULL);
  }
  ```
  Deletes orphan mapped `content`, cleans up all previously allocated nodes with `ft_lstclear`, and returns `NULL` without leaking memory.

---

## Resources & References

### Linux Programmer's Manual (System Man Pages)
Official system documentation for libc routines and memory management functions:
- [`malloc(3)`](https://manpages.debian.org/bookworm/manpages-dev/malloc.3.en.html) — Dynamic memory allocation, sizing, and heap management.
- [`calloc(3)`](https://manpages.debian.org/bookworm/manpages-dev/calloc.3.en.html) — Zero-initialized memory array allocation and overflow prevention.
- [`memcpy(3)`](https://manpages.debian.org/bookworm/manpages-dev/memcpy.3.en.html) — Copying memory areas and non-overlapping buffer rules.
- [`memmove(3)`](https://manpages.debian.org/bookworm/manpages-dev/memmove.3.en.html) — Memory copying with overlapping buffer guarantees.
- [`memset(3)`](https://manpages.debian.org/bookworm/manpages-dev/memset.3.en.html) — Filling memory buffers with a constant byte.
- [`bzero(3)`](https://manpages.debian.org/bookworm/manpages-dev/bzero.3.en.html) — Writing zeroed bytes to a byte string.
- [`strdup(3)`](https://manpages.debian.org/bookworm/manpages-dev/strdup.3.en.html) — Duplicate a string via dynamic heap allocation.
- [`strnstr(3)`](https://manpages.debian.org/bookworm/libbsd-dev/strnstr.3bsd.en.html) / [FreeBSD strnstr(3)](https://man.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3) — Size-bounded substring location within a string.

### BSD Libc Reference Implementations
Reference manuals and source implementations for BSD-specific standard extensions:
- [FreeBSD strlcpy(3) Manual](https://man.freebsd.org/cgi/man.cgi?query=strlcpy&sektion=3) — Size-bounded string copying specification.
- [FreeBSD strlcat(3) Manual](https://man.freebsd.org/cgi/man.cgi?query=strlcat&sektion=3) — Size-bounded string concatenation specification.
- [FreeBSD bzero(3) Manual](https://man.freebsd.org/cgi/man.cgi?query=bzero&sektion=3) — Byte zeroing specification.
- [FreeBSD Source: strlcpy.c](https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/strlcpy.c) — Official BSD reference source code for `strlcpy`.
- [FreeBSD Source: strlcat.c](https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/strlcat.c) — Official BSD reference source code for `strlcat`.
- [FreeBSD Source: bzero.c](https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/bzero.c) — Official BSD reference source code for `bzero`.

### Classic C Literature & Standards
- [Brian W. Kernighan & Dennis M. Ritchie: The C Programming Language (2nd Edition)](https://en.wikipedia.org/wiki/The_C_Programming_Language) — The seminal reference for ANSI C syntax, pointer arithmetic, and standard library architecture.
- [ISO/IEC C Language Reference (cppreference.com)](https://en.cppreference.com/w/c) — Standardized reference documentation for C types, string functions, and memory behaviors.

### Repository & Author
- **Author Profile:** [https://github.com/ayhamshalabi](https://github.com/ayhamshalabi)
- **Project Repository:** [https://github.com/ayhamshalabi/libft](https://github.com/ayhamshalabi/libft)

---

## License

This project is open-source and available under the [MIT License](LICENSE).
