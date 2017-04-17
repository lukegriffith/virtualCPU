
using namespace std;

// Memory register data structure to allow a static class to hold registers.
class memory_register 
{
    public:

        static bitset<8> getRegister(bitset<4> location1, bitset<4> location2) 
        {
            bitset<8> reg;

            long reglocation;

            reg = getloc(location1, location2);

            reglocation = reg.to_ulong();

            return memory_register::registers[reglocation];
        }

        static void setRegister(bitset<4> location1, bitset<4> location2, bitset<8> value)
        {
            bitset<8> reg;
            long reglocation;

            reg = getloc(location1, location2);
            reglocation = reg.to_ulong();

            memory_register::registers[reglocation] = value;
        }

        static void initRegister()
        {
            for (int i; i <= 128; i = i + 1)
            {
                memory_register::registers[i] = bitset<8>();
            }
        }

    private:
        static bitset<8> getloc(bitset<4> loc1, bitset<4> loc2)
        {
            // Use math opposed to sting operations. Convert loc1 to ulong - multiply by 8, convert loc2 to int
            // and add to result of loc1. Convert to bitset<8>
            return bitset<8> (std::string(loc1.to_string<char,std::string::traits_type,std::string::allocator_type>() + loc2.to_string<char,std::string::traits_type,std::string::allocator_type>()));


            long l1, l2, result;

            l1 = loc1.to_ulong();
            l2 = loc2.to_ulong(); 

            result = l1 * 8  + l2; 

        }

        static std::array<bitset<8>,128> registers;
};
