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
#include "helpers.h"

// static property needs to be defined in cpp
std::array<bitset<8>,128> memory_cell::cells;
std::array<string,128> program_counter::program;
std::array<bitset<8>,15> cpu_register::registers;
int program_counter::cursor;

void loadRegister(char R, char X, char Y) 
{
    bitset<4> x = hex_to_bits(X);
    bitset<4> y = hex_to_bits(Y);
    bitset<4> r = hex_to_bits(R);
    bitset<8> bitpattern;

    bitpattern = memory_cell::getCell(x, y);
    cpu_register::setRegister(r, bitpattern);

}


void processOperation(string instruction) 
{


   switch (instruction[0])
    {
        case '0':
           loadRegister(instruction[1], instruction[2], instruction[3]);
           break;

        default:
            cout<<"Unable to find operation"<<std::endl;
    }

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
//    bitset<4> x = hex_to_bits('F');
//
//    bitset<8> reg = memory_cell::getCell(x, x);
//
//    cout<<"original reg "<<reg<<"\n";
//
//    reg = bitset<8>(std::string("11111111"));
//
//    memory_cell::setCell(x, x, reg);
//
//    bitset<8> reg1 = memory_cell::getCell(x, x);
//
//    cout<<"reg "<<reg<<" reg1 "<<reg1 ;
//
//    cout<<std::endl<<program_counter::getLine();
//
//    program_counter::goToLine(20);
//
//    cout<<std::endl<<program_counter::getLine();
//
//    bitset<8> cpu_reg = cpu_register::getRegister(x);
//
//    cout<<std::endl<<"CPU Register "<<cpu_reg;
//
//    cpu_register::setRegister(x, reg);
//
//    cout<<std::endl<<"Set CPU Register.";
//
//    reg = cpu_register::getRegister(x);
//
//    cout<<std::endl<<"Register "<<reg;
//

    bitset<4> cell = hex_to_bits('1');
    bitset<8> reg = bitset<8>(std::string("11111101"));

    memory_cell::setCell(cell, cell, reg);

    cout<<"Set memory cell 11(16), to FF(16) 11111101(2)"<<std::endl;

    string a = "hello";


    processOperation( program_counter::getLine() );

    cout<<"First line has been processed, CPU register 1 should be set with content of memory cell 11"<<std::endl;

    cout<<cpu_register::getRegister(cell);


    return 0;
}

