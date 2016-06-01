#include<cstdio>
#include<algorithm>
using namespace std;

int N;
typedef struct loc {
	long long x, a;
};
bool comp(loc a, loc b) {
	return a.x < b.x;
}

loc input[100000];
long long l = 0, r = 0, answer;
int main() {
	scanf("%lld", &N);
	for (int index = 0; index < N; index++) {
		scanf("%lld %lld", &input[index].x, &input[index].a);
		r += input[index].a;
	}

	sort(input, input + N, comp);
	for (int index = 0; index < N; index++) {
		l += input[index].a;
		r -= input[index].a;
		if (l >= r) {
			answer = index;
			break;
		}
	}
	printf("%lld", input[answer].x);
}