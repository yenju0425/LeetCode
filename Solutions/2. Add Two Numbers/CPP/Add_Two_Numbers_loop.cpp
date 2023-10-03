#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum   = 0;
        int carry = 0;
        
        ListNode* firstNode = nullptr;
        ListNode* preNode   = nullptr;
        
        while(l1 != nullptr || l2 != nullptr || carry) {
            int l1_val = (l1 != nullptr) ? l1->val : 0;
            int l2_val = (l2 != nullptr) ? l2->val : 0;

            sum   = l1_val + l2_val + carry;
            carry = sum / 10;
            sum   = sum % 10;
        
            ListNode* newNode = new ListNode(sum);
            
            if(preNode != nullptr) {
                preNode->next = newNode;
            }
            else {
                firstNode = newNode;
            }
            
            preNode = newNode;

            if(l1 != nullptr) {
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                l2 = l2->next;
            }
        }
        
        return firstNode;
    }
};

int main() {
    Solution S;

    ListNode a2(2);
    ListNode a1(9, &a2);
    ListNode a0(9, &a1);

    ListNode b1(9);
    ListNode b0(9, &b1);

    // 299 + 99 = 398
    ListNode* result = S.addTwoNumbers(&b0, &a0);
    ListNode* temp = nullptr;
    
    // Print the result
    while(result != nullptr) {
        cout << result->val;
        temp = result;
        result = result->next;
        delete temp; // Deallocate memory for each node
    }
    cout << endl;

    return 0;
}
