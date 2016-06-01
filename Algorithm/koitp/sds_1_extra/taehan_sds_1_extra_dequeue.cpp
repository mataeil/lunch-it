#include<cstdio>
#include<queue>
using namespace std;

int N, K;
int input[100002];
deque<int> dq;

int main() {
	scanf("%d %d", &N, &K);
	for (int index = 1; index <= N; index++) {
		scanf("%d", &input[index]);
		while (!dq.empty() && input[dq.back()] < input[index]) {
			dq.pop_back();
		}
		dq.push_back(index);
		if (dq.front() <= index - K) {
			dq.pop_front();
		}
		if (index >= K) {
			printf("%d\n", input[dq.front()]);
		}
	}
}