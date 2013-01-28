struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( intervals.size() == 0 || intervals.size() == 1)
			return intervals;
		sort(intervals.begin(),intervals.end(),Compare);
		list<Interval> lIntervals(intervals.begin(),intervals.end());
		int len = intervals.size();
		list<Interval>::iterator it = lIntervals.begin() ;
		list<Interval>::iterator pre = lIntervals.begin() ;
		for( ++it ; it != lIntervals.end() ;  )
		{
			if( it->start <= pre->end)
			{
				if(it->end > pre->end)
					pre->end = it->end;
				it = lIntervals.erase(it);
			}
			else
			{
				pre = it;
				it++;
			}
		}
		intervals.clear();
		for(list<Interval>::iterator it = lIntervals.begin() ; it != lIntervals.end() ; it++)
		{
			intervals.push_back(*it);
		}
		return intervals;
	}

private:
	static bool Compare(Interval a, Interval b)
	{
		return a.start < b.start;
	}
};