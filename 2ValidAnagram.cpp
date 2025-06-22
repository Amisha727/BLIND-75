// Problem: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#include <bits/stdc++.h>
using namespace std;
//for boolean we can use boolalpa

//Bruteforce approach
// Time Complexity: O(n log n), where n is the length of the strings (due to sorting)
// Space Complexity: O(1), since we are not using any extra space except for the input strings
bool isAnagram(string s, string t){
    if(s.length() != t.length()) return false; // If lengths differ, they cannot be anagrams
    //sort them
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t; // Compare sorted strings
}

// Optimized approach using Hashing
// Time Complexity: O(n), where n is the length of the strings
// Space Complexity: O(1), since we are using a fixed-size array for counting characters
bool isAnagram_Hash(string s, string t) {
    if(s.length() != t.length()) return false; // If lengths differ, they cannot be anagrams
    vector<int> count(26, 0); // Assuming only lowercase letters a-z
    for(char c : s) {
        count[c - 'a']++; // Increment count for character in s
    }
    for(char c : t) {
        count[c - 'a']--; // Decrement count for character in t
        if(count[c - 'a'] < 0) return false; // If count goes negative, t has more of that character than s
    }
    return true; // If all counts are zero, they are anagrams
}



//main function
int main() {
    string s, t;
    cin >> s;
    cin >> t;

   cout<< boolalpha<< isAnagram(s, t) << endl; // Output true or false based on whether s and t are anagrams
    cout<< boolalpha<< isAnagram_Hash(s, t) << endl; // Output true or false based on whether s and t are anagrams using hashing
    return 0;
}