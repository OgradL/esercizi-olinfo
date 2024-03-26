#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    priority_queue<int> queue;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        num *= -1;
        queue.push(num);
    }

    uint64_t cost = 0;
    int sum = 0;
    while (queue.size() > 1) {
        int tmp = queue.top();
        tmp *= -1;
        sum = tmp;
        queue.pop();

        int tmp2 = queue.top();
        tmp2 *= -1;
        sum += tmp2;
        queue.pop();

        cost += sum;
        sum *= -1;
        queue.push(sum);

    }
    cout << cost;
}
