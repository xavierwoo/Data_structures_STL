//
// Created by 吴 歆韵 on 2024/8/14.
//

#include "hbut_algorithms.hpp"
#include <stack>
#include "hbut_stack.h"

auto hbut::check_brackets_matching(const std::string& str) -> bool {
    std::stack<char> stk;
//    hbut::stack<char> stk;
    for(char c : str){
        switch (c) {
            case '(':
            case '[':
            case '{':
                stk.push(c);
                break;
            case ')':
                if (stk.empty()) return false;
                if (stk.top() != '(') return false;
                stk.pop();
                break;
            case ']':
                if (stk.empty()) return false;
                if (stk.top() != '[') return false;
                stk.pop();
                break;
            case '}':
                if (stk.empty()) return false;
                if (stk.top() != '{') return false;
                stk.pop();
                break;
        }
    }
    return stk.empty();
}


void hbut::hanoi(
        const int n,
        const char curr,//当前柱
        const char aux, //辅助柱
        const char tar  //目标柱
){
    if ( n <= 0 )return;
    hanoi(n-1, curr, tar, aux);
    std::cout<<"\t将"<<n<<"号盘从"<<curr<<"移动到"<<tar<<"\n";
    hanoi(n-1, aux, curr, tar);
}

