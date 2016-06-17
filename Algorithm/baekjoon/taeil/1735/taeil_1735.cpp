#include <cstdio>
#include <vector>
using namespace std;
 
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int head = a*d+c*b;
    int body = b*d;
    int g = gcd(head,body);
    printf("%d %d\n",head/g,body/g);
     
    return 0;
}
