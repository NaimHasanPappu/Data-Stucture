#include<bits/stdc++.h>
 
using namespace std;
 
#define inf 100001
 
int arr[100001],tree[4*100001];
 
void segment ( int n, int b, int e ){
   
    if ( b == e ){
       
        tree[n] = arr[b];
       
        return;
    }
    
    int left = n*2;
       
    int right = n*2 + 1;
       
    int middle = ( b + e ) / 2;
       
    segment ( left, b, middle );
       
    segment ( right, middle+1, e );
       
    tree[n]=min(tree[left],tree[right]);
}
 
int query ( int n, int b, int e, int i, int j ){
   
    if ( i>e || j<b ){
       
        return inf;
    }
   
    if ( b>=i && e<=j ){
       
        return tree[n];
    }
    
    int left=n*2;
       
    int right=n*2+1;
       
    int middle=(b+e)/2;
       
    int x = query(left,b,middle,i,j);
       
    int y = query(right,middle+1,e,i,j);
       
    return min(x,y);
}
 
int main(){
	
	int T;
	
	scanf("%d",&T);
	
	for(int t=0; t<T; t+=1){
		
		int n,q;
		
		scanf("%d %d",&n,&q);
		
		for(int i=1; i<=n; i+=1){
			
			scanf("%d",&arr[i]);
		}
		
		printf("Case %d:\n",t+1);
		
		segment(1,1,n);
		
		while(q--){
			
			int i,j;
			
			scanf("%d %d",&i,&j);
			
			int p=query(1,1,n,i,j);
			
			printf("%d\n",p);
		}
	}
	
	return 0;
}
