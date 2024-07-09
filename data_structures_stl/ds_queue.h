//
//  ds_queue.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/8.
//

#ifndef ds_queue_h
#define ds_queue_h

#include "ds_list.h"
#include <cassert>
namespace ds {

template <typename T>
struct queue{
private:
    list<T> _data;
public:
    void push(const T& );
    auto front() -> T&;
    void pop();
    auto empty() -> bool;
};

}

template <typename T>
void ds::queue<T>::push(const T& value){
    _data.push_back(value);
}

template <typename T>
auto ds::queue<T>::front() -> T&{
    assert(_data.size() > 0 && "队列中没有元素！");
    return *_data.begin();
}

template <typename T>
void ds::queue<T>::pop(){
    assert(_data.size() > 0 && "队列中没有元素！");
    _data.erase(_data.begin());
}

template <typename T>
auto ds::queue<T>::empty() -> bool {
    return _data.size() == 0;
}

#endif /* ds_queue_h */
