#include <iostream>
#include <chrono>

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
    ListNode* insertionSortList0(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* work = NULL;
        ListNode* prev = head;
        ListNode* p = head->next;

        //pΪδ����ڵ�
        while (p) {
            //���������Ѿ�����ڵ�
            if (p->val >= prev->val) {
                prev = p;
                p = p->next;
            }
            else {
                //pժ��
                prev->next = p->next;
                work = p;
                p = p->next;
                //��ͷ��ʼ�ұ�pС�Ľڵ㣬���뵽����ǰ��
                if (head->val > work->val) {
                    //���뵽ͷ�ڵ�֮ǰ
                    work->next = head;
                    head = work;
                }
                else {
                    //���뵽ͷ�ڵ��
                    ListNode* temp = head;
                    while (temp->next->val <= work->val) {
                        temp = temp->next;
                    }
                    work->next = temp->next;
                    temp->next = work;
                }
            }
        }

        return head;
    }

    //ʹ���ڱ��ڵ㣬�������⴦��ͷ���ı�����
    ListNode* insertionSortList1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur = NULL, *prev = NULL, *ans = NULL;
        
        dummy_head->next = head;
        prev = head; //prevָ��ǰ����������ڵ�
        cur = head->next;

        while (cur) {
            if (cur->val >= prev->val) {
                //���������򲿷�
                prev = cur;
                cur = cur->next;
                continue;
            }
            //cur�ڵ�ժ��
            prev->next = cur->next;
            ListNode* p = dummy_head;
            //��ͷ��ʼ���Һ���λ�ò���
            while (p->next->val <= cur->val) {
                p = p->next;
            }
            //�ҵ���cur��Ľڵ�Ϊp->next����cur���뵽p�ڵ����
            cur->next = p->next;
            p->next = cur;
            //��������
            cur = prev->next;
        }
        ans = dummy_head->next;

        delete dummy_head;

        return ans;
    }

    //�½�������ԭ����ȡ�ڵ����������
    ListNode* insertionSortList2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* oldNode = NULL;
        ListNode* dummy_head = new ListNode(0);
        ListNode* ans = NULL;

        /* ժ�µ�һ���ڵ���������� */
        dummy_head->next = head;
        head = head->next;
        dummy_head->next->next = NULL;

        while (head) {
            //��ԭ����ȡ�ڵ�
            oldNode = head;
            head = head->next;
            //�Ͽ�ժ�µĽڵ���ԭ���������
            oldNode->next = NULL;

            //�ѽڵ㰴˳�����������
            ListNode* p = dummy_head->next;
            ListNode* prev = dummy_head;
            while (p != NULL && p->val <= oldNode->val) {
                prev = p;
                p = p->next;
            }
            oldNode->next = prev->next;
            prev->next = oldNode;
        }
        ans = dummy_head->next;

        delete dummy_head;

        return ans;
    }

    int addHeadList(ListNode** head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = &newNode;
        }
        else {
            newNode->next = *head;
            *head = newNode;
        }
        return 0;
    }

    void printList(ListNode* head) {
        if (!head) {
            cout << "list is null" << endl;
            return;
        }
        ListNode* p = head;
        while (p){
            cout << p->val << ',';
            p = p->next;
        }
        cout << endl;
        return;
    }
};


//int main(char argc, char** argv) {
//    Solution solution;
//    ListNode* head = new ListNode(0);
//    const int max = 10000;
//
//    srand((unsigned int)time(NULL));
//    for (int i = 0; i < max; i++) {
//        solution.addHeadList(&head, rand() % INT_MAX);
//    }
//
//    //solution.printList(head);
//    auto start = chrono::steady_clock::now();
//    head = solution.insertionSortList0(head);
//    auto end = chrono::steady_clock::now();
//    chrono::duration<double, micro> elapsed = end - start; // std::micro ��ʾ��΢��Ϊʱ�䵥λ
//    cout << "insertionSortList0 " << "max:" << max << " time: " << elapsed.count() << "us" << endl;
//
//    start = chrono::steady_clock::now();
//    head = solution.insertionSortList1(head);
//    end = chrono::steady_clock::now();
//    elapsed = end - start; // std::micro ��ʾ��΢��Ϊʱ�䵥λ
//    cout << "insertionSortList1 " << "max:" << max << " time: " << elapsed.count() << "us" << endl;
//
//    start = chrono::steady_clock::now();
//    head = solution.insertionSortList2(head);
//    end = chrono::steady_clock::now();
//    elapsed = end - start; // std::micro ��ʾ��΢��Ϊʱ�䵥λ
//    cout << "insertionSortList2 " << "max:" << max << " time: " << elapsed.count() << "us" << endl;
//
//    //solution.printList(head);
//
//	return 0;
//};
