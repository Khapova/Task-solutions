#include <iostream>
using namespace std;

/*
2. Add Two Numbers
Создаём фиктивный начальный узел answer, который упрощает построение результирующего списка,
и переменную carry для переноса в следующий разряд.
Пока хотя бы один список не закончился или остался перенос,
складываем значения текущих узлов и carry;
последняя цифра суммы (sum % 10) становится новым узлом результата, а sum / 10 — новым переносом.
После каждой итерации передвигаем указатели по исходным спискам и в конце возвращаем answer.next,
пропуская фиктивный узел.
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode answer(0);
            ListNode* current = &answer;
            int carry = 0;
            while (l1 != nullptr || l2 != nullptr || carry != 0) {
                int val1 = 0;
                int val2 = 0;
                if (l1 != nullptr) {
                    val1 = l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    val2 = l2->val;
                    l2 = l2->next;
                }
                int sum = val1 + val2 + carry;
                int dig = sum % 10;
                carry = sum / 10;
                current->next = new ListNode(dig);
                current = current->next;
            }
            return answer.next;
        }
};