//Problem: Given an array of strings strs, group the anagrams together. You can return the answer in any order.
#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach- TC(m*n*log(n)) & SC O(m*n)
vector<vector<string>> groupAnagram_Brute(vector<string>& strs){
    unordered_map<string, vector<string>> res;
    for(const auto&s : strs){
        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        res[sortedS].push_back(s);
    }
    vector<vector<string>> result;
    for(auto& pair : res){
        result.push_back(pair.second);
    }
    return result;
}


//Optimal Approach - TC O(m*n)  & SC- O(m*n)
vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> res;
    for(const auto& s: strs){
        vector<int> count(26, 0);
        for(char c:s){
            count[c - 'a']++;
        }
        string key = to_string(count[0]);
        for(int i=1; i<26; i++){
            key += ',' + to_string(count[i]);
        }
        res[key].push_back(s);
    }
    vector<vector<string>> result;
    for(const auto& pair: res){
        result.push_back(pair.second);
    }
    return result;
}


//Main Function and taking input from user
int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0; i<n; i++){
        cin>>strs[i];
    }

    vector<vector<string>> res = groupAnagram_Brute(strs);
    for(const auto& group : res){
        for(const string& word : group){
            cout<<word<<" ";
        }
        cout<<endl;
    }

    vector<vector<string>> result = groupAnagrams(strs);
    for(const auto& group : result){
        for(const string& word : group){
            cout<<word<<" ";
        }
        cout<<endl;
    }
    return 0;
}