#include<bits/stdc++.h>
 
using namespace std;
 
#define mx 100005
 
int arr[mx] , tree[(mx+1)*4];
 
void segment ( int n , int b , int e ){
 
    if ( b == e ){
 
        tree[n] = arr[b];
 
        return;
    }
 
 
    int left = n * 2;
 
    int right = n * 2 + 1;
 
    int middle = ( b + e ) / 2;
 
    segment ( left , b , middle );
 
    segment ( right , middle + 1 , e );
 
    tree[n] = tree[left] + tree[right];
}
 
int query ( int n , int b , int e , int i , int j ){
 
    if ( b > j || e < i ){
 
        return 0 ;
    }
 
    if ( b >= i && e <= j ){
 
        return tree[n];
    }
 
 
    int left = n * 2;
 
    int right = n * 2 + 1;
 
    int middle = ( b + e ) / 2;
 
    int x = query ( left , b , middle , i , j );
 
    int y = query ( right , middle + 1 , e , i , j );
 
    return x + y;
}
 
void update ( int n , int b , int e , int i , int v ){
 
    if (i > e || i < b){
 
        return;
    }
 
    if ( b == e ){
    	
    	arr[b]+=v;
 
        tree[n] += v;
 
        return;
    }
 
    int left = n * 2;
 
    int right = n * 2 + 1;
 
    int middle = (b + e) / 2;
 
    update ( left , b , middle , i , v );
 
    update ( right , middle + 1 , e , i , v );
 
    tree[n] = tree[left] + tree[right];
}

int main(){
 
    int T;
 
    scanf ("%d",&T);
    
    for(int t=0; t<T; t+=1){
    	
    	int n,q;
    	
    	scanf("%d %d",&n,&q);
    	
    	for(int i=0; i<n; i+=1){
    		
    		scanf("%d",&arr[i]);
		}
		
		printf("Case %d:\n",t+1);
		
		segment(1,0,n-1);
		
		while(q--){
			
			int k;
			
			scanf("%d",&k);
			
			if(k==1){
				
				int i;
				
				scanf("%d",&i);
				
				printf("%d\n",arr[i]);
				
				update(1,0,n-1,i,-arr[i]);
			}
			
			else if(k==2){
				
				int i,v;
				
				scanf("%d %d",&i,&v);
				
				update(1,0,n-1,i,v);
			}
			
			else if(k==3){
				
				int i,j;
				
				scanf("%d %d",&i,&j);
				
				int p=query(1,0,n-1,i,j);
				
				printf("%d\n",p);
			}
		}
	}
	
	return 0;
}
