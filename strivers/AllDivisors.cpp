void print_divisors(int n) {
    vector<int> temp;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (n / i != i)
                temp.push_back(n / i);
        }
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";
}