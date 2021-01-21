#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q, size, value, row, index;
    
    cin >> n >> q;
    
    vector <vector<int>> nQuery;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> size;
        
        vector<int> iQuery;
        
        for (int j = 0; j < size; ++j)
        {
            cin >> value;
            iQuery.push_back(value);
        }
        nQuery.push_back(iQuery);
    }
    
    for (int k = 0; k < q; ++k)
    {
        cin >> row >> index;
        cout << nQuery[row][index] << endl;
    }
    return 0;
}
