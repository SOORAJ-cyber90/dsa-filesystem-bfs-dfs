# File System Representation and Search Using BFS and DFS

**Activity Data Structures and Algorithms | UKF College of Engineering & Technology

A C program that models a file system as a graph (adjacency matrix) and searches for a file using Breadth-First Search (BFS) and Depth-First Search (DFS).

## Concept
- Each file or directory is a **node**.
- Each parent → child link is an **edge** (`adj[i][j] = 1` means `i` contains `j`).
- BFS explores level by level using a queue; DFS goes deep first using recursion.
- Both stop as soon as the target file is found and print the traversal order.

## Sample file system
```
root
├── docs
│   ├── report.pdf
│   └── notes.txt
├── pics
│   └── photo.jpg
└── src
    ├── main.c
    └── util.c
```

## Build and run
```bash
gcc -Wall -o filesystem_search filesystem_search.c
./filesystem_search < sample_input.txt
```

## Input format
1. Number of nodes
2. Node names (space separated)
3. Number of edges
4. Each edge as `parent child`
5. Starting node
6. File to search

## Sample 1: file found (`main.c`)
Input: `sample_input.txt`
```
BFS traversal: root docs pics src report.pdf notes.txt photo.jpg main.c
BFS result: File FOUND
DFS traversal: root docs report.pdf notes.txt pics photo.jpg src main.c
DFS result: File FOUND
```

## Sample 2: file not found (`video.mp4`)
Input: `sample_input_notfound.txt`
```
BFS traversal: root docs pics src report.pdf notes.txt photo.jpg main.c util.c
BFS result: File NOT found
DFS traversal: root docs report.pdf notes.txt pics photo.jpg src main.c util.c
DFS result: File NOT found
```

Full outputs are in `sample_output.txt` and `sample_output_notfound.txt`.

## Complexity
Adjacency matrix: O(V²) time for both BFS and DFS, O(V²) space.
