//
//  hbut_binary_tree.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/23.
//

#ifndef hbut_binary_tree_h
#define hbut_binary_tree_h

#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

namespace hbut {
template <typename T>
struct Binary_tree{
    struct Node;
private:
    Node* _root{nullptr};
    
    static void pre_order_recur(const Node* const);
    static void in_order_recur(const Node* const);
    static void post_order_recur(const Node* const);
    static void delete_node_recur(const Node*);
    static auto get_depth_recur(const Node* const) -> unsigned int;
public:
    Binary_tree(Node* r):_root(r){}
    ~Binary_tree();
    struct HuffmanComparator;
    static auto make_huffman_tree(const std::vector<T>& values) -> Binary_tree<T>;

    Binary_tree(const std::vector<T>& , const T& );
    
    void level_traversal_print() const;
    void pre_order_traversal_print_recursive() const;
    void pre_order_traversal_print_iterative() const;
    
    void in_order_traversal_print_recursive() const;
    void in_order_traversal_print_iterative() const;
    
    void post_order_traversal_print_recursive() const;
    void post_order_traversal_print_iterative() const;

    auto get_depth()const -> unsigned int;

    struct Location;
    void print(const unsigned int) const ;
};
}

namespace hbut {
template <typename T>
struct Binary_tree<T>::Node{
    T data;
    Node* left;
    Node* right;
    Node(const T& d, Node* l=nullptr, Node* r=nullptr)
    : data(d), left(l), right(r){}
};
}

namespace hbut {
template <typename T>
struct Binary_tree<T>::Location{
    unsigned int indent; //光标缩进
    unsigned int level;  //光标所在行
};
}

namespace hbut {
template <typename T>
struct Binary_tree<T>::HuffmanComparator{
    auto operator()(
        const Node* const a,
        const Node* const b
    ) -> bool{
        return a->data > b->data;
    }
};
}

//*********************Binary_tree成员函数实现*******************
template <typename T>
void hbut::Binary_tree<T>::delete_node_recur(
    const Node* node
){
    if(node == nullptr) return;
    delete_node_recur(node->left);
    delete_node_recur(node->right);
    delete node;
}

template <typename T>
hbut::Binary_tree<T>::~Binary_tree(){
    delete_node_recur(_root);
}

template <typename T>
hbut::Binary_tree<T>::Binary_tree(
    const std::vector<T>& vec,
    const T& void_value
){
    if(vec.empty()) return;
    unsigned int i {0};
    const auto n {vec.size()};

    std::queue<Node* const> Q;
    _root = new Node(vec[i]);
    Q.push(_root);
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
        do{ ++i; }while(i < n && vec[i] == void_value);
    }
}

template <typename T>
void hbut::Binary_tree<T>::level_traversal_print() const {
    if(_root == nullptr)return;
    std::queue<const Node*> Q;
    //queue<const Node* const> Q; //应该也可以使用hbut::queue
    Q.push(_root);
    while(!Q.empty()){
        auto curr {Q.front()}; Q.pop();
        std::cout<<curr->data<<' ';
        if(curr->left != nullptr) Q.push(curr->left);
        if(curr->right != nullptr) Q.push(curr->right);
    }
}

template <typename T>
void hbut::Binary_tree<T>::pre_order_recur(
    const Node* const node
){
    if(node == nullptr) return;
    
    std::cout<<node->data<<" ";
    pre_order_recur(node->left);
    pre_order_recur(node->right);
}

template <typename T>
void hbut::Binary_tree<T>::pre_order_traversal_print_recursive(
)const{
    pre_order_recur(_root);
}

template <typename T>
void hbut::Binary_tree<T>::pre_order_traversal_print_iterative(
)const{
    if(_root == nullptr) return;
    std::stack<const Node*> S;
//    stack<const Node*> S;
    S.push(_root);
    while(!S.empty()){
        auto curr {S.top()}; S.pop();
        std::cout<<curr->data<<' ';
        if(curr->right != nullptr) S.push(curr->right);
        if(curr->left != nullptr) S.push(curr->left);
    }
}

template <typename T>
void hbut::Binary_tree<T>::in_order_recur(
    const Node* const node
){
    if(node == nullptr) return;
    
    in_order_recur(node->left);
    std::cout<<node->data<<' ';
    in_order_recur(node->right);
}

template <typename T>
void hbut::Binary_tree<T>::in_order_traversal_print_recursive(
) const {
    in_order_recur(_root);
}

template <typename T>
void hbut::Binary_tree<T>::in_order_traversal_print_iterative(
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
void hbut::Binary_tree<T>::post_order_recur(
    const Node* const node
){
    if(node == nullptr)return;
    
    post_order_recur(node->left);
    post_order_recur(node->right);
    std::cout<<node->data<<' ';
}

template <typename T>
void hbut::Binary_tree<T>::post_order_traversal_print_recursive(
) const {
    post_order_recur(_root);
}

template <typename T>
void hbut::Binary_tree<T>::post_order_traversal_print_iterative(
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
auto hbut::Binary_tree<T>::get_depth_recur(
    const Node* const node
) -> unsigned int{
    if (node == nullptr){
        return 0;
    }
    auto left_depth {get_depth_recur(node->left)};
    auto right_depth {get_depth_recur(node->right)};
    return 1 + std::max(left_depth, right_depth);
    //注意std::max需要algorithm头文件
}

template <typename T>
auto hbut::Binary_tree<T>::get_depth(
) const -> unsigned int {
    return get_depth_recur(_root);
}

template <typename T>
void hbut::Binary_tree<T>::print(const unsigned int screenwidth) const {
    if(_root == nullptr) return;
    std::cout<<'\n';
    unsigned int curr_level {0}; //记录当前打印的层
    unsigned int curr_indent {0}; //记录当前光标的位置
    std::queue<std::pair<const Node* const, const Location>> Q;
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
auto hbut::Binary_tree<T>::make_huffman_tree(
    const std::vector<T>& values
) -> Binary_tree <T> {
    std::priority_queue<Node*,
            std::vector<Node*>,
            HuffmanComparator> priority_Q;
    for(auto& v : values){
        auto node {new Node(v)};
        priority_Q.push(node);
    }
    while(priority_Q.size() > 1){
        auto left {priority_Q.top()};
        priority_Q.pop();
        auto right {priority_Q.top()};
        priority_Q.pop();
        auto new_node {new Node(left->data + right->data,
                                left, right)};
        priority_Q.push(new_node);
    }
    return Binary_tree<T>(priority_Q.top());
}
#endif /* hbut_binary_tree_h */
