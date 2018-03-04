#include <iostream>

int main() {
    //This section will include some of the most common bitwise operations
    
    int i1 = 8;
    
    //Multiply by 2
    int i2 = i1 << 1;
    
    //Divide by 4
    int i3 = i2 >> 2;
    
    //set 2nd bit on
    int i4 = (i1 | (1 << 2));
    
    //check if the 2nd bit is on
    int i5 = (i1 & (1 << 2));
    
    //clear the 2nd bit
    int i6 = (i1 & (~(1 << 2)));
    
    //flip the 2nd bit
    int i7 = (i1 ^ (1 << 2));
    
    //get the first bit on (from right to left)
    int i8 = (i1 & -i1);
    
    //set all bit on
    int n = 4;  //bitsize of i1
    int i9 = (1 << n) - 1;
    
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << i3 << std::endl;
    std::cout << i4 << std::endl;
    std::cout << i5 << std::endl;
    std::cout << i6 << std::endl;
    std::cout << i7 << std::endl;
    std::cout << i8 << std::endl;
    std::cout << i9 << std::endl;
    
}
