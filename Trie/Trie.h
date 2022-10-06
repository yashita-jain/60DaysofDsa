#include <bits/stdc++.h>
using namespace std;
#include "TrieNode.h"

class Trie
{
TrieNode* root;
public:


  Trie()
{
root=new TrieNode('\0');
}

void insertWord(TrieNode* root,string word){

   //Base case
   if(word.size()==0){
    root->isTerminal=true;
    return;
   } 

   //Small calculation
   int index=word[0]-'a';
   TrieNode* child;
   if(root->children[index]!=NULL){
    child=root->children[index];
   }
   else{
    child=new TrieNode(word[0]);
    root->children[index]=child;
   }

   //Recursive call
   insertWord(child,word.substr(1));
}
   
//for User
void insertWord(string word){
    insertWord(root,word);
   }



bool searchWord(string word,TrieNode* root){

//Base case
if(word.size()==0){
   return root->isTerminal;
}

//Small calculation && recursive call
int index=word[0]-'a';
if(root->children[index]!=NULL){
TrieNode* child=root->children[index];
return searchWord(word.substr(1),child);}
else{
return false;
}
}


//for user
bool searchWord(string word){
return searchWord(word,root);
}

void removeWord(string word,TrieNode* root){

   //Base Case
if(word.size()==0){
   root->isTerminal=false;
   return;
}

//small calculation
int index=word[0]-'a';
TrieNode* child;
if(root->children[index]!=NULL){
child=root->children[index];
}
else{
   return;
}

removeWord(word.substr(),child);

//remove child node if it is useless
if(child->isTerminal==false){
   for(int i=0;i<26;i++){
     if(child->children[i]!=NULL){
     return;}
   }

   delete child;
   root->children[index]=NULL;
}

}

//for user
void removeWord(string word){
   removeWord(word,root);
}

};




