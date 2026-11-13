#include "Graph.hpp"
#include <string>

int main(void){
    Graph<std::string> friends;
    //insert vertices

    friends.insertVertex("Ross");
    friends.insertVertex("Monica");
    friends.insertVertex("Rachel");
    friends.insertVertex("Chandler");
    friends.insertVertex("Joey");
    friends.insertVertex("Phoebe");


    //create freindship
    friends.insertEdge("Ross", "Monica");
    friends.insertEdge("Ross", "Rachel");
    friends.insertEdge("Monica", "Rachel");
    friends.insertEdge("Rachel", "Joey");

    //print the graph
    friends.print();

    //friends.BFS()

    std::cout<< friends.getDegree("Chandler");
    
    std::cout << friends.hasEdge("Phoebe", "Joey");

    std::cout<< "Ross to Chandler" <<friends.shortestPath("Ross", "Chandler");
    //how many frineds 
return 0;
}