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

void Hashtable::create( int num ) {
    this->v1.resize( num );
    this->n = num;
    std::cout << "success" << std::endl;
}

