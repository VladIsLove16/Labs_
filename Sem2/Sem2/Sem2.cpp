
#include <iostream>
using namespace std;
char Task='-1';
int k;
class Queue {
private:
    int n=0, q[3];
public: 
    void Push(int k) {
        if (n == sizeof(q)/sizeof(q[0]) ) {
            throw "Очередь заполнена\n";
        }
        *(q + n) = k;
        n++;
        //cout << n;
    }
    int Pop() {
        int m;
        if (n == 0) {
            throw "Очередь пуста\n";
        }
        
        m = *(q);
        for (int i=0 ; i < n-1; i++)
        {
            *(q + i) = *(q + i + 1);
        }
        *(q + n-1) = 0;
        n--;
        //cout << n;
        return m;
    }
};
Queue q;
class Stack {
private:
    int n = 0, s[3];
public:
    void Push(int k) {
        if (n == sizeof(s) / sizeof(s[0])) {
            throw "Cтек заполнен\n";
        }
        *(s + n) = k;
        n++;
        //cout << n;
    }
    int Pop() {
        int m;
        if (n == 0) {
            throw "Стек пуст\n";
        }
        m = *(s + n-1);
        *(s + n-1) = 0;
        n--;
        return m;

    }
};
Stack s;

void RQueue() {
    char Cont = '1';
    while (Cont!='0')
    {
        cout << "Введите действие: Pop(o), Push(i), 0 для выхода из задачи ";
        cin >> Cont;
        switch (Cont)
        {
        case'o':
            try {
                
                cout << "Выведен элемент: "<<q.Pop() << endl;
            }
            catch (...){
                cout << "Ошибка! Очередь пуста\n";
            }
            break;
        case'i':
            try {
                cout << "Введите элемент для вставки: ";
                cin >> k;
                q.Push(k);
            }
            catch (...) {
                cout << "Ошибка! Очередь заполнена\n";
            }
            break;
        case'0':
            cout << "Выход из задачи... \n";
            break;
        default:
            cout << "Такого действия нет \n";
            break;
        }
    }
}
void RStack() {
    char Cont = '1';
    while (Cont != '0')
    {
        cout << "Введите действие: Pop(o), Push(i), 0 для выхода из задачи ";
        cin >> Cont;
        switch (Cont)
        {
        case'o':
            try {
                cout << "Выведен элемент: " << s.Pop() << endl;
            }
            catch (...) {
                cout << "Ошибка! Стек пуст\n";
            }
            break;
        case'i':
            
            try {
                cout << "Введите элемент для вставки: ";
                cin >> k;
                s.Push(k);
            }
            catch (...) {
                cout << "Ошибка! Стек заполнен\n";
            }
            break;
        case'0':
            cout << "Выход из задачи... \n";
            break;
        default:
            cout << "Такого действия нет\n";
            break;
        }
    }
}
int main()
{
    setlocale( 0, "rus");
    while (Task != '0') {
        cout << "Введите номер задачи или 0 для выхода: ";
        cin >> Task;
        switch (Task)
        {
        case '1':
            RQueue();
            break;
        case '2':
            RStack();
            break;
        case '0':
            cout << "Выход из программы... \n";
        default:
            cout << "Такой задачи нет \n";
            break;
        }
    }
}
