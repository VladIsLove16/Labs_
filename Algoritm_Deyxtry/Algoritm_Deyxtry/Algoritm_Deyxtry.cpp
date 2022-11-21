
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define n 10
int begin_index=0;
int v[n]//посещена ли вершина
, d[n]//минимальные расстояния до вершин графа от исходной
, von_punkt[n]// номера вершин ([eq знает)
, a[n][n];//расстояния между вершинами
int minindex, mini, temp,j=0,k=0;
int main()
{
    string line;
    setlocale(0, "");
    ifstream in1("D:\\Informatika\\Algoritm_Deyxtry\\Data_In.txt");
    if (in1.is_open())
    {
        cout << "Вывод матрицы расстояний из файла\n";
        while (getline(in1, line))
        {
            //cout << line << endl;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ') {
                    temp = 0;
                    do {
                        temp *= 10;
                        temp += (int)(line[i]-'0');
                        i++;
                    } while (line[i] != ' ' && i< line.length());
                    a[j][k] = temp;
                    cout << a[j][k]<<" ";
                        k++;
                }
            }
            k = 0;
            j++;
            cout << endl;
        }
    }
    in1.close();
    cout << "Матрица расстояний:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout<< a[i][j]<<" ";
        cout << endl;
    }
   
    for (int i = 0; i < n; i++) {
        d[i] = 10000;
        v[i] = 0;
    }   
    d[begin_index] = 0;
    do {
        minindex = 10000;
        mini = 10000;
        for (int i = 0; i < n; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 0) && (d[i] < mini))
            { // Переприсваиваем значения
                mini = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = mini + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 1;
            cout << "Расстояния до вершин от начальной с индексом "<<begin_index<<" на данном шаге : ";
            for (int i = 0; i < n; i++)
            {
                
                cout << d[i]<<" ";
            }
            cout << endl;
        }
    } while (minindex < 10000);
    cout<<("\nКратчайшие расстояния до вершин: \n");
    for (int i = 0; i < n; i++)
        cout<< d[i]<<" ";
    // Восстановление пути
    int ver[n]; // массив посещенных вершин
    int end = n-1; // индекс конечной вершины = 5 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = d[end]; // вес конечной вершины
    while (end != begin_index) // пока не дошли до начальной вершины
    {
        for (int i = 0; i < n; i++) // просматриваем все вершины
            if (a[i][end] != 0) // если связь есть
            {
                int temp = weight - a[i][end]; // определяем вес пути из
               // предыдущей вершины
                    if (temp == d[i]) // если вес совпал с рассчитанным
                    { // значит из этой вершины и был переход
                        weight = temp; // сохраняем новый вес
                        end = i; // сохраняем предыдущую вершину
                        ver[k] = i + 1; // и записываем ее в массив
                        k++;
                    }
            }
    }
    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    cout << "\nЗапись кратчайшего пути в файл\n";
    ofstream out;
    out.open("D:\\Informatika\\Algoritm_Deyxtry\\Data_Out.txt");
    if (out.is_open())
    {
        for (int i = k - 1; i >= 0; i--) 
            out << ver[i];
    }
    out.close();
    ifstream in("D:\\Informatika\\Algoritm_Deyxtry\\Data_Out.txt");
    if (in.is_open())
    {
        cout << "Вывод кратчайшего пути от начальной  до вершины с максимальным индексом из файла\n";
        while (getline(in, line))
        {   
            cout << line << endl;
        }
    }
    in.close();
    return 0;
}
