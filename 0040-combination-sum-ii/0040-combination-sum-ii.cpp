class Solution {
public:
    void Solve (int idx , int n , vector<int>& ds , vector<int>& candidates , int target , vector<vector<int>> &ans ){
        if(target == 0){
            ans.push_back(ds);
            return ;
        }
        if(idx == n){
            return ;
        }
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            Solve(idx + 1, n ,ds ,candidates , target - candidates[idx] , ans );
            ds.pop_back();
        }
        int j = idx + 1;
        while (j < n && candidates[j] == candidates[idx]) j++;
        Solve(j, n, ds, candidates, target, ans);   
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size() ;
        vector<int> ds;
        vector<vector<int>> ans;
        Solve(0, n, ds, candidates, target, ans);
        return ans ;
    }
};