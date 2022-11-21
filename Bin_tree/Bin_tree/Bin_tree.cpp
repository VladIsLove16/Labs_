// Bin_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <assert.h>
#include <string.h>
#include < queue >
#include < stack >

using namespace std;
struct bin_node
{
int data;
struct bin_node* left;
struct bin_node* right;
};
/*Бинарное дерево*/
struct bin_tree
{
    struct bin_node* root; //Указатель на корень дерева
    int count; //Количество вершин в дереве
};
struct bin_tree* bin_create()
{
   struct bin_tree *tree =new struct bin_tree;
   /* память и возвращает указатель на нее* /*/
    if (tree == NULL) //если памяти недостаточно
        return NULL;
    tree->root = NULL; //Дерево пустое
    tree->count = 0;
    return tree;
}
int bin_search(const struct bin_tree* tree, int item)
{
    const struct bin_node* node;
    assert (tree != NULL); /*проверяет чему равен адрес tree. Если он нулевой, то функция
    завершается.*/
    node = tree->root; //присваивается адрес корня дерева
    for (;;)
    {
        if (node == NULL)
            return NULL; //дерево пустое или вершина есть лист
        else if (item == node->data) /*если узел не последний и равен искомому, то
        возвращается 1 как признак успешного поиска*/
            return 1;
        else if (item > node->data) //если узел не последний и меньше искомого то   идем вправо по дереву
            node = node->right;
        else
            node = node->left; //если не так то идем влево по дереву
    }
}
int bin_insert(struct bin_tree* tree, int item)
{
    struct bin_node* node, ** nee;
    assert(tree != NULL);
    nee = &tree->root;
    node = tree->root;
    for (;;)
    {
        if (node == NULL) //дерево пусто или вершина отсутствует
        {
            *nee = new bin_node; //запись в поле root или left или right
            node = *nee; /*node и root (или left или right) будут равны.
            node указывает на следующую вершину. Пунктир.
            Цветные линии*/
            if (node != NULL) //проверка результата выделения памяти
            {
                node->data = item;
                node->left = node->right = NULL;
                tree->count++;
                return 1;
            }
            else
                return 0;
        }
        else if (item == node->data)
            return 2;
        else if (item > node->data)
        {
            nee = &node->right;
            node = node->right;
        }
        else
        {
            nee = &node->left;
            node = node->left;
        }
    }
}
int bin_delete(struct bin_tree* tree, int item)
{
    struct bin_node** q, * z;
    assert(tree != NULL);
    q = &tree->root;
    z = tree->root;
    //Поиск элемента удаления
    for (;;)
    {
        if (z == NULL)
            return NULL;
        else if (item == z->data)
            break;
        else if (item > z->data)
        {
            q = &z->right;
            z = z->right;
        }
        else
        {
            q = &z->left;
            z = z->left;
        }
    }
    //Первый случай
    if (z->right == NULL)
        *q = z->left;
    else
    {
        struct bin_node* y = z->right;
        //Второй случай
        if (y->left == NULL)
        {
            y->left = z->left;
            *q = y;
        }
        //Третий случай
        else
        {
            struct bin_node* x = y->left;
            while (x->left != NULL)
            {
                y = x;
                x = y->left;
            }
            y->left = x->right;
            x->left = z->left;
            x->right = z->right;
            *q = x;
        }
    }
    tree->count--;
    free(z); //Удаление элемента
    return 1;
}
void levelOrderPrint(bin_node* root) {
    if (root == NULL)
    {
        return;
    }
    queue<bin_node*> q; // Создаем очередь
    q.push(root); // Вставляем корень в очередь

    while (!q.empty()) // пока очередь не пуста
    {
        bin_node* temp = q.front(); // Берем первый элемент в очереди
        q.pop();  // Удаляем первый элемент в очереди
        cout << temp->data << " "; // Печатаем значение первого элемента в очереди

        if (temp->left != NULL)
            q.push(temp->left);  // Вставляем  в очередь левого потомка

        if (temp->right != NULL)
            q.push(temp->right);  // Вставляем  в очередь правого потомка
    }
}
void preorderPrint(bin_node* root)
{
    if (root == NULL)   // Базовый случай
    {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);   //рекурсивный вызов левого поддерева
    preorderPrint(root->right);  //рекурсивный вызов правого поддерева
}
void inorderPrint(bin_node* root)
{
    if (root == NULL)   // Базовый случай
    {
        return;
    }
    inorderPrint(root->left);   //рекурсивный вызов левого поддерева
    cout << root->data << " ";
    inorderPrint(root->right);  //рекурсивный вызов правого поддерева
}
void postorderPrint(bin_node* root)
{
    if (root == NULL)   // Базовый случай
    {
        return;
    }
    postorderPrint(root->left);   //рекурсивный вызов левого поддерева
    postorderPrint(root->right);  //рекурсивный вызов правого поддерева
    cout << root->data << " ";
}
void reverseInorderPrint(bin_node* root)
{
    if (root == NULL)   // Базовый случай
    {
        return;
    }
    reverseInorderPrint(root->right);  //рекурсивный вызов правого поддерева
    cout << root->data << " ";
    reverseInorderPrint(root->left);   //рекурсивный вызов левого поддерева

}
void iterativePreorder(bin_node* root)
{
    if (root == NULL)
    {
        return;
    }
    stack<bin_node*> s;  // Создаем стек
    s.push(root);  // Вставляем корень в стек
    /* Извлекаем из стека один за другим все элементы.
       Для каждого извлеченного делаем следующее
       1) печатаем его
       2) вставляем в стек правого! потомка
          (Внимание! стек поменяет порядок выполнения на противоположный!)
       3) вставляем в стек левого! потомка */
    while (s.empty() == false)
    {
        // Извлекаем вершину стека и печатаем
        bin_node* temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right)
            s.push(temp->right); // Вставляем в стек правого потомка
        if (temp->left)
            s.push(temp->left);  // Вставляем в стек левого потомка
    }
}
char str_data[100] = "060320020908202289002010340";
const int n = 15;
int tree_data[n];
int main()
{
    setlocale(0, "");
    bin_tree* tree = bin_create();
    for (int i = 0; i < strlen(str_data); i++) {
        if (i + 1 < strlen(str_data)) {
            tree_data[i / 2] = (str_data[i] - '0') * 10 + str_data[i + 1] - '0';
            //cout << tree_data[i / 2] << " ";
        }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        bin_insert(tree, tree_data[i]);
    }
    for (int i = 0; i < n; i++)
    {
        bin_insert(tree, tree_data[i]);
    }
    cout << "Count: " << tree->count << endl;
    cout << "Рисуем дерево: "; cout << endl;
    cout << "Обход в ширину через очередь: ";
    levelOrderPrint(tree->root); cout << endl;
    cout << "Прямой обход через рекурсию: ";
    preorderPrint(tree->root); cout << endl;
    cout << "Cимметричный обход через рекурсию: ";
    inorderPrint(tree->root); cout << endl;
    cout << "Обратный обход через рекурсию: ";
    postorderPrint(tree->root);
    cout << "Обратный cимметричный обход через рекурсию: ";
    reverseInorderPrint(tree->root);
    cout << "Прямой обход через стек: ";
    iterativePreorder(tree->root);
}