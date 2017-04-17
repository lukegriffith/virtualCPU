#include <stdio.h>
#include <iostream>


using namespace std; 
class superclass {

    public:
        int superid;
};



class subclass : superclass {

    public:
        int subid;
};

int main() {

    subclass a = subclass();

    
    a.subid = 1; 

    cout<<a.superid; 

    return 0; 
}