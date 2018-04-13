#include <iostream>
#include <string>
#include <algorithm>

class BigNumber {
    friend std::ostream& operator <<(std::ostream& os, const BigNumber& bn) {

        return os << bn._num;
    }
public:
    BigNumber() : _num("0") {
    }
    
    BigNumber(const std::string& s) : _num(s) {
    }

    BigNumber operator + (const BigNumber& rhs) const {
        short carry = 0;
        auto i1 = _num.rbegin();
        auto i2 = rhs._num.rbegin();
        std::string result;
        while (i1 != _num.rend() && i2 != rhs._num.rend()) {
            short cur = *i1 - '0' + *i2 - '0' + carry;
            short add = cur % 10;
            result += ('0' + add);
            carry = cur / 10;
            i1++;
            i2++;
        }
        
        while (i1 != _num.rend()) {
            short cur = *i1 - '0' + carry;
            short add = cur % 10;
            result += ('0' + add);
            carry = cur / 10;
            i1++;
        }
        
        while (i2 != rhs._num.rend()) {
            short cur = *i2 - '0' + carry;
            short add = cur % 10;
            result += ('0' + add);
             carry = cur / 10;
            i2++;
        }
        
        if (carry != 0) {
            result += ('0' + carry);
        }
        
        std::reverse(result.begin(), result.end());
        
        return BigNumber(result);
    }
    
    BigNumber& operator += (const BigNumber& rhs) {
        *this = *this + rhs;
        return *this;
    }
    
    BigNumber operator * (const BigNumber& rhs) const {
        BigNumber result;
        int numZero = 0;
        for(auto it1 = rhs._num.rbegin(); it1 != rhs._num.rend(); it1++) {
            short carry = 0;
            std::string curResult(numZero++, '0');
            for(auto it2 = _num.rbegin(); it2 != _num.rend(); it2++) {
                short cur = (*it1 - '0') * (*it2 - '0') + carry;
                short add = cur % 10;
                curResult += ('0' + add);
                carry = cur / 10;

            }
            
            if (carry > 0) {
                curResult += ('0' + carry);
            }
            
            std::reverse(curResult.begin(), curResult.end());
            
            result += BigNumber(curResult);
        }
        return result;
    }

private:
    std::string _num;
};
