#pragma once
#include "opencv2/opencv.hpp"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <chrono>
#include <map>

using namespace std;
using namespace cv;

template <class E>
class Sort
{
public:
    // virtual void sort(E &a) = 0;
    // 是否升序
    bool isSort(vector<E> &a)
    {
        int l = a.size();

        for (int i = 0; i < l; i++)
        {
            if (less(a[i], a[i - 1]))
                return false;
        }

        return true;
    }

protected:
    // 是否小于
    static bool less(E &p, E &b)
    {
        return p < b;
    }
    // 交换
    static void exch(vector<E> &a, int i, int j)
    {
        E t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    // 得到最大值索引
    static int v_max_index(vector<E> &a)
    {
        int biggest = (int)*max_element(begin(a), end(a));
        return biggest;
    }
    // 得到最小值索引
    static int v_min_index(vector<E> &a)
    {
        int biggest = (int)*min_element(begin(a), end(a));
        return biggest;
    }
    // 得到最大位数
    static int max_digit(vector<E> &a)
    {
        int max = v_max_index(a);
        int d = 1;
        while (max >= 10)
        {
            max = max / 10;
            d++;
        }
        return d;
    }

    // 堆的操作
    // 父结点索引
    static int parent(int k)
    {
        return ((k - 1) / 2);
    }
    // 左孩子索引
    static int left(int k)
    {
        return (2 * k + 1);
    }
    // 右孩子索引
    static int right(int k)
    {
        return (2 * k + 2);
    }
    // 上浮
    static void swim(vector<E> &a, int k, bool isImg)
    {
        while (k > 0 && less(a[parent(k)], a[k]))
        {
            exch(a, parent(k), k);
            k = parent(k);
        }
    }
    // 下沉
    static void sink(vector<E> &a, int k, int l, int &index, bool isImg)
    {
        while (left(k) < l)
        {
            int j = left(k);
            if (j < l - 1 && less(a[j], a[right(k)]))
                j++;
            if (!less(a[k], a[j]))
                break;
            exch(a, j, k);
            k = j;
            if (isImg)
            {
                show_lzb(a, index, "堆排序");
                ++index;
            }
        }
        if (isImg)
        {
            show_lzb(a, index, "堆排序");
            ++index;
        }
    }

public:
    // 测试时间
    static long long getCurrentTimeNano()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }
    // 将降序排列
    static void re_vet(vector<E> &a)
    {
        std::sort(a.rbegin(), a.rend());
    }
    // 测试用例生成
    // n为生成的数量，RangeL和RangeR表示生成的数在这两个之间
    static vector<E> generateRandomA(int n, int RangeL, int RangeR)
    {
        vector<E> a;

        if (RangeL > RangeR)
        {
            int temp = RangeL;
            RangeL = RangeR;
            RangeR = temp;
        }

        srand((unsigned)time(NULL));

        for (int i = 0; i < n; i++)
        {
            a.push_back((E)(rand() % (RangeR - RangeL + 1) + RangeL));
        }

        return a;
    }
    // 展示数组
    static void show(vector<E> &a)
    {
        int l = a.size();

        for (int i = 0; i < l; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    // 可视化数组
    static void show_lzb(vector<E> &arr, int title, string _type)
    {
        Mat drawImage = Mat::zeros(Size(768, 256), CV_8UC3);

        int _max = 0;
        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > _max)
            {
                _max = arr[i]; // 找到数组中的最大值，后面需要归一化
            }
        }

        for (int i = 0; i < 768; i++)
        {
            int current_value = (int)(double(arr[i]) / double(_max) * 256); // 每次都要将数组的值根据最大值归一化到0-255之间
            line(drawImage, Point(i, drawImage.rows - 1), Point(i, drawImage.rows - 1 - current_value), Scalar(255, 0, 255), 1, 8);
        }
        // imshow(title, drawImage);
        // waitKey(0);
        string _title = to_string(title);

        string path1;
        string path2 = "./img/";
        string path3 = "/";
        string c = ".jpg";

        path1.append(path2 + _type + path3 + _title + c);
        imwrite(path1, drawImage);
    }

