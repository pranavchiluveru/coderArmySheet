#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	vector<int> res;
	int carry=0,sum=0;
	int i=n-1,j=m-1;
	while(i>=0&&j>=0)
	{
			sum=a[i]+b[j]+carry;
			carry=sum/10;
			sum=sum%10;
			res.push_back(sum);
			i--;
			j--;
	}
	while(i>=0)
	{
		sum=a[i]+carry;
		carry=sum/10;
		sum=sum%10;
		res.push_back(sum);
		i--;
	}
	while(j>=0)
	{
		sum=b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		res.push_back(sum);
		j--;
	}
	reverse(res.begin(),res.end());
	return res;
}
