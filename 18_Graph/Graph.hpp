#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

template <typename T>
class Graph {
public:
    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2);
    bool update(const T& oldVal, const T& newVal);
    bool contains(const T& v) const;
    bool containsEdge(const T& v1, const T& v2) const; // true if edge v1-v2 exists
    void print() const; // prints vertices and adjacency list

    int getDegree(const T& vertex) const;
    bool hasEdge(const T& val);
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> adjacency_list;

    int searchVertexIndex(const T& value) const;
};

#include "Graph.tpp"   // templates need their definitions visible to main

#endif