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
            
            std::cout <<result <<" " << cur << std::endl;
        }
        
        while (i1 != _num.rend()) {
            std::cout <<result << std::endl;
            short cur = *i1 - '0' + carry;
            short add = cur % 10;
            result += ('0' + add);
            carry = cur / 10;
            i1++;
        }
        
        while (i2 != rhs._num.rend()) {
            std::cout <<result << std::endl;
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

private:
    std::string _num;
};

int main() {
    
    BigNumber b1("9999");
    BigNumber b2("1111");
    
    std::cout << b1 + b2 << std::endl;
    
}
