#pragma once
#include <iostream>
#include <map>
#include <string>
#include <cstring>


using namespace std;

class StringMatch {
public:

	//朴素匹配算法
	static void NaiveString(const char* T, const char* P) {
		size_t t = strlen(T);
		size_t m = strlen(P);
		size_t j = 0;
		for (size_t s = 0; s <= t - m; s++) {
			while (j < m)
			{
				if (m - 1 == j && T[j + s] == P[j]) {
					//cout << "找到一个有效偏移: " << s << endl;
					j = 0;
					break;
				}
				else if (T[j + s] == P[j]) {
					j++;
				}
				else {
					j = 0;
					break;
				}
			}
		}

	}

	static void Test(const char* T, const char* P) {
		cout << "元素" << T[0] << endl;
		cout << "元素" << P[0] << endl;
		size_t c = 2;
		size_t d = 0;
		bool a = T[c] == P[d];
		cout << (int)a << endl;
	}
};

class KMP {
private:
	char* p;
	size_t p_len;

	//DFA状态机
	map<char, int*> dfa;

	//判断键值是否存在，如果不存在则开辟一块空间
	void isMap(char str) {
		if (dfa.find(str) == dfa.end()) {
			dfa[str] = new int[p_len]();
		}
	}
public:
	//构造模式的确定的有限状态自动机
	KMP(char* p_out) {
		p = p_out;
		p_len = strlen(p_out);

		//ASCII码最大值
		int r = 179;
		
		dfa[p[0]] = new int[p_len]();
		dfa[p[0]][0] = 1;

		for (size_t st = 0, j = 1; j < p_len; j++) {
			for (int c = 0; c < r; c++) {
				//复制匹配失败的值
				isMap((char)c);
				dfa[(char)c][j] = dfa[(char)c][st];
			}
			//复制匹配成功的值
			isMap(p[j]);
			dfa[p[j]][j] = j + 1;
			//更新启动状态
			st = dfa[p[j]][st];
		}

	}
	//展示状态机
	void showdfa() {
		cout << "模式"<< p << "的DFA为：" << endl;
		cout << "m | ";
		for (int j = 0; j < p_len; j++) {
			cout << p[j] << "  ";
		}
		cout << endl;
		cout << "———";
		for (int j = 0; j < p_len; j++) {
			cout << "———";
		}
		cout << endl;

		for (int i = 0; i < strlen(p); i++) {
			
			cout << p[i] << " | ";
			for (int j = 0; j < p_len; j++) {
				cout << dfa[p[i]][j] << "  ";
			}
			cout << endl;
		}
		cout << "ot| ";
		for (int j = 0; j < p_len; j++) {
			cout << "0" << "  ";
		}
		cout << endl;
	}

	//运行状态机
	void Search(char* txt) {
		int i, j, l = strlen(txt),count = 0;
		for (i = 0, j = 0; i < l; i++) {
			j = dfa[txt[i]][j];
			if (j == p_len) {
				count++;
				//cout << "找到了有效偏移：" << i - p_len + 1 << endl;
				j = 0;
			}
		}
		if (count == 0) {
			cout << "未找到有效偏移！" << endl;
		}
	}

};