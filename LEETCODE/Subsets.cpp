// 78. Subsets
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given an integer array nums of unique elements, return all possible

// (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

 

// Constraints:

//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10
//     All the numbers of nums are unique.


class Solution {
public:
     void f(vector<int> nums, int index,vector<int> temp,vector<vector<int>> &ans){
            if(index==nums.size()){
                ans.push_back(temp);
                return;
            }
            temp.push_back(nums[index]);
            f(nums,index+1,temp,ans);
            temp.pop_back();
            f(nums,index+1,temp,ans);
            return ;
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans;
        vector <int> temp;
       
        f(nums,0,temp,ans);
        return ans;
    }

};