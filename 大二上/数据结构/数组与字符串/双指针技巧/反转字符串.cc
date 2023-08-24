#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;
        while(l<=r){
            std::swap(s[l],s[r]);
            l++,r--;
        }
    }
};