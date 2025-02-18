# Number Triples Problem

## (IARCS OPC Archive, K Narayan Kumar, CMI)

## Problem Description

Given a sequence of triples of positive integers, find the minimum value chain connecting two given numbers A and B.

### Chain Definition
A chain connecting numbers A and B is a sequence of triples:
- A₀ W₀ A₁, A₁ W₁ A₂, A₂ W₂ A₃, ... Aₖ₋₂ Wₖ₋₂ Aₖ₋₁, Aₖ₋₁ Wₖ₋₁ Aₖ

Where:
- A₀ = A (starting number)
- Aₖ = B (ending number)
- For each i (0 ≤ i < k), either the triple Aᵢ Wᵢ Aᵢ₊₁ or Aᵢ₊₁ Wᵢ Aᵢ must exist in the given set of triples

The value of a chain is the sum of all Wᵢs in the chain.

## Input Format
```
M A B
X₁ Y₁ Z₁
X₂ Y₂ Z₂
...
Xₘ Yₘ Zₘ
```
Where:
- M: Number of triples
- A, B: Numbers to be connected
- Each subsequent line contains a triple (Xᵢ, Yᵢ, Zᵢ)

## Output Format
```
YES
value
```
OR
```
NO
```
- Print "YES" if a chain exists, followed by the minimum chain value
- Print "NO" if no chain exists

## Constraints
- 1 ≤ Xᵢ, Yᵢ, Zᵢ ≤ 2000
- M ≤ 4000000

## Example 1
### Input:
```
9 1 11
1 2 5
5 2 6
1 3 8
8 1 11
1 1 6
10 1 6
11 3 6
10 4 8
10 1 11
```
### Output:
```
YES
3
```

## Example 2
### Input:
```
9 1 2
1 2 5
5 2 6
1 3 8
8 1 11
1 1 6
10 1 6
11 3 6
10 4 8
10 1 11
```
### Output:
```
NO
```

## Solution Approach
1. Model the problem as a graph:
   - Numbers become nodes
   - Each triple (X, Y, Z) creates two edges: X→Z and Z→X with weight Y
2. Use Dijkstra's algorithm to find the shortest path:
   - Weights are positive (Y values)
   - Need to find minimum total weight path
   - Graph is weighted and potentially sparse
3. The minimum path weight (if exists) is the answer

## Time Complexity
- O(M log N) where:
  - M is the number of triples (edges)
  - N is the number of unique numbers (nodes)

## Space Complexity
- O(N + M) for storing the graph and algorithm data structures