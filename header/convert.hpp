#pragma once
#include <strstream>
#include <iostream>
#include <string>

class StringTo {
public:
    static int convertStringToInt(const std::string &s)
    {
        int val;
        std::strstream ss;
        ss << s;
        ss >> val;
        return val;
    }

    static double convertStringToDouble(const std::string &s)
    {
        double val;
        std::strstream ss;
        ss << s;
        ss >> val;
        return val;
    }

    static long convertStringToLong(const std::string &s)
    {
        long val;
        std::strstream ss;
        ss << s;
        ss >> val;
        return val;
    }
};