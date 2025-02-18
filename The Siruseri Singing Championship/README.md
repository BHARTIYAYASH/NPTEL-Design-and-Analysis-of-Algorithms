# Siruseri Singing Championship

## (Zonal Computing Olympiad 2019)

## Problem Statement
The **Siruseri Singing Championship** is a competition where **N singers** participate. Each singer has a **vocal range** represented by a **lower limit (L)** and an **upper limit (U)**, indicating the pitches they can sing. The limits for each singer are unique, and **L < U**.

A match between two singers follows these rules:
- A singer **Si (Li, Ui)** wins against another singer **Sj (Lj, Uj)** if Si's range strictly contains Sj's range.
- If neither singer's range strictly contains the other, the match ends in a **draw** (which doesn't happen in this problem).
- The winner gets **2 points**, and the loser gets **0 points**.

At the end of the tournament, each singer's total score is determined based on their wins.

## Input Format
- The first line contains an integer **N** (number of singers).
- The next **N** lines contain two integers **Li** and **Ui**, representing the vocal range of each singer.

## Output Format
- A single line containing **N integers**, where the i-th integer represents the final score of the i-th singer.

## Constraints
- **2 ≤ N ≤ 10⁵**
- **1 ≤ Li < Ui ≤ 10⁹**
- All **2N** integers are distinct.
- No match ends in a draw.

## Example
### Input 1:
```
5
3 23
4 20
11 16
5 19
1 25
```
### Output 1:
```
6 4 0 2 8
```
### Input 2:
```
7
3 22
9 17
6 19
13 16
2 25
14 15
5 21
```
### Output 2:
```
10 4 6 2 12 0 8
```

## Approach to Solve the Problem
1. **Sorting the Singers**: Since each singer's range is unique, sorting singers by their **lower bound (L)** helps determine the hierarchy of vocal ranges.
2. **Finding Wins Efficiently**:
   - The range of a singer is strictly contained in another if their **lower bound is greater** than another singer's **lower bound**.
   - By sorting singers based on **L**, we can easily determine how many other singers have a smaller range.
   - Each singer wins against **N-1-i** other singers in the sorted order.
3. **Using Efficient Search**:
   - **Binary Search** or **Linear Search** helps in mapping the sorted order to the original input efficiently.
   - Sorting takes **O(N log N)**, and searching takes **O(N)**, leading to an overall complexity of **O(N log N)**.

This method ensures the problem is solved efficiently within the given constraints.

