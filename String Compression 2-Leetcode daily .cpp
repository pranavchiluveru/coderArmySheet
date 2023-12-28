int t[101][27][101][101];//i,prev_char 0 to 25 geniune 26=-1 so we take 27,freq,k
class Solution {
public:
    string s;
    int find(int i,int prev_char,int freq,int k)
    {
        if(k<0) return INT_MAX;
        if(i>=s.length())return 0;
        if(t[i][prev_char][freq][k]!=-1)return t[i][prev_char][freq][k];
        int del_i=find(i+1,prev_char,freq,k-1);
        int keep_i;
        if(s[i]-'a'!=prev_char)
        {
            keep_i=1+find(i+1,s[i]-'a',1,k);
        }
        else
        {
            int onemoreaddition=0;
            if(freq==1||freq==9||freq==99)
                onemoreaddition=1;//aa,i=1,prev=a,freq=1 it becomes a2 so length isincreased by 1
            keep_i=onemoreaddition+find(i+1,prev_char,freq+1,k);
        }
        return t[i][prev_char][freq][k]=min(del_i,keep_i);
    }
    int getLengthOfOptimalCompression(string str, int k) {
        int n=s.length();
        s=str;
        memset(t,-1,sizeof(t));
        return find(0,26,0,k);//find(index,prev_char=26 instead of -1,freq of prev char,k)
    }
};
