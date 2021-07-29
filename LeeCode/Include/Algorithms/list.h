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

        //p为未排序节点
        while (p) {
            //跳过本身已经有序节点
            if (p->val >= prev->val) {
                prev = p;
                p = p->next;
            }
            else {
                //p摘链
                prev->next = p->next;
                work = p;
                p = p->next;
                //从头开始找比p小的节点，插入到它的前面
                if (head->val > work->val) {
                    //插入到头节点之前
                    work->next = head;
                    head = work;
                }
                else {
                    //插入到头节点后
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

    //使用哨兵节点，无需特殊处理头结点改变的情况
    ListNode* insertionSortList1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur = NULL, *prev = NULL, *ans = NULL;
        
        dummy_head->next = head;
        prev = head; //prev指向当前已排序的最大节点
        cur = head->next;

        while (cur) {
            if (cur->val >= prev->val) {
                //跳过已排序部分
                prev = cur;
                cur = cur->next;
                continue;
            }
            //cur节点摘链
            prev->next = cur->next;
            ListNode* p = dummy_head;
            //从头开始查找合适位置插入
            while (p->next->val <= cur->val) {
                p = p->next;
            }
            //找到比cur大的节点为p->next，把cur插入到p节点后面
            cur->next = p->next;
            p->next = cur;
            //继续遍历
            cur = prev->next;
        }
        ans = dummy_head->next;

        delete dummy_head;

        return ans;
    }

    //新建链表，从原链表取节点插入新链表
    ListNode* insertionSortList2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* oldNode = NULL;
        ListNode* dummy_head = new ListNode(0);
        ListNode* ans = NULL;

        /* 摘下第一个节点插入新链表 */
        dummy_head->next = head;
        head = head->next;
        dummy_head->next->next = NULL;

        while (head) {
            //从原链表取节点
            oldNode = head;
            head = head->next;
            //断开摘下的节点与原链表的连接
            oldNode->next = NULL;

            //把节点按顺序插入新链表
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
//    chrono::duration<double, micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
//    cout << "insertionSortList0 " << "max:" << max << " time: " << elapsed.count() << "us" << endl;
//
//    start = chrono::steady_clock::now();
//    head = solution.insertionSortList1(head);
//    end = chrono::steady_clock::now();
//    elapsed = end - start; // std::micro 表示以微秒为时间单位
//    cout << "insertionSortList1 " << "max:" << max << " time: " << elapsed.count() << "us" << endl;
//
//    start = chrono::steady_clock::now();
//    head = solution.insertionSortList2(head);
//    end = chrono::steady_clock::now();
//    elapsed = end - start; // std::micro 表示以微秒为时间单位
//    cout << "insertionSortList2 " << "max:" << max << " time: " << elapsed.count() << "us" << endl;
//
//    //solution.printList(head);
//
//	return 0;
//};
