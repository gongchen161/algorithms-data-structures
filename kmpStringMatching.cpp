#include <iostream>
#include <vector>
#include <string>

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
    
    
    string s;
    string p;
    
    getline(cin, s);
    getline(cin, p);

    
    vector<int> res = kmpStringMatching(s,p);
    
    cout << "KMP search result : ";
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it <<" ";
    }
    cout << endl;
    
    return 0;
}
