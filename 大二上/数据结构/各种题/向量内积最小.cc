#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
auto multiple(vector<int> &a,vector<int> &b){
    vector<int> ans;
    // ans.resize(a.size());
    for(int i=0;i<a.size();i++){
        ans.push_back(a[i]*b[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        a.push_back(h);
    }
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        b.push_back(h);
    }
    sort(a.begin(),a.end(),[](int aa,int ab){
        return aa>ab;
    });
    sort(b.begin(),b.end(),[](int t,int m){
        return t<m;
    });
    auto ans=multiple(a,b);
    int sum=accumulate(ans.begin(),ans.end(),0);
    cout<<sum;
}