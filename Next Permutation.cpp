class Solution {
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int size = num.size();
		if( size == 0 || size == 1)
			return ;
		int biggest = num[size-1];
		int smallest = num[size-1];
		for( int i = size - 2; i >= 0; i -- )
		{
			if( num[i] >= biggest)
			{
				if( num[i] > biggest)
					biggest = num[i];
				if( num[i] < smallest)
					smallest = num[i];
				continue ;
			}
			else
			{
				sort(num.begin()+ i + 1,num.end());
				vector<int>::iterator upper = upper_bound(num.begin() + i + 1,num.end(),num[i]);
				swap(*(num.begin() + i),*upper);
				return ;
			}
		}
		sort(num.begin(),num.end());
		return ;
	}
};