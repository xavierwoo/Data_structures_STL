//
//  ds_Calculator.hpp
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/15.
//

#ifndef ds_Calculator_hpp
#define ds_Calculator_hpp

#include "ds_tree.h"
#include "ds_queue.h"
#include <string>
#include <queue>

namespace ds {
struct Calculator{
private:
    using string = std::string;
    using Expression = Tree<string>::Node;
    using Parameter_list = Tree<string>::Node::Child_list;
    
    Expression _grammar_tree; //语法树
    std::queue<string> _token_queue; //词符队列
    bool _is_grammar_correct {true};
    double _result; //计算结果
    
    void parse(const string&);
    void tokenize(const string&);
    auto analyze() -> Expression ;
    auto analyze_para() -> Parameter_list;
    
    auto evaluate(const Expression&) -> double;
    auto calculate_add(const Parameter_list&) -> double;
    auto calculate_sub(const Parameter_list&) -> double;
    auto calculate_mul(const Parameter_list&) -> double;
    auto calculate_div(const Parameter_list&) -> double;
    
public:
    Calculator(const string&);
    double get_result(){return _result;}
};
}

#endif /* Calculator_hpp */
