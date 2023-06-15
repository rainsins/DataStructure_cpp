#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "AQueue.hpp"
#include "LQueue.hpp"
#include "LStack.hpp"
#include "myerror.hpp"
#include "convert.hpp"
#include <math.h>
#include <cstring>
#include <map>

using namespace std;

class Stack_Apply {
public:
	//括号匹配
	static bool Brack_match(char* brack) {
		LStack<char>* bstack = new LStack<char>();

		char temp;
		for (int i = 0; i < strlen(brack); i++) {
			temp = brack[i];
			if (temp == '(' || temp == '[') {
				bstack->Push(temp);
			}
			else if(temp == ')'){
				if ( !bstack->Empty() && bstack->Pop() != '(') {
					Log::WARN("String is non-conformity!");
					return false;
				}
			}
			else if (temp == ']') {
				if (bstack->Pop() != '[') {
					Log::WARN("String is non-conformity!");
					return false;
				}
			}
		}
		if (!bstack->Empty()) {
			Log::WARN("String is non-conformity!");
			return false;
		}
		return true;
	}
	//判断运算符优先级, in为true
	static bool PriorCom(char left, char right, bool postion) {
		//栈内运算符优先级映射
		map<char, short> xinmap = {
			{'^', 0b1100},
			{'*', 0b0100},
			{'/', 0b0100},
			{'%', 0b0100},
			{'+', 0b0010},
			{'-', 0b0010},
			{'(', 0b0000},
			{')', 0b0001}
		};
		//栈外运算符优先级映射
		map<char, short> xoutmap = {
			{'^', 0b1000},
			{'*', 0b0100},
			{'/', 0b0100},
			{'%', 0b0100},
			{'+', 0b0010},
			{'-', 0b0010},
			{'(', 0b1111},
			{')', 0b0001}
		};

		if (postion) {
			if (xinmap[left] <= xinmap[right]) {
				return true;
			}
			return false;
		}
		else {
			if (xoutmap[left] > xoutmap[right]) {
				return true;
			}
			return false;
		}

		
	}
	//中缀表达式转换为后缀表达式，运算符都为双目，单目不作考虑。
	static stack<string> PexpreToSexpre(char *exp) {
		stack<string> suffix_exp;
		stack<char> opera_exp;
		//判断表达式括号的合法性
		if (!Brack_match(exp)) {
			Log::Error("exp is non-conformity!");
		}
		//缓冲字符，数字可能有多位
		string temp = "";

		for (size_t i = 0; i < strlen(exp);i++) {
			if (isdigit(exp[i]) || exp[i] == '.') {
				//拼接字符，如12.4 + 23，12.4有4个字符，需要将字符拼接好后入栈。
				temp = temp + exp[i];
				//最后的整理
				if (i == strlen(exp) - 1 && temp.length() != 0) {
					suffix_exp.push(temp);
					while (!opera_exp.empty()) {
						temp = opera_exp.top();
						opera_exp.pop();
						suffix_exp.push(temp);
					}
					temp = "";
				}
				continue;
			}
			
			else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' || exp[i] == '%') {
				if (temp.length() != 0) {
					//将拼接好的字符入栈
					suffix_exp.push(temp);
				}
				//判断运算符的优先级，需要保证运算符栈的栈顶的优先级比较高。
				if (opera_exp.empty() || PriorCom(exp[i], opera_exp.top(), false) || (!PriorCom(exp[i], opera_exp.top(), false) && opera_exp.top() == '(')) {
					opera_exp.push(exp[i]);
					temp = "";
					continue;
				}
				else {
					while (!opera_exp.empty() && PriorCom(exp[i], opera_exp.top(), true))
					{
						temp = opera_exp.top();
						suffix_exp.push(temp);
						opera_exp.pop();
					}
					opera_exp.push(exp[i]);
					temp = "";
					continue;
				}
			}
			else if (exp[i] == '(') {
				opera_exp.push(exp[i]);
				continue;
			}
			else if (exp[i] == ')') {
				if (temp.length() != 0) {
					suffix_exp.push(temp);
				}
				while (opera_exp.top() != '(') {
					temp = opera_exp.top();
					opera_exp.pop();
					suffix_exp.push(temp);
				}
				opera_exp.pop();
				temp = "";
				continue;
			}
			else {
				continue;
			}
		}
		while (!opera_exp.empty())
		{
			temp = opera_exp.top();
			suffix_exp.push(temp);
			opera_exp.pop();
		}
		
		stack<string> suffix;
		while (!suffix_exp.empty()) {
			temp = suffix_exp.top();
			suffix.push(temp);
			suffix_exp.pop();
		}

		return suffix;
	}
	//表达式求值
	static stack<long double> ExpressionEvaluation(stack<string> suff_exp) {
		stack<long double> operand;
		long double left = 0;
		long double right = 0;
		long double value = 0;
		while (!suff_exp.empty())
		{
			if (suff_exp.top() == "*" || suff_exp.top() == "/" || suff_exp.top() == "^" || suff_exp.top() == "%" || suff_exp.top() == "+" || suff_exp.top() == "-") {
				const char* temp = suff_exp.top().data();
				right = operand.top();
				operand.pop();
				left = operand.top();
				operand.pop();
				switch (temp[0])
				{
				case '*':
					value = left * right;
					operand.push(value);
					break;
				case '/':
					value = left / right;
					operand.push(value);
					break;
				case '^':
					value = pow(left,right);
					operand.push(value);
					break;
				case '%':
					value = fmod(left,right);
					operand.push(value);
					break;
				case '+':
					value = left + right;
					operand.push(value);
					break;
				case '-':
					value = left - right;
					operand.push(value);
					break;
				default:
					Log::Error("exp is non-conformity!");
					break;
				}
				suff_exp.pop();
			}
			else {
				operand.push(std::stold(suff_exp.top()));
				suff_exp.pop();
			}
		}
		return operand;
	}
};