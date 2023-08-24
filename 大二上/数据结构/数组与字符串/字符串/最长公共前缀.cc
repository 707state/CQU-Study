#include<bits/stdc++.h>
using std::vector;
using std::string;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        auto min_=(*std::min_element(strs.begin(),strs.end())).length();
        int index_=0;
        for(index_=0;index_<min_;index_++){
            bool flag=1;
            char c=strs[0][index_];
            for(int i=1;i<strs.size();i++){
                if(strs[i][index_]!=c){
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
        }
        return strs[0].substr(0,index_);
    }
};