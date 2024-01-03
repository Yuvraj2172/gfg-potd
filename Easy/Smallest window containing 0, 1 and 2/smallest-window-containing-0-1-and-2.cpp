//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int zero = -1, one = -1, two = -1;
        int len = INT_MAX;
        for(int i=0; i<s.size(); i++){
            char temp = s[i];
            if(temp == '0')zero = i;
            else if(temp == '1')one = i;
            else if(temp == '2')two = i;
            if(zero!= -1 && one != -1 && two != -1){
                mini = min(zero, min(one,two));
                maxi = max(zero, max(one, two));
                len = min(len, maxi - mini +1);
            }
        }
        return len == INT_MAX ? -1 : len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends