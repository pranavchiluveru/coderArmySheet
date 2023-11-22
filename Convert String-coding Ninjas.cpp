#include <bits/stdc++.h> 
//Tc=O(n) SC=O(1)
string convertString(string str) 
{
	// WRITE YOUR CODE HERE
	int n=str.size();
	str[0] = toupper(str[0]);
	int f=0;
	for(int i=1;i<n;i++)
	{
        if (f == 1) 
		    {
            str[i] = toupper(str[i]);
            f = 0;
        }
        if(str[i]==' ')
			    f=1;
		
	}
	return str;
}
