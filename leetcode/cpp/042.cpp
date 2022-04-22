class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int h = height.size();
        vector<int> left_max(h), right_max(h);
        left_max[0] = height[0];
        for(int i = 1; i < h; ++i){
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[h - 1] = height[h - 1];
        for(int i = h - 2; i >= 0; --i){
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for(int i = 0; i < h; ++i){
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};