//Problem: Given an array of integers, return an array such that each element at index i of the output array is equal to the product of all the numbers in the input array except the one at i.
// Note: You must solve it without division and in O(n) time complexity.
// You can also solve it in O(1) space complexity if you do not consider the output array as extra space.
// Approach: We can solve this problem by calculating the prefix and suffix products for each element in the array. The prefix product is the product of all elements before the current element, and the suffix product is the product of all elements after the current element. The final result for each index can be obtained by multiplying the prefix and suffix products for that index.
// TC: O(n), SC: O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> product_except_self(vector<int>& nums){
    int n = nums.size();
    vector<int> res(n, 1);
    int prefix = 1;

    for(int i=0; i<n; i++){
        res[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for(int i = n-1; i>=0; i--){
        res[i] *= suffix;
        suffix *= nums[i];
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<int> result = product_except_self(nums);
    for(int i=0; i<n; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}