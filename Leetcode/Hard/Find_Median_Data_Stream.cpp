#include <queue>
#include <functional>

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
			int minSize = minHeap_.size();
			if(minSize==0)
			{
				minHeap_.push(num);
				return;
			}
			else
			{
				int minTop = minHeap_.top();
				if(num>minTop)
				{
				  minHeap_.push(num);
				}
				else
				{
					maxHeap_.push(num);
				}
			}

			int maxSize = maxHeap_.size();
			minSize = minHeap_.size();

			if(minSize-maxSize>1)
			{
				int minTop = minHeap_.top();
				minHeap_.pop();
				maxHeap_.push(minTop);
			}
			else if(maxSize-minSize>0)
			{
				int maxTop = maxHeap_.top();
				maxHeap_.pop();
				minHeap_.push(maxTop);
			}
			
    }

    // Returns the median of current data stream
    double findMedian() {
        int maxSize = maxHeap_.size();
				int minSize = minHeap_.size();
				if(maxSize==minSize)
				{
					int maxTop = maxHeap_.top();
					int minTop = minHeap_.top();
					double r = 0.5f * (maxTop + minTop);
					return r;
				}
				else
				{
					return minHeap_.top();
				}
    }

private:
	std::priority_queue<int> maxHeap_;
	std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap_;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();