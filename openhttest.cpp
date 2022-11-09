#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"

class Openhttest: public Hashtable {
    public: 
    int hash2( int key );
    std::string insert( int key, std::string lName );
    std::string search( int key );
    std::string del( int key );
};

int Openhttest::hash2( int key ) {
    int h2 = abs(key / this->n) % this->n;
    if(h2 % 2 == 0) {
        h2 = h2 + 1;
    }
    return h2;
}

std::string Openhttest::insert( int key, std::string lName ) {

    int len = this->v1.size();
    if(len == this->n) {
        return "failure";
    }

    for( int i = 0 ; i < this->n ; i++ ) {
        if( this->v1[i].key == key ) {
            return "failure";
        }
    }

    for( int i = 0 ; i < this->n ; i++ ) {
        int index = (this->hash1( key ) + (i * this->hash2( key ))) % this->n;
        // std::cout << std::to_string(this->hash1(key)) + " " + std::to_string( i ) + " times " + std::to_string(this->hash2( key )) + " mod " + std::to_string( this->n ) << std::endl;
        if(this->v1[index].key == 0) {
            this->v1[index].key = key;
            this->v1[index].data = lName;
            return "success";
        }
    }
    
    return "failure";
}

std::string Openhttest::search( int key ) {
    
    for( int i = 0 ; i < this->n ; i++ ) {
        int index = (this->hash1( key ) + (i * this->hash2( key ))) % this->n;
        if(this->v1[index].key == key) {
            return "found " + this->v1[index].data + " in " + std::to_string(index);
        }
    }

    return "not found";
}

std::string Openhttest::del( int key ) {
   
    for( int i = 0 ; i < this->n ; i++ ) {
        int index = (this->hash1( key ) + (i * this->hash2( key ))) % this->n;
        if(this->v1[index].key == key) {
            this->v1[index].key = 0;
            this->v1[index].data = "";
            return "success";
        }
    }

    return "failure";
}

int main() {
    Openhttest o1;
    
    do {
        std::string inp;
        std::getline(std::cin, inp);

        if(inp == ""){
            break;
        }
        else {
            char inst = inp[0];
            std::string input = inp.substr(2);
            if(inst == 'm') {
                int n = stoi(input);
                o1.create1(n);
            }
            else if(inst == 'i') {
                int sp = input.find_first_of(" ");
                int key = stoi(input.substr(0, sp));
                std::string name = input.substr(sp + 1, input.length() - sp - 1);
                std::cout << o1.insert(key, name) << std::endl;
            }
            else if(inst == 's') {
                int n = stoi(input);
                std::cout << o1.search(n) << std::endl;
            }
            else if(inst == 'd') {
                int n = stoi(input);
                std::cout << o1.del(n) << std::endl;
            }
        }

    } while(true);
}