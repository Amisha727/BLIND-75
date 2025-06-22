// Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach
// Time Complexity: O(n^2), where n is the number of elements in the array
// Space Complexity: O(1), since we are not using any extra space except for the input array
vector<int> twoSum_Bruteforce(vector<int>& nums, int target){
    unordered_map<int, int>mpp;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {};
}

// Optimized Approach using Hash Map
// Time Complexity: O(n), where n is the number of elements in the array
// Space Complexity: O(n), since we are using a hash map to store the elements
vector<int> twoSum_HashMap(vector<int>& nums, int target){
    unordered_map<int, int>mpp;
    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        if(mpp.find(complement) != mpp.end()){
            return {mpp[complement], i};
        }
        mpp[nums[i]] = i;
    }
    return {};
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    vector<int> result;
    result = twoSum_Bruteforce(nums, target);
    vector<int> result2;
    result2 = twoSum_HashMap(nums, target);
    for(int index : result) {
        cout<<index<< " "<<endl;
    }
    for(int index1: result2){
        cout<<index1<<" "<<endl;
    }
    cout<<endl;
    return 0;
}