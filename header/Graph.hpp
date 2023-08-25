#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "LList.hpp"

using namespace std;

//无向图
class UGraph
{
private:
    vector<LList<int>*> v;
    LList<int>* bag;
    
public:
    UGraph(int v_n){
        v = vector<LList<int>*>(v_n);
    }

    int V(){

    }

    int E(int v){

    }

    void addEdge(){

    }

    vector<int>::iterator abj(){

    }

    static int degree(UGraph G, int V){

    }

    static int MaxDegree(UGraph G){

    }

    static double AvgDegree(UGraph G){

    }

    static int Selfloops(UGraph G){

    }

    static string toString(UGraph G){

    }


};
