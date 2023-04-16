
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//Q:6,2,5,4,5,1,6
//A:12
int main()
{
    vector<int>a={6,2,5,4,5,1,6};
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
    cout<<"The max area under the given histogram is: "<<ans<<endl;
    
    
        
    return 0;
}
