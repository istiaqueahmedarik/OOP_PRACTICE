#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string book_name;
    Node *prev, *next;

    Node(string book_name)
    {
        this->book_name = book_name;
        prev = NULL;
        next = NULL;
    }
};
class DLL
{
    Node *head, *tail;
    int book_count;

public:
    DLL()
    {
        head = NULL;
        tail = NULL;
        book_count = 0;
    }
    void add_book(string book_name)
    {
        Node *new_node = new Node(book_name);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        book_count++;
    }
    void remove_book(string book_name)
    {
        if (book_count == 0)
        {
            cout << "No books in the library" << endl;
            return;
        }
        if (book_count <= 2)
        {
            cout << "You need to add more books to the library" << endl;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->book_name == book_name)
            {
                if (temp == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (temp == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                book_count--;
                break;
            }
            temp = temp->next;
        }
        }
    void print_books()
    {
        if (book_count == 0)
        {
            cout << "No books in the library" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->book_name << endl;
            temp = temp->next;
        }
    }
    void get_size()
    {
        cout << book_count << endl;
    }
};

int main()
{
    DLL d;
    d.add_book("Harry Potter");
    d.add_book("The Alchemist");
    d.add_book("The Da Vinci Code");
    d.print_books();
    d.remove_book("The Alchemist");
    d.print_books();
}