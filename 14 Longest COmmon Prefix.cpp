class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*TC=O(n2)
        int len=INT_MAX;
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            while(j<strs[i].size()&&strs[i][j]==strs[0][j])
                j++;
            len=min(len,j);
        }
        return strs[0].substr(0,len);
        */
        //TC=O(nlogn)
        sort(strs.begin(),strs.end());
        int i=0;
        while(i<strs[0].size()&&strs[0][i]==strs[strs.size()-1][i])
            i++;
        return strs[0].substr(0,i);
    }
};
