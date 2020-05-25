#include <iostream>
using namespace std;
struct Node {
    int x;
    Node* next;
    Node* prev;
};
struct list {
    Node* first;
    Node* last;
} rost{ NULL, NULL };
short ch;    // для хронологии где и что делали
//-------------------------------------------------------
void addfir()// добавить в начало
{
    Node* el = new Node;
    *el = { ++ch, NULL, NULL };
    if (rost.first) {
        el->next = rost.first;
        rost.first->prev = el;
        rost.first = el;
    }
    else
        rost.last = rost.first = el;
}
//-------------------------------------------------------
void addlas()// добавить в конец
{
    Node* el = new Node;
    *el = { ++ch, NULL, NULL };
    if (rost.last) {
        el->prev = rost.last;
        rost.last->next = el;
        rost.last = el;
    }
    else
        rost.last = rost.first = el;
}
//-------------------------------------------------------
void delfir()// удалить в начале
{
    if (rost.first) {
        Node* time = rost.first;
        rost.first = rost.first->next;
        rost.first->prev = NULL;
        delete time;
    }
    else
        cout << "Null!\n";
}
//-------------------------------------------------------
void dellas()// удалить в конце
{
    if (rost.last) {
        Node* time = rost.last;
        rost.last = rost.last->prev;
        rost.last->next = NULL;
        delete time;
    }
    else
        cout << "Null!\n";
}
//-------------------------------------------------------
void show()// показать
{
    if (rost.first) {
        Node* time = rost.first;
        while (time) {
            cout << time->x << endl;
            time = time->next;
        }
    }
    else
        cout << "Null!\n";
}
//-------------------------------------------------------
int main()
{
    for (;;) {
        char sym;
        cout << "Add first - q\nAdd last - a\nDel first - z\nDel last - w\nShow - s\n";
        cin >> sym;
        switch (sym) {
        case 'q': addfir(); break;
        case 'a': addlas(); break;
        case 'z': delfir(); break;
        case 'w': dellas(); break;
        case 's': show(); break;
        default: continue;
        }
    }
    return 0;
}