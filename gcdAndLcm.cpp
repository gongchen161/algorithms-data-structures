#include <iostream>

using T = long long;

//Greatest Common Divisor
T gcd(T a, T b){
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

//Least Common Multiple
T lcm(T a, T b) {
    return a * (b / gcd(a, b));
}


int main(){
    
    std::cout<<gcd(10,50)<<std::endl;
    std::cout<<gcd(1,78)<<std::endl;
    std::cout<<gcd(24,64)<<std::endl;
    std::cout<<gcd(13, 47)<<std::endl;
    
    std::cout<<lcm(10,50)<<std::endl;
    std::cout<<lcm(1,78)<<std::endl;
    std::cout<<lcm(24,64)<<std::endl;
    std::cout<<lcm(13, 47)<<std::endl;
    
    return 0;
}
