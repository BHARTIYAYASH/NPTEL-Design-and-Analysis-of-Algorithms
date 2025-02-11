# Prisoner Escape

## (Baltic Olympiad in Informatics, 2009)



## Problem Statement
A group of war prisoners are trying to escape from a prison. They have thoroughly planned the escape from the prison itself, and after that, they hope to find shelter in a nearby village. However, the village (marked as B) and the prison (marked as A) are separated by a canyon, which is also guarded by soldiers. These soldiers sit in their pickets and rarely move. The range of view of each soldier is limited to exactly **100 meters**. Depending on the locations of soldiers, it may be possible to pass the canyon safely, keeping the distance to the closest soldier strictly larger than 100 meters at any moment.

You are to write a program that, given the width and the length of the canyon and the coordinates of every soldier in the canyon, determines whether prisoners can pass the canyon unnoticed.

---
## Solution Approach
This problem can be modeled as an **undirected graph**:
1. Each soldier is represented as a **vertex**.
2. An **edge** exists between two soldiers if their **ranges overlap** (i.e., their Euclidean distance is within 200 meters).
3. Two additional vertices `s` and `t` are introduced:
   - `s`: Represents the **northern side** of the canyon.
   - `t`: Represents the **southern side** of the canyon.
4. Any soldier whose **view covers the northern boundary** is connected to `s`, and any soldier whose **view covers the southern boundary** is connected to `t`.
5. The problem reduces to checking if **there exists a path from `s` to `t`** in the graph, which can be solved using **Breadth-First Search (BFS)**.

---
## Input Format
- The first line contains three integers: `L`, `W`, and `N`:
  - `L`: Length of the canyon.
  - `W`: Width of the canyon.
  - `N`: Number of soldiers.
- The next `N` lines each contain two integers, `X[i]` and `Y[i]`, representing the coordinates of the i-th soldier.

Constraints:
- `1 ≤ W ≤ 50,000`
- `1 ≤ L ≤ 50,000`
- `1 ≤ N ≤ 250`

---
## Output Format
- Print **`0`** if the prisoners can escape.
- Print **`1`** if they cannot.

---
## Example Test Cases

### **Input 1**
```
130 340 5
10 50
130 130
70 170
0 180
60 260
```
### **Output 1**
```
1
```

### **Input 2**
```
500 300 4
250 0
250 300
100 150
400 150

```
### **Output 2**
```
0
```

---




