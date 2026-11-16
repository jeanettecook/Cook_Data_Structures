#include "Graph.hpp"
#include <iostream>
#include <queue>

/*template <typename T>
int Graph<T>::searchVertexIndex(const T& value) const {
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (vertices[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Graph<T>::insertVertex(const T& v) {
    if (searchVertexIndex(v) != -1) {
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }
    vertices.push_back(v);
    std::vector<int> tmp;
    adjacency_list.push_back(tmp);   // creates empty list of neighbours for the vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
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

    adjacency_list[i_v1].push_back(i_v2);
    if (i_v1 != i_v2) {
        adjacency_list[i_v2].push_back(i_v1);
    }
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
    for (int neighbour : adjacency_list[i_v1]) {
        if (neighbour == i_v2) return true;
    }
    return false;
}

template <typename T>
bool Graph<T>::update(const T& oldVal, const T& newVal) {
    int i_old = searchVertexIndex(oldVal);
    if (i_old == -1) { std::cout << "update: vertex does not exist\n"; return false; }
    if (oldVal == newVal) return true;
    if (searchVertexIndex(newVal) != -1) { std::cout << "update: new value already exists\n"; return false; }
    vertices[i_old] = newVal;
    return true;
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < (int)vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (int neighbour : adjacency_list[i]) {
            std::cout << vertices[neighbour] << " ";
        }
        std::cout << "\n";
    }
}
int getDegree(const T& vertex) const{
    int i = searchVertexIndex(vertex);

    if (i == -1){
        return -1;
    }
    return adjacency_list[i].size();
    //find the vertex (return -1 if not found)
    //return the adjancency_list size 

}

bool hasEdge(const T& v1, const T& v2) const{
    int i_v1 = searchVertexIndex(v1);
    //find indices of both vertices (return false if not found)
    //search adjancency_list for first(second) index
}

template <typename T> 
void Graph<T>::BFS (const T& start) const{
    int start_index = searchVertexIndex(start);
    
    if(start_index == -1){
        std::cout <<"BFS: incorrect start vertex\n";

    }
}

//create a queue and the vector of discovered vertices

std::queue<int> q; 
std::vector<bool> discovered(vertices.size(), false);

//add the start vertex into the queue

q.push(start_index);
//mark start index discovered
discovered[start_index] = true;

while(q!empty()){
    //get the front value from the queue
   int current_index = q.front(); 
   q.pop();
   //discover neighbors and add non discovered in the queue

   for (int neighbor : adjancency_list[current_index]){
    if (!discovered)
   }
   std::vector<bool> visited(vertices.size(), false);
   DFSExplore(index, visited);
}

template <typename T> 
void Graph<T>::DFSExplore(int index, std::vector<bool>& visited) const{
    visited[index] = true;

    if (print){
        std::cout << vertices [index] << " "
    }
    std::cout<< vertices[index] << " ";

    //go through visitors 
    //if not visited call DFSExplore for that vertex
    for (int neighbor : adjancency_list[index]){
        if(!visited[neighbor]){
            DFSExplore(neighbor, visited, print);
        }
    }
}
template <typename T>
bool Graph<T>::isConnected() const{
    if (vertices.empty()){
        return true;
    }
    std::vector<bool> visited(vertices.size(), false);

    //perform DFS
    DFSExplore(0, visited, false);

    for (bool v; visted){
        if (!v){
            return false;
        }
    }
    return true;
}

//fix
std::cout<< "isConnected" << friends.isConnected()<< std::endl;

//fix
friends.insertEdge("Rachel", "Phoebe", "")

template <typename T> 
void Graph<T>::shortestPath(const T& start, const T& end) const {
    int start_vertex = searchVertexIndex

    std::queue<int> q;
    std::queue<
}
*/


#include <queue>
#include <climits>

template <typename T>
int Graph<T>::searchVertexIndex(const T& value) const {
    for (int i = 0; i < (int)vertices.size(); i++)
        if (vertices[i] == value) return i;
    return -1;
}

template <typename T>
void Graph<T>::insertVertex(const T& v) {
    if (searchVertexIndex(v) != -1) return;   // no duplicates
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
    for (const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) return;    // edge already exists
    }
    adjacency_list[i_v1].push_back(Edge(i_v2, weight));
    adjacency_list[i_v2].push_back(Edge(i_v1, weight));
}

template <typename T>
bool Graph<T>::update(const T& oldVal, const T& newVal) {
    int i = searchVertexIndex(oldVal);
    if (i == -1 || searchVertexIndex(newVal) != -1) return false;
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
int Graph<T>::getDegree(const T& vertex) const {
    int i = searchVertexIndex(vertex);
    if (i == -1) return -1;
    return (int)adjacency_list[i].size();
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < (int)vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (const Edge& edge : adjacency_list[i]) {
            std::cout << vertices[edge.neighbor] << "(" << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int s = searchVertexIndex(start);
    if (s == -1) return;
    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        std::cout << vertices[cur] << " ";
        for (const Edge& edge : adjacency_list[cur]) {
            if (!visited[edge.neighbor]) {
                visited[edge.neighbor] = true;
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
    if (s == -1) return;
    std::vector<bool> visited(vertices.size(), false);
    DFSExplore(s, visited);
    std::cout << std::endl;
}

// Dijkstra: total weight of the cheapest path, or -1 if no path / bad vertex
template <typename T>
int Graph<T>::shortestPath(const T& start, const T& end) const {
    int s = searchVertexIndex(start);
    int e = searchVertexIndex(end);
    if (s == -1 || e == -1) return -1;

    std::vector<int> dist(vertices.size(), INT_MAX);
    // min-heap of (distance, vertex)
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;   // skip stale entries
        for (const Edge& edge : adjacency_list[u]) {
            int nd = d + edge.weight;
            if (nd < dist[edge.neighbor]) {
                dist[edge.neighbor] = nd;
                pq.push({nd, edge.neighbor});
            }
        }
    }
    return dist[e] == INT_MAX ? -1 : dist[e];
}