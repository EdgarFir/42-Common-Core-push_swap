# Push_swap - Milestone 2 Common-Core project

This project focused on implementing and exploring **sorting algorithms** and **stack manipulation* by developing a program that sorts integers using a limited set of operations. It provided a hands-on opportunity to dive deep into algorithmic logic and code optimization.

## Algorithm used - Turkish Sort

Turkish Sort is an advanced sorting strategy used in the Push Swap project to optimize the number of operations required to sort a list of integers using two stacks.

Unlike traditional sorting algorithms that focus solely on theoretical complexity, **Turkish Sort** is tailored specifically for the constraints of **Push Swap**, aiming to reduce the total number of instructions executed — a key evaluation metric in the project.

## Core Idea
### Turkish Sort – Step-by-Step Breakdown

**Turkish Sort** is a chunk-based sorting approach optimized for the **Push Swap** project. Below is the step-by-step logic of the algorithm:

#### Step 1: Initial Push to Stack B

- Push the **first two elements** from **stack A** to **stack B**.  
  This sets up stack B for comparisons and organized reinsertion later.

#### Step 2: Move Elements from A to B

- While **stack A has more than 3 elements**:
  - Selectively push elements from **A to B** based on their value (typically using **chunk ranges**).
  - The chunk system divides the list into value intervals, and elements are pushed to B in order of chunk appearance to balance distribution.

#### Step 3: Sort the Remaining 3 Elements in Stack A

- Once **only 3 elements remain in stack A**, sort them using a **simple sorting routine** (e.g., a mini sort function for 3 elements using `sa`, `ra`, `rra`).

#### Step 4: Push Elements Back from B to A

- While **stack B is not empty**:
  - For each number from the top to the bottom **push** to A choosing the minimum operations required, based on their value (typically using **chunk ranges**).
  - This ensures elements are reinserted in **descending order**, resulting in a sorted ascending stack A.

#### Step 5: Final Adjustment – Push Minimum to Top

- After all elements are back in stack A:
  - Locate the **minimum value** in A.
  - Rotate A (`ra` or `rra`) until the minimum is at the **top**.

This ensures that stack A is **fully sorted** in ascending order, with the smallest number on top.

## Time Complexity
- Average case: O(n log n)

- Worst case: O(n²)

While the theoretical average is close to **O(n log n)**, actual performance depends heavily on how chunks are selected and how efficiently elements are moved between stacks.

## Space Complexity

- O(n)

Only the two main stacks (**A** and **B**) and auxiliary variables are used. No additional dynamic memory or complex data structures are introduced, so the space usage remains linear in relation to the number of elements.

Effective for mid to large datasets (100–500 numbers).

**Turkish Sort tutorial source**: https://medium.com/@ayogun/push-swap-c1f5d2d41e97

## Concepts learned:
- Development and analysis of efficient sorting algorithms, within the constraints of a specific and limited instruction set.

- Implementation of strategies to minimize the number of operations required to sort data, focusing on performance optimization.

- Consolidation of knowledge related to algorithmic complexity, emphasizing both time and space efficiency.

- This project was essential for strengthening problem-solving skills and logical thinking, by requiring the design of efficient solutions under strict operational constraints.
