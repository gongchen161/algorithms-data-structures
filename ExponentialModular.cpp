#include <iostream>


using T = long long;


//Find (x^y) % d for any large/small numbers
T expMod(T x, T p, T d){
    T ans = 1;
    
    while(p > 0){
        if(p % 2 == 1)
            ans = (ans*x)%d;
        x = (x*x)%d;
        p /= 2;
    }
    
    return ans;
}

int main() {
    assert(expMod(2, 5, 7) == 4); // ( 2 ^ 5 ) % 7
    assert(expMod(3456, 789, 123456789) == 66221163);
    assert(expMod(987654321, 123, 1e9+7) == 328320105);
    
    return 0;
}
