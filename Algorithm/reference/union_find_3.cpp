#include <cstdio>
int set[100];
int size[100];

int findSet(int x){
	if(set[x] == x) return x;
	return set[x] = findSet(set[x]);
}

void unionSet(int x, int y){
	int a = findSet(x);
	int b = findSet(y);
	if(size[a] < size[b]){
		set[a] = b;
		size[b] += size[a];
 	}else{
		set[b] = a;
		size[b] += size[a];
	}
}

int main(){
	for(int i=0; i<100; i++) {
		set[i] = i;
		size[i] = 1;	
	}
	
	for(int i=10; i>1; i--) unionSet(i,i-1);
	
	for(int i=1; i<=10; i++) printf("%d ",set[i]);
	
	return 0;
} 
 
 
