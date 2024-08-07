//
//  ds_tree.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/14.
//

#ifndef ds_tree_h
#define ds_tree_h

#include <vector>
#include <stack>
#include <queue>
#include <iostream>

#include "ds_vector.h"
#include "ds_queue.h"
#include "ds_stack.h"

namespace ds {
template <typename T>
struct Tree{
    struct Node;
private:
    Node* _root;
    
    static void dfs_pre_order_recur(const Node&);
    static void dfs_post_order_recur(const Node&);
public:
    Tree(Node* r): _root(r){}
    ~Tree(){delete _root;}
    
    void DFS_pre_order_print_recursive() const;
    void DFS_pre_order_print_iterative() const;
    void DFS_post_order_print_recursive() const;
    void BFS_print() const;
};
}

namespace ds {
template <typename T>
struct Tree<T>::Node{
    
    //可以使用ds::vector
    using Child_list = std::vector<Node>;
    
    T data;
    Child_list children;
    
    Node() = default;
    Node(const T& d, const Child_list& c)
        :data(d), children(c){}
};
}

//****************Tree<T>成员函数实现*******************/
template <typename T>
void ds::Tree<T>::dfs_pre_order_recur(
    const Node& node
){
    std::cout<<node.data<<' ';
    for(const auto& c : node.children){
        dfs_pre_order_recur(c);
    }
}

template <typename T>
void ds::Tree<T>::DFS_pre_order_print_recursive(
)const{
    if(_root == nullptr) return;
    dfs_pre_order_recur(*_root);
}

template <typename T>
void ds::Tree<T>::DFS_pre_order_print_iterative() const {
    if(_root == nullptr) return;
    std::stack<const Node* const> S;
    S.push(_root);
    
    while(!S.empty()){
        auto curr {S.top()}; S.pop();
        std::cout<<curr->data<<' ';
        
        //若希望遍历顺序与递归方式一致，
        //此处可以逆序将孩子节点指针压入栈
        for(const auto& c : curr->children){
            S.push(&c);
        }
    }
}

template <typename T>
void ds::Tree<T>::dfs_post_order_recur(
    const Node& node
){
    for(const auto& c : node.children){
        dfs_post_order_recur(c);
    }
    std::cout<<node.data<<' ';
}

template <typename T>
void ds::Tree<T>::DFS_post_order_print_recursive(
) const {
    if(_root == nullptr)return;
    dfs_post_order_recur(*_root);
}

template <typename T>
void ds::Tree<T>::BFS_print() const {
    if(_root == nullptr) return;
    std::queue<const Node* const> Q;
    Q.push(_root);
    
    while(!Q.empty()){
        auto curr {Q.front()}; Q.pop();
        std::cout<<curr->data<<' ';
        
        for(auto& c : curr->children){
            Q.push(&c);
        }
    }
}

#endif /* ds_tree_h */
