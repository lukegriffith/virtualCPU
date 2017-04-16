/* program_counter.h
Reads and processes the program in memory.
*/

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <array>

using namespace std;

class program_counter
{

   public:
        static void readProgram(string path)
        {
            string instruction;
            ifstream file; 
            int i;

            file.open(path);

            // Iterate each line of the program.
            while (getline(file, instruction))
            { 
                if (i > 128) {
                    cout<<"Program longer than 128 line limit."; 
                }
                program[i] = instruction;
                i = i + 1; 
            }
            
            goToLine(0);
        }

        static string getLine()
        {
            return program[cursor];
        }

        static void goToLine(int line)
        {
            cursor = line;
        }

        static void nextLine()
        {
            cursor = cursor + 1;
        }

   private:
        static std::array<string, 128> program;
        static int cursor;
};