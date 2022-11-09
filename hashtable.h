#include <iostream>
#include <vector>
#include <string>

class Node {
    public:
    int key; 
    std::string data;
    Node() {
        this->key = 0;
        this->data = "";
    }
    ~Node() {
        this->key = 0;
        this->data = "";
    }
    Node( int k, std::string d ) {
        this->key = k;
        this->data = d;
    }
};

class Hashtable {
    public: 
    int n;
    std::vector<Node> v1;
    std::vector<Node> *a1;

    Hashtable();  
    ~Hashtable();
    void create1( int num );
    void create2( int num );
    int hash1( int key );
};
