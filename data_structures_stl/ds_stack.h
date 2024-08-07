//
//  ds_stack.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/8.
//

#ifndef ds_stack_h
#define ds_stack_h

#include "ds_vector.h"
#include <cassert>

namespace ds{

template <typename T>
struct stack{
private:
    vector<T> _data;//也可以使用std::vector
    
public:
    void push(const T& );
    auto top() -> T&;
    void pop();
    auto size() const -> unsigned int{return _data.size();}
    auto empty() const -> bool{return size() == 0;}
};

}

template <typename T>
void ds::stack<T>::push(const T& value){
    _data.push_back(value);
}

template <typename T>
auto ds::stack<T>::top() -> T&{
    assert(_data.size() > 0 && "栈中没有元素！");
    return _data[_data.size() - 1];
}

template <typename T>
void ds::stack<T>::pop(){
    assert(_data.size() > 0 && "栈中没有元素！");
    _data.erase(_data.end()-1);
}

#endif /* ds_stack_h */
