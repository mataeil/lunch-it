#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 100000
using namespace std;

struct EMPLOYEE{
	int fisrt,second;
}e1[MAX+1], e2[MAX+1];

bool comp1(const EMPLOYEE& a, const EMPLOYEE& b){
	return a.fisrt < b.fisrt;
}
struct comp2{
	bool operator()(const EMPLOYEE& a, const EMPLOYEE& b){
		return a.second > b.second;
	}
};

priority_queue<EMPLOYEE,vector<EMPLOYEE>,comp2> que;  
int main(){
	int size,test_case;
	int answer[20];
	scanf("%d",&test_case);
	for(int t=0; t<test_case; t++){
		que = priority_queue<EMPLOYEE,vector<EMPLOYEE>,comp2>();
		scanf("%d",&size);
		for(int i=0; i<size; i++){
			scanf("%d %d", &e1[i].fisrt, &e1[i].second);
		}
		sort(e1, e1+size, comp1);
		
		que.push(e1[0]);
		EMPLOYEE pop;
		for(int i=1; i<size; i++){
			pop = que.top();
			if(e1[i].second < pop.second)
				que.push(e1[i]);	
		}
		answer[t]=que.size();		
	}		
	for(int i=0; i<test_case; i++)
		printf("%d\n",answer[i]);
	
	return 0;
}
