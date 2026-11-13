#include "HashMap.hpp"
#include <string>

int main(){
//create a hash table 
HashMap <std::string> map;

map.insert(8, "a");
map.insert(15, "b");
map.insert(22, "c");

map.print();


return 0;

}