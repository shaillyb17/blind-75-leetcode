#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
    
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        // inserting the data
        if(maxheap.empty() || maxheap.top() > num)
            maxheap.push(num);
        else
            minheap.push(num);
        
        
        // balance the trees
        if(maxheap.size() > minheap.size() + 1) { // we inserted item to maxheap
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size() < minheap.size()) { // we inserted item to minheap
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.empty()) return 0;
        if(maxheap.size() == minheap.size())    return ((maxheap.top() + minheap.top()) / 2.0); // even
        return maxheap.top(); // odd
    }
};

int main(){
    int n;	cin >> n;
    
    return 0;
} 