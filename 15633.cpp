# include<iostream>
# include <algorithm>
using namespace std;

int n, m;
int arr[10];
int key[10];
int dap[10];

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << dap[i] << ' ';

		cout << '\n';
		return;
	}
	int sim=0;
	for (int i = 0; i < n; i++) {
		if (!key[i]&&sim!=arr[i]) {
			dap[k] = arr[i];
			key[i] = 1;
			sim = arr[i];
			backtracking(k + 1);
			key[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	backtracking(0);

	return 0;
}
