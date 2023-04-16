//Binary matrix:   0 1 1 0
//                 1 1 1 1
//                 1 1 1 1
//                 1 1 0 0

//Ans:8 (considering the area between r2 & r3)

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int MAH(vector<int> a){
    vector<int>nsr;
    vector<int>nsl;
    vector<int>width;
    int diff;
    stack<int>s1;
    stack<int>s2;
    int n=a.size();
    int ans=INT_MIN;
    
    
    //TO find nearest smaller to left(nsl) 
    for(int i=0;i<n;i++){
        if(s1.size()==0)
        {
            s1.push(-1);
            nsl.push_back(-1);
        }
        else{
            if(a[s1.top()]>=a[i]){
                while(a[s1.top()]>=a[i]&&s1.size()>1)
                s1.pop();
            }
            nsl.push_back(s1.top());
        }
        s1.push(i);
    }
    //now nsl contains left boundary for all the elements
    
    
    //To find nsr 
    for(int i=n-1;i>=0;i--){
        if(s2.size()==0){
            nsr.push_back(n);
            s2.push(n);
        }
        else{
            if(a[s2.top()]>=a[i]){
                while(s2.size()>1&&a[s2.top()]>=a[i])
                s2.pop();
            }
            nsr.push_back(s2.top());
        }
        s2.push(i);
    }
    reverse(nsr.begin(),nsr.end());
    
    
    //To find the width array
    for(int j=0;j<n;j++){
        diff=(nsr[j]-nsl[j])-1;
        width.push_back(diff);
    }
   
    //To find the max area
    for(int i=0;i<n;i++){
        ans=max(ans,(width[i]*a[i]));
    }
    return ans;
}
int main()
{
    int mx=INT_MIN;
    vector<int>v;
    vector<vector<int>>a={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    for(int j=0;j<4;j++){
        v.push_back(a[0][j]);
    }
     mx=max(mx,MAH(v));
    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]==0)
            v[j]=0;
            else
            v[j]=v[j]+a[i][j];
        }
        mx=max(mx,MAH(v));
    }
    cout<<mx;
    return 0;
}
