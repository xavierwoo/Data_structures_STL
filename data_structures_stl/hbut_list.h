//
//  hbut_list.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/6.
//

#ifndef hbut_list_h
#define hbut_list_h

#include <optional>
#include <cassert>

namespace hbut {

template <typename T>
struct list{
private:
    struct Node;
    Node* _head;
    Node* _tail;
    unsigned int _size;
    
public:
    struct iterator;
    list();
    ~list();
    
    auto size() const -> unsigned int{return _size;}
    void push_back(const T& );
    auto begin() -> iterator;
    auto end() -> iterator;
    auto insert(const iterator , const T& ) -> iterator;
    auto erase(const iterator ) -> iterator;
};

}

namespace hbut {

template <typename T>
struct list<T>::Node{
    Node* prev {nullptr};
    std::optional<T> data {std::nullopt};
    Node* next {nullptr};
    
    Node() = default;
    Node(const T& value): data(value){}
};

}

namespace hbut {

template <typename T>
struct list<T>::iterator{
    friend list;
private:
    Node *_curr;
public:
    iterator(Node* curr_node): _curr(curr_node){}
    
    auto operator++() -> iterator&;
    auto operator--() -> iterator&;
    auto operator*() -> T&;
    auto operator!=(const iterator ) -> bool;
};

}

//********** hbut::list 成员函数实现********************
template <typename T>
hbut::list<T>::list():_size(0){
    _head = new Node();
    _tail = new Node();
    _head->next = _tail;
    _tail->prev = _head;
}

template <typename T>
hbut::list<T>::~list(){
    Node* curr {_head};
    while(curr != nullptr){
        auto next {curr->next};
        delete curr;
        curr = next;
    }
}

template <typename T>
void hbut::list<T>::push_back(const T& value){
    auto new_node {new Node(value)};
    
    new_node->next = _tail;
    new_node->prev = _tail->prev;
    _tail->prev->next = new_node;
    _tail->prev = new_node;
    ++_size;
}

template <typename T>
auto hbut::list<T>::begin() -> iterator{
    return iterator(_head->next);
}

template <typename T>
auto hbut::list<T>::end() -> iterator{
    return iterator(_tail);
}

//在pos位前插入value
template <typename T>
auto hbut::list<T>::insert(
    const iterator pos,
    const T& value
) -> iterator {
    
    auto new_node {new Node(value)};
    auto prev {pos._curr->prev};
    
    new_node->prev = prev;
    new_node->next = pos._curr;
    prev->next = new_node;
    pos._curr->prev = new_node;
    ++_size;
    
    return iterator(new_node);
}

template <typename T>
auto hbut::list<T>::erase(
    const iterator pos
) -> iterator {
    
    pos._curr->prev->next = pos._curr->next;
    pos._curr->next->prev = pos._curr->prev;
    iterator ret_it(pos._curr->next);
    delete pos._curr;
    --_size;
    return ret_it;
}

//********** hbut::list<T>::iterator 成员函数实现********************

template <typename T>
auto hbut::list<T>::iterator::operator++() -> iterator& {
    assert(_curr->next != nullptr && "当前迭代器没有后继！");
    _curr = _curr->next;
    return *this;
}

template <typename T>
auto hbut::list<T>::iterator::operator--() -> iterator& {
    assert(_curr->prev != nullptr && "当前迭代器没有前驱！");
    _curr = _curr->prev;
    return *this;
}

template <typename T>
auto hbut::list<T>::iterator::operator*() -> T&{
    assert(_curr->data.has_value() && "当前迭代器没有值！");
    return _curr->data.value();
}

template <typename T>
auto hbut::list<T>::iterator::operator!=(
    const iterator other
) -> bool {
    
    return _curr != other._curr;
}

#endif /* list_h */
