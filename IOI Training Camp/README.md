# IOI Training Camp - Maximum Segment Sum with Drops

## Problem Description
Given a sequence of N test marks and a number K, find the maximum sum of a contiguous segment where up to K marks can be dropped from the segment.

## Problem Statement
In the IOI training camp, students are evaluated based on their test marks. The evaluation is done by:
1. Finding the best contiguous segment of marks
2. Students are allowed to drop up to K tests from their chosen segment
3. The sum of remaining marks in that segment is their final score

## Input Format
```
N K
mark_1
mark_2
...
mark_N
```
- First line contains two integers N and K
- Following N lines contain one integer each representing the marks

## Output Format
```
maximum_sum
```
- A single integer representing the maximum possible sum after dropping up to K elements from a segment

## Constraints
- 1 ≤ N ≤ 10^4
- 0 ≤ K ≤ 10^2
- -10^4 ≤ marks ≤ 10^4
- For 40% test cases: N ≤ 250

## Sample Test Case
### Input
```
10 2
6
-5
3
-7
6
-1
10
-8
-8
8
```

### Output
```
24
```

### Explanation
- Without dropping any tests: Best segment is tests 5-7 with sum = 15
- With dropping 2 tests: Best segment is tests 1-7, dropping tests 2 and 4, sum = 24

## Solution Approach
The solution uses Dynamic Programming with two states:
1. `best[i][j]`: Maximum segment sum up to position i dropping j elements
2. `curr[i][j]`: Maximum segment sum ending at position i dropping j elements

For each position and number of drops allowed:
- Consider including current element
- Consider dropping current element
- Consider starting new segment from current element

## Time and Space Complexity
- **Time Complexity**: O(N × K)
  - N: Number of test marks
  - K: Maximum allowed drops
  - We process each position for each possible number of drops

- **Space Complexity**: O(N × K)
  - Two 2D arrays of size N × K for storing states

## Implementation
The solution is implemented in C++ using dynamic programming approach. The code maintains optimal substructure and overlapping subproblems properties essential for DP solutions.

---
*Note: This problem was originally from INOI 2011*