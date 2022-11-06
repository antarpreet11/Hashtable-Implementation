#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"

class Openhttest: public Hashtable {
    public: 
    std::string insert( int key, std::string lName );
    std::string search( int key );
    std::string del( int key );
};

std::string Openhttest::insert( int key, std::string lName ) {
    
    for( int i = 0; i < this->n ; i++ ) {
        if( this->v1[i].key == key ) {
            return "failure";
        }
    }

    int index = key % this->n;
    for(int i = index; i < this->n ; i++) {
        if( this->v1[i].key == 0 ) {
            this->v1[i].data = lName;
            this->v1[i].key = key;
            return "success";
        }
    }
    for(int i = 0; i < index; i++) {
        if( this->v1[i].key == 0 ) {
            this->v1[i].data = lName;
            this->v1[i].key = key;
            return "success";
        }
    }
    return "failure";
}

std::string Openhttest::search( int key ) {
    int index = key % this->n;

    for(int i = index; i < this->n ; i++) {
        if( this->v1[i].key == key ) {
            return "found " + this->v1[i].data + " in " + i;
        }
    }
    for(int i = 0; i < index; i++) {
        if( this->v1[i].key == key ) {
            return "found " + this->v1[i].data + " in " + i;
        }
    }
    return "not found";
}

std::string Openhttest::del( int key ) {
    int index = key % this->n;

    for(int i = index; i < this->n ; i++) {
        if( this->v1[i].key == key ) {
            this->v1[i].key = 0;
            this->v1[i].data = "";
            return "success";
        }
    }
    for(int i = 0; i < index; i++) {
        if( this->v1[i].key == key ) {
            this->v1[i].key = 0;
            this->v1[i].data = "";
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
                o1.create(n);
            }
            else if(inst == 'i') {
                int sp = input.find_first_of(" ");
                int key = stoi(input.substr(0, sp));
                std::string name = input.substr(sp + 1, input.length() - sp - 1);
                std::cout << o1.insert(key, name) << std::endl;
            }
            input = stoi(input);
            else if(inst == 's') {
                std::cout << o1.search(input) << std::endl;
            }
            else if(inst == 'd') {
                std::cout << o1.del(input) << std::endl;
            }
        }

    } while(true);
}