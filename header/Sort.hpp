#pragma once
#include "opencv2/opencv.hpp"
#include <vector>
#include <cstdlib> 
using namespace std;
using namespace cv;

template<class E>
class Sort
{
public:
   // virtual void sort(E &a) = 0;

    bool isSort(vector<E> &a){
        int l = a.size();

        for(int i = 0; i < l ; i++){
            if(less(a[i],a[i - 1])) return false;
        }

        return true;
    }
protected:
    bool less(E &p,E &b){
        return p < b;
    }

    static void exch(vector<E> &a,int i,int j){
        E t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

public:
    //测试用例生成
    //n为生成的数量，RangeL和RangeR表示生成的数在这两个之间
    static vector<E> generateRandomA(int n, int RangeL, int RangeR){
        vector<E> a;

        if(RangeL > RangeR){
            int temp = RangeL;
            RangeL = RangeR;
            RangeR = temp;
        }

        srand((unsigned)time(NULL));

        for(int i =0;i<n;i++){
            a.push_back((E)(rand()%(RangeR - RangeL +1) + RangeL));
        }

        return a;
    }
    //展示数组
    static void show(vector<E> &a){
        int l = a.size();

        for(int i = 0; i < l;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    static void show_lzb(vector<E> &arr, string title)
    {
        Mat drawImage = Mat::zeros(Size(256, 256), CV_8UC3);
    
        int _max = 0;
        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > _max)
            {
                _max = arr[i];//找到数组中的最大值，后面需要归一化
            }
        }
    
        for (int i = 0; i < 256; i++)
        {
            int current_value = (int)(double(arr[i]) / double(_max) * 256);//每次都要将数组的值根据最大值归一化到0-255之间
            line(drawImage, Point(i, drawImage.rows - 1), Point(i, drawImage.rows - 1 - current_value), Scalar(255, 0, 255));
        }
        imshow(title, drawImage);
    }

    //选择排序
    static void Selection(vector<E> &a){
        E temp;
        int index = 0;
        int lenght = a.size();
        for(int i = 0; i < lenght;i++){
            index = i;
            temp = a[i];
            for(int j = i; j < lenght ; j++){
                if(a[j] < temp){
                    temp = a[j];
                    index = j;
                }
            }
            exch(a,i,index);
            show_lzb(a, "图形");
        }
    }

    //插入排序
    static void Insertion(vector<E> &a){
        
    }
};