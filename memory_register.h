
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
            return bitset<8> (std::string(loc1.to_string<char,std::string::traits_type,std::string::allocator_type>() + loc2.to_string<char,std::string::traits_type,std::string::allocator_type>()));
        }

        static std::array<bitset<8>,128> registers;
};
