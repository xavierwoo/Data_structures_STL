//
//  ds_binary_tree.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/23.
//

#ifndef ds_binary_tree_h
#define ds_binary_tree_h

#include "ds_heap.h"

#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <utility>

namespace ds {
template <typename T>
struct Binary_tree{
    struct Node;
private:
    Node* _root{nullptr};
    
    static void recursively_delete_node(Node* );
    static void pre_order_recur(const Node* const);
    static void in_order_recur(const Node* const);
    static void post_order_recur(const Node* const);
public:
    Binary_tree(Node* r):_root(r){}
    ~Binary_tree();
    Binary_tree(const std::vector<T>& , const T& );
    
    void level_traversal_print() const;
    void pre_order_traversal_print_recursive() const;
    void pre_order_traversal_print_iterative() const;
    
    void in_order_traversal_print_recursive() const;
    void in_order_traversal_print_iterative() const;
    
    void post_order_traversal_print_recursive() const;
    void post_order_traversal_print_iterative() const;
    
    struct Location;
    void print(const unsigned int) const ;
};
}

namespace ds {
template <typename T>
struct Binary_tree<T>::Node{
    T data;
    Node* left;
    Node* right;
    Node(const T& d, Node* l=nullptr, Node* r=nullptr)
    : data(d), left(l), right(r){}
};
}

namespace ds {
template <typename T>
struct Binary_tree<T>::Location{
    unsigned int indent;
    unsigned int level;
};
}

namespace ds {
template <typename T>
struct HuffmanNode{
    Binary_tree<T>::Node* tree_node;
    auto operator>(const HuffmanNode& other) const -> bool{
        return tree_node->data > other.tree_node->data;
    }
    auto operator>=(const HuffmanNode& other) const -> bool{
        return tree_node->data >= other.tree_node->data;
    }
};

template <typename T>
auto make_huffman_tree(std::vector<T> ) -> Binary_tree<T>;
}

//*********************Binary_tree成员函数实现*******************
template <typename T>
void ds::Binary_tree<T>::recursively_delete_node(
    Node* node
){
    if(node == nullptr) return;
    recursively_delete_node(node->left);
    recursively_delete_node(node->right);
    delete node;
}

template <typename T>
ds::Binary_tree<T>::~Binary_tree(){
    recursively_delete_node(_root);
}

template <typename T>
ds::Binary_tree<T>::Binary_tree(
    const std::vector<T>& vec,
    const T& void_value
){
    if(vec.empty()) return;
    std::queue<Node*> Q;
    _root = new Node(vec[0]);
    Q.push(_root);
    
    unsigned int i {0};
    auto n {vec.size()};
    
    while(!Q.empty()){
        auto parent {Q.front()}; Q.pop();
        //检查左孩子是否存在
        if(2 * i + 1 < n && vec[2 * i + 1] != void_value){
            auto child {new Node(vec[2 * i + 1])};
            parent->left = child;
            Q.push(child);
        }
        //检查右孩子是否存在
        if(2 * i + 2 < n && vec[2 * i + 2] != void_value){
            auto child {new Node(vec[2 * i + 2])};
            parent->right = child;
            Q.push(child);
        }
        
        //将i移动到下一个非空元素
        do{
            ++i;
        }while(i < n && vec[i] == void_value);
    }
}

template <typename T>
void ds::Binary_tree<T>::level_traversal_print() const {
    if(_root == nullptr)return;
    std::queue<const Node*> Q;
    Q.push(_root);
    while(!Q.empty()){
        auto curr {Q.front()}; Q.pop();
        std::cout<<curr->data<<' ';
        if(curr->left != nullptr) Q.push(curr->left);
        if(curr->right != nullptr) Q.push(curr->right);
    }
}

template <typename T>
void ds::Binary_tree<T>::pre_order_recur(
    const Node* const node
){
    if(node == nullptr) return;
    
    std::cout<<node->data<<' ';
    pre_order_recur(node->left);
    pre_order_recur(node->right);
}

template <typename T>
void ds::Binary_tree<T>::pre_order_traversal_print_recursive(
)const{
    pre_order_recur(_root);
}

template <typename T>
void ds::Binary_tree<T>::pre_order_traversal_print_iterative(
)const{
    if(_root == nullptr) return;
    std::stack<const Node*> S;
    S.push(_root);
    while(!S.empty()){
        auto curr {S.top()}; S.pop();
        std::cout<<curr->data<<' ';
        if(curr->right != nullptr) S.push(curr->right);
        if(curr->left != nullptr) S.push(curr->left);
    }
}

