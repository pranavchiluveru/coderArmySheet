class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        /*brute force TC=O(n^2) SC=O(1)
        int n=s.length();
        int larg=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                        larg=max(larg,j-i-1);
                }
            }
        }
        return larg;
        */
        /*Approach 2 : TC=O(n) SC=O(n)
        unordered_map<char,int> m;
        int n=s.length(),larg=-1;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])==m.end())
                m[s[i]]=i;
            else
            {
                larg=max(larg,i-m[s[i]]-1);
            }
        }
        return larg;
        */

        //Approach 3 :Using Arrays TC=O(n) SC=O(26)=O(1)
        vector<int> found(26,-1);
        int n=s.length(),larg=-1;
        for(int i=0;i<n;i++)
        {
            int temp=s[i]-'a';
            if(found[temp]==-1)
            {
                found[temp]=i;
            }
            else
            {
                larg=max(larg,i-found[temp]-1);
            }
        }
        return larg;
        
    }
};
