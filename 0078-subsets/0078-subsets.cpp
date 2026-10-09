//By bit manipulation
class Solution {
private:
    vector<vector<int>> func(vector<int>& nums, int i) {
        int n=(1<<nums.size());
        vector<vector<int>> ans;
        for (int num=0;num<n;num++){
            vector<int>temp;
            for(int i=0;i<nums.size();i++){
                if((num&(1<<i))!=0){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        ans = func(nums, 0);
        return ans;
    }
}; 