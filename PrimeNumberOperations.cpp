#include <iostream>
#include <vector>
#include <cassert>

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
    
    
    auto verifyVectorResult = [] (const vector<T>& expected, const vector<T>& actual) {
        assert(expected.size() == actual.size());
        
        for (size_t i = 0; i < expected.size(); i++) {
            assert(expected[i] == actual[i]);
        }
    };

    fillPrime(100);
    verifyVectorResult(
        vector<T>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97},
        primes);

    verifyVectorResult(
       vector<T>{2, 2, 5, 5}, // 100 = 2 * 2 * 5 * 5
       primePowerFactor(100)
    );

    verifyVectorResult(
       vector<T>{13},
       primePowerFactor(13)
    );

    verifyVectorResult(
       vector<T>{2},
       primePowerFactor(2)
    );

    verifyVectorResult(
       vector<T>{2, 2, 3, 5, 5}, // 100 = 2 * 2 * 5 * 5
       primePowerFactor(300)
    );
    
}
