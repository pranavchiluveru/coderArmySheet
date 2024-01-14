class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return 0;
        vector<int> s1(26,0),s2(26,0);
        for(int i=0;i<word1.size();i++)
        {
           s1[word1[i]-'a']++; 
        }
        for(int i=0;i<word2.size();i++)
        {
           s2[word2[i]-'a']++; 
        }
        //characters should be same
        for(int i=0;i<26;i++)
        {
            if(s1[i]==0&&s2[i]!=0||s1[i]!=0&&s2[i]==0)
                return 0;
        }

        //count of frequencies should be same
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};
