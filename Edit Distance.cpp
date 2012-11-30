/*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		minSteps = -1;
		return minDis(word1,word2,0);
	}

private:
	map<string ,map<string,int> > record;
	unsigned int minSteps;
private:
	void FillRecord(string& orgWord, string & desWord,int value)
	{
		if(record.find(desWord) == record.end())
		{
			map<string,int> m;
			m[orgWord] = value;
			record[desWord] = m;
		}
		else
			record[desWord][orgWord]= value;
	}

	int minDis(string & orgWord,string & desWord ,int step)
	{
		int ret;

		if(record.find(desWord) != record.end() && record[desWord].find(orgWord) != record[desWord].end())
			return record[desWord][orgWord];

		if(orgWord.size() == 0 && desWord.size() == 0)
		{
			if(minSteps > step)
				minSteps = step;
		}
		if(orgWord.size() == 0)
		{
			ret = desWord.size();
			FillRecord(orgWord,desWord,ret);
			return ret	;
		}
		if(desWord.size() == 0)
		{
			ret = orgWord.size();
			FillRecord(orgWord,desWord,ret);
			return ret;
		}

		if( step > minSteps)
			return 1;

		string orgWordSub = orgWord.size()==1?string(""): orgWord.substr(1);
		string desWordSub = desWord.size()==1?string(""): desWord.substr(1);

		if(orgWord[0] == desWord[0])
		{
			int doNoneSetps = minDis( orgWordSub,desWordSub,step); 
			ret =doNoneSetps;
			FillRecord(orgWord,desWord,ret);
			return ret;
		}
		else
		{
			int addSteps = minDis(orgWord,desWordSub,step+1) + 1;
			int delSteps = minDis(orgWordSub,desWord,step+1) + 1;
			int replaceSteps = minDis( orgWordSub,desWordSub,step+1) + 1; 
			ret = min(min(delSteps,addSteps),replaceSteps);
			FillRecord(orgWord,desWord,ret);		
			return ret;
		}
	}
};