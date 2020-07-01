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
        //p->nextΪδ����ڵ�
        while (p && p->next) {
            if (p->val > p->next->val) {
                //��p->nextС��ǰ��Ľڵ㣬��ȡ���ýڵ㣨ע�ⲻ�Ͽ�ԭ������
                work = p->next;
                p->next = p->next->next;
                
                //��ͷ��ʼ�ҵ���work���������������ǰ��
                if (head->val >= work->val) {
                    //���뵽ͷ��
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
            //������һ���ڵ�
            p = p->next;
        }

        return head;
    }
};

int main(char argc, char** argv) {

    
	return 0;
}