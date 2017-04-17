#include <array> 

using namespace std;

// Emulates the CPU registers for the program
class cpu_register
{
    public:
        static bitset<8> getRegister(bitset<4> location)
        {
            long loc = location.to_ulong();
            return cpu_register::registers[loc];
        }

        static void setRegister(bitset<4> location, bitset<8> value)
        {
            long loc = location.to_ulong();
            cpu_register::registers[loc] = value;
        }
    private:
        static std::array<bitset<8>,15> registers;
};