#include<bits/stdc++.h>
using std::string,std::stringstream;
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string tmp;
        s.clear();
        while(ss>>tmp){
            std::reverse(tmp.begin(),tmp.end());
            s+=(tmp+" ");
        }
        return s.substr(0,s.length()-1);
    }
};