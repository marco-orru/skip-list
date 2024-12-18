# Skip List

> Part of a University project for the class _Algorithms and Data Structures_ (**[ASD](https://laurea.informatica.unito.it/do/corsi.pl/Show?_id=iw3r)**, *Algoritmi e Strutture Dati*, UNITO Informatica).


## Overview

The project includes:
- A [**Skip List**](https://en.wikipedia.org/wiki/Skip_list) implementation in C, supporting dynamic insertion, search, and deletion of elements.
- An **Error Finder** tool to identify spelling errors in an input file using a dictionary.

### Features
- **Efficient Skip List implementation**:
  - Dynamic insertion and search with adjustable height.
  - Customizable ordering via user-defined comparator functions.
- **Case-insensitive error detection**:
  - Identifies words in the text file that are not present in the dictionary.
  - Prints a list of misspelled or unknown words.
- **Highly modular design**:
  - Skip List implementation can be reused in other projects.
- **Portable**:
  - Standard C99-compatible implementation.
- **Diagnostics**:
  - Assertions to validate parameters and ensure reliability.

---

## Requirements

- A **C99-compatible** compiler.
- Standard C libraries (no external dependencies).
- A dictionary file (`.txt` format, one word per line).
- An input file (`.txt` format, containing text to analyze).

---

## Building the Project

1. **Clone the repository**:
    ```sh
    git clone https://github.com/your-username/skip-list.git
    cd skip-list
    ```

2. **Compile the project**:
    ```sh
    gcc -o skip-list main.c errors-finder.c skip-list.c -I.
    ```

3. **Run the executable**:
    ```sh
    ./skip-list <dictionary_file> <input_file> <max_height>
    ```

---

## Usage

### CLI Command
Run the program to check spelling errors:
```sh
./skip-list <dictionary_file> <input_file> <max_height>
```

- `<dictionary_file>`: Path to the dictionary file (one word per line).
- `<input_file>`: Path to the text file to analyze.
- `<max_height>`: Maximum height of the skip list (minimum value: 1).

### Example

#### Dictionary File (`dictionary.txt`):
```
apple
banana
cherry
date
elderberry
```

#### Input File (`input.txt`):
```
This is an apple.
Here we have a mango and a banana.
Cherries are delicious.
```

#### Command:
```sh
./skip-list dictionary.txt input.txt 5
```

#### Output:
```
Loading dictionary...
Finding errors...
Errors found:
  - This
  - is
  - an
  - mango
  - and
  - a
  - Cherries
  - are
  - delicious
```

---

## API Documentation

### Skip List Functions

1. **`new_skiplist(SkipList **list, size_t max_height, compare_fn compare)`**:
   - Allocates a new skip list with the given maximum height and comparator.

2. **`clear_skiplist(SkipList **list)`**:
   - Frees memory used by the skip list and its nodes.

3. **`insert_skiplist(SkipList *list, void *item)`**:
   - Inserts a new item into the skip list.

4. **`search_skiplist(SkipList *list, void *item)`**:
   - Searches for an item in the skip list. Returns the item if found, or `NULL` if not.

### Error Finder Functions

1. **`find_errors(FILE *dict_file, FILE *text_file, size_t max_height)`**:
   - Loads the dictionary into a skip list, processes the text file, and prints errors.

---

## File Formats

### Dictionary File
- Each line contains one word.
- Example:
    ```
    apple
    banana
    cherry
    ```

### Input File
- Contains arbitrary text.
- Words are separated by non-alphabetic characters.