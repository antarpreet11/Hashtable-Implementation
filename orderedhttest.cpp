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
    int pos = 0;

    for(int i = 0; i < len; i++) {
        if(this->a1[index][i].key == key) {
            return "failure";
        }
        if(this->a1[index][i].key < key) {
            pos = i + 1;
        }
    }

    Node n1;
    n1.key = key;
    n1.data = lName;
    this->a1[index].insert(this->a1[index].begin() + pos, n1);
    
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
    
    int index = this->hash1( key );
    int len = this->a1[index].size();

    if(len == 0) {
        return "failure";    
    }

    for(int i = 0; i < len; i++) {
        if(this->a1[index][i].key == key) {
            this->a1[index].erase(this->a1[index].begin() + i);
            return "success";
        }
    }

    return "failure";
}

void Orderedhttest::print( int index ) {

    if(this->a1[index].size() == 0) {
        std::cout << "chain is empty" << std::endl;
    }
    else {
        std::cout << std::to_string(this->a1[index][0].key);
        for( int i = 1; i < this->a1[index].size(); i++ ) {
            std::cout << " " + std::to_string(this->a1[index][i].key);
        }
        std::cout << std::endl;
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