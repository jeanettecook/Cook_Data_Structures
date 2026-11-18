// Graph.tpp -- included at the bottom of Graph.hpp; do not compile this file on its own.

#include <queue>
#include <vector>
#include <utility>     // std::pair
#include <functional>  // std::greater
#include <climits>     // INT_MAX
#include "../15_Binary_Heap/MinHeap.hpp"

template <typename T>
int Graph<T>::searchVertexIndex(const T& value) const {
    for (int i = 0; i < (int)vertices.size(); i++)
        if (vertices[i] == value) return i;
    return -1;
}

template <typename T>
void Graph<T>::insertVertex(const T& v) {
    if (searchVertexIndex(v) != -1) {
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }
    vertices.push_back(v);
    adjacency_list.push_back(std::vector<Edge>());
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2, int weight) {
    if (weight < 0) {
        std::cout << "insertEdge: negative weights\n";
        return;
    }
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
        return;
    }
    if (containsEdge(v1, v2)) {
        std::cout << "insertEdge: edge already exists\n";
        return;
    }
    adjacency_list[i_v1].push_back(Edge(i_v2, weight));
    if (i_v1 != i_v2)   // don't add a self-loop twice
        adjacency_list[i_v2].push_back(Edge(i_v1, weight));
}

template <typename T>
bool Graph<T>::update(const T& oldVal, const T& newVal) {
    int i = searchVertexIndex(oldVal);
    if (i == -1) return false;
    if (oldVal == newVal) return true;
    if (searchVertexIndex(newVal) != -1) return false;
    vertices[i] = newVal;
    return true;
}

template <typename T>
bool Graph<T>::contains(const T& v) const {
    return searchVertexIndex(v) != -1;
}

template <typename T>
bool Graph<T>::containsEdge(const T& v1, const T& v2) const {
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    if (i_v1 == -1 || i_v2 == -1) return false;
    for (const Edge& edge : adjacency_list[i_v1])
        if (edge.neighbor == i_v2) return true;
    return false;
}

template <typename T>
bool Graph<T>::hasEdge(const T& v1, const T& v2) const {
    return containsEdge(v1, v2);
}

template <typename T>
int Graph<T>::getWeightEdge(const T& v1, const T& v2) const {
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    if (i_v1 == -1 || i_v2 == -1) return -1;
    for (const Edge& edge : adjacency_list[i_v1])
        if (edge.neighbor == i_v2) return edge.weight;
    return -1;   // no such edge
}

template <typename T>
int Graph<T>::getDegree(const T& vertex) const {
    int i = searchVertexIndex(vertex);
    if (i == -1) return -1;
    return (int)adjacency_list[i].size();
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < (int)vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (const Edge& edge : adjacency_list[i])
            std::cout << vertices[edge.neighbor] << "(" << edge.weight << ") ";
        std::cout << std::endl;
    }
}

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int s = searchVertexIndex(start);
    if (s == -1) {
        std::cout << "BFS: incorrect start vertex\n";
        return;
    }
    std::vector<bool> discovered(vertices.size(), false);
    std::queue<int> q;
    discovered[s] = true;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << vertices[cur] << " ";
        for (const Edge& edge : adjacency_list[cur]) {
            if (!discovered[edge.neighbor]) {
                discovered[edge.neighbor] = true;
                q.push(edge.neighbor);
            }
        }
    }
    std::cout << std::endl;
}

template <typename T>
void Graph<T>::DFSExplore(int index, std::vector<bool>& visited) const {
    visited[index] = true;
    std::cout << vertices[index] << " ";
    for (const Edge& edge : adjacency_list[index])
        if (!visited[edge.neighbor]) DFSExplore(edge.neighbor, visited);
}

template <typename T>
void Graph<T>::DFS(const T& start) const {
    int s = searchVertexIndex(start);
    if (s == -1) {
        std::cout << "DFS: incorrect start vertex\n";
        return;
    }
    std::vector<bool> visited(vertices.size(), false);
    DFSExplore(s, visited);
    std::cout << std::endl;
}

// Dijkstra: total weight of the cheapest path, or -1 if there's no path / bad vertex
template <typename T>
int Graph<T>::shortestPath(const T& start, const T& end) const {
    int s = searchVertexIndex(start);
    int e = searchVertexIndex(end);
    if (s == -1 || e == -1) return -1;

    std::vector<int> dist(vertices.size(), INT_MAX);
    // min-heap of (distance, vertex index)
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> pq;
    dist[s] = 0;
    pq.push(std::make_pair(0, s));
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;   // skip outdated entries
        for (const Edge& edge : adjacency_list[u]) {
            int nd = d + edge.weight;
            if (nd < dist[edge.neighbor]) {
                dist[edge.neighbor] = nd;
                pq.push(std::make_pair(nd, edge.neighbor));
            }
        }
    }
    return dist[e] == INT_MAX ? -1 : dist[e];
}
template <typename T>
int Graph<T>::shortestPathByDistance(const T& start, const T& end) const {
    int start_index = searchVertexIndex(start);
    int end_index = searchVertexIndex(end);

    if (start_index == -1 || end_index == -1) {
        std::cout << "shortestPathByDistance: incorrect vertices\n";
        return -1;
    }

    std::vector<int> distances(vertices.size(), INT_MAX);
    std::vector<bool> visited(vertices.size(), false);

    // each heap entry is Edge(vertex index, distance from start)
    MinHeap<Edge> pq;

    // set distance to source with zero
    distances[start_index] = 0;
    // insert the source into the heap
    pq.insert(Edge(start_index, 0));

    while (!pq.empty()) {
        // take the closest unvisited vertex
        Edge top = pq.extractMin();
        int current = top.neighbor;

        if (visited[current]) {
            continue;   // already finalized, skip outdated entry
        }
        visited[current] = true;

        if (current == end_index) {
            return distances[current];
        }

        for (const Edge& edge : adjacency_list[current]) {
            int neighbor = edge.neighbor;
            int weight = edge.weight;

            int new_distance = distances[current] + weight;

            if (!visited[neighbor] && new_distance < distances[neighbor]) {
                distances[neighbor] = new_distance;
                pq.insert(Edge(neighbor, new_distance));
            }
        }
    }

    return -1;   // end is not reachable from start
}