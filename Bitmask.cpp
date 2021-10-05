#include <iostream>

int main() {
    // This section includes some common bitwise operations
    

    // Multiply by 2
    assert(8 << 1 == 16);
    
    // Divide by 4
    assert(16 >> 2 == 4);
    
    // Set 2nd bit on
    // 1001 -> 1101 ==> 9 -> 13
    assert((9 | (1 << 2)) == 13);
    
    // Check if the 2nd bit is on
    // 1000 ==> false
    assert((8 & (1 << 2)) == 0);
    // 1100 ==> true
    assert((12 & (1 << 2)) != 0);

    // Clear the 2nd bit
    // 1111 -> 1011 
    assert((15 & (~(1 << 2))) == 11);
    
    // Flip the 2nd bit
    // 1101 -> 1001 
    assert((13 ^ (1 << 2)) == 9);
    
    // Get the first bit that is on (least significant -- from right to left)
    // 1100 -> 2nd bit on -> 4
    assert((12 & -12) == 4);
    // 1101 -> 0th bit on -> 1
    assert((13 & -13) == 1);
    // 1000 -> 3rd bit on -> 1
    assert((8 & -8) == 8);

    // Set all bits on
    // 1111
    assert((1 << 4) - 1 == 15);

    // Other bit-related logics
    // a ^ a = 0
    // a ^ 0 = a
    for (int i = 0; i < 100; i++) {
        assert(i ^ i == 0);
        assert(i ^ 0 == i);
    }
   
}
