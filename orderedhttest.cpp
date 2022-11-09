#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"

class Orderedhttest: public Hashtable {
    public: 
    std::string insert( int key, std::string lName );
    std::string search( int key );
    std::string del( int key );
    void print( int index );
};

std::string Orderedhttest::insert( int key, std::string lName ) {
    
    int index = this->hash1( key );
    int len = this->a1[index].size();

    for(int i = 0; i < len; i++) {
        if(this->a1[index][i].key == key) {
            return "failure";
        }
    }
    this->a1[index].resize(len + 1);
    this->a1[index][len].key = key;
    this->a1[index][len].data = lName;
    return "success";
    
}

std::string Orderedhttest::search( int key ) {
    
    int index = this->hash1( key );
    int i = 0;
     while(this->a1[index][i].key != 0) {
        if(this->a1[index][i].key == key) {
            return "found " + this->a1[index][i].data + " in " + std::to_string(index);
        }
        i = i+1;
    }
    
    return "not found";
}

std::string Orderedhttest::del( int key ) {
    
    return "failure";
}

void Orderedhttest::print( int index ) {
    
    for( int i = 0; i < this->a1[index].size(); i++ ) {
        std::cout << std::to_string(this->a1[index][i].key) + " ";
    }
}

int main() {
    Orderedhttest o1;
    
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
                o1.create2(n);
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
            else if(inst == 'p') {
                int n = stoi(input);
                o1.print(n);
            }
        }

    } while(true);
}