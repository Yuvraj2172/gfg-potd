//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
        if(n==1)return 1;
        int left(0), right(0), pivot(0);
        for(int i=1; i<n;i++)right += a[i];
        while(pivot < n-1 && left!=right){
            pivot++;
            right -= a[pivot];
            left += a[pivot-1];
        }
        return (left == right) ? (pivot+1) : -1;
    }
 
};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends