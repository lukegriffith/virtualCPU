
using namespace std;

// Emulates the memory for the program 
class memory_cell 
{
    public:

        static bitset<8> getCell(bitset<4> location1, bitset<4> location2) 
        {
            bitset<8> reg;

            long reglocation;

            reg = getloc(location1, location2);

            reglocation = reg.to_ulong();

            return memory_cell::cells[reglocation];
        }

        static void setCell(bitset<4> location1, bitset<4> location2, bitset<8> value)
        {
            bitset<8> reg;
            long reglocation;

            reg = getloc(location1, location2);
            reglocation = reg.to_ulong();

            memory_cell::cells[reglocation] = value;
        }

        static void initMemory()
        {
            for (int i; i <= 128; i = i + 1)
            {
                memory_cell::cells[i] = bitset<8>();
            }
        }

    private:
        static bitset<8> getloc(bitset<4> loc1, bitset<4> loc2)
        {
            // previous implementation using string operations. 
            // return bitset<8> (std::string(loc1.to_string<char,std::string::traits_type,std::string::allocator_type>() + loc2.to_string<char,std::string::traits_type,std::string::allocator_type>()));

            // current implementation, using math. 
            long l1, l2, result;

            l1 = loc1.to_ulong();
            l2 = loc2.to_ulong(); 

            result = l1 * 16  + l2; 

            return bitset<8>(result);


        }

        static std::array<bitset<8>,128> cells;
};
