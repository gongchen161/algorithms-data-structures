//GCD of two numbers

#include <iostream>

using T = int;

T GCD(T a, T b){
    if(b == T(0))
        return a;
    
    return GCD(b, a%b);
}



int main(){
    std::cout<<GCD(10,50)<<std::endl;
    std::cout<<GCD(1,78)<<std::endl;
    std::cout<<GCD(24,64)<<std::endl;
    std::cout<<GCD(13, 47)<<std::endl;
    
    return 0;
}
