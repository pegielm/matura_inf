#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool sorted(vector<int> arr, int n){
    if (n == 0 || n == 1)
        return true;
     for (int i = 1; i < n; i++)
      if (arr[i - 1] > arr[i])
            return false;
    return true;
}
int display(vector<int> a, int n){
	vector <int>::iterator it;
	int k=n;
	int itvar;
	int operacje=0;
 // for(int i=0;i<n;i++){   	
//	 cout << a[i] << " ";	 	
//	}
//	cout<<endl; 
	while(!(a[0]==1)){
		it =find(a.begin(), a.end(),a[0]-1);
			operacje+=distance(a.begin(), it);
//			cout<<" *it "<<*it<<endl;
			itvar=*it;
		a.erase(it);
		a.insert(a.begin(),1,itvar);
		
	
//		cout<<endl<<"operacje "<<operacje<<endl;
//			for(int i=0;i<a.size();i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
	}
	while(!sorted(a,n)){
		it =find(a.begin(), a.end(),k);
		operacje+=distance(a.begin(), it);
//		cout<<" *it "<<*it<<endl;
		itvar=*it;
		a.erase(it);
		a.insert(a.begin(),1,itvar);
		
		k--;
		cout<<endl<<"operacje2 "<<operacje<<endl;
		for(int i=0;i<a.size();i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	cout << endl<<operacje<<endl; ;
	return operacje;
}
int main()
{
    int n;
    long long suma;
    int czasowa=0;
    vector<int> tab;
	suma=0;
    cin >> n;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        a[i]=i+1;
    }

    do{
    	
        czasowa=display(a, n);
        tab.push_back(czasowa);
        suma+=czasowa;
 //       cout<<endl<<"NASTEPNA"<<endl;
    }while(next_permutation(a.begin(), a.end())); 
	cout<<" suma= "<<suma<<endl;
	sort(tab.begin(),tab.end());
	int zlicz[100];
	memset(zlicz, 0, 100 * sizeof(int));
	for(int i=0;i<tab.size();i++){
		cout<<tab[i]<<" ";
		zlicz[tab[i]]++;
	}
	cout<<endl;
	for(int i=0;i<100;i++){
		cout<<i<<" wystapil "<<zlicz[i]<<" razy"<<endl;
	}

    return 0;
}
