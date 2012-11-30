/*
You have a room-full of balances and weights. Each balance weighs ten pounds and is
considered perfectly balanced when the sum of weights on its left and right sides are
exactly the same. You have placed some weights on some of the balances, and you have placed
some of the balances on other balances. Given a description of how the balances are arranged
and how much additional weight is on each balance, determine how to add weight to the balances
so that they are all perfectly balanced.

There may be more than one way to balance everything, but always choose the way that places additional weight on the lowest balances.

The input file will begin with a single integer, N, specifying how many balances there are.
Balance 0 is specified by lines 1 and 2, balance 1 is specified by lines 3 and 4, etc…
Each pair of lines is formatted as follows:
WL
WR

WL and WR indicate the weight added to the left and right sides, respectively.
is a space-delimited list of the other balance that are on that side of this balance.
may contain zero or more elements.

Consider the following input:

4
0 1
0 2
0
0 3
3
0
0
0

Balance 0 has balance 1 on its left side and balance 2 on its right side
Balance 1 has balance 3 on its right side
Balance 2 has three pounds on its left side
Balance 3 has nothing on it

Since balance 3 has nothing on it it is already perfectly balanced, and weighs a total of 10 pounds.
Balance 2 has no other balance on it, so all we need to do is balance it by putting three pounds on its right side. Now it weighs a total of 16 pounds.
Balance 1 has balance three on its right side, which weighs 10 pounds, so we just put 10 pounds on its left side. Balance 1 weighs a total of 30 pounds.
Balance 0 has balance 1 on its left side (30 pounds), and balance 2 on its right side (16 pounds), we can balance it by adding 14 pounds to the right side.

The output should be N lines long, with the nth line listing the weight added to the nth balance, formatted as follows:

:

So the output for this problem would be:

0: 0 14
1: 10 0
2: 0 3
3: 0 0
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


#define BalanceWeight 10

enum  Side { Unproceeded,Left, Right , NoNeed};

struct TreeNode
{
public:
	TreeNode():isRoot(true),side(Unproceeded){}
	int id;
	int TwoSidesWeight()
	{
		if(side == Unproceeded)
			return -1;
		else
		{
			if(side == NoNeed)
				return 0;
			if( side == Left)
				return 2* rightWeight;
			if( side == Right)
				return 2* leftWeight;
		}
	}
	bool isRoot;
	int toAdd;
	Side side;
	int leftWeight, rightWeight;
	vector<TreeNode*> leftNodes ,rightNodes ;
};


int GetWeight( TreeNode * root)
{
	if( root == NULL)
		return 0;
	if( root->side != Unproceeded)
		return root->TwoSidesWeight();

	int balanceWeight= BalanceWeight;
	int leftWeights = root->leftWeight;
	for( int i = 0; i < (root->leftNodes).size(); i++)
	{
		leftWeights += BalanceWeight;
		leftWeights += GetWeight((root->leftNodes)[i]);
	}
	int rightWeights = root->rightWeight;
	for(int i = 0 ; i< (root->rightNodes).size();i++)
	{
		rightWeights += BalanceWeight;
		rightWeights += GetWeight((root->rightNodes)[i]);
	}

	if(leftWeights == rightWeights)
	{
		root->side = NoNeed;
		return leftWeights + rightWeights;
	}
	int toAdd = 0;
	if(leftWeights < rightWeights)
	{
		toAdd = rightWeights-leftWeights;
		root->side = Left;
		root->toAdd = toAdd;
		return 2* rightWeights;
	}
	else
	{
		toAdd = leftWeights - rightWeights;
		root->side = Right;
		root->toAdd = toAdd;
		return 2* leftWeights;
	}
}

void BuildTree(vector<TreeNode*> & input)
{
	int numNodes ;
	cin >> numNodes;
	for(int i = 0 ; i< numNodes ; i++)
	{
		input.push_back( new TreeNode());
	}

	string line;
	getline(cin, line);
	for( int i = 0 ; i < numNodes ;i++)
	{
		vector<string>  leftVector;
		string temp;
		getline(cin,line);
		string::size_type pos;
		string::size_type begin=0;
		
		
		string tempString = "";
		for( int k =0 ; k < line.size(); k++)
		{		
			if(line[k] != ' ')
			{
				tempString += line[k];
				if( k == line.size()-1)
					leftVector.push_back(tempString);
			}
			else
			{
				leftVector.push_back(tempString);
				tempString ="";
			}
		}

		getline(cin,line);
		tempString = "";
		vector<string>  rightVector;
		for( int k =0 ; k < line.size(); k++)
		{		
			if(line[k] !=' ')
			{
				tempString += line[k];
				if( k == line.size()-1)
					rightVector.push_back(tempString);
			}
			else
			{
				rightVector.push_back(tempString);
				tempString ="";
			}
		}

		input[i]->id = i;

		input[i]->leftWeight = atoi(leftVector[0].c_str());
		for(int j = 1; j< leftVector.size(); j++)
		{
			int child = atoi(leftVector[j].c_str());
			input[i]->leftNodes.push_back(input[child]);
			input[child]->isRoot = false;
		}

		input[i]->rightWeight = atoi(rightVector[0].c_str());
		for( int j = 1; j <rightVector.size(); j++)
		{
			int child = atoi(rightVector[j].c_str());
			input[i]->rightNodes.push_back(input[child]);
			input[child]->isRoot = false;
		}
	}
}

void Print(const vector<TreeNode*> & input)
{
	for(int i =0 ; i < input.size() ; i++)
	{
		cout << i <<": ";
		if(input[i]->side == NoNeed)
		{
			cout << "0 0";
		}
		
		if(input[i]->side == Left)
		{
			cout<< input[i]->toAdd <<" 0";
		}
		
		if( input[i]->side == Right)
		{
			cout << "0 " << input[i]->toAdd;
		}
		cout<< endl;
	}
}

void main()
{
	freopen("debug\\in.txt","r",stdin); 

	vector<TreeNode*> input;
	BuildTree(input);
	for(int i = 0; i < input.size(); i++)
	{
		if( input[i]->isRoot)
			GetWeight(input[i]);
	}
	Print(input);

	for(int i =0 ;i< input.size(); i++)
		delete input[i];
}