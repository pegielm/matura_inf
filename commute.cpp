#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int najkrotsza(vector<int> grid[],int tab[][3],int trasa,int v){
	int min=trasa;
	int zas,k;
		//	cout<<"obecny wieszcholek "<<v<<endl;
	if(grid[v].size()==0){
			
	//		cout<<"koniec nie ma synow zwracam"<<trasa-tab[v][2]<<endl;
			return trasa-tab[v][2];
			
		}
	for(int i=0;i<grid[v].size();i++){

		
		
	//		cout<<"idziemy do "<<grid[v][i];
			zas=najkrotsza(grid,tab,trasa,grid[v][i]);
			if(zas<min){
			min=zas;
			k=i;
			}	
	}
//	cout<<"koniec sasiadow zwracam min = "<<min<<endl;
	return min-tab[v][2];
	
}
int main(){
	int l,n;
	cin>>l>>n;
	int tab[n][3]; // 0-start 1-koniec 2-o ile skraca 
	int z;
	vector<int> s[n];
	for(int i=0;i<n;i++){
		cin>>tab[i][0]>>tab[i][1]>>z;
		tab[i][2]=(tab[i][1]-tab[i][0])-z;
		if(tab[i][1]>l)tab[i][2]=-999999999; //o ile skraca trase
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=i){
				if(tab[i][1]<=tab[j][0]){ //poczatkek drugiego w koncu albo za koncem pierwszego 
					s[i].push_back(j);
				}
			}
		}
	}
//	for(int i=0;i<n;i++){
//		cout<<"z "<<i<<" dostepne : ";
//		for(int j=0;j<s[i].size();j++){
//			cout<<s[i][j]<<" ";
//		
//		}
//		cout<<endl;
//	}
	int trasa=l,pom;
	for(int i=0;i<n;i++){
	
	pom=najkrotsza(s,tab,l,i);
	if(pom<trasa)trasa=pom;
	}
	cout<<trasa<<endl;
	return 0;
}
