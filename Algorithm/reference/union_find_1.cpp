#include <cstdio>
int set[100];

int findSet(int x){
	while(x != set[x]){
		x = set[x];
	}
	return x;
}

void unionSet(int x, int y){
	int a = findSet(x);
	int b = findSet(y);
	set[a] = b;	
}

int main(){
	for(int i=0; i<100; i++) set[i] = i;
	
	unionSet(5,4);
	unionSet(4,3);
	unionSet(3,2);
	unionSet(2,1);
	
	for(int i=1; i<6; i++) printf("%d ",set[i]);
	
	return 0;
} 
