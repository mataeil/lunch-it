#include<cstdio>
#include<vector>
#include<queue>
#define C_MAX 800
#define INF 100000000
using namespace std;
 
static int chk[C_MAX+1];
static int answer[C_MAX+1];
static int answer2[C_MAX+1];
static int answer3[C_MAX+1];
vector< vector< pair<int,int> > > v(C_MAX+1);
 
vector<int> dijkstra(int start, int c_size){
    vector<int> dist(c_size+1);
     
    for(int i=1; i<C_MAX+1; i++)
        chk[i] = 0; 
    for(int i=1; i<c_size+1; i++)
        dist[i] = INF;          
    dist[start] = 0;
     
    for(int k=0; k<c_size-1; k++){
        int min = INF;
        int index;
        for(int i=1; i<c_size+1; i++){
            if(min > dist[i]  && chk[i] == 0){
                min = dist[i];
                index = i;  
            }               
        }                   
        chk[index] = 1;     
        for(int i=0; i<v[index].size(); i++){
            int y = v[index][i].first;
            int cost = v[index][i].second;
            if(dist[y] > dist[index]+cost){          
                dist[y] = dist[index]+cost;         
            }
        }
    }
    return dist;
}
int main(){
    int c_size, b_size,a,b,c,mid1,mid2;
    int an1,an2;
    scanf("%d %d",&c_size,&b_size); 
    for(int i=0; i<b_size; i++){
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    scanf("%d %d",&mid1,&mid2);
     
    vector<int> st = dijkstra(1,c_size);
    vector<int> ed = dijkstra(c_size,c_size);
    vector<int> du = dijkstra(mid1,c_size);
     
    an1 = st[mid1] + du[mid2] + ed[mid2];
    an2 = st[mid2] + du[mid2] + ed[mid1];
     
    if(an1 < an2 && an1 < INF)
        printf("%d\n",an1);
    else if(an1 >= an2 && an2 < INF)
        printf("%d\n",an2);
    else
        printf("-1\n",an2);
                 
     
    return 0;
}
