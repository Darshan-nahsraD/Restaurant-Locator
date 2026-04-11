# Restaurant Locator using 2D Range Tree (AVL Based)

This project implements an efficient system to query restaurants within a given rectangular region using advanced data structures.

## Problem Statement

Given a list of restaurants represented as coordinates (x, y), efficiently answer queries of the form:

Find all restaurants within a rectangular region:
x ∈ [x1, x2] and y ∈ [y1, y2]

A brute force approach would take O(n) time per query, which becomes inefficient for large datasets.

## Approach

To optimize query performance, we use a 2D Range Tree built using AVL Trees.

### Key Idea

- Construct a primary AVL tree based on x-coordinates
- Each node stores points corresponding to that x value
- Perform efficient range queries on x
- Filter results based on y-coordinates

### Steps

1. Preprocess restaurant data into a balanced AVL tree
2. Query nodes within the x-range [x1, x2]
3. Filter those points further using the y-range [y1, y2]

## Time Complexity

| Operation        | Complexity       |
|----------------|------------------|
| Preprocessing   | O(n log n)       |
| Query           | O((log n)^2) (ideal) |

## Project Structure
