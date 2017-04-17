#include <bitset>
#include <stdio.h>
#include <iostream>

using namespace std;


int main (int argc, char* argv[]) {

    long i,j,k;
    bitset<8> i8, j8, k8;
    bitset<4> i4, j4, k4;

   string in = argv[1]; 
    i =  atoi(in.c_str());
    

    i4 = i; 

    cout<<i<<"and "<<i4;


    return 0; 
}