//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
// Your code goes here
    int s1=str1.size();
    int s2=str2.size();
    int count1[26],count2[26];
    int count=0;
    for(int i=0;i<26;i++)
    {
        count1[i]=0;
        count2[i]=0;
    }
    for(int i=0;i<s1;i++)
    {
        count1[str1[i]-'a']++;
    }
    for(int i=0;i<s2;i++)
    {
        count2[str2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(count1[i]==count2[i])
            continue;
        else if(count1[i]>count2[i])
            count+=(count1[i]-count2[i]);
        else
            count+=(count2[i]-count1[i]);
    }
    return count;
}
