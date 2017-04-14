#include <iostream>
#include <array>
 
int main()
{
    std::array<int, 3> arr;
 
    // set values:
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
 
    // get values:
    std::cout << "(" << std::get<0>(arr) << ", " << std::get<1>(arr)
              << ", " << std::get<2>(arr) << ")\n";
}