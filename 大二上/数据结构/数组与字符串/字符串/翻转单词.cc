#include<bits/stdc++.h>
using std::stringstream;
using std::string;
using std::list;
class Solution{
    public:
    string reverseWords(string s) {
        stringstream ss(s);
        list<string> vs;
        string tmp;
        while(ss>>tmp){
            vs.push_front(tmp);
        }
        s.clear();
        for(auto i:vs){
            s+=(i+" ");
        }
        return s.substr(0,s.size()-1);
    }
};