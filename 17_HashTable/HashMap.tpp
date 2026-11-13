

template <typename T>
class HashMap{

template <typename T>
HashMap<T>::HashMap(int capacity) : size (0){
    for (int i = 0; i < data.size(); i++){
    std::cout<< 
    }
    data.resize(capacity, HashNode<T>(-1, T()));
}
template <typename T>
int HashMap<T>::hash(int key) const{
    int index = key % static_cast<int> (data.size());
    if (index < 0) index += data.size();
    return index;
}

template <typename T>
void HashMap<T>::insert (int key const T& value){
    int index = hash(key);
    int start = index;
}
template <typename T> 
void HashMap<T>::insert(int key, const T& value){
    int index = hash(key);
    int start = index;

   // while (data[index].key != -1 && data [index].key != key){
       // index = (index + 1) % data.size();
      //  if (index ==start){
      //      std::cout << "Hash table is full, cannot insert key" << key << "\n";
       // return;
        //}
    while (!data[index].empty()){
       if(data[index]).deleted()){
        break; 
       }
    }
    }
    
    if (data[index].key == -1){
        size++;
    }
    data[index].key = key;
    data[index].value = valuel
}
template <typename T>
void HashMap<T>::print() const{
    std::cout<< "Hash table(" << size << " of  " << data.size()<< "slots used) \n";
    for (int i = 0; i < data.size(); i++){
        if (data[i].empty()){ // is empty if key = -1
            std::cout<< "["<< i << "] key: "<< data[i].key 
            << " value: "<< data[i]. value<< "\n";
        }
    }
}

template <typename T>
int HashMap<T>:: searchIndex(int key) const{
    int index = hash(key); 
    int counter = 0;

    while(!data[index].empty()){
        if (data[index].key == key){
            return index;
        }
        index = (index + 1 ) % data.size();
    }
    if(counter >= data.size()){
        return -1;
    }
    
    return -1;
}
template <typename T>
const T& HashMap<T>::search(int key) const {
    int index = seachIndex(key);

    if(index == -1){
        throw std::out_of_range("search: key not found");
    }
    return data[index].value;
}

//need to make delete 
template <typename T>
void HashHap<T>::remove(int key){
    int index = searchIndex(key);

    if (index == -1){
        std::count
        return;
    }

}