template <typename T>
void ds::Binary_tree<T>::in_order_recur(
    const Node* const node
){
    if(node == nullptr) return;
    
    in_order_recur(node->left);
    std::cout<<node->data<<' ';
    in_order_recur(node->right);
}

template <typename T>
void ds::Binary_tree<T>::in_order_traversal_print_recursive(
) const {
    in_order_recur(_root);
}

template <typename T>
void ds::Binary_tree<T>::in_order_traversal_print_iterative(
) const {
    if(_root == nullptr) return;
    std::stack<const Node*> S;
    
    const Node* curr {_root};
    
    while(curr != nullptr || !S.empty()){
        //将指针移动到最左，并在S中记录路径
        while(curr != nullptr){
            S.push(curr);
            curr = curr->left;
        }
        
        //当前节点为栈顶元素
        curr = S.top(); S.pop();
        
        //输出当前节点
        std::cout<<curr->data<<' ';
        
        //移动至右孩子
        curr = curr->right;
    }
}

template <typename T>
void ds::Binary_tree<T>::post_order_recur(
    const Node* const node
){
    if(node == nullptr)return;
    
    post_order_recur(node->left);
    post_order_recur(node->right);
    std::cout<<node->data<<' ';
}

template <typename T>
void ds::Binary_tree<T>::post_order_traversal_print_recursive(
) const {
    post_order_recur(_root);
}

template <typename T>
void ds::Binary_tree<T>::post_order_traversal_print_iterative(
) const {
    if(_root == nullptr) return;
    std::stack<const Node*> S;
    
    const Node* curr {_root};
    const Node* last_visited {nullptr};
    
    while(curr != nullptr || !S.empty()){
        //将指针移动到最左，并在S中记录路径
        while(curr != nullptr){
            S.push(curr);
            curr = curr->left;
        }
        
        auto top_node {S.top()};
        //检查是否有右子树需要访问
        if(top_node->right != nullptr 
           && top_node->right != last_visited){
            curr = top_node->right;
        }else{
            //处理当前栈顶
            std::cout<<top_node->data<<' ';
            last_visited = top_node;
            S.pop();
        }
    }
}

template <typename T>
void ds::Binary_tree<T>::print(const unsigned int screenwidth) const {
    if(_root == nullptr) return;
    std::cout<<'\n';
    unsigned int curr_level {0}; //记录当前打印的层
    unsigned int curr_indent {0}; //记录当前光标的位置
    std::queue<std::pair<const Node*, const Location>> Q;
    Q.push(std::make_pair(_root, Location{screenwidth / 2, 0}));
    
    while(!Q.empty()){
        auto [curr, location] {Q.front()}; Q.pop();
        
        //在location打印curr
        if(location.level == curr_level){
            const auto indent {location.indent - curr_indent};
            for(int i{0}; i<indent; ++i) std::cout<<' ';
            std::cout<<curr->data;
        }else{
            std::cout<<'\n';
            for(int i{0}; i<location.indent; ++i) std::cout<<' ';
            std::cout<<curr->data;
            curr_level = location.level;
        }
        curr_indent = location.indent;
        
        const auto offset {screenwidth / 2 / (1<<(location.level + 1))};
        if(curr->left != nullptr){
            Q.push(std::make_pair(curr->left,
                                  Location{location.indent - offset,
                                            location.level + 1}));
        }
        if(curr->right != nullptr){
            Q.push(std::make_pair(curr->right,
                                  Location{location.indent + offset,
                                            location.level + 1}));
        }
    }
}

//***************Huffman Code函数实现**********************
template <typename T>
auto ds::make_huffman_tree(std::vector<T> values) -> Binary_tree<T>{
    std::priority_queue<HuffmanNode<T>,
        std::vector<HuffmanNode<T>>,
        std::greater<HuffmanNode<T>>> priority_Q;
    for(auto& v : values){
        HuffmanNode<T> huffman_node {new Binary_tree<T>::Node(v)};
        priority_Q.push(huffman_node);
    }
    while(priority_Q.size() > 1){
        auto left {priority_Q.top().tree_node};
        priority_Q.pop();
        auto right {priority_Q.top().tree_node};
        priority_Q.pop();
        HuffmanNode<T> new_huffman_node{
            new Binary_tree<T>::Node(left->data + right->data,
                                         left, right)
        };
        priority_Q.push(new_huffman_node);
    }
    
    return Binary_tree<T>(priority_Q.top().tree_node);
}
#endif /* ds_binary_tree_h */
