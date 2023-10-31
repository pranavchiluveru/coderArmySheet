#include<bits/stdc++.h>
//TC =O(n*n) SC=O(n*n)
int LongestPalindromicSubsequence(int len,string &str)
{
	
	string t=str;
	reverse(t.begin(),t.end());
	vector<vector<int>> dp(len+1,vector<int>(len+1,0));
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(str[i-1]==t[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len][len];
}
int minimumInsertions(string &str)
{
	// Write your code here.
	int len=str.size();
	//Logic: we find LongestPalindromicSubsequence we keep that part intact and we need to add remaining characters to make it palindrome
	//ex: accba-in this LPS=acca i.e 4 length we keep it as it is we need to add one character b i.e(5-4) to make it abccba palindrome
  //Note : for any  string  to make it a palindrome  we do string+reverse(string) ->at max we need to add len(string) no. of characters 
	int x=LongestPalindromicSubsequence(len,str);
	return len-x;
}
