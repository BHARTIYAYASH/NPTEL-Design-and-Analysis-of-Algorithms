#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> marks(n);
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }
    
    vector<vector<int>> best(n + 1, vector<int>(k + 1, INT_MIN));
    vector<vector<int>> curr(n + 1, vector<int>(k + 1, 0));
    
    int result = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0) {
                best[i][j] = marks[i];
                curr[i][j] = marks[i];
                continue;
            }
            
            if (j == 0) {
                curr[i][j] = max(curr[i-1][j] + marks[i], marks[i]);
                best[i][j] = max(best[i-1][j], curr[i][j]);
                continue;
            }
            
            curr[i][j] = max({
                curr[i-1][j] + marks[i],
                curr[i-1][j-1],
                marks[i]
            });
            
            best[i][j] = max(best[i-1][j], curr[i][j]);
        }
    }
    
    for (int j = 0; j <= k; j++) {
        result = max(result, best[n-1][j]);
    }
    
    cout << result << endl;
    return 0;
}