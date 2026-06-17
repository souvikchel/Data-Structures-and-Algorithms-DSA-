#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Node{
  public:
  unordered_map<char,Node*> children;
  bool endOfWord;
  int freq;

  Node(){
    endOfWord=false;
  }
};

class Trie{
  Node* root;

  public:
  Trie(){
    root=new Node();
    root->freq=-1;
  }


  void insert(string key){
    Node* temp=root;
    for(int i=0;i<key.size();i++ ){
      if(temp->children.count(key[i])==0){
        temp->children[key[i]]=new Node();
        temp->children[key[i]]->freq=1;


      }else{
        temp->children[key[i]]->freq++;
      }
      temp=temp->children[key[i]];
    }
    temp->endOfWord=true;
  }

  bool search(string key){
    Node* temp=root;
    for(int i=0;i<key.size();i++){
        if(temp->children.count(key[i])){
          temp=temp->children[key[i]];
        }else{
          return false;
        }
    }
    return temp->endOfWord;
  }

  bool startsWith(string prefix){
    Node* temp=root;
    for(int i=0;i<prefix.size();i++){
        if(temp->children.count(prefix[i])){
          temp=temp->children[prefix[i]];
        }else{
          return false;
        }
    }
    return true;;
  }

  string getPrefix(string key){
    Node* temp=root;
    string prefix="";
    for(int i=0;i<key.size();i++){
      prefix+=key[i];
      if(temp->children[key[i]]->freq==1){
        return prefix;
      }
      temp=temp->children[key[i]];
    }
    return prefix;
  }

  int countHelper(Node* root){
    int ans=0;

    for(pair<char,Node*> child: root->children){
      ans+=countHelper(child.second);
    }
    return ans+1;
  }

  int countNodes(){
    return countHelper(root);
  }

  void longestStringHelper(Node* root, string &ans, string temp){

    for(pair<char,Node*> child: root->children){
      if(child.second->endOfWord){
      temp+=child.first;

      if((temp.size()==ans.size() && temp< ans)|| (temp.size()>ans.size())){
        ans=temp;
      }
      longestStringHelper(child.second,ans,temp);
      temp=temp.substr(0,temp.size()-1);
    }
  }
  }


  string longestStringWithEOW(){
    string ans="";
    longestStringHelper(root,ans,"");
    return ans;
  }

};

bool helper(Trie &trie,string key){
  if(key.size()==0){
    return true;
  }

  for(int i=0;i<key.size();i++){
    string first=key.substr(0,i+1);
    string second=key.substr(i+1);

    if(trie.search(first) && helper(trie,second)){
      return true;
    }
  }
  return false;
}

bool WordBreak(vector<string> dict,string key){
  Trie trie;
  for(int i=0;i<dict.size();i++){
    trie.insert(dict[i]);
  }
  return helper(trie,key);

}

void prefixProb(vector<string> dict){
  Trie trie;
  for(int i=0;i<dict.size();i++){
    trie.insert(dict[i]);
  }
  for(int i=0;i<dict.size();i++){
    cout<<trie.getPrefix(dict[i])<<endl;
  }
}

int countUniqueSubstring(string str){
  Trie trie;
  for(int i=0;i<str.size();i++){
    string suffix=str.substr(i);
    trie.insert(suffix);

  }

  return trie.countNodes();
}

string longestString(vector<string> dict){
  Trie trie;

  for(int i=0;i<dict.size();i++){
    trie.insert(dict[i]);
  }

  return trie.longestStringWithEOW();
}



int main(){
  /*Trie trie;
  vector<string> words={"the","a","there","their","any","thee"};

  for(int i=0;i<words.size();i++){
    trie.insert(words[i]);
  }
  cout<<trie.search("any")<<endl;*/

  /*vector<string> dict={"i","like","sam","samsung","mobile","ice"};
  cout<<WordBreak(dict,"ilikesamsung")<<endl;*/

  /*vector<string> dict={"zebra","dog","duck","dove"};
  prefixProb(dict);*/

  vector<string> words={"apple","app","mango","man","woman"};

  Trie trie;
  for(int i=0;i<words.size();i++){
    trie.insert(words[i]);
  }

  cout<<trie.startsWith("app")<<endl;

  string str="ababa";

  cout<<countUniqueSubstring(str)<<endl;

  vector<string> dict={"a","banana","app","appl","ap","apply","apple"};
  cout<<longestString(dict)<<endl;


  return 0;
}
