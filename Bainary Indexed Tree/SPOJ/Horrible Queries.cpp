#include<bits/stdc++.h>

using namespace std;

#define lli long long int

void update_point(vector <lli> &tree,lli i,lli n,lli v){
	
	while(i<=n){
		
		tree[i]+=v;
		
		i+=(i&(-i));
	}
}

void update_range ( vector <lli> &tree1,vector <lli> &tree2,lli i,lli j,lli n,lli v){
	
	update_point(tree1,i,n,v);
	
	update_point(tree1,j+1,n,-v);
	
	update_point(tree2,i,n,v*(i-1));
	
	update_point(tree2,j+1,n,-v*j);
}

lli query1(vector <lli> &tree,lli i){
	
	lli sum=0;
	
	while(i>0){
		
		sum+=tree[i];
		
		i-=(i&(-i));
	}
	
	return sum;
}

lli query2(vector <lli> &tree1,vector <lli> &tree2,lli i){
	
	lli sum1=(query1(tree1,i))*i;
	
	lli sum2=query1(tree2,i);
	
	return (sum1-sum2);
}

lli range_query(vector <lli> &tree1,vector <lli> &tree2,lli i,lli j){
	
	lli sum1=query2(tree1,tree2,j);
	
	lli sum2=query2(tree1,tree2,i-1);
	
	return (sum1-sum2);
}

int main(){
	
	lli T;
	
	scanf("%lld",&T);
	
	while(T--){
		
		lli n,q;
		
		scanf("%lld %lld",&n,&q);
		
		vector <lli> Tree1,Tree2;
		
		for(lli i=0; i<=n; i+=1){
			
			Tree1.push_back(0);
			
			Tree2.push_back(0);
		}
		
		while(q--){
			
			lli i,j,k,v;
			
			scanf("%lld %lld %lld",&k,&i,&j);
			
			if(k==0){
				
				scanf("%lld",&v);
				
				update_range(Tree1,Tree2,i,j,n,v);
			}
			
			else{
				
				lli sum=range_query(Tree1,Tree2,i,j);
				
				printf("%lld\n",sum);
			}
		}
	}
}
