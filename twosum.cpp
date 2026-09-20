#include <iostream>
#include <vector>
using namespace std;
/*
167. Two sum II - Input Array Is Sirted
Используем два указателя: left_idx ставим в начало отсортированного массива,
а right_idx — в конец.
Если сумма элементов меньше target, сдвигаем левый указатель вправо,
чтобы увеличить сумму; если больше — сдвигаем правый влево, чтобы уменьшить её.
При совпадении возвращаем индексы, увеличенные на 1.
*/

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