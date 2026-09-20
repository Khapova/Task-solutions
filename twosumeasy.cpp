#include <iostream>
#include <vector>
using namespace std;

/*
1. Two sum
Перебираем все возможные пары элементов: первый цикл выбирает первый элемент,
а второй начинается с i + 1, чтобы не использовать один элемент дважды.
Если сумма элементов равна target, сразу возвращаем их индексы.
Если подходящей пары нет, нужно вернуть пустой вектор.
*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int len = nums.size();
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    if(nums[i] + nums[j] == target) {
                        return {i, j};
                    }
                }
            }
        }
};