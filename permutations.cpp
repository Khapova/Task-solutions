#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
60. Permutation Sequence
Создаём список доступных цифр от 1 до n и переводим k в нумерацию с нуля, уменьшив его на единицу.
На каждой позиции делим k на (m - 1)!, где m — количество оставшихся цифр:
результат определяет индекс следующей цифры в списке.
Выбранную цифру добавляем в ответ и удаляем из списка, после чего обновляем k через остаток от деления.
Повторяем, пока все цифры не будут использованы.
*/

class Solution {
    public:
        int factorial(int n) {
            int ans = 1;
            for (int i = 1; i <= n; i++) {
                ans *= i;
            }
            return ans;
        }
        string getPermutation(int n, int k) {
            vector<int> digital;
            for (int i = 1; i <= n; i++) {
                digital.push_back(i);
            }
            string ans = "";
            k--;
            while (!digital.empty()) {
                int per = factorial(digital.size() - 1);
                int idx = k / per;
                ans += to_string(digital[idx]);
                digital.erase(digital.begin() + idx);
                k %= per;
            }
            return ans;
        }
};