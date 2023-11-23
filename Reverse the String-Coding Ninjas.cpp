#include <bits/stdc++.h> 
//TC=O(n) SC=O(1)
string reverseString(string str)
{
	// Write your code here.
	int j=str.size()-1,i=0;
	while(i<j)
	{
		swap(str[i],str[j]);
		i++;
		j--;
	}
	return str;
}
