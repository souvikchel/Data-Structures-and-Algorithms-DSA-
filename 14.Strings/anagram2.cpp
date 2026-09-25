#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;


bool isAnagram(string str1,string str2){
  if(str1.length()!=str2.length()){
    return false;
  }
  vector<int> freq(26,0);
  
  for(int i=0;i<str1.length();i++){
    char ch=str1[i];
    int idx=ch-'a';
    freq[idx]++;
  }
  for(int j=0;j<str2.length();j++){
    char ch=str2[j];
    if(freq[ch]==0){
      freq[ch]++;
    }
    freq[ch]--;

}
cout<<"Valid anagram";
return true;
}



int main(){
    string str1="anagram";
    string str2="nagaram";
    isAnagram(str1,str2);
    return 0;
}