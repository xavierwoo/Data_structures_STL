//
//  hbut_calculator.cpp
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/15.
//

#include "hbut_calculator.hpp"
#include <regex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using std::cout;

hbut::Calculator::Calculator(
    const string& source_code
){
    parse(source_code);
    _result = _is_grammar_correct ?
            evaluate(_grammar_tree)
            : 
            INFINITY;
    //INFINITY 在<cmath>头文件中定义
}

void hbut::Calculator::parse(
    const string& source_code
){
    tokenize(source_code);
    _grammar_tree = analyze();
    if(!_token_queue.empty()){
        _is_grammar_correct = false;
        cout << "非法表达式\n";
    }
}

void hbut::Calculator::tokenize(
    const string& expression
){
    string spaces_added_expression
        = regex_replace(expression, 
                        std::regex("[(),]"), " $0 ");
    
    std::istringstream iss {spaces_added_expression};
    string token;
    while (iss >> token) _token_queue.push(token);
}

auto hbut::Calculator::analyze() -> Expression {
    auto token {_token_queue.front()};
    _token_queue.pop();
    
    if(_token_queue.front() != "("){
        return Expression(token, {});
    } else {
        _token_queue.pop();
        return Expression(token, analyze_para());
    }
}

auto hbut::Calculator::analyze_para() -> Parameter_list{
    Parameter_list parameters;
    while(!_token_queue.empty() && _token_queue.front() != ")"){
        if(!parameters.empty()){
            if(_token_queue.front() != ","){
                cout<<"标识符需要用“,”分隔！\n";
                _is_grammar_correct = false;
                return parameters;
            }
            _token_queue.pop(); //删除 “,”
        }
        parameters.push_back(analyze());
    }
    if( _token_queue.empty() ){
        cout << "表达式缺少匹配的“)“！\n";
        _is_grammar_correct = false;
        return parameters;
    }
    _token_queue.pop();
    return parameters;
}

auto hbut::Calculator::evaluate(const Expression& expr) -> double{
    const string& identifier {expr.data};
    const Parameter_list& parameters {expr.children};
    
    if(identifier == "add") return calculate_add(parameters);
    else if(identifier == "sub") return calculate_sub(parameters);
    else if(identifier == "mul") return calculate_mul(parameters);
    else if(identifier == "div") return calculate_div(parameters);
    else if(std::all_of(identifier.begin(), identifier.end(), 
                        [](char c){return std::isdigit(c);})){
        if(!parameters.empty()){
            cout <<"常数不可作为函数："<<identifier<<" ！\n";
            _is_grammar_correct = false;
            return INFINITY;
        }
        return (double) std::stoi(identifier);
    } else {
        cout<<"未知函数："<<identifier<<"！\n";
        _is_grammar_correct = false;
        return INFINITY;
    }
}

auto hbut::Calculator::calculate_add(
    const Parameter_list& parameters
)-> double{
    double result{0.0};
    for(const auto& expr : parameters){
        result += evaluate(expr);
    }
    return result;
}

auto hbut::Calculator::calculate_sub(
    const Parameter_list& parameters
) -> double {
    if (parameters.empty()){
        _is_grammar_correct = false;
        cout<<"sub函数至少需要一个参数！\n";
        _is_grammar_correct = false;
        return INFINITY;
    }
    if(parameters.size() == 1){
        return 0 - evaluate(parameters[0]);
    }
    double result = evaluate(parameters[0]);
    for(auto iter{parameters.begin()+1}; 
        iter != parameters.end();
        ++iter
    ){
        result -= evaluate(*iter);
    }
    return result;
}

auto hbut::Calculator::calculate_mul(
    const Parameter_list& parameters
) -> double {
    double result{1.0};
    for(auto& expr : parameters){
        result *= evaluate(expr);
    }
    return result;
}

auto hbut::Calculator::calculate_div(
    const Parameter_list& parameters
) -> double {
    if(parameters.size() != 2){
        cout<<"div函数只接受两个参数！\n";
        _is_grammar_correct = false;
        return INFINITY;
    }
    return evaluate(parameters[0]) 
        / evaluate(parameters[1]);
}
