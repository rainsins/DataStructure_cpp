#pragma once
#include "QueueAndStack_apply.hpp"
#include "RChar.hpp"
#include <ctime>


void test() {
    char a[100] = "12-23+20/30-30*20*20-45-23+89*(20+7)";
    char b[100] = "(34-24+35.6-36.8+78.987)*34-23-23/(23-67+87)";
    char c[100] = "(34-24+35.6-36.8+78.987)^34-23-(23/(23-67+87))%2";



    long double a_v = 12 - 23 + 20 / 30 - 30 * 20 * 20 - 45 - 23 + 89 * (20 + 7);
    cout << "a的正确结果：" << a_v << endl;
    long double b_v = (34 - 24 + 35.6 - 36.8 + 78.987) * 34 - 23 - 23 / (23 - 67 + 87);
    cout << "b的正确结果：" << b_v << endl;
    long double c_v = 34 - 24 + 35.6 - 36.8 + 78.987;
    c_v = pow(c_v, 34);
    long double dd = (23.0 / (23 - 67 + 87));
    dd = fmod(dd, 2);
    c_v = c_v - 23 - dd;
    cout << "c的正确结果：" << c_v << endl;

    stack<string> a_s = Stack_Apply::PexpreToSexpre(a);
    stack<string> b_s = Stack_Apply::PexpreToSexpre(b);
    stack<string> c_s = Stack_Apply::PexpreToSexpre(c);

    stack<string> c_ss = Stack_Apply::PexpreToSexpre(c);;
    string tem;
    while (!c_ss.empty()) {
        tem = tem + c_ss.top();
        c_ss.pop();
    }
    cout << "c的后缀运行结果：" << tem << endl;

    long double a_sss = Stack_Apply::ExpressionEvaluation(a_s).top();
    long double b_sss = Stack_Apply::ExpressionEvaluation(b_s).top();
    long double c_sss = Stack_Apply::ExpressionEvaluation(c_s).top();

    cout << "a的运行结果：" << a_sss << endl;
    cout << "b的运行结果：" << b_sss << endl;
    cout << "c的运行结果：" << c_sss << endl;

    int aaaaa = 38;
    char fff = (char)aaaaa;

    cout << "字符：" << fff << endl;

    char ppp[200] = "w0asa";
    char txt[90000] = "ascdkaaasjdajkdaaasdoow0w0dzda00aaasdq002;aaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasd;;'''sckodaaasdsjndjsadnsajdjssajndjsadjsajdaaaasdjsjaaasdndjwnjdwaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaaswaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasraaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasraaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaassdaaasdaaasdaaasdaaasdaaassddjwadiowajidjwidjwiajidskadkskdsajdkaskdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdsadawdwdwdwdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdefdwdwedfefefaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdaaasdasadadasdadedwdwsdjskkdakadkooijioddsfksdjfdslfl;sd.fvsdfvsdflvsdk;fksdlfls;fwe;lfkl;sefl's'flsdlf;lsd'f;'sdfsdfdlfkvlsdfv'sd;fvs'dlfl'sd'f;;;dsf;d;sf;df;df;sd.f;sdfgvsd;'d;'dssfgvsvsv;'dsdfsdfdsfsefsefefesfesfesfesfsefsd,f;ll";

    for (int i = strlen(txt); i < 40000; i++) {
        txt[i] = 's';
    }

    cout << "txt的长度" << strlen(txt) << endl;

    cout << txt << endl;

    KMP* jjd = new KMP(ppp);

    clock_t start = clock();
    jjd->Search(txt);
    clock_t end = clock();

    cout << "KMP花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

    jjd->showdfa();

    clock_t start_p = clock();
    StringMatch::NaiveString(txt, ppp);
    clock_t end_p = clock();

    cout << "花费了" << (double)(end_p - start_p) / CLOCKS_PER_SEC << "秒" << endl;

}