class Solution {
public:
    string toLowerCase(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' and s[i]<='Z')
            {
                s[i]+='a'-'A';
            }
        }
        return s;
    }
};
