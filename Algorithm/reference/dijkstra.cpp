#include<cstdio>
#include<vector>
#include<queue>
#define C_MAX 1000
#define INF 2100000000
using namespace std;
 
static int chk[C_MAX+1];
static int answer[C_MAX+1];
vector< vector< pair<int,int> > > v(C_MAX+1);
int main(){
    int c_size, b_size,a,b,c,start,end;
    scanf("%d %d",&c_size,&b_size);
    for(int i=0; i<b_size; i++){
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
    }
    scanf("%d %d",&start,&end);
     
    for(int i=1; i<c_size+1; i++)
        answer[i] = INF;
         
    answer[start] = 0;
     
    for(int i=0; i<c_size-1; i++){
        int min = INF;
		int x = -1;
		for(int i=1; i<=c_size; i++){
			if(chk[i] == 0 && min > answer[i]){
				min = answer[i];
				x = i;
			}
		}
        chk[x] = 1;       
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i].first;
            int cost = v[x][i].second;
            if(answer[y] > answer[x]+cost && chk[y] != 1){         
                answer[y] = answer[x]+cost;
            }
        }
    }

    printf("%d\n",answer[end]);
     
    return 0;
}
