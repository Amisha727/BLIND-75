// Problem: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

//Bruteforce approach
// Time Complexity: O(n^2), where n is the number of elements in the array
// Space Complexity: O(1), no extra space used
bool containsDuplicate(vector<int>& nums){
    if(nums.size() < 2) return false; // If the array has less than 2 elements, no duplicates can exist
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] == nums[j]){
                return true;
            }
        }
    }
    return false;
}

// Optimized approach using Hashing
// Time Complexity: O(n), where n is the number of elements in the array
// Space Complexity: O(n), where n is the number of unique elements in the array
bool containsDuplicate_Hash(vector<int>& nums){
    unordered_map<int, int>mpp;
    for(int i=0; i<nums.size(); i++){
        if(mpp.find(nums[i]) != mpp.end()){
            return true;
        }
        mpp[nums[i]] = 1; // Store the element in the hash map
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<( containsDuplicate(nums) ? "true" : "false")<<endl;
    cout<<( containsDuplicate_Hash(nums) ? "true" : "false")<<endl;
    return 0;
}
