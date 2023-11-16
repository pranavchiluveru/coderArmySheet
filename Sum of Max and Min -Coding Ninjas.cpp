#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	// Write your code here.
	/*
	sort(arr,arr+n);
	int min=arr[0];
	int max=arr[n-1];
	return min+max;
	*/
	int min=arr[0],max=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	return min+max;
}
