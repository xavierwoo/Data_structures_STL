//
//  hbut_queue.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/8.
//

#ifndef hbut_queue_h
#define hbut_queue_h

#include "hbut_list.h"
#include <cassert>
namespace hbut {

template <typename T>
struct queue{
private:
    list<T> _data; //也可以使用std::list
public:
    void push(const T& );
    auto front() -> T&;
    void pop();
    auto size() const -> unsigned int{
        return _data.size();
    }
    auto empty() const -> bool{
        return size() == 0;
    }
};

}

template <typename T>
void hbut::queue<T>::push(const T& value){
    _data.push_back(value);
}

template <typename T>
auto hbut::queue<T>::front() -> T&{
    assert(_data.size() > 0 && "队列中没有元素！");
    return *_data.begin();
}

template <typename T>
void hbut::queue<T>::pop(){
    assert(_data.size() > 0 && "队列中没有元素！");
    _data.erase(_data.begin());
}

#endif /* hbut_queue_h */
