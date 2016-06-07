#include<cstdio>
#include<vector>
#include<queue>
#define C_MAX 1000
#define INF 2100000000
using namespace std;
 
static int chk[C_MAX+1];
static int answer[C_MAX+1];
static int path[C_MAX+1];
struct VTX{
    int index, val;
    VTX(int index, int val) : index(index), val(val){
    }
    bool operator < (const VTX &other) const{
        return val > other.val;
    }
};
priority_queue<VTX> pq;
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
         
    pq.push(VTX(start,0));
    answer[start] = 0;  
    path[start] = -1;
     
//  for(int k=0; k<c_size; k++){
//      int min = INF;
//      int index;
//      for(int i=1; i<c_size+1; i++){
//          if(min > answer[i]  && chk[i] == 0){
//              min = answer[i];
//              index = i;  
//          }               
//      }                   
//      chk[index] = 1;     
//      for(int i=0; i<v[index].size(); i++){
//          int y = v[index][i].first;
//          int cost = v[index][i].second;
//          if(answer[y] > answer[index]+cost){          
//              answer[y] = answer[index]+cost;
//              path[y] = index;                
//          }
//      }
//  }
     
    while(!pq.empty()){ 
        VTX x = pq.top();
        pq.pop();
        if(chk[x.index] == 1)
            continue;
        answer[x.index] = x.val;
        chk[x.index] = 1;       
        for(int i=0; i<v[x.index].size(); i++){
            int y = v[x.index][i].first;
            int cost = v[x.index][i].second;
            if(answer[y] > answer[x.index]+cost && chk[y] != 1){         
                answer[y] = answer[x.index]+cost;
                path[y] = x.index;
                pq.push(VTX(y,answer[y]));
            }
        }
    }
 
    printf("%d\n",answer[end]);
    int printArr[c_size+1];
    int pi=0;
    int z = end;
    while(z != -1){     
        printArr[pi++] = z;
        z = path[z];
    }
    printf("%d\n",pi);
    for(int i=pi-1; i>=0; i--)
        printf("%d ",printArr[i]);
    printf("\n");
    return 0;
}
