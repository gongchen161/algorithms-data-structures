#include <iostream>

using T = long long;

// Greatest Common Divisor
T gcd(T a, T b){
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

// Least Common Multiple
T lcm(T a, T b) {
    return a * (b / gcd(a, b));
}


int main(){

    assert(gcd(1, 42) == 1);    
    assert(gcd(10, 50) == 10);
    assert(gcd(13, 47) == 1);

    assert(lcm(1, 42) == 42);
    assert(lcm(10, 50) == 50);
    assert(lcm(13, 47) == 13 * 47);
    
    return 0;
}
