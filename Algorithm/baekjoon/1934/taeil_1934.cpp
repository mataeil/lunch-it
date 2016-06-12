#include <cstdio>
#include <vector>
using namespace std;
 
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int main(){
    int a,b,g,ans,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        int g = gcd(a,b);
        ans = (a/g)* b;
        printf("%d\n",ans); 
    } 
    return 0;
}
