//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> addOne(int a[], int n) {
        vector<int> v(n);
        int carry = 1;
        for(int i= n-1; i>=0; i--){
            int x = a[i] + carry;
            if(x<10){
                carry =0;
            }
            v[i] = x%10;
        }
        if(carry == 0)return v;
        vector<int> v1(n+1,1);
        for(int i=0; i<n;i++){
            v1[i+1] =v[i];
        }
        return v1;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.addOne(a, n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends