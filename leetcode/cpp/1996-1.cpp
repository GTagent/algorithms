class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
    }
    struct node{
        int val;
        int maxd;
        int mind;
        int l, r;
        node(int _v, int _maxd, int _mind, int _l, int _r){
            val = _v;
            maxd = _maxd;
            mind = _mind;
            l = _l;
            r = _r;
        }
    };
    int binSearch(vector<vector<int>>& a, int _l, int _r, int k){
        int l = _l;
        int r = _r;
        while(l < r){
            int m = (l + r) >> 1;
            if(a[m][1] == k)
                return m;
            if(a[m][1] > k){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), cmp);
        int ans = 0;
        vector<node> groups;
        groups.push_back(node(prop[0][0], prop[0][1], prop[0][1], 0, 0));
        int k = 0;
        for(int i = 1; i < prop.size(); ++i){
            if(prop[i][0] == groups[k].val){
                groups[k].r = i;
                groups[k].maxd = max(groups[k].maxd, prop[i][1]);
                groups[k].mind = min(groups[k].mind, prop[i][1]);
            }else{
                ++k;
                groups.push_back(node(prop[i][0], prop[i][1], prop[i][1], i, i));
            }
        }
        int maxd = groups[k].maxd;
        for(int i = k - 1; i >= 0; --i){
            if(groups[i].mind < maxd){
                if(groups[i].maxd < maxd){
                    ans += groups[i].r - groups[i].l + 1;
                }else{
                    int m = binSearch(prop, groups[i].l, groups[i].r, maxd);
                    // cout<<i<<" "<<m<<" "<<prop[m][0]<<" "<<prop[m][1]<<" "<<maxd<<endl;
                    if(prop[m][1] >= maxd){
                        ans += m - groups[i].l;
                    }else{
                        ans += m - groups[i].l + 1;
                    }
                }
            }
            maxd = max(maxd, groups[i].maxd);
        }
        return ans;
    }
};