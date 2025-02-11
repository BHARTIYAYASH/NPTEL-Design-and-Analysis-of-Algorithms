**# Prisoner Escape #**
(Baltic Olympiad in Informatics, 2009)

A group of war prisoners are trying to escape from a prison. They have thoroughly planned the escape from the prison itself, and after that they hope to find shelter in a nearby village. However, the village (marked as B, see picture below) and the prison (marked as A) are separated by a canyon which is also guarded by soldiers. These soldiers sit in their pickets and rarely walk; the range of view of each soldier is limited to exactly 100 meters. Thus, depending on the locations of soldiers, it may be possible to pass the canyon safely, keeping the distance to the closest soldier strictly larger than 100 meters at any moment.

You are to write a program which, given the width and the length of the canyon and the coordinates of every soldier in the canyon, and assuming that soldiers do not change their locations, determines whether prisoners can pass the canyon unnoticed.

Solution Hint
The soldiers can be modelled as an undirected graph G. Let each soldier be represented by a vertex. Add an edge between two vertices if and only if the range of view of the corresponding soldiers overlaps. Add two additional vertices s and t, representing the northern and southern side of the canyon, respectively. Connect s and t to those vertices representing soldiers who range of view includes the respective side of the canyon. Use depth-first-search or breadth-first-search to check whether there is a path between s and t in G.

Input format
The first line contains three integers L, W, and N – the length and the width of the canyon, and the number of soldiers, respectively. Each of the following N lines contains a pair of integers Xi and Yi – the coordinates of i-th soldier in the canyon (0 ≤ Xi ≤ L, 0 ≤ Yi ≤ W). The coordinates are given in meters, relative to the canyon: the southwestern corner of the canyon has coordinates (0, 0), and the northeastern corner of the canyon has coordinates (L,W), as seen in the picture above. Note that passing the canyon may start at coordinate (0,ys) for any 0 ≤ ys ≤ W and end at coordinate (L,ye) for any 0 ≤ ye ≤ W. Neither ys nor ye need to be integer.

Output format
Output a single integer: 0 if the prisoners can escape, 1 if they cannot.

Test data
1≤W ≤ 50,000 1 ≤ L ≤ 50,000 1 ≤ N ≤ 250

Example

Sample input 1
130 340 5
10 50
130 130
70 170
0 180
60 260
Sample output 1
1

Sample input 2
500 300 4
250 0
250 300
100 150
400 150
Sample output 2
0
