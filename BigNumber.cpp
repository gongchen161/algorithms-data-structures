#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>


// For adding and multiplying unsigned numbers that are bigger than ULLONG_MAX (2^64)
class BigNumber {
    // print a big number
    friend std::ostream& operator <<(std::ostream& os, const BigNumber& bn) {
        return os << bn.num_;
    }
public:
    BigNumber() : num_("0") {
    }
    
    BigNumber(const std::string& s) : num_(s) {
        num_.erase(0, num_.find_first_not_of('0'));
        if (num_.empty()) {
            num_ = "0";
        }
    }

    BigNumber operator + (const BigNumber& rhs) const {
        short carry = 0;
        auto i1 = num_.rbegin();
        auto i2 = rhs.num_.rbegin();
        std::string result;
        while (i1 != num_.rend() && i2 != rhs.num_.rend()) {
            short cur = *i1 - '0' + *i2 - '0' + carry;
            short add = cur % 10;
            result += ('0' + add);
            carry = cur / 10;
            i1++;
            i2++;
        }
        
        while (i1 != num_.rend()) {
            short cur = *i1 - '0' + carry;
            short add = cur % 10;
            result += ('0' + add);
            carry = cur / 10;
            i1++;
        }
        
        while (i2 != rhs.num_.rend()) {
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
        for(auto it1 = rhs.num_.rbegin(); it1 != rhs.num_.rend(); it1++) {
            short carry = 0;
            std::string curResult(numZero++, '0');
            for(auto it2 = num_.rbegin(); it2 != num_.rend(); it2++) {
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

    std::string toString() {
        return num_;
    }

private:
    std::string num_;
};


int main() {
    BigNumber a;
    BigNumber b("18");
    assert( (a + b).toString() == "18");
    assert( (a * b).toString() == "0");
    
    BigNumber c("89");
    assert( (b + c).toString() == "107");
    assert( (c * b).toString() == "1602");
    

    BigNumber d("999999999999999999999999999999");
    BigNumber e("1234567890987654321");
    assert( (d + e).toString() == "1000000000001234567890987654320");
    assert( (d * e).toString() == "1234567890987654320999999999998765432109012345679");

  
}