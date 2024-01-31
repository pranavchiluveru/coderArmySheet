class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Brute force 2 for loops TC=O(n2) SC=O(1)
        //Optimal approach :Using stack TC=O(n) SC=O(n)
        //ex:5,4,1,2,6
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> s;//stores index
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&temperatures[i]>=temperatures[s.top()])
            {
                s.pop();
            }
            if(!s.empty())
            {
                res[i]=s.top()-i;
            }
            s.push(i);
        }
        return res;
    }
};
