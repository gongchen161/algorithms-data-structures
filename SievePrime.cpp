//Sieve’s method of finding prime numbers

#include <iostream>
#include <vector>

std::vector<bool>isPrime;

void sieve(int N) {
    isPrime = std::vector<bool>(N+1, true);

    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i = 2; i * i <= N; ++i) {
        if(isPrime[i] == true) {
            for(int j = i * i; j <= N ;j += i)
                isPrime[j] = false;
        }
    }
}



int main(){
    
    auto Print = [](){
        for(int i=0; i<isPrime.size(); i++){
            if(isPrime[i]){
                std::cout<<i<<" ";
            }
        }
        std::cout<<std::endl;
    };
    
    sieve(10);
    Print();
    
    sieve(100);
    Print();
    
    sieve(1000);
    Print();
    
}
