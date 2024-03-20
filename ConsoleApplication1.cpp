﻿#include <iostream>

using namespace std;

struct Node // вузол
{
    double data;
    Node* next;
};

// Додавання вузла
void Add_Node(Node*& head, Node*& end, double x)
{
    Node* c = new Node;
    c->next = NULL;
    c->data = x;
    if (head == NULL)
    {
        head = c; end = c;
    }
    else
    {
        end->next = c;
        end = c;
    }
}

// Виведення списку
void Print_List(Node* head)
{
    cout << "\nThe list:" << endl;
    Node* c = head;
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
}

// Звільнення пам'яті
void Free_Memory(Node*& head)
{
    Node* c = head;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

void Insert_After(Node*& prev, int x)
{
    if (prev == NULL)
    {
        cout << "The given previous node cannot be NULL!";
        return;
    }
    Node* c = new Node;
    c->data = x;
    c->next = prev->next;
    prev->next = c;
}

void DeleteNodePtr(Node*& head, Node*& end, Node* ptr)
{
    if (ptr == NULL) return;
    Node* c = head;
    if (ptr == head)
    {
        head = c->next;
        delete c;
        return;
    }

    while (c->next != ptr && c != NULL)
    {
        c = c->next;
    }
    if (c == NULL) return;
    c->next = ptr->next; // с->next->next
    if (ptr == end) end = c;
    delete ptr;
}

void Task1()
{
    // 15 | дійсний | Обчислити добуток мінімального і максимального елементів списку
    Node* head = NULL, * end = NULL, * c;
    double x;
    cout << "Task1 Input 10 elements:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cin >> x; Add_Node(head, end, x);
    }
    Print_List(head);

    double min = head->data, max = head->data; // мін. та макс.
    c = new Node;
    c = head;
    while (c != NULL) // цикл знаходження мін та макс
    {
        if (c->data > max) max = c->data;
        if (c->data < min) min = c->data;
        c = c->next;
    }
    cout << "\nMin = " << min << ". Max = " << max << ". Min*Max = " << min * max << endl;

    Free_Memory(head); // кінець роботи програми
    return;
}

void Task2()
{
    // 15 | дійсний | Поміняти місцями максимальний елемент з першим
    Node* head = NULL, * end = NULL, * c;
    double x;
    cout << "Task2 Input 10 elements:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cin >> x; Add_Node(head, end, x);
    }
    Print_List(head);

    double max = head->data; // макс.
    c = new Node;
    c = head;
    while (c != NULL) // цикл знаходження мін та макс
    {
        if (c->data > max) max = c->data;
        c = c->next;
    }

    if (head->data == max)
    {
        cout << "\nMax element is already first element";
        return;
    }

    Node* prev = NULL;
    c = head;
    while (c != NULL && c->data != max)
    {
        prev = c;
        c = c->next;
    }

    Node* tmp = head->next;
    prev->next = head;
    head->next = c->next;
    c->next = tmp;

    head = c;

    cout << "New list:" << endl;
    Print_List(head);

    Free_Memory(head); // кінець роботи програми
    return;
}

void Task3()
{
    // 15 | цілий | Вводити елементи, доки сума елементыв не стане більшою за -10
    // Вставити в список останній парний елемент після кожного непарного елемента 
    Node* head = NULL, * end = NULL, * c;
    int x, sum = 0;
    cout << "Task3 Input 10 elements:" << endl;
    while (true)
    {
        cin >> x; Add_Node(head, end, x);
        if (x < 0) sum += x;
        if (sum < -10) break;
    }
    Print_List(head);

    Node* last_even = NULL; c = head;
    int i = 0;
    if (head == end)
    {
        cout << "\nCannot execute program with only one element" << endl;
        return;
    }
    else
    {
        while (c != NULL) // Знаходження останнього парного елемента
        {
            i++;
            if (c->next == NULL && i % 2 != 0)
            {
                break;
            }
            last_even = c;
            c = c->next;
        }
    }
    
    c = head;
    i = 0;
    while (c->next != NULL && c != NULL)
    {
        i++;
        if (i % 2 != 0)
        {
            Node* tmp = c;
            c = c->next;
            Insert_After(tmp, last_even->data);
            continue;
        }
        c = c->next;
    }
    Print_List(head);


    Free_Memory(head);
    return;
}

void Task4()
{
    // 15 | Цілий | Вводити елементи, доки сума парних елементів не стане більшою за 20
    // Вилучити всі елементи з абсолютним значенням менше 5
    Node* head = NULL, * end = NULL, * c;
    int x, i = 0, sum = 0;
    cout << "Task3 Input 10 elements:" << endl;
    while (sum < 20)
    {
        i++;
        cin >> x; Add_Node(head, end, x);
        if (i % 2 == 0) sum += x;
    }
    Print_List(head);

    c = head;
    while (c != NULL)
    {
        if (abs(c->data) < 5)
        {
            Node* tmp = c;
            c = c->next;
            DeleteNodePtr(head, end, tmp);
        }
        else
        {
            c = c->next;
        }

    }
    Print_List(head);

    Free_Memory(head);
    return;
}

int main()
{
    //Task1();
    //Task2();
    //Task3();
    Task4();

    return 0;
}