#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int m,n;
 
bool canReachTreasure(vector<vector<char> > &maze, int i, int j, int p, vector< vector<bool> > &visit){
	if(i< 0 || i>=m || j<0 || j>=n || p<0 || maze[i][j] == '#' ){
    return false;
  }
	if(maze[i][j] == 'x' ){
    return true;
  }
	if(!visit[i][j]){
	visit[i][j]=true;
	if(canReachTreasure(maze,i+1,j,(maze[i][j]=='s')?p-1:p,visit)){
    return true;
  }
	if(canReachTreasure(maze,i,j+1,(maze[i][j]=='s')?p-1:p,visit)){
    return true;
  }
	if(canReachTreasure(maze,i,j-1,(maze[i][j]=='s')?p-1:p,visit)){
    return true;
  }
	if(canReachTreasure(maze,i-1,j,(maze[i][j]=='s')?p-1:p,visit)){
    return true;
  }
	maze[i][j]='#';
	visit[i][j]=false;
}
	return false;
}
int main() {
	int z;
	int a,b;
	cin>>m>>n>>z;
	vector<vector<char> > maze(m,vector<char>(n,32)); 
	vector<vector<bool> > visit(m,vector<bool>(n,0)); 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			
			cin>>maze[i][j];
			if(maze[i][j] == '@'){
				a=i;
				b=j;
			}			
		}	
	}
	if(canReachTreasure( maze, a, b,(int) z/2, visit))
	{
	cout<<"SUCCESS"<<endl;
	}
	else{
	cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
