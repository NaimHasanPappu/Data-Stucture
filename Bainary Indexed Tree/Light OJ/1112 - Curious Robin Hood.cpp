#include<bits/stdc++.h>

using namespace std;

#define V vector < int >

V tree,arr;

void update ( int size , int index , int value ){
	
	while ( index<=size ){
		
		tree[index] += value;
		
		index += ((index) & (-index));
	}
}

int query ( int index ){
	
	int sum=0;
	
	while ( index > 0 ){
		
		sum += tree[index];
		
		index -= ((index) & (-index));
	}
	
	return sum;
}

void build (int n){
	
	arr.clear();
	
	tree.clear();
	
	for(int i=0; i<=n; i+=1){
	
		arr.push_back(0);
	
		tree.push_back(0);
	}
}

int main(){
	
	int n;
	
	cin>>n;
		
	build(n);
	
	for(int i=1; i<=n; i+=1){
		
		arr[i]=i;
		
		update()
	}
}
