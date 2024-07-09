//
//  ds_Calculator.cpp
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/15.
//

#include "ds_Calculator.hpp"
#include <regex>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include <limits>
#include <cmath>

using std::cerr;

ds::Calculator::Calculator(const string& source_code){
    grammar_tree = parse(source_code);
    _result = _is_grammar_correct ?
            evaluate(grammar_tree)
            : 
            INFINITY;
}

auto ds::Calculator::parse(
    const string& source_code
) -> Expression{
    
    auto tokens {tokenize(source_code)};
    auto root {analyze(tokens)};
    if(!tokens.empty()){
        _is_grammar_correct = false;
        cerr << "非法表达式\n";
    }
    return root;
}

auto ds::Calculator::tokenize(
    const string& expression
) -> Token_Q {
    string spaces_added_expression
        = regex_replace(expression, 
                        std::regex("[(),]"), " $0 ");
    
    std::istringstream iss {spaces_added_expression};
    Token_Q token_Q;
    string token;
    
    while (iss >> token) token_Q.push(token);
    return token_Q;
}

auto ds::Calculator::analyze(
    Token_Q& token_Q
) -> Expression{
    
    auto token {token_Q.front()};
    token_Q.pop();
    
    if(token_Q.front() != "("){
        return Expression(token, {});
    } else {
        token_Q.pop();
        return Expression(token, analyze_para(token_Q));
    }
}

auto ds::Calculator::analyze_para(
    Token_Q& token_Q
) -> Parameter_list{
    
    Parameter_list parameters;
    while(!token_Q.empty() && token_Q.front() != ")"){
        if(!parameters.empty()){
            if(token_Q.front() != ","){
                cerr<<"标识符需要用“,”分隔！\n";
                _is_grammar_correct = false;
                return parameters;
            }
            token_Q.pop(); //删除 “,”
        }
        parameters.push_back(analyze(token_Q));
    }
    if( token_Q.empty() ){
        cerr << "表达式缺少匹配的“)“！\n";
        _is_grammar_correct = false;
        return parameters;
    }
    token_Q.pop();
    return parameters;
}

auto ds::Calculator::evaluate(const Expression& expr) -> double{
    
    const string& identifier {expr.data};
    const Parameter_list parameters {expr.children};
    
    if(identifier == "add") return calculate_add(parameters);
    else if(identifier == "sub") return calculate_sub(parameters);
    else if(identifier == "mul") return calculate_mul(parameters);
    else if(identifier == "div") return calculate_div(parameters);
    else if(std::all_of(identifier.begin(), identifier.end(), 
                        [](char c){return std::isdigit(c);})){
        if(!parameters.empty()){
            cerr <<"常数不可作为函数："<<identifier<<" ！\n";
            _is_grammar_correct = false;
            return INFINITY;
        }
        return (double) std::stoi(identifier);
    } else {
        cerr<<"未知函数："<<identifier<<"！\n";
        _is_grammar_correct = false;
        return INFINITY;
    }
}

auto ds::Calculator::calculate_add(
    const Parameter_list& parameters
)-> double{
    
    double result{0.0};
    for(auto& expr : parameters){
        result += evaluate(expr);
    }
    return result;
}

auto ds::Calculator::calculate_sub(
    const Parameter_list& parameters
) -> double {
    
    if (parameters.empty()){
        _is_grammar_correct = false;
        cerr<<"sub函数至少需要一个参数！\n";
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

auto ds::Calculator::calculate_mul(
    const Parameter_list& parameters
) -> double {
    double result{1.0};
    for(auto& expr : parameters){
        result *= evaluate(expr);
    }
    return result;
}

auto ds::Calculator::calculate_div(
    const Parameter_list& parameters
) -> double {
    if(parameters.size() != 2){
        cerr<<"div函数只接受两个参数！\n";
        _is_grammar_correct = false;
        return INFINITY;
    }
    return evaluate(parameters[0]) 
        / evaluate(parameters[1]);
}
