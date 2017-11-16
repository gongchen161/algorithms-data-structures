//Find (x^y) % d for any large or small numbers

#include <iostream>

using T = long long;

T exp_mod(T x, T p, T d){
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
    
    std::cout<<exp_mod(2, 5, 7)<<std::endl;  //2^5 %7
    std::cout<<exp_mod(3243, 231, 21321)<<std::endl;
    return 0;
}
