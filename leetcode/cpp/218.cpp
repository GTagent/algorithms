class Solution {
public:
    struct uel{
        int val,pos;
    };
    struct{
        bool operator()(uel a, uel b) const {return (a.val < b.val) || ((a.val == b.val) && (a.pos < b.pos));}
    }uelComp;
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<uel> arr;
        for(int i = 0; i < nums.size(); ++i){
            uel ele;
            ele.val = nums[i];
            ele.pos = i;
            arr.push_back(ele);
        }
        sort(arr.begin(), arr.end(), uelComp);
        for(int i = 1; i < arr.size(); ++i){
            // cout<<arr[i].val<<" "<<arr[i].pos<<endl;
            if(arr[i].val == arr[i - 1].val){
                if(abs(arr[i].pos - arr[i - 1].pos) <= k)
                    return true;
            }
        }
        return false;
    }
};