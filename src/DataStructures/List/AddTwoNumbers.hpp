#include <memory>

/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1: 

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


*/

namespace rsn
{
 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ~ListNode()
    {
        if(this->next) 
        {
            delete this->next;
        }
    }
 };

class AddTwoNumbersSolution {
    inline static constexpr int base = 10;
public:
    std::unique_ptr<ListNode> addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        int carryOut = 0;

        auto makeList = [&head, &current, &carryOut](int lhs, int rhs) -> void 
        {
            auto val = lhs + rhs + carryOut;
            auto digit = val % base;
            carryOut = val / base;
            auto* temp = new ListNode{digit};
            if (!head) 
            {
                head = temp;
                current = head;
            }
            else 
            {
                current->next = temp;
                current = current->next;
            }
            
        };

        while (l1 != nullptr && l2 != nullptr)
        {
            makeList(l1->val, l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        // if only l1 digits left
        while(l1 != nullptr)
        {
            makeList(l1->val, 0);
            l1 = l1->next;
        }

        // if only l2 digits left
        while(l2 != nullptr)
        {
            makeList(0, l2->val);
            l2 = l2->next;
        }

        if(!l1 && !l2 && carryOut) 
        {
            makeList(0, 0);
        }

        return std::unique_ptr<ListNode>(head);
    }
};

}
 