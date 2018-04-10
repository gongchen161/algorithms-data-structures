#include <iostream>
#include <string>

using namespace std;

string LongestPalindrome(const string& s) {
        
    int maxLength = 1;
    int startIndex = 0;
    for(int i = 0; i<s.size(); i++) {
        int l1 = findLength(s, i, i);
        int l2 = findLength(s, i, i+1);       
        int m = max(l1, l2);
        
        if (m > maxLength) {
            maxLength = m;
            startIndex = i- (m-1)/2;
        }    
    }
    
    return s.substr(startIndex, maxLength);
    
}

int findLength(const string& s, int left, int right) {
    
    while (left >= 0 && right < s.size() && s[left]==s[right]){
        left--; 
        right++;
    }
    
    return right -left - 1;
}
