#include <bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map <string ,int> myMap;
pair<string,int> p("abc",1);
myMap.insert(p);
myMap["ghi"]=2;
cout<<myMap["abc"]<<endl;
myMap["abc"]=80;
cout<<myMap["abc"]<<endl;

cout<<myMap.at("ghi")<<endl;
myMap.erase("ghi");
cout<<myMap["ghi"]<<endl;

cout<<myMap.count("abc")<<endl;
return 0;
}