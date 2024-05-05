#include <iostream>
#include <vector>
using namespace std;
#define N 200001
vector <int> miasta[N];
int visited [N];
int gildia [N];
void dfs( int v, int g){
	visited[v]=1;
	gildia[v]=g;
	g=(g+1)%2;
	for(int i=0;i<miasta[v].size();i++){
		if(visited[miasta[v][i]]==0){
			dfs(miasta[v][i],g);
		}
	}
	
	
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		miasta[a].push_back(b);	
		miasta[b].push_back(a);	
	}
	for(int i=1;i<=n;i++){
		if(miasta[i].size()==0){
			cout<<"NIE"<<endl;
			return 0;
		}
	}
	cout<<"TAK"<<endl;
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			dfs(i,1);
		}
	}
	for(int i=1;i<=n;i++){
		if(gildia[i]==1){
			cout<<"K"<<endl;
		}
			if(gildia[i]==0){
			cout<<"S"<<endl;
		}
	}
	
	
	
	return 0;
}
