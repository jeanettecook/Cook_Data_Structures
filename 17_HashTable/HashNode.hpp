#ifndef HASHNODE_HPP
#define HASHNODE_HPP


template <typename T> 

class HashNode {
    public:
        HashNode(int key, const T& value) : key(key), value(value){

        }
        bool empty()const{
            return key == -1;
        }
        bool deleted()

        }
        static HashNode<T> makeDeleted(){
            return HashNode<T> (-2, T());
        }
        //
        static HashNode<T> make
        int key;
        T value;
};
#endif