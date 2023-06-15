class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.size();
	    int lp[n+1];
	    char str[n+1];
	    for(int i=0;i<n;i++)
	    {
	        str[i+1]=s[i];
	        lp[i]=0;
	    }
	    lp[n]=0;
	    int first=0,second=2;
	    while(second<=n)
	    {
	        if(str[first+1]==str[second])
	        {
	            lp[second]=first+1;
	            first++;
	            second++;
	        }
	        else
	        {
	            if(first==0)
	                second++;
	            else
	            {
	                first=lp[first];
	            }
	        }
	    }
	    return lp[n];
	}
};
