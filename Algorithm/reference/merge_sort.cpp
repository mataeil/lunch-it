#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <time.h>
using namespace std;

bool comp(int A, int B){
	return  A <= B;
}

void m_sort(vector<int>& v, int left, int right){
	if(left == right) return;
	int mid = (left+right)/2;
	m_sort(v,left,mid);
	m_sort(v,mid+1,right);	
	
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
	int size = 1000000;
	for(int i=0; i<size; i++){
		v.push_back(i);
	}
	
	srand ( time(NULL) );	
	random_shuffle(v.begin(),v.end());		
	
	vector<int> v1;	
	vector<int> v2;	
	vector<int> v3;
	
	v1.assign(v.begin(),v.end());
	v2.assign(v.begin(),v.end());	    
	v3.assign(v.begin(),v.end());	    
	
	clock_t before;		 
	
	printf("size = %d\n",size);
	before = clock();	
	m_sort(v,0,size-1);	
	printf("merge_sort : %5.2f  ms elapsed\n", (double)(clock() - before) / CLOCKS_PER_SEC);

	before = clock();	
	sort(v3.begin(),v3.end());
	printf("c++ <algorith> sort : %5.2f  ms elapsed\n", (double)(clock() - before) / CLOCKS_PER_SEC);
	
	return 0;
}
