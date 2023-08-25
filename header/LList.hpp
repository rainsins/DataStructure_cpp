#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node
{
public:
    const T _data;
    Node<T> *_next; // 下一个结点

    Node() : _data(0)
    {
        _next = nullptr;
    };
    Node(const T &v) : _data(v)
    {
        _next = nullptr;
    };
};

template <class T>
class LinkList
{
private:
    Node<T> *_head;  // 头结点
    Node<T> *_stern; // 尾结点
    Node<T> *_temp;  // 操作实现的中间使用变量
    mutable size_t _size;

public:
    LinkList();                                   // 构建一个单链表;
    LinkList(const T &v);                         // 头结点设置为特殊值（如果有需要）
    ~LinkList();                                  // 销毁一个单链表;
    void CreateLinkList(vector<T> &n);            // 使用一个向量创建一个单链表
    void CreateLinkList(T n[], size_t len);       // 使用一个数组创建一个单链表
    void CreateLinkList(size_t len);              // cin输入创建一个单链表
    size_t GetSize();                             // 获取线性表长度
    bool IsEmpty();                               // 判断单链表是否为空
    vector<int> Find(const T &data);              // 查找节点
    vector<int> ForDeleteFind(const T &data);     // 查找结点，返回该值的索引递减数组，该序列只能用于删除操作
    Node<T> *FindIndex(int index);                // 查找索引节点
    void InsertElemAtEnd(const T &data);          // 在尾部插入指定的元素
    void InsertElemAtIndex(const T &data, int n); // 在指定位置插入指定元素
    void InsertElemAtHead(const T &data);         // 在头部插入指定元素
    void DeleteElemAtEnd();                       // 在尾部删除元素
    void DeleteElemAtIndex(int n);                // 删除索引元素
    void DeleteAll();                             // 删除所有数据
    void DeleteElemAtPoint(const T &data);        // 删除指定的数据
    void DeleteElemAtHead();                      // 在头部删除节点
    void Show();                                  // 展示链表
};

// 创建一个空链表
template <class T>
LinkList<T>::LinkList() : _size(0)
{
    this->_head = this->_stern = this->_temp = new Node<T>();
};

// 创建一个头结点是特殊值的空链表
template <class T>
LinkList<T>::LinkList(const T &v) : _size(0)
{
    this->_head = this->_stern = new Node<T>(v);
    this->_temp = nullptr;
};

// 销毁一个单链表;
template <class T>
LinkList<T>::~LinkList()
{
    delete _head;
};

// 使用vector创建一个单链表
template <class T>
void LinkList<T>::CreateLinkList(vector<T> &n)
{
    size_t size = n.size();
    for (size_t i = 0; i < size; i++)
        this->InsertElemAtEnd(n[i]);
};

// 使用一个数组创建单链表
template <class T>
void LinkList<T>::CreateLinkList(T n[], size_t len)
{
    this->_temp = this->_head;
    for (size_t i = 0; i < len; i++)
        this->InsertElemAtEnd(n[i]);
}

// cin创建链表
template <class T>
void LinkList<T>::CreateLinkList(size_t len)
{
    T value;
    for (size_t i = 0; i < len; i++)
    {

        cout << "输入第" << i + 1 << "元素:";
        cin >> value;
        InsertElemAtEnd(value);
    }
}

// 尾部插入
template <class T>
void LinkList<T>::InsertElemAtEnd(const T &data)
{
    Node<T> *newnd = new Node<T>(data);
    this->_stern->_next = newnd;
    this->_stern = newnd;
    this->_size++;
};

// 头插
template <class T>
void LinkList<T>::InsertElemAtHead(const T &data)
{
    Node<T> *newnd = new Node<T>(data);
    this->_temp = this->_head->_next;
    this->_head->_next = newnd;
    newnd->_next = this->_temp;
    this->_size++;
}

