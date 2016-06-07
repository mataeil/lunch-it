#include<cstdio>
#include<vector>
#define V_MAX 500
#define INF 99999999999
using namespace std;
 
static long long path[V_MAX+1];
int v_size, e_size, w_size;
vector < vector< pair<int,int> > > v(V_MAX+1);
 
void eraseVector(int v_size){
    for(int i=0; i<v_size+1; i++){
        v[i].erase(v[i].begin(), v[i].begin()+v[i].size());     
    }
}
 
int main(){
    int T;
    scanf("%d",&T);
    for(int test_case=0; test_case < T; test_case++){            
    //  vector < vector< pair<int,int> > > v(V_MAX+1);
        int a,b,c;
        scanf("%d %d %d",&v_size, &e_size, &w_size);
        v.clear();
        v.resize(v_size+1);
        for(int i=0; i<e_size; i++){
            scanf("%d %d %d",&a, &b, &c);   
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
        }
        for(int i=0; i<w_size; i++){
            scanf("%d %d %d",&a, &b, &c);   
            v[a].push_back(make_pair(b,-c));
        }
                 
        path[1] = 0LL;
        for(int i=2; i<v_size+1; i++){
            path[i] = INF;
        }
         
        for(int n=0; n<v_size; n++){     
            for(int i=1; i<v_size+1; i++){
                if(path[i] != INF){
                    for(int j=0; j<v[i].size(); j++){
                        int x = v[i][j].first;
                        int y = v[i][j].second;                 
                        if(path[x] > path[i] + (long long) y)
                            path[x] = path[i] + (long long) y;
                    }   
                }           
            }
        }
         
        int cycle = 0;
        for(int i=1; i<v_size+1; i++){
            if(path[i] != INF){
                for(int j=0; j<v[i].size(); j++){
                    int x = v[i][j].first;
                    int y = v[i][j].second;                 
                    if(path[x] > path[i] + (long long) y){
                        cycle = 1;
                    //  break;
                    }                       
                }
            //  if(cycle == 1)  break;
            }           
        }
         
        if(cycle == 1)      
            printf("YES\n");
        else
            printf("NO\n");
             
        //eraseVector(v_size);
         
    }   
    return 0;
