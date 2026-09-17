/*

https://leetcode.com/problems/left-and-right-sum-differences/

Left and Right Sum Differences


*/


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum;

        leftSum.push_back(0);
        leftSum.push_back(nums[0]);
        int sum1 = nums[0];

        for(int i=1; i<nums.size()-1; i++){
            sum1 += nums[i];
            leftSum.push_back(sum1);
        }


        for(int i=1; i<nums.size(); i++){
            int sum2 = nums[i];
            for(int j =i+1; j<nums.size(); j++){
                sum2 += nums[j];
            }
            rightSum.push_back(sum2);
        }
        rightSum.push_back(0);

        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            result.push_back(abs(leftSum[i] - rightSum[i]));
        }
        

        return result;
    }
};