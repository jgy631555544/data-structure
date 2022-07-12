//
// Created by 金冠宇 on 2022/7/12.
//

#include <iostream>
#include <string>
#include <vector>

//简单模式匹配算法
using namespace std;

int findStr(string str, string substr) {
    int i = 1;
    int j = 1;
    int k = i;
    while (i <= str.length() && j < substr.length()) {
        if (str[i] == substr[j]) {
            i++;
            j++;
        } else {
            i = k++;
            j = 1;
        }
    }
    if (j > substr.length()) return k;
    return 0;
}

/*
 * 求解next数组要懂得的概念
 * 1、前缀：包含首位字符但不包含末位字符的子串
 * 2、后缀：包含末位字符但不包含首位字符的子串
 * 3、next数组的定义：当主串和模式串的某一位字符不匹配时，模式串要回退的位置
 * 4、next[j]的值：第j位字符前面j-1位字符组成的子串的前后缀重合字符数+1
 */

int GetNext(char ch[], int length, int next[]) {
    next[1] = 0;
    int i = 1, j = 0;
    while (i <= length) {
        if (j == 0 || ch[i] == ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int kmp(string str, string substr, int next[]) {
    int i = 1;
    int j = 1;
    while (i <= str.length() && j < substr.length()) {
        if (str[i] == substr[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > substr.length()) return i - substr.length();
    return 0;
}




