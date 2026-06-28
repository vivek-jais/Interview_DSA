class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<pair<long long, long long>> merged;

        for(auto &v:occupiedIntervals){
            long long l = v[0], r= v[1];
            if(merged.empty() || l>merged.back().second +1){
                merged.push_back({l,r});
            }else{
                merged.back().second = max(merged.back().second, r);
            }
        }

        vector<vector<int>> ans;

        for(auto &[l,r]:merged){
            if(r<freeStart || l>freeEnd){
                ans.push_back({(int)l, (int)r});
                continue;
            }

            if(l<freeStart){
                ans.push_back({(int)l, freeStart -1});
            }

            if(r>freeEnd){
                ans.push_back({freeEnd+1,(int)r});
            }
        }
        return ans;
    }
};