//Find (x^y) % d for any large or small numbers

#include <iostream>

using T = long long;

T ExpMod(T x, T p, T d){
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
    
    std::cout<<ExpMod(2, 5, 7)<<std::endl;  //2^5 %7
    std::cout<<ExpMod(3243, 231, 21321)<<std::endl;
    
    return 0;
}
