#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"

Hashtable::Hashtable() {
    this->n = 0;
}

Hashtable::~Hashtable() {
    this->n = 0;
    this->v1.clear();
}

void Hashtable::create1( int num ) {
    this->v1.resize( num );
    this->n = num;
    std::cout << "success" << std::endl;
}

void Hashtable::create2( int num ) {
    this->a1 = new std::vector<Node>[num];
    this->n = num;
    std::cout << "success" << std::endl;
}

int Hashtable::hash1( int key ) {
    return key % this-> n;
}
