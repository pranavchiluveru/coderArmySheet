class Solution {
public:
    int SubarraySumEqualsK(int arr[],int k,int n)
    {
        //prefix method TC=O(n) SC=O(n)
        unordered_map<int,int> mpp;
        int count=0;
        int prefixsumarray[n];
        prefixsumarray[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefixsumarray[i]=prefixsumarray[i-1]+arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(prefixsumarray[i]==k)
                count++;
            if(mpp.find(prefixsumarray[i]-k)!=mpp.end())
                count+=mpp[prefixsumarray[i]-k];
            mpp[prefixsumarray[i]]++;
        }
        return count;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //TC=O(rows^2*cols) SC=O(cols) watch yt video of coding decoded
        int res=0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int summedarr[cols];
        for(int i=0;i<rows;i++)//starting row
        {
            for(int i = 0; i < cols; i++) {
                summedarr[i] = 0;
            }

            for(int j=i;j<rows;j++)//ending row
            {
                for(int k=0;k<cols;k++)//for columns
                {
                    summedarr[k]+=matrix[j][k];
                }
                res+=SubarraySumEqualsK(summedarr,target,cols);
            }
        }
        return res;
    }
};
