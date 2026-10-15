class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() &&
                   heights[st.top()] > currHeight) {

                int h = heights[st.top()];
                st.pop();

                int leftBoundary = st.empty() ? -1 : st.top();
                int width = i - leftBoundary - 1;

                int area = h * width;
                maxArea = max(maxArea, area);
            }
            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
        
    }
};