#include<cstdio>
int N, K;
int input[10000], l = 1, r = 0, max = 0, m, count;

int main() {
	scanf("%d %d", &K, &N);
	for (int index = 0; index < K; index++) {
		scanf("%d", &input[index]);
		if (r < input[index]) {
			r = input[index];
		}
	}
	while (r >= l) {
		m = (l + r) / 2;
		count = 0;
		for (int index = 0; index < K; index++) {
			count += input[index] / m;
		}
		if (count >= N) {
			if (max < m) {
				max = m;
			}
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	printf("%d", max);

}

