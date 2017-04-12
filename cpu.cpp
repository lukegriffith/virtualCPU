/*  Virtual CPU project */
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

void write_debug(string message, bool debug)
{
    if (debug)
    {
        cout<<message<<"\n";
    }
}

bitset<4> hex_to_bits(char hex)
{
    
    bitset<4> bits;

    switch (hex)
    {
        case '0':
            bits = bitset<4> (std::string("0000"));
            break;
        case '1':
            bits = bitset<4> (std::string("0001"));
            break;
        case '2':
            bits = bitset<4> (std::string("0010"));
            break;
        case '3':
            bits = bitset<4> (std::string("0011"));
            break;
        case '4':
            bits = bitset<4> (std::string("0100"));
            break;
        case '5':
            bits = bitset<4> (std::string("0101"));
            break;
        case '6':
            bits = bitset<4> (std::string("0110"));
            break;
        case '7':
            bits = bitset<4> (std::string("0111"));
            break;
        case '8':
            bits = bitset<4> (std::string("1000"));
            break;
        case '9':
            bits = bitset<4> (std::string("1001"));
            break;
        case 'A':
            bits = bitset<4> (std::string("1010"));
            break;
        case 'B':
            bits = bitset<4> (std::string("1011"));
            break;
        case 'C':
            bits = bitset<4> (std::string("1100"));
            break;
        case 'D':
            bits = bitset<4> (std::string("1101"));
            break;
        case 'F':
            bits = bitset<4> (std::string("1111"));
            break;
    }
    

    return bits;
}

void process_instruction(string instruction)
{
    bitset<4> bits;

    bits = hex_to_bits(instruction[0]);

    cout<<"OpCode - "<<bits<<"\n";
}

int main()
{
    string instruction, path;
    ifstream program;
    bool debug = 1;
    
    path = "program.txt";

    printf ("virtual CPU\n%s\n", "---------------");

    program.open(path);

    // Iterate each line of the program.
    while (getline(program, instruction))
    { 
        write_debug(instruction, debug);
        process_instruction(instruction);
    }



    return 0;
}

