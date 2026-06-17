class MinStack {
public:
    stack<pair<int, int>> st;
    int minimum = INT_MAX;

    MinStack() {
    }

    void push(int val) {
        if (st.empty())
            minimum = val;
        else
            minimum = min(st.top().second, val);

        st.push({val, minimum});
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
