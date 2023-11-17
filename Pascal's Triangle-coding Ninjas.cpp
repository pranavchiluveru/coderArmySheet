#include <bits/stdc++.h>
//TC=O(n^2) SC=O(1)
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i=0;i<n;i++){
    vector<long long int> temp(i+1);        
    for(int j=0;j<=i;j++){
      if(j==0 || j==i){
        temp[j]=1;
      }
      else{
        temp[j]=(ans[i-1][j-1]+ans[i-1][j]);
      }
                
    }
    ans.push_back(temp);
    temp.clear();
  }
  return ans;
}

