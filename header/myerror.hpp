#pragma once
#include <fstream>
#include <iostream>

using namespace std;

class Log {
public:
    static void Error(string message) {
            string err = "";
            string c = "[EEROR]:";
            err.append(c + message);

            ofstream LogFile("Log.txt");
            LogFile << err << "\n";
            LogFile.close();

            cout << err << endl;
            exit(1);
    }

    static void WARN(string message) {
        string warn = "";
        string c = "[WARNING]:";
        warn.append(c + message);

        ofstream LogFile("Log.txt");
        LogFile << warn << "\n";
        LogFile.close();

        cout << warn << endl;
    }

    static void INFO(string message) {
        string info = "";
        string c = "[INFO]:";
        info.append(c + message);

        ofstream LogFile("Log.txt");
        LogFile << info << "\n";
        LogFile.close();
    }



    static void ListTime(string message, clock_t start, clock_t end, int len) {
        cout << message << "运行时间" << (int)(end - start) / CLOCKS_PER_SEC << "s" << endl;
        std::cout << "表长度为：" << len << std::endl;
    }
};
