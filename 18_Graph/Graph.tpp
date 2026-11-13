#include "Graph.hpp"
#include <iostream>
#include <queue>

template <typename T>
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
