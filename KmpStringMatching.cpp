#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

vector<int> kmpStringMatching(const string& s, const string& p) {
    vector<int> result;
    
    int n = s.size();
    int m = p.size();

    vector<int> stop(m+1);
    
    int i = 0;
    int j = -1;
    stop[0] = -1;
    while (i < m) {
        while(j >= 0 && p[i] != p[j]) {
            j = stop[j];
        }
        ++i;
        ++j;
        stop[i] = j;
    }
    
    i = 0;
    j = 0;
    
    while (i < n) {
        while (j >= 0 && s[i] != p[j]) {
            j = stop[j];
        }
        ++i;
        ++j;
        
        if (j == m) {
            result.push_back(i-m);
            j = stop[j];
        }
    }
    return result;
}

int main() {
    
    vector<int> res = kmpStringMatching("aaababbab", "ab");

    assert(res.size() == 3);
    assert(res[0] == 2);
    assert(res[1] == 4);
    assert(res[2] == 7);

    res = kmpStringMatching("abababababa", "aba");

    assert(res.size() == 5);
    assert(res[0] == 0);
    assert(res[1] == 2);
    assert(res[2] == 4);
    assert(res[3] == 6);
    assert(res[4] == 8);


    res = kmpStringMatching("abababababa", "c");

    assert(res.size() == 0);

    res = kmpStringMatching("abcdefg", "abcdefg");

    assert(res.size() == 1);
    assert(res[0] == 0);

    return 0;
}
