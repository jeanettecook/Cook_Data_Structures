#include "Graph.hpp"
#include <string>

int main(void) {
    Graph<std::string> friends;

    // insert vertices
    friends.insertVertex("Orlando");
    friends.insertVertex("Miami");
    friends.insertVertex("Lakeland");
    friends.insertVertex("Naples");
    friends.insertVertex("Tampa");

    // create friendships (weight defaults to 1)
    friends.insertEdge("Orlando", "Miami");
    friends.insertEdge("Orlando", "Lakeland");
    friends.insertEdge("Lakeland", "Miami");
    friends.insertEdge("Naples", "Miami");
    friends.insertEdge("Naples", "Miami");   // duplicate, gets ignored
    friends.insertEdge("Tampa", "Naples");
    friends.insertEdge("Tampa", "Miami");

    // print the graph
    friends.print();

    std::cout << "BFS from Orlando: ";
    friends.BFS("Orlando");
    std::cout << "DFS from Orlando: ";
    friends.DFS("Orlando");

    std::cout << "Degree of Miami: " << friends.getDegree("Miami") << std::endl;
    std::cout << "Tampa-Naples edge? " << std::boolalpha
              << friends.hasEdge("Tampa", "Naples") << std::endl;
    std::cout << "Orlando to Tampa: " << friends.shortestPath("Orlando", "Tampa") << std::endl;

    return 0;
}