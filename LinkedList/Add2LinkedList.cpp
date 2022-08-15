#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    struct Node *reverseList(struct Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void insertTail(struct Node *&head, struct Node *&tail, int digit)
    {
        Node *temp = new Node(digit);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node *add(struct Node *first, struct Node *second)
    {

        int carry = 0;
        Node *ansTail = NULL;
        Node *ansHead = NULL;

        while (first != NULL && second != NULL)
        {
            int sum = carry + first->data + second->data;

            int digit = sum % 10;

            insertTail(ansHead, ansTail, digit);
            carry = sum / 10;

            first = first->next;
            second = second->next;
        }

        while (first != NULL)
        {

            int sum = carry + first->data;
            int digit = sum % 10;
            insertTail(ansHead, ansTail, digit);
            carry = sum / 10;

            first = first->next;
        }

        while (second != NULL)
        {

            int sum = carry + second->data;
            int digit = sum % 10;
            insertTail(ansHead, ansTail, digit);
            carry = sum / 10;

            second = second->next;
        }
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            insertTail(ansHead, ansTail, digit);
            carry = sum / 10;
        }

        return ansHead;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverseList(first);
        second = reverseList(second);

        Node *ans = add(first, second);
        ans = reverseList(ans);

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
