#include "Graph.hpp"

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