/*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
    
    map<string ,map<string,int> > mem;
    
public:
    int minDistance(string word1, string word2) 
    {
        if(word1.length() == 0)
            return word2.length();
        if(word2.length() == 0)
            return word1.length();
            
        mem.clear();
        
        return minDis(word1, word2);
    }

    int minDis(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( mem.find(word1) != mem.end() && mem[word1].find(word2) != mem[word1].end())
        {
            return  mem[word1][word2];
        }
        
        int ret = 0;
        if(word1.length() == 0)
        {
            ret = word2.length();
            mem[word1][word2] = ret;
            return ret;
        }
            
        int i = 0;
        while( i < word1.length() && i < word2.length())
        {
            if(word1[i] != word2[i])
            {
                break;
            }
            i++;
        }
        
        if( i == word2.length())
        {
            ret =word1.substr(i).length();
             mem[word1][word2] = ret;
            return ret;            
        }

        if( i == word1.length())
        {
            ret =  word2.substr(i).length();
             mem[word1][word2] = ret;
            return ret;            
        }
        
        int insert = minDis(word1.substr(i), word2.substr(i+1)) + 1;
        int deleted = minDis(word1.substr(i+1), word2.substr(i)) + 1;
        int replaced = minDis(word1.substr(i+1), word2.substr(i+1)) + 1;
        
        ret = min(insert,min(deleted,replaced));
         mem[word1][word2] = ret;
        return ret;
    }
};