    // 选择排序
    static void Selection(vector<E> &a, bool isImg)
    {
        E temp;
        int index = 0;
        int lenght = a.size();
        for (int i = 0; i < lenght; i++)
        {
            index = i;
            temp = a[i];
            for (int j = i; j < lenght; j++)
            {
                if (a[j] < temp)
                {
                    temp = a[j];
                    index = j;
                }
            }
            exch(a, i, index);
            if (isImg)
                show_lzb(a, i, "选择排序");
        }
    }

    // 插入排序
    static void Insertion(vector<E> &a, bool isImg)
    {
        int lenght = a.size();
        for (int i = 0; i < lenght; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (a[j] < a[j - 1])
                {
                    exch(a, j, j - 1);
                }
            }
            if (isImg)
                show_lzb(a, i, "插入排序");
        }
    }

    static void Insertion(vector<E> &a, int low, int hig, bool isImg, int &co)
    {
        for (int i = low; i <= hig; i++)
        {
            for (int j = i; j > low; j--)
            {
                if (a[j] < a[j - 1])
                {
                    exch(a, j, j - 1);
                }
            }
            if (isImg)
            {
                show_lzb(a, co, "快速排序");
                co ++;
            }
        }
    }
    // 希尔排序
    static void Shell(vector<E> &a, bool isImg)
    {
        int l = a.size();
        int h = 1;
        int index = 0;
        while (h < ceil(l / 3))
        {
            h = h * 3 + 1;
        }
        while (h >= 1)
        {
            for (int i = h; i < l; i++)
            {
                for (int j = i; j >= h && less(a[j], a[j - h]); j = j - h)
                {
                    exch(a, j, j - h);
                }
                if (isImg)
                {
                    show_lzb(a, index, "希尔排序");
                    ++index;
                }
            }
            h = h / 3;
        }
    }
    // 冒泡排序
    static void Bubble(vector<E> &a, bool isImg)
    {
        bool tag = false;
        int l = a.size();
        for (int i = 0; i < l; i++)
        {
            tag = false;
            for (int j = l - 1; j >= i; j--)
            {
                if (a[j] < a[j - 1])
                {
                    exch(a, j, j - 1);
                    tag = true;
                }
            }
            if (isImg)
                show_lzb(a, i, "冒泡排序");
            if (!tag)
                return;
        }
    }

    // 计数排序
    static vector<E> Count(vector<E> &a, bool isImg)
    {
        int max = (int)v_max_index(a);
        int min = (int)v_min_index(a);

        int l = a.size();
        int cl = max - min + 1;

        int c = 0;

        vector<E> temp(l);
        vector<E> count(cl, 0);

        for (int i = 0; i < l; i++)
        {
            count[a[i] - min]++;
        }

        for (int i = 1; i < cl; i++)
        {
            count[i] = count[i] + count[i - 1];
        }

        for (int i = l - 1; i >= 0; i--)
        {
            temp[count[a[i] - min] - 1] = a[i];
            --count[a[i] - min];
            if (isImg)
            {
                show_lzb(temp, c, "计数排序");
                c++;
            }
        }

        return temp;
    }
    // 基数排序
    static void Radix(vector<E> &a, bool isImg)
    {
        int l = a.size();
        vector<E> temp(l);
        vector<E> count(10, 0);

        int k = 0;

        int c = 0;

        int digit = 1;

        int d = max_digit(a);
        // cout << "最大位数：" << d << endl;
        for (int i = 1; i <= d; i++)
        {
            for (int j = 0; j < 10; j++)
                count[j] = 0;

            for (int j = 0; j < l; j++)
            {
                k = (a[j] / digit) % 10;
                count[k]++;
            }

            for (int j = 1; j < 10; j++)
                count[j] = count[j] + count[j - 1];

            for (int j = l - 1; j >= 0; j--)
            {
                k = (a[j] / digit) % 10;
                temp[count[k] - 1] = a[j];
                --count[k];
                if (isImg)
                {
                    show_lzb(temp, c, "基数排序");
                    c++;
                }
            }

            for (int j = 0; j < l; j++)
                a[j] = temp[j];

            digit = digit * 10;
        }
    }

    // 堆排序

    static void Heap(vector<E> &a, bool isImg)
    {
        int l = a.size() - 1;
        int index = 0;

        for (int i = parent(l); i >= 0; i--)
            sink(a, i, l + 1, index, isImg);

        while (l > 0)
        {
            exch(a, 0, l--);
            sink(a, 0, l + 1, index, isImg);
        }
    }
    //归并排序
    //归并操作
    static void Merge(vector<E> &a,int low,int mid, int hig, bool isImg , vector<E> &tmp , int &co)
    {
        int i = low, j = mid + 1;
        for(int x = low; x <= hig;x++)
            tmp[x] = a[x];
        for(int k = low; k <= hig;k++){
            if(i > mid){
                a[k] = tmp[j ++ ];
            }else if(j > hig){
                a[k] = tmp[i ++ ];
            }else if(less(tmp[j] ,tmp[i])){
                a[k] = tmp[j ++ ];
            }else{
                a[k] = tmp[i ++ ];
            }
            if (isImg)
            {
                show_lzb(a, co, "归并排序");
                co ++;
            }
        }
    }
    // 自顶向下归并排序
    static void Merge_TD(vector<E> &a, int low, int hig, bool isImg, vector<E> &tmp, int &co)
    {
        if(hig <= low) 
            return;
        int mid = low + (hig - low) / 2;
        Merge_TD(a ,low, mid ,isImg , tmp , co);
        Merge_TD(a ,(mid + 1), hig ,isImg , tmp , co);
        Merge(a, low , mid , hig, isImg, tmp , co);
    }
    // 自顶向下归并排序主函数
    static void Merge_TD(vector<E> &a, bool isImg)
    {
        int l = a.size();
        vector<E> tmp(l);
        int co = 0;
        Merge_TD(a, 0 , l - 1 , isImg, tmp, co);
    }

    // 自底向上归并排序
    static void Merge_DU(vector<E> &a, vector<E> &tmp, bool isImg)
    {
        int l = a.size();
        int co = 0;

        for(int sz = 1; sz < l;sz = sz + sz){
            for(int low = 0; low < l - sz;low += sz +sz){
                Merge(a,low,low + sz - 1, min(low + sz + sz - 1,l - 1), isImg , tmp , co);
            }
        }
    }
    // 自底向上归并排序主函数
    static void Merge_DU(vector<E> &a, bool isImg)
    {
        vector<E> tmp(a.size());
        Merge_DU(a, tmp, isImg);
    }

    //归并排序
    //top为选择一个方向进行归并排序
    static void Merge(vector<E> &a,bool top,bool isImg)
    {
        if(top){
            Merge_TD(a,isImg);
        }else{
            Merge_DU(a,isImg);
        }
    }

    static int partition(vector<E> &a, int low, int hig, bool isImg, int &co){
        int i = low, j = hig + 1;
        E v = a[low];
        while(true){
            while (less(a[++i], v))
                if(i == hig) break;
            while (less(v, a[--j]))
                if(j == low) break;
            if(i >= j) break;
            exch(a, i, j);
            if (isImg)
            {
                show_lzb(a, co, "快速排序");
                co ++;
            }
        }
        exch(a, low , j);
        if (isImg)
        {
            show_lzb(a, co, "快速排序");
            co ++;
        }
        return j;
    }

    static void Quick(vector<E> &a, int low, int hig, bool isImg, int &co)
    {
        if(hig <= low){
            // Insertion(a, low, hig, isImg, co);
            return;
        }
        int j = partition(a, low , hig, isImg , co);
        Quick(a, low, j - 1, isImg, co);
        Quick(a, j + 1, hig, isImg, co);

    }

    // 快速排序
    static void Quick(vector<E> &a, bool isImg)
    {
        int l = a.size();
        int co = 0;

        Quick(a, 0, l - 1, isImg, co);
    }
};