class Solution {
public:
    int getV(vector<int>& height, int l, int r){
        return min(height[l], height[r]) * (r - l);
    }
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = getV(height, left, right);
        while(left < right){
            if(height[left] <= height[right]){
                int ll = left + 1;
                while(ll < right && height[ll] <= height[left]) ++ll;
                if(ll >= right) break;
                int vault = getV(height, ll, right);
                if (vault > ans){
                    ans = vault;
                }
                left = ll;
            }else{
                int rr = right - 1;
                while(rr > left && height[rr] <= height[right]) --rr;
                if(rr <= left) break;
                int vault = getV(height, left, rr);
                if (vault > ans){
                    ans = vault;
                }
                right = rr;
            }
        }
        return ans;
    }
};