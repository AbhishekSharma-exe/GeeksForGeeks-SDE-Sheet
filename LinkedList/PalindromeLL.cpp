#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

class Solution
{
public:
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node *reverse(Node *head)
    {

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
        {
            return true;
        }

        Node *middle = getMid(head);

        Node *temp = middle->next;
        middle->next = reverse(temp);

        Node *head1 = head;
        Node *head2 = middle->next;

        while (head2 != NULL)
        {
            if (head2->data != head1->data)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};

int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}
