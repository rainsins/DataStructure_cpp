#include <iostream>
#include "header/Sort.hpp"
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

template<typename T>
std::vector<T> create_copy(std::vector<T> const &vec)
{
    std::vector<T> v;
    for (T const &e: vec) {
        v.push_back(e);
    }
 
    return v;
}

int main()
{
    int max = 20000;
    int min = 0;
    int num = 10000;
    vector<int> a = Sort<int>::generateRandomA(num, min, max);
    vector<int> a1 = create_copy<int>(a);
    vector<int> a2 = create_copy<int>(a);
    vector<int> a3 = create_copy<int>(a);
    vector<int> a4 = create_copy<int>(a);
    vector<int> a5 = create_copy<int>(a);
    vector<int> a6 = create_copy<int>(a);
    vector<int> a7 = create_copy<int>(a);
    vector<int> a8 = create_copy<int>(a);
    vector<int> a9 = create_copy<int>(a);
    vector<int> a10 = create_copy<int>(a);

//--------------------------------------------------------------------------

    //Sort<int>::show(a);
    double startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Insertion(a, false);
    double endTime = (double) Sort<int>::getCurrentTimeNano();
    double elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("插入排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(a);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Insertion(a, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("插入排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Insertion(a, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("插入排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;

//--------------------------------------------------------------------------

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Selection(a1, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("选择排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(a1);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Selection(a1, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("选择排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a1);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Selection(a1, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("选择排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Shell(a2, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("希尔排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(a2);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Shell(a2, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("希尔排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a2);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Shell(a2, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("希尔排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Bubble(a3, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("冒泡排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(a3);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Bubble(a3, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("冒泡排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a3);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Bubble(a3, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("冒泡排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------

    //Sort<int>::show(a4);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    vector<int> aa = Sort<int>::Count(a4, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("计数排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(aa);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    vector<int> as = Sort<int>::Count(aa, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("计数排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(aa);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    vector<int> af = Sort<int>::Count(aa, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("计数排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------

    //Sort<int>::show(a5);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Radix(a5, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("基数排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(a5);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Radix(a5, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("基数排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a5);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Radix(a5, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("基数排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------
    //Sort<int>::show(a6);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Heap(a6, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("堆排序平均情况所需时间: %f ms\n", elapsedNanoseconds);
    //Sort<int>::show(a6);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Heap(a6, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("堆排序有序情况所需时间: %f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a6);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Heap(a6, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("堆排序逆序情况所需时间: %f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------
    // Sort<int>::show(a7);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Merge(a7,true, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("自顶向下的归并排序平均情况所需时间: % f ms\n", elapsedNanoseconds);
    // Sort<int>::show(a7);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Merge(a7,true, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("自顶向下的归并排序有序情况所需时间: % f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a7);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Merge(a7,true, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("自顶向下的归并排序逆序情况所需时间: % f ms\n", elapsedNanoseconds);
    cout << endl;

//--------------------------------------------------------------------------
    // Sort<int>::show(a8);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Merge(a8,false, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("自底向上的归并排序平均情况所需时间: % f ms\n", elapsedNanoseconds);
    // Sort<int>::show(a8);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Merge(a8,false, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("自底向上的归并排序有序情况所需时间: % f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a8);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Merge(a8,false, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("自底向上的归并排序逆序情况所需时间: % f ms\n", elapsedNanoseconds);
    cout << endl;
//--------------------------------------------------------------------------
    // Sort<int>::show(a9);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Quick(a9, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("快速排序平均情况所需时间: % f ms\n", elapsedNanoseconds);
    // Sort<int>::show(a9);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Quick(a9, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("快速排序有序情况所需时间: % f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a9);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    Sort<int>::Quick(a9, false);
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("快速排序逆序情况所需时间: % f ms\n", elapsedNanoseconds);
    cout << endl;

//--------------------------------------------------------------------------
    // Sort<int>::show(a9);
    startTime = (double) Sort<int>::getCurrentTimeNano();
    sort(a10.begin(),a10.end());
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("C ++自带排序算法平均情况所需时间: % f ms\n", elapsedNanoseconds);
    // Sort<int>::show(a10);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    sort(a10.begin(),a10.end());
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("C ++自带排序算法有序情况所需时间: % f ms\n", elapsedNanoseconds);

    Sort<int>::re_vet(a10);

    startTime = (double) Sort<int>::getCurrentTimeNano();
    sort(a10.begin(),a10.end());
    endTime = (double) Sort<int>::getCurrentTimeNano();
    elapsedNanoseconds = (endTime - startTime)/1000000.0;
    printf("C ++自带排序算法逆序情况所需时间: % f ms\n", elapsedNanoseconds);
    cout << endl;

    return 0;
    
}

// g++ `pkg-config opencv4 --libs --cflags opencv4` ./main.cpp -o ./main.o -std=c++11
// ./main.o 