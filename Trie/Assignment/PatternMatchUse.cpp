#include <bits/stdc++.h>
#include "PatternMatchin.h"
using namespace std;

int main()
{
    int n;
cin>>n;
    PatternMatchin T;
    vector<string>v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        T.insertWord(s);
        v.push_back(s);
    }
    // string s;
    // cout << "Insert Pattern" << endl;
    // cin >> s;
    // cout << T.searchPattern(s) << endl;
bool x;


for(int i=0;i<n;i++){
    x=T.searchPalindromeWord(v[i]);
if(x==true){
    
    break;
}
}
cout<<x<<endl;

    
    return 0;
}