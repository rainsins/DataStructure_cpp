#pragma once
using namespace std;

template<class E>
class Sort
{
public:
    virtual void sort(E &a) = 0;

    bool isSort(E &a){
        int l = getlength(a);

        for(int i = 0; i < l ; i++){
            if(less(a[i],a[i - 1])) return false;
            return true;
        }
    }
protected:
    bool less(E &p,E &b){
        return p < b;
    }

    void show(E &a){
        int l = getlength(a);

        for(int i = 0; i < l;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void exch(E &a,int i,int j){
        E t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    int getlength(E &array){
     	return (sizeof(array) / sizeof(array[0]));
    }

    static void selection(E &a){
        
    }
};