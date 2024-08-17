//
//  hbut_b_tree.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/4/23.
//

#ifndef hbut_b_tree_h
#define hbut_b_tree_h

#include <vector>

//TODO
namespace hbut {
template <typename T>
struct B_tree{
private:
    struct Node;
    Node *root;
    const unsigned int M;
};
}

namespace hbut {
template <typename T>
struct B_tree<T>::Node{
    bool is_leaf;
    std::vector<T> keys;
    std::vector<Node*> children;
};
}

#endif /* hbut_b_tree_h */
