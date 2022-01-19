//
//  main.cpp
//  AllSubsets
//
//  Created by Saddam on 1/19/22.

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int>subSet;
    
    void findSubset(vector<int>& nums,int indx){
       
        for(int i=0;i<subSet.size();i++)  cout<<subSet[i]<<" ";
        cout<<endl;
        
        if(indx>=nums.size()){
          
            return;
        }
        for(int i=indx;i<nums.size();i++){
            
            subSet.push_back(nums[i]);
            ans.push_back(subSet);
            findSubset(nums,i+1);
            subSet.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        findSubset(nums, 0);
        return ans;
    }
};
int main(){
    
    vector<int>vec={1,2,3,4};
    Solution ob;
    ob.subsets(vec);
    
}
