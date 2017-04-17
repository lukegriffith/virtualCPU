/*  Virtual CPU project */
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <array>
#include "memory_cell.h"
#include "program_counter.h"
#include "cpu_register.h"

// static property needs to be defined in cpp
std::array<bitset<8>,128> memory_cell::cells;
std::array<string,128> program_counter::program;
std::array<bitset<8>,15> cpu_register::registers;
int program_counter::cursor;

// writes to console, if debug is enabled.
void write_debug(string message, bool debug)
{
    if (debug)
    {
        cout<<message<<"\n";
    }
}

// Converts a hexadecimal character into its binary bitset.
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

    cout<<"OpCode - "<<bits<<" "<<instruction[0]<<"\n";
}



int main(int argc, char* argv[])
{
    string path;
    bool debug = 0;
    path = "program.txt";
    //memory_cell::initMemory();
    program_counter::readProgram(path);

    printf ("virtual CPU\n%s\n", "---------------");
    bitset<4> x = hex_to_bits('F');

    bitset<8> reg = memory_cell::getCell(x, x);

    cout<<"original reg "<<reg<<"\n";

    reg = bitset<8>(std::string("11111111"));

    memory_cell::setCell(x, x, reg);

    bitset<8> reg1 = memory_cell::getCell(x, x);

    cout<<"reg "<<reg<<" reg1 "<<reg1 ;

    cout<<std::endl<<program_counter::getLine();

    program_counter::goToLine(20);

    cout<<std::endl<<program_counter::getLine();

    bitset<8> cpu_reg = cpu_register::getRegister(x);

    cout<<std::endl<<"CPU Register "<<cpu_reg;

    cpu_register::setRegister(x, reg);

    cout<<std::endl<<"Set CPU Register.";

    reg = cpu_register::getRegister(x);

    cout<<std::endl<<"Register "<<reg;


    return 0;
}

