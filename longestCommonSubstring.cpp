#include <iostream>
#include <string>

using namespace std;

string longestCommonSubstring(const string& s1, const string& s2) {
        
	int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        
        int maxLength = 0;
        int startIndex = 0;
        for(int i = 0; i<n; i++) {
            if (s1[i] == s2[0]) {
                dp[i][0] = 1;
                maxLength = 1;
                startIndex = i;
            }
        }
        
        for(int i = 0; i<m; i++) {
            if (s1[0] == s2[i]) {
                dp[0][i] = 1;
                maxLength = 1;
                startIndex = i;
            }
        }
        
        for (int i = 1; i<n; i++) {
            for (int j = 1; j <m; j++) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                    
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        startIndex = i + 1 - maxLength;
                    }
                } 
            }
        }
        return s1.substr(startIndex, maxLength);
}
