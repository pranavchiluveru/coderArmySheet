int makeBeautiful(string s) {
	// Write your code here TC=O(n) SC=O(1)
	int n=s.size(),ops=0,ops1=0;
	//comparing with 010101....
	for(int i=0;i<n;i++)
	{
		if(i%2==0&&s[i]!='0')
			ops++;
		if(i%2==1&&s[i]!='1')
			ops++;
	}
	//comparing with 10101...
	for(int i=0;i<n;i++)
	{
		if(i%2==0&&s[i]!='1')
			ops1++;
		if(i%2==1&&s[i]!='0')
			ops1++;
	}
	return min(ops,ops1);
}
