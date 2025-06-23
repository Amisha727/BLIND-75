//Problem: Longest Consecutive Sequence
#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach- TC - O(n^2), SC- O(1)
int longestConsecutive_Brute(vector<int>& nums){
    int n = nums.size();
    int longest = 0;
    for(int i=0; i<n; i++){
        int curr = nums[i];
        int cnt = 1;
        while(find(nums.begin(), nums.end(), curr + 1) != nums.end()){
            curr += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

//Optimal Approach TC- O(1), SC- O(N)
int longestConsecutive_Optimal(vector<int>& nums){
    unordered_set<int> numset(nums.begin(), nums.end());
    int longest = 0;
    for(int num: nums){
        if(numset.find(num-1) == numset.end()){
            int curr = num;
            int cnt = 1;
            while(numset.find(curr + 1) != numset.end()){
                curr  += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<longestConsecutive_Brute(nums)<<endl;
    cout<<longestConsecutive_Optimal(nums)<<endl;
    return 0;
}