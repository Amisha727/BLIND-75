#include<iostream>
using namespace std;
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // if LSB is 1, add 1 to count
        n >>= 1; // right shift to process the next bit 
    }
    return count;
} //TC: O(log n) for n bits, SC: O(1)

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of 1 bits in " << n << " is: " << countBits(n) << endl;
    return 0;
}

















/* ⚡ Optimized Approach: Brian Kernighan’s Algorithm
Each time n = n & (n - 1) removes the lowest set bit.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            n &= (n - 1); // drop the lowest set bit
            count++;
        }
        return count;
    }
};*/