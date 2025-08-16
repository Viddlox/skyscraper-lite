# Skyscraper Puzzle Solver

> **Note:** This is a working solution for the 4x4 Skyscraper puzzle problem.

## Overview

This project implements a recursive backtracking algorithm to solve the classic Skyscraper puzzle. The solver uses depth-first search with constraint propagation to find valid solutions for 4x4 grid configurations.

## Prerequisites

Before diving into the code, ensure you understand these fundamental concepts:

### Core Concepts
- **[Recursion](https://www.geeksforgeeks.org/introduction-to-recursion-2/)** - The foundation of our solving algorithm
- **[Call Stack](https://www.youtube.com/watch?v=aCPkszeKRa4&t=131s)** - Understanding how recursive calls are managed
- **[Binary Trees](https://www.w3schools.com/dsa/dsa_data_binarytrees.php)** - Visualize the call stack during recursion
- **[Depth-First Search](https://www.youtube.com/watch?v=cS-198wtfj0)** - The main recursive algorithm used
- **[Brute-Force vs. Backtracking](https://en.wikipedia.org/wiki/Brute-force_search)** - Understanding the solving approach
- **[Constraint Propagation](https://www.ibm.com/docs/en/icos/22.1.0?topic=optimizer-constraint-propagation)** - How local decisions propagate globally

### Additional Resources
- **[Play the Game](https://www.puzzle-skyscrapers.com/)** - Experience the puzzle firsthand
- **[Command Line Arguments](https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean)** - Understanding program input

## Technical Implementation

### Libraries Used
- `#include <stdbool.h>` - Clean boolean operations instead of integer truthy values
- `#include <unistd.h>` - For `write(1, &c, 1)` function

> **Note:** We avoid `stdlib.h` and `malloc` by using hardcoded arrays for simplicity and automatic memory management.

## Architecture

The program operates in two distinct phases:

### 1. Input Parsing & Validation (`main.c`)

The program accepts exactly 2 command-line arguments:
1. Executable path
2. Edge clues as a space-delimited string

**Example Input:**
```bash
./a.exe "3 2 2 1 2 2 1 3 4 2 1 3 1 2 2 2"
```

**Validation Process:**
- Extract and convert string characters to integers
- Store clues in an array for solving reference
- Verify exactly 16 clues for 4x4 grid
- Initialize a 2D board array with zeros (empty cells)

### 2. Solving Phase

The solver employs a combination of:
- **Brute-force approach** - Systematic exploration of possibilities
- **Constraint propagation** - Local validation with global impact
- **Recursive depth-first traversal** - Tree-based solution search

## Algorithm Design

### Recursive Function Requirements

Every recursive function needs two fundamental components:

#### 1. Exit Condition (Base Case)
The solver exits when the board is completely solved, determined by three conditions:

1. **Completeness** - Every cell contains a value (no zeros)
2. **Edge Clue Satisfaction** - All row/column intersections satisfy their corresponding edge clues
3. **Uniqueness** - No duplicate tower heights in any row or column

#### 2. Recursive Condition
When the board isn't solved, the algorithm continues with backtracking:

1. **Cell Selection** - Identify the next empty cell `board[row][col]`
2. **Height Testing** - Try placing each possible tower height (1-4)
3. **Validation** - Apply constraint propagation to check partial board validity
4. **Recursion** - If valid, recursively explore deeper along that path
5. **Backtracking** - If invalid or no solution found, backtrack and try next height

### Tree Navigation Analogy

Think of the solving process as navigating a decision tree:

- **Root Node** - Represents the completed, solved board
- **Levels** - Each level corresponds to choosing a tower height for one cell
- **Branches** - Each node can branch into up to 4 child states (heights 1-4)
- **Traversal** - Move down one branch at a time using depth-first search
- **Backtracking** - When hitting a base case, propagate results up the call stack
- **Exploration** - After completing one branch, backtrack and try the next available height

This ensures all possibilities are explored until a solution is found or the search space is exhausted.

## File Structure

- `main.c` - Input parsing, validation, and program entry point
- `solve.c` - Core solving algorithm and recursive functions
- `check.c` - Validation and constraint checking functions
- `a.exe` - Compiled executable

---

*For detailed explanations of helper methods and solving techniques, please refer to the accompanying video documentation.* 