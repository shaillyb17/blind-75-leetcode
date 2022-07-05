// Non-graph approach implemented

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    set<long> numSet;
    for(long x: nums)
        numSet.insert(x);
    long maxLen = 0;
    for(long x: nums) {
        if(numSet.find(x - 1) == numSet.end()) {
            long length = 0;
            while(numSet.find(x + length) != numSet.end())
                length++;
            maxLen = max(length, maxLen);
        }
    }
    return maxLen;
}

int main(){
    // initialisation of graph is not implemented
    // only functions defined as required on leetcode
    
    return 0;
}