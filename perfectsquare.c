// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends





class Solution{   
public:
    int checkPerfectSquare(int N){
    
    int num = N,  flag = 0;
 
    for (int i = 1; i <= num; i++) 
    {
        if ( i * i == num) {
            flag = 1;
            break;
        }
        if ( i * i > num) {
        break;
        }
    }
    
    if (flag == 1)
        return 1;
    else
        return 0;
   
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkPerfectSquare(N) << endl;
    }
    return 0; 
}   // } Driver Code Ends
