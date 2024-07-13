//
//  ds_forward_list.h
//  data_structures_stl
//  单链表 std::forward_list 模拟
//
//  Created by 吴 歆韵 on 2024/4/5.
//

#ifndef ds_forward_list_h
#define ds_forward_list_h

#include <optional>
#include <cassert>

namespace ds {

template <typename T>
struct forward_list{
private:
    struct Node;
    Node* _head;
    Node* _tail;
public:
    struct iterator;
    forward_list();
    ~forward_list();
    
    void push_front(const T& );
    auto begin() -> iterator;
    auto end() -> iterator;
    
    auto insert_after(const iterator, const T&) -> iterator;
    auto erase_after(const iterator )-> iterator;
    void reverse();
};

}//namespace ds

namespace ds {

template <typename T>
struct forward_list<T>::Node{
    std::optional<T> data {std::nullopt};
    Node* next {nullptr};
    
    Node() = default;
    Node(const T& value):data(value){}
};

}//namespace ds

namespace ds {

template <typename T>
struct forward_list<T>::iterator{
    friend forward_list;
private:
    Node* _curr;
public:
    iterator(Node* curr_node):_curr(curr_node){}
    
    auto operator++() -> iterator&;
    auto operator*() -> T&;
    auto operator!=(const iterator) -> bool;
};

}//namespace ds

//********** ds::forward_list 成员函数实现********************
template <typename T>
ds::forward_list<T>::forward_list(){
    _head = new Node();
    _tail = new Node();
    _head->next = _tail;
}

template <typename T>
ds::forward_list<T>::~forward_list(){
    Node* curr {_head};
    while(curr != nullptr){
        auto next {curr->next};
        delete curr;
        curr = next;
    }
}

template <typename T>
void ds::forward_list<T>::push_front(
    const T& value
){
    auto new_node{new Node(value)};
    new_node->next = _head->next;
    _head->next = new_node;
}

template <typename T>
auto ds::forward_list<T>::begin() -> iterator{
    return iterator(_head->next);
}

template <typename T>
auto ds::forward_list<T>::end() -> iterator{
    return iterator(_tail);
}

template <typename T>
auto ds::forward_list<T>::insert_after(
    const iterator pos,
    const T& value
) -> iterator {

    auto new_node {new Node(value)};
    new_node->next = pos._curr->next;
    pos._curr->next = new_node;
    return iterator(new_node);
}

template <typename T>
auto ds::forward_list<T>::erase_after(
    const iterator pos
) -> iterator {

    assert(pos._curr->next != nullptr
            && "此迭代器没有后继！");
    auto node_to_del{pos._curr->next};
    pos._curr->next = pos._curr->next->next;

    delete node_to_del;

    return iterator(pos._curr->next);
}

template <typename T>
void ds::forward_list<T>::reverse(){
    auto *new_head {new Node()};
    new_head->next = _tail;

    while( _head->next != _tail){
        auto next {_head->next};
        _head->next = next->next;

        next->next = new_head->next;
        new_head->next = next;
    }
    _head->next = new_head->next;
    delete new_head;
}

//********** ds::forward_list::iterator 成员函数实现********************
template <typename T>
auto ds::forward_list<T>::iterator::operator++(
) -> iterator&{

    assert(_curr != nullptr
            && "此迭代器没有后继！");
    _curr = _curr->next;
    return *this;
}

template <typename T>
auto ds::forward_list<T>::iterator::operator*(
) -> T&{

    assert(_curr->data != std::nullopt
            && "当前节点没有值！");
    return _curr->data.value();
}

template <typename T>
auto ds::forward_list<T>::iterator::operator!=(
    const iterator other
) -> bool{

    return _curr != other._curr;
}


#endif /* ds_forward_list_h */
