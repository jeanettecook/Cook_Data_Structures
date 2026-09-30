#ifndef BTNODE_HPP
#define BTNODE_HPP

template<typename T>
class BTNode{
   
public:
BTNode(const T& val = T(), BTNode<T> *l = nullptr, BTNode<T>* r= nullptr) :
data(val), left(l), right(r) {

}
bool isLeaf() const{
    //both of it's children are nullptrs
    return(!left && !right);
}
bool hasOnlyOneChild() const{
    return(right && !left) || (!right && left);
}
bool hasTwoChildren() const{
    return right && left;  // does not need parenthesis because it is not checking two things
}
T data;
BTNode<T>* left;
BTNode<T>* right;




};
#endif