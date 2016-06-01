#include<cstdio>
#include<cstring>

using namespace std;

int n = 0, min_val = 100;
bool input[22] = { true, }, input2[22] = { true, }, result = false;

int main() {
	for (int index = 1; index <= 20; index++) {
		scanf("%d", &input[index]);
	}

	memcpy(input2, input, sizeof(bool) * 22);

	for (int index = 1; index <= 20; index++) {
		if (input[index - 1] == true) {
			input[index - 1] = !input[index - 1];
			input[index] = !input[index];
			input[index + 1] = !input[index + 1];
			n++;
		}
		result |= input[index - 1];
	}
	result |= input[20];
	if (!result) {
		min_val = n;
	}

	result = false;
	n = 0;
	for (int index = 2; index <= 20; index++) {
		if (input2[index - 1] == true) {
			input2[index - 1] = !input2[index - 1];
			input2[index] = !input2[index];
			input2[index + 1] = !input2[index + 1];
			n++;
		}
		result |= input2[index - 1];
	}
	result |= input2[20];
	if (!result && min_val > n) {
		min_val = n;
	}

	if (min_val <= 20) {
		printf("%d", min_val);
	}
	else {
		printf("-1");
	}

	return 0;
}