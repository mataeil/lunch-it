#include <cstdio>
#include <vector>
#include <queue>
#define V_MAX 1000 
#define INF 100000
using namespace std;
 
int n,m,x;
struct VTX{
    int index,val;
    VTX(int index, int val) : index(index), val(val){       
    }
    bool operator < (const VTX &other) const{
        return val > other.val;
    }
};
 
vector<vector<pair<int,int> > > v1(V_MAX+1);
vector<vector<pair<int,int> > > v2(V_MAX+1);
 
vector<int> dijkstra(vector<vector<pair<int,int> > > v, int start){ 
    vector<bool> chk(n+1);
    fill(chk.begin(), chk.end(), false);    
    vector<int> path(n+1,INF);    
    priority_queue<VTX> pq;
     
    path[start] = 0;    
    pq.push(VTX(start, 0));
     
    while(!pq.empty()){     
        int x = pq.top().index;
        pq.pop();       
        if(chk[x] == true) continue;                
        chk[x] = true;
        for(int i=0; i<v[x].size(); i++){            
            int y = v[x][i].first;
            if(chk[y] == true) continue;
            int cost = v[x][i].second;          
            if(path[y] > path[x] + cost){                
                path[y] = path[x] + cost;
                pq.push(VTX(y,path[y]));
            }
        }
    }
     
    return path;
}
 
int main(){
//  freopen("test/1238.txt","r",stdin); 
    scanf("%d %d %d",&n,&m,&x);
    int a,b,c;
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        v1[a].push_back(make_pair(b,c));
        v2[b].push_back(make_pair(a,c));
    }
     
    vector<int> path1 = dijkstra(v1,x);
    vector<int> path2 = dijkstra(v2,x);
     
    int max=0;
    for(int i=1; i<=n; i++){     
        if(max < path1[i] + path2[i] ){
            max = path1[i] + path2[i];
        }
    }
     
    printf("%d\n",max);
     
    return 0;
}
