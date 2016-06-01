#include<cstdio>
#include<algorithm>

using namespace std;
int N, input[5][20002];
int Answer[20002];
int x;
bool comp(const int a, const int b) {
	int count = 0;
	for (int index = 0; index < 5; index++) {
		if (input[index][a] > input[index][b]) {
			count++;
			if (count >= 2) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	scanf("%d", &N);

	for (int index = 0; index < 5; index++) {
		for (int index2 = 0; index2 < N; index2++) {
			scanf("%d", &x);
			input[index][x] = index2;
			Answer[index2] = x;
		}
	}

	sort(Answer, Answer + N, comp);

	for (int index = 0; index < N; index++) {
		printf("%d ", Answer[index]);
	}
}