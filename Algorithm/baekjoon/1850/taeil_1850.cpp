#include <cstdio>
#include <vector>
using namespace std;
 
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int main(){
    long long a,b,g;
    scanf("%lld %lld",&a,&b);
 
    if(a<b) swap(a,b);
    g = gcd(a,b);
     
    while(g--){
        printf("1");
    }
    printf("\n");
     
    return 0;
}
