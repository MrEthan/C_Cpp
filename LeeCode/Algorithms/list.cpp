#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p = head;
        ListNode* work = NULL;

        if (!head || !head->next) {
            return head;
        }
        //p->next为未排序节点
        while (p && p->next) {
            if (p->val > p->next->val) {
                //若p->next小于前面的节点，则取出该节点（注意不断开原有链表）
                work = p->next;
                p->next = p->next->next;
                
                //从头开始找到比work大的数，插在它的前面
                if (head->val >= work->val) {
                    //插入到头部
                    work->next = head;
                    head = work;
                }
                else {
                    ListNode* temp = head;
                    while (temp->next->val < work->val) {
                        temp = temp->next;
                    }
                    temp->next = work;
                    work->next = temp->next->next;
                }
            }
            //遍历下一个节点
            p = p->next;
        }

        return head;
    }
};

int main(char argc, char** argv) {

    
	return 0;
}