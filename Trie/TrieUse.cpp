#include <bits/stdc++.h>
#include"Trie.h"
using namespace std;

int main()
{Trie T;
T.insertWord("abc");
T.insertWord("def");
T.insertWord("xyz");
T.insertWord("qqq");

cout<<T.searchWord("abc")<<endl;
cout<<T.searchWord("qqqe")<<endl;

T.removeWord("abc");
cout<<T.searchWord("abc")<<endl;

return 0;
}