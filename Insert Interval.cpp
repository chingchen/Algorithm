/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
        	// Start typing your C/C++ solution below
        	// DO NOT write int main() function
		int size = intervals.size();
		int low ;
		bool lowFound = FindIndex(intervals,newInterval.start,low);
		int high;
		int  highFound = FindIndex(intervals,newInterval.end, high);
		if(low== high)
		{
			if(lowFound || highFound)
			{
				intervals[low].start = min(intervals[low].start,newInterval.start);
				intervals[low].end = max(intervals[low].end,newInterval.end);
			}
			else
			{
				intervals.insert(intervals.begin() + low, Interval(newInterval.start,newInterval.end));
			}
		}
		else
		{
			if(highFound)
			{
				intervals[high].start = min(intervals[low].start,newInterval.start);
				intervals.erase(intervals.begin() + low,intervals.begin() + high);
			}
			else
			{
				int newStart = min(intervals[low].start,newInterval.start);
				int newHigh = newInterval.end;
				intervals.insert(intervals.begin() + high,Interval(newStart,newHigh));
				intervals.erase(intervals.begin() + low, intervals.begin() + high);				
			}
				
		}
		return intervals;
		
	}
	bool FindIndex(vector<Interval> &intervals , int val, int & index)
	{
		int begin = 0, end = intervals.size() -1;
		while(begin <= end)
		{
			int mid = begin + (end - begin)/2;
			if(intervals[mid].end >= val && intervals[mid].start <= val)
			{
				index = mid;
				return true;
			}
			else if( val > intervals[mid].end)
				++begin;
			else
				--end;
		}
		index = begin;
		return false;	
	}
};