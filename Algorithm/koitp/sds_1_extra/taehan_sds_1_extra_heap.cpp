#include<cstdio>
#include<queue>
using namespace std;

struct comp{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	}
};
int N, K, v;

priority_queue<pair<int, int>, vector<pair<int, int>>, comp>  pq;

int main() {
	scanf("%d %d", &N, &K);
	for (int index = 1; index <= N; index++) {
		scanf("%d", &v);
		pq.push(make_pair(v, index));
		if (index >= K) {
			while (pq.top().second <= (index - K)) {
				pq.pop();
			}
			printf("%d\n", pq.top().first);
		}
	}
}
