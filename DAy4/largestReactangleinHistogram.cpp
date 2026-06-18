class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Sentinel

        stack<int> st;
        int n = heights.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                res = max(res, height * width);
            }

            st.push(i);
        }

        return res;
    }
};
