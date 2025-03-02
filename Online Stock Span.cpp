#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    int n;

    cout << "Enter the number of stock prices: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the stock prices:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        cout << "Stock span for " << prices[i] << ": " << spanner.next(prices[i]) << endl;
    }

    return 0;
}
