#include <iostream>
#include <vector>
using namespace std;

using T = long long;

vector<bool> isPrime; //array indicating prime or not
vector<T> primes; //store all the primes


//Sieve’s method of finding prime numbers
void sievePrime(T N) {
    isPrime = std::vector<bool>(N+1, true);
    
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(T i = 2; i * i <= N; ++i) {
        if(isPrime[i] == true) {
            for(T j = i * i; j <= N ;j += i)
                isPrime[j] = false;
        }
    }
}


//check if a number is prime
//maximum number allowed = isPrime.size() ^ 2
bool checkPrime(T N) {
    if (N < isPrime.size())
        return isPrime[N];
    
    for (T i = 0; i < isPrime.size(); ++i) {
        if (N % i == 0)
            return false;
    }
    return true;
}

//fill a vector containing all primes smaller than N
void fillPrime(T N) {
    sievePrime(N);
    primes.clear();
    
    for (T i = 0; i <= N; i++) {
        if (checkPrime(i))
            primes.push_back(i);
    }
}

//prime power factorization of a number
vector<T> primePowerFactor(T N) {
    vector<T> result;
    T i = 0;
    T factor = primes[i];
    
    while (factor * factor <= N) {
        while (N % factor == 0) {
            result.push_back(factor);
            N /= factor;
        }
        factor = primes[++i];
    }
    
    if (N != 1)
        result.push_back(N);
    
    return result;
}
int main(){
    
    auto Print = [](const vector<T>& v){
        for(int i=0; i<v.size(); i++){
            std::cout<<v[i]<<" ";
        }
        std::cout<<std::endl;
    };
    
    fillPrime(10);
    Print(primes);
    
    fillPrime(100);
    Print(primes);
    
    fillPrime(2000);
    Print(primes);
    
    
    Print(primePowerFactor(100));
    Print(primePowerFactor(13));
    Print(primePowerFactor(1000));
    
}
