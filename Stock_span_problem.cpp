
Q:100,80,60,70,60,75,85
A: 1, 1,1, 2, 1, 4, 6


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 vector<int>v={100,80,60,70,60,75,85};
 vector<int>ans;
 stack<int>s;
 int k;
 int n=v.size();
 for(int i=0;i<n;i++){
     if(s.size()==0)
     ans.push_back(1);
     else
     { if(v[s.top()]<=v[i]){
             while(s.size()>0&&v[s.top()]<=v[i]){
                 s.pop();
             }
     }
             if(s.size()==0)
             ans.push_back(i+1);
             else{
                 k=i-s.top();
                 ans.push_back(k);
             }
         }
         s.push(i);
 }

     for(auto it:ans)
     cout<<it<<" ";
 
    return 0;
}
