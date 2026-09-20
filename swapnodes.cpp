#include <iostream>
using namespace std;

/*
24. Swap Nodes in Pairs
Сначала проверяем, что в списке есть хотя бы два узла, и сохраняем второй узел как новую голову.
Затем берём узлы парами, сохраняем начало следующей пары и
меняем направление связей между двумя текущими узлами.
С помощью указателя previous соединяем переставленную пару с предыдущей,
после чего переходим к следующей паре.
В конце возвращаем новую голову списка.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        ListNode* newhead = head->next;
        ListNode* previous = nullptr;
        while (current != nullptr && current->next != nullptr) {
            ListNode* nextcur = current->next;
            ListNode* nextnext = nextcur->next;
            nextcur->next = current;
            current->next = nextnext;
            if (previous != nullptr) {
                previous->next = nextcur;
            }
            previous = current;
            current = nextnext;
        }        
    }
};