#include<cstdio>
#include<vector>
#define V_MAX 500
#define INF 2100000000
using namespace std;
 
static int path[V_MAX+1];
int v_size, e_size;
vector < vector< pair<int,int> > > v(V_MAX+1);
 
int main(){
    int a,b,c;
    scanf("%d %d",&v_size, &e_size);
    for(int i=0; i<e_size; i++){
        scanf("%d %d %d",&a, &b, &c);   
        v[a].push_back(make_pair(b,c));
    }
     
    path[1] = 0;
    for(int i=2; i<v_size+1; i++){
        path[i] = INF;
    }
     
    for(int n=0; n<v_size; n++){     
        for(int i=1; i<v_size+1; i++){
            for(int j=0; j<v[i].size(); j++){
                int x = v[i][j].first;
                int y = v[i][j].second;
                if(path[x] > path[i] + y)
                    path[x] = path[i] + y;
            }
        }
    }
     
    for(int i=1; i<v_size+1; i++){
        for(int j=0; j<v[i].size(); j++){
            int x = v[i][j].first;
            int y = v[i][j].second;
            if(path[x] > path[i] + y){
                printf("-1\n");
                return 0;   
            }               
        }
    }
     
    for(int i=2; i<v_size+1; i++){
        if(path[i] == INF)
            printf("-1\n");
        else
            printf("%d\n",path[i]);
    }
     
    return 0;
}
