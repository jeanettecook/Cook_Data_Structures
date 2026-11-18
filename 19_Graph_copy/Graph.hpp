#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

template <typename T>
class Graph {
public:
    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2, int weight = 1);
    bool update(const T& oldVal, const T& newVal);
    bool contains(const T& v) const;
    bool containsEdge(const T& v1, const T& v2) const;
    void print() const;

    int getDegree(const T& vertex) const;
    bool hasEdge(const T& v1, const T& v2) const;
    int shortestPath(const T& start, const T& end) const;

    void BFS(const T& start) const;
    void DFS(const T& start) const;

    int getWeightEdge(const T& v1, const T& v2) const;

private:
    struct Edge {
        int neighbor;
        int weight;
        Edge(int n, int w) : neighbor(n), weight(w) {}
    };

    bool operator <(const T& val)

    std::vector<T> vertices;
    std::vector<std::vector<Edge>> adjacency_list;

    int searchVertexIndex(const T& value) const;
    void DFSExplore(int index, std::vector<bool>& visited) const;
};

#include "Graph.tpp"

#endif