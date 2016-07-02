#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

bool comp(int A, int B){
	return  A <= B;
}

void sort(vector<int>& v, int left, int right){
	if(left == right) return;
	int mid = (left+right)/2;
	sort(v,left,mid);
	sort(v,mid+1,right);	
	
	vector<int> temp;
	int cur1=left,cur2=mid+1;	
	while(cur1 <= mid || cur2 <= right){
		if(cur1 > mid) 
			temp.push_back(v[cur2++]);			
		else if(cur2 > right) 
			temp.push_back(v[cur1++]);			
		else if(comp(v[cur1],v[cur2])) 
			temp.push_back(v[cur1++]);			
		else 
			temp.push_back(v[cur2++]);			
	}
	
	for(int i=0; i<temp.size(); i++) v[left+i] = temp[i];
			
	return;
}

int main(){
	vector<int> v;
	int size = 10;
	for(int i=0; i<size; i++){
		v.push_back(i);
	}
	
	srand ( time(NULL) );	
	random_shuffle(v.begin(),v.end());
	
	printf("before sort : ");
	for(int i=0; i<size; i++){
		printf("%d ",v[i]);
	}
	
	sort(v,0,v.size()-1);
	
	printf("\nafter sort : ");
	for(int i=0; i<size; i++){
		printf("%d ",v[i]);
	}		
	
	return 0;
}
