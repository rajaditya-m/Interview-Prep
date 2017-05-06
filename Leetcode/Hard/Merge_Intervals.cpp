/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

static bool customComparator(const Interval &i1, const Interval &i2)
{
	return (i1.start<i2.start);
}

std::vector<Interval> merge(std::vector<Interval> &intervals)
{
    std::vector<Interval> result;
    if(intervals.size()==0)
        return result;    
	std::sort(intervals.begin(),intervals.end(),customComparator);
	int i=0;
	int j=1;
	int rstart = intervals[0].start;
	int rend = intervals[0].end;
	int n = intervals.size();
	while(i<n && j<n)
	{
		//Two intervals are [rstart,rend] and [interval[j].start,interval[j].end]
		//Check for overlap
		if((intervals[j].start <= rend) && (rstart <= intervals[j].end))
		{
			rend = std::max(rend,intervals[j].end);
			rstart = std::min(rstart,intervals[j].start);
			j++;
		}
		else
		{
			result.push_back(Interval(rstart,rend));
			rstart = intervals[j].start;
			rend = intervals[j].end;
			i = j;
			j++;
		}
	}
	result.push_back(Interval(rstart,rend));
	return result;
}
};