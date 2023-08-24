#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    /* data */
public:
    std::vector<std::vector<int> > merge(std::vector<std::vector<int> >& intervals){
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        if(n==1){
            return intervals;
        }
        vector<vector<int> > vec;
        vec.push_back(intervals[0]);
        int j=0;
        for(int i=j+1;i<n;i++){
            if(intervals[i][0]<=vec[j][1]){
                vec[j][1]=max(vec[j][1],intervals[i][1]);
            }else{
                vec.push_back(intervals[i]);
                j++;
            }
     
        }
    return vec;
    }
};


