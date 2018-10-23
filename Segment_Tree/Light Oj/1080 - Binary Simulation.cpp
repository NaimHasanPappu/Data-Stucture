#include<bits/stdc++.h>

using namespace std;

int arr[100001],tree[100005*4],lazy[100005*4];

void make(string s){
	
	int n=s.length();
	
	for(int i=0; i<n; i+=1){
		
		if(s[i]=='1'){
			
			arr[i+1]=1;
		}
		
		else{
			
			arr[i+1]=0;
		}
	}
	
	for(int i=0; i<=4*(n+1); i+=1){
		
		tree[i]=lazy[i]=0;
	}
}

void build(int n,int b,int e){
	
	if(b>e){
		
		return;
	}
	
	if(b==e){
		
		tree[n]=arr[b];
		
		return;
	}
	
	int m=(b+e)>>1;
	
	build(n*2,b,m);
	
	build(n*2+1,m+1,e);
	
	tree[n]=tree[n*2]+tree[n*2+1];
}

void update(int n,int b,int e,int i,int j){
	
	if(b>e){
		
		return;
	}
	
	if(lazy[n]!=0){
		
		int c=(lazy[n])%2;
		
		if(c==1){
			
			tree[n]=(e-b+1)-tree[n];
		}
		
		if(b!=e){
			
			lazy[n*2]+=lazy[n];
			
			lazy[n*2+1]+=lazy[n];
		}
		
		lazy[n]=0;
	}
	
	if(b>j || e<i){
		
		return;
	}
	
	if(b>=i && e<=j){
		
		tree[n]=(e-b+1)-tree[n];
		
		if(b!=e){
		
			lazy[n*2]^=1;
		
			lazy[n*2+1]^=1;
		}
		
		return;
	}
	
	int m=(b+e)>>1;
	
	update(n*2,b,m,i,j);
	
	update(n*2+1,m+1,e,i,j);
	
	tree[n]=tree[n*2]+tree[n*2+1];
}

int query(int n,int b,int e,int i,int j){
	
	if(b>e){
		
		return 0;
	}
	
	if(lazy[n]!=0){
		
		int c=(lazy[n])%2;
		
		if(c==1){
			
			tree[n]=(e-b+1)-tree[n];
		}
		
		if(b!=e){
			
			lazy[n*2]+=lazy[n];
			
			lazy[n*2+1]+=lazy[n];
		}
		
		lazy[n]=0;
	}
	
	if(b>i || e<j){
		
		return 0;
	}
	
	if(b>=i && e<=j){
		
		return tree[n];
	}
	
	int m=(b+e)>>1;
	
	int q1=query(n*2,b,m,i,j);
	
	int q2=query(n*2+1,m+1,e,i,j);
	
	return (q1+q2);
}

int main(){
	
	int T;
	
	scanf("%d",&T);
	
	for(int t=0; t<T; t+=1){
	
		int n,q;
		
		char s[100001];
		
		scanf("%s",&s);
		
		string S=s;
		
		scanf("%d",&q);
		
		printf("Case %d:\n",t+1);
		
		make(S);
		
		n=S.length();
		
		build(1,1,n);
		
		while(q--){
			
			char K[2];
			
			scanf("%s",&K);
			
			string k=K;
			
			if(k=="I"){
				
				int i,j;
				
				scanf("%d %d",&i,&j);
				
				update(1,1,n,i,j);
			}
			
			else if(k=="Q"){
				
				int i;
				
				scanf("%d",&i);
				
				int p=query(1,1,n,i,i);
				
				printf("%d\n",p);
			}
		}
	}
	
	return 0;
}
