// TC: O(N)
// MC: O(N) 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int diffNum = 0;
        for(auto num : nums)
        {
            diffNum = diffNum ^ num;
        }
        return diffNum;
    }
};