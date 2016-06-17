#include <cstdio>
#include <algorithm>
#define MAXN 200001
using namespace std;
 
int T;
int n;
 
struct temp{
    int x,y;
}maxP;
 
int ccw (long long x1, int y1, int x2, int y2, int x3, int y3){
    long long temp = (long long)x1*y2 + (long long)x2*y3 + (long long)x3*y1 - ((long long)y1*x2 + (long long)y2*x3 + (long long)y3*x1);
    if(temp > 0) return 1;
    if(temp < 0) return -1;
    return 0;
}
 
struct Point{
    int x,y;
    bool operator < (const Point& other) const{
        int clock = ccw(maxP.x, maxP.y, x, y, other.x, other.y);
        if(clock < 0) return 1;
        if(clock > 0) return 0;
        if(y == other.y) return x < other.x;
        return y > other.y;
    }
}p[MAXN];
 
int stk[MAXN], s_top;
 
long long dist(struct Point& a, struct Point& b){
    return (long long)(a.x - b.x)*(a.x - b.x) + (long long)(a.y - b.y)*(a.y - b.y);
}
 
int main(){
//  freopen("test/convex.txt","r",stdin);
    scanf("%d",&T);
    while(T--){     
        scanf("%d",&n);
        int k=0;
        for(int i=0; i<n; i++){
            scanf("%d %d",&p[i].x,&p[i].y);
            if(p[i].y > p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x))          
                k = i;
        }
         
        maxP.x = p[k].x;
        maxP.y = p[k].y;
        swap(p[k],p[0]);
        sort(p+1, p+n);
         
        stk[0] = 0;
        s_top = 0;
         
        //convex hull
        for(int i=1; i<n; i++){
            while(s_top > 0 && ccw(p[stk[s_top-1]].x, p[stk[s_top-1]].y, p[stk[s_top]].x, p[stk[s_top]].y, p[i].x, p[i].y) >= 0 ) 
                stk[s_top--] = 0;
            stk[++s_top] = i;
        }
         
        int ans1,ans2;
        int e=0;
        long long max = -1;
          
        for(int s=0; s<=s_top; s++){
            while( dist( p[stk[s]], p[stk[e]] ) <= dist( p[stk[s]], p[stk[(e+1)%(s_top+1)]]) )  
                e = (e + 1)%(s_top+1);
            long long d = dist( p[stk[s]], p[stk[e]] );
            if(max < d){
                ans1 = stk[s];
                ans2 = stk[e];             
                max = d;
            }
        }
          
        printf("%d %d %d %d\n",p[ans1].x, p[ans1].y, p[ans2].x, p[ans2].y);
    }
    return 0;
}
