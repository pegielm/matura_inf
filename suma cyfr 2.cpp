#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int maxsuma(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;
    for (i = 1; i < n; i++)
    {
        if(incl > excl){
        	excl_new = incl;
		}
		else{
			excl_new = excl;
		}
        incl = excl + arr[i];
        excl = excl_new;
    }
 
    return ((incl > excl) ? incl : excl);
}
 
int main()
{
	int n,x,sum=0;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(9-x);
		sum+=x;
	}
    cout<<maxsuma(arr, arr.size())+sum;
    return 0;
}
