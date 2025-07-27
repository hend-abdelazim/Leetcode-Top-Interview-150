class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1, maxArea = 0;
        while (l < r) {
            int width = (r-l), length = (min(height[l],height[r]));
            int area = width * length;
            maxArea = max(maxArea, area);
            if(height[l] <= height[r]) l++;
            else if (height[r] < height[l]) r--;
        }
        return maxArea;
    }
};