// 查找结点，返回该值的索引数组
template <class T>
vector<int> LinkList<T>::Find(const T &data)
{
    vector<int> value = vector<int>();
    this->_temp = this->_head;
    int j = 0;
    while (this->_temp != nullptr)
    {
        if (data == this->_temp->_data)
        {
            value.push_back(j);
        }
        j++;
        this->_temp = this->_temp->_next;
    }
    return value;
}

// 查找结点，返回该值的索引递减数组，该序列只能用于删除操作
template <class T>
vector<int> LinkList<T>::ForDeleteFind(const T &data)
{
    vector<int> value = vector<int>();
    this->_temp = this->_head;
    int i = 0, j = 0;
    while (this->_temp != nullptr)
    {
        if (data == this->_temp->_data)
        {
            value.push_back(j - i);
            i++;
        }
        j++;
        this->_temp = this->_temp->_next;
    }
    return value;
}

// 使用索引查找结点
template <class T>
Node<T> *LinkList<T>::FindIndex(int index)
{
    this->_temp = this->_head;
    if (index > this->_size || index < 0)
        return nullptr;
    if (index == 0)
        return this->_head;
    for (int l = index; l > 0; l--)
        this->_temp = this->_temp->_next;
    return this->_temp;
}

// 在索引位置插入元素
template <class T>
void LinkList<T>::InsertElemAtIndex(const T &data, int n)
{
    if (n > this->_size + 1 || n <= 0)
        return;
    if (n == this->_size + 1)
        this->InsertElemAtEnd(data);
    this->_temp = FindIndex(n - 1);
    Node<T> *newnd = new Node<T>(data);
    Node<T> *tnd = this->_temp->_next;
    this->_temp->_next = newnd;
    newnd->_next = tnd;
    this->_size++;
}

// 删除该索引位置元素
template <class T>
void LinkList<T>::DeleteElemAtIndex(int n)
{
    if (n > this->_size || n <= 0)
        return;
    this->_temp = FindIndex(n - 1);
    Node<T> *tnd = this->_temp->_next;
    this->_temp->_next = this->_temp->_next->_next;
    if (n == this->_size)
        this->_stern = this->_temp;
    delete tnd;
    tnd = nullptr;
    this->_temp = nullptr;
    this->_size--;
}

// 在尾部删除元素
template <class T>
void LinkList<T>::DeleteElemAtEnd()
{
    if (this->_size == 0)
        return;
    Node<T> *tnd = this->FindIndex(this->_size - 1);
    tnd->_next = nullptr;
    this->_stern = tnd;
    this->_size--;
}

// 删除所有元素
template <class T>
void LinkList<T>::DeleteAll()
{
    this->_temp = this->_head->_next;
    this->_head->_next = nullptr;
    delete this->_temp;
    this->_temp = nullptr;
    this->_stern = this->_head;
    this->_size = 0;
}

template <class T>
void LinkList<T>::DeleteElemAtPoint(const T &data)
{
    vector<int> indexs = this->ForDeleteFind(data);
    for (auto i : indexs)
        this->DeleteElemAtIndex(i);
}

template <class T>
void LinkList<T>::DeleteElemAtHead()
{
    if (this->_head->_next == nullptr)
        return;
    this->_temp = this->_head->_next;
    this->_head->_next = this->_head->_next->_next;
    delete this->_temp;
    this->_temp = nullptr;
    this->_size--;
}

// 表是否为空
template <class T>
bool LinkList<T>::IsEmpty()
{
    return this->_size == 0;
}

// 表长
template <class T>
size_t LinkList<T>::GetSize()
{
    return this->_size;
}

template <class T>
void LinkList<T>::Show()
{
    this->_temp = this->_head->_next;
    while (this->_temp != nullptr)
    {
        if (this->_temp->_next == nullptr)
            cout << this->_temp->_data;
        else
            cout << this->_temp->_data << "->";

        this->_temp = this->_temp->_next;
    }
    cout << endl;
    this->_temp = this->_head;
};
