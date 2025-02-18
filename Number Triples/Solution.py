from collections import defaultdict
import heapq

def build_graph(triples):
    graph = defaultdict(list)
    
    for x, y, z in triples:
        graph[x].append((z, y))
        graph[z].append((x, y))
    
    return graph

def dijkstra(graph, start, end):
    pq = [(0, start)]
    distances = defaultdict(lambda: float('inf'))
    distances[start] = 0
    visited = set()
    
    while pq:
        curr_dist, curr_node = heapq.heappop(pq)
        
        if curr_node in visited:
            continue
            
        visited.add(curr_node)
        
        if curr_node == end:
            return curr_dist
        
        for next_node, weight in graph[curr_node]:
            if next_node in visited:
                continue
                
            distance = curr_dist + weight
            
            if distance < distances[next_node]:
                distances[next_node] = distance
                heapq.heappush(pq, (distance, next_node))
    
    return None

def solve_number_triples(M, A, B, triples):
    graph = build_graph(triples)
    result = dijkstra(graph, A, B)
    
    if result is None:
        return False, None
    else:
        return True, result

def main():
    M, A, B = map(int, input().split())
    triples = []
    for _ in range(M):
        x, y, z = map(int, input().split())
        triples.append((x, y, z))
    
    path_exists, min_value = solve_number_triples(M, A, B, triples)
    
    if path_exists:
        print("YES")
        print(min_value)
    else:
        print("NO")

if __name__ == "__main__":
    main()