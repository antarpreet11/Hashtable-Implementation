#include <iostream>
#include <vector>
#include <string>

class DataItem {
    public: 
    int key; 
    std::string data;
    DataItem( int key, std::string data) {
        this->key = key;
        this->data = data;
    }
};

class Hashtable {
    public: 
    int n;
    std::vector<DataItem> v1;
    Hashtable();
    ~Hashtable();
    void create( int num );
};
