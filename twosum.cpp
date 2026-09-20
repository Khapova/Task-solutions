#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> answer;
            int curr_sum;
            int left_idx = 0;
            int right_idx = nums.size() - 1;
            while (left_idx < right_idx) {
                curr_sum = nums[left_idx] + nums[right_idx];
                if (curr_sum == target) {
                    answer.push_back(left_idx + 1);
                    answer.push_back(right_idx + 1);
                    break;
                }
                else if (curr_sum < target) {
                    left_idx += 1;
                }
                else {
                    right_idx -= 1;
                }
            }
            return answer;
        }
};