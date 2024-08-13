//
//  hbut_graph.h
//  data_structures_stl
//
//  Created by 吴 歆韵 on 2024/5/16.
//

#ifndef hbut_graph_h
#define hbut_graph_h

#include <vector>
#include <optional>
#include <algorithm>
#include <cassert>
#include <limits> // UINT_MAX
#include <cmath> // INFINITY
#include <queue>
#include <stack>
#include <utility>

namespace hbut {

template <typename T>
struct Graph{
    struct To_edge;

    using Vertex_list = std::vector<std::optional<T>>;
    using Edge_list = std::vector<To_edge>;
    using All_edge_list = std::vector<Edge_list>;
    
private:
    Vertex_list _vertices;
    All_edge_list _all_edge_list;
    unsigned int _vertex_num{0};
    unsigned int _edge_num{0};
    
    void add_edge_by_id(const unsigned int,
                        const unsigned int,
                        const double);
    auto get_edge_weight_by_id(const unsigned int,
                               const unsigned int) const -> double;
    void remove_edge_by_id(const unsigned int,
                           const unsigned int);
    void remove_vertex_by_id(const unsigned int);
    auto get_vertex_id(const T&) const -> std::optional<unsigned int>;
    
public:
    
    Graph()=default;
    
    auto add_vertex(const T&) -> unsigned int;
    void add_edge(const T&, const T&, const double);
    void print() const;
    auto get_edge_weight(const T&, const T&) const -> double;
    auto get_vertex_by_id(const unsigned int) -> std::optional<T>&;
    void remove_edge(const T&, const T&);
    void remove_vertex(const T&);
    auto vertex_num() const {return _vertex_num;}
    auto edge_num() const {return _edge_num;}
    
    
    
    using vector_uint = std::vector<unsigned int>;
    using vector_double = std::vector<double>;
    using vector_T = std::vector<T>;
    using vector_bool = std::vector<bool>;
    using queue_uint = std::queue<unsigned int>;
    using stack_uint = std::stack<unsigned int>;
    
    //遍历算法
    void BFS_print(const T&)const;
    void DFS_print_iterative(const T&)const;
    void DFS_print_recursive(const T&)const;
    
    //最短路径
    auto find_min_unvisited_v(
        const vector_bool&, const vector_double&
        )const-> std::optional<unsigned int>;
    
    auto Dijkstra(const unsigned int
        ) const -> std::pair<vector_uint, vector_double>;
    auto shortest_path(const T&, const T&
        ) const -> std::pair<vector_T, double>;
    
    //最小生成树
    struct Edge_info;
    using vector_Edge = std::vector<Edge_info>;
    auto min_spanning_tree_prim(const T&
        ) const -> std::pair<vector_Edge, double>;
    
    struct Edge_id_info;
    struct Edge_heap_comparator;
    using vector_int = std::vector<int>;
    auto generate_edge_heap() const -> std::priority_queue<
                                        Edge_id_info,
                                        std::vector<Edge_id_info>,
                                        Edge_heap_comparator>;
    auto min_spanning_tree_kruskal(
        ) const -> std::pair<vector_Edge, double>;
    
    
    //拓扑排序
    auto in_degree(unsigned int) const -> unsigned int;
    auto topology_sort() const -> std::optional<vector_uint>;
    
    //关键路径
    auto critical_path_print() const;
};

}


namespace hbut {

template <typename T>
struct Graph<T>::To_edge{
    unsigned int to_id;
    double weight;
};

}

namespace hbut {

template <typename T>
struct Graph<T>::Edge_info{
    T from_vertex;
    T to_vertex;
    double weight;
};

}

namespace hbut {

template <typename T>
struct Graph<T>::Edge_id_info{
    unsigned int from_id;
    unsigned int to_id;
    double weight;
};

template <typename T>
struct Graph<T>::Edge_heap_comparator{
    auto operator()(Edge_id_info& a, Edge_id_info& b){
        return a.weight > b.weight;
    }
};

}

//****************Graph<T>成员函数实现*********************

//获取顶点v在顶点数组中的下标号，若v不存在则返回nullopt
template <typename T>
auto hbut::Graph<T>::get_vertex_id(
    const T& v
) const -> std::optional<unsigned int> {
    
    for(auto i{0}; i<_vertices.size(); ++i){
        const auto& opt_v {_vertices[i]};
        if (opt_v != std::nullopt && *opt_v == v){
            return std::optional<unsigned int>(i);
        }
    }
    return std::nullopt;
}

template <typename T>
auto hbut::Graph<T>::add_vertex(const T& v) -> unsigned int{
    assert(get_vertex_id(v) == std::nullopt && "不能插入重复的顶点");
    
    _vertices.push_back(v);
    _all_edge_list.push_back(Edge_list());
    ++_vertex_num;
    return (unsigned int)(_vertices.size() - 1);
}

template <typename T>
void hbut::Graph<T>::add_edge_by_id(
    const unsigned int from_id,
    const unsigned int to_id,
    const double edge_weight
){
    const To_edge to_edge{.to_id = to_id,
                        .weight = edge_weight};
    _all_edge_list[from_id].push_back(to_edge);
    ++_edge_num;
}

template <typename T>
void hbut::Graph<T>::add_edge(
    const T& from,
    const T& to,
    const double weight
){
    const auto opt_from_id = get_vertex_id(from);
    const auto opt_to_id = get_vertex_id(to);
    assert(opt_from_id != std::nullopt && "from不存在！");
    assert(opt_to_id != std::nullopt && "to不存在！");
    
    add_edge_by_id(*opt_from_id, *opt_to_id, weight);
}

template <typename T>
auto hbut::Graph<T>::get_edge_weight_by_id(
    const unsigned int from_id,
    const unsigned int to_id
)const -> double {
    
    for(const auto& to_edge : _all_edge_list[from_id]){
        if(to_edge.to_id == to_id){
            return to_edge.weight;
        }
    }
    return INFINITY;
}

template <typename T>
auto hbut::Graph<T>::get_edge_weight(
    const T& from, const T& to
)const -> double{
    
    const auto opt_from_id = get_vertex_id(from);
    const auto opt_to_id = get_vertex_id(to);
    assert(opt_from_id != std::nullopt && "from不存在！");
    assert(opt_to_id != std::nullopt && "to不存在！");
    
    return get_edge_weight_by_id(*opt_from_id, *opt_to_id);
}

template <typename T>
void hbut::Graph<T>::print() const {
    std::cout<<"\nGraph:\n";
    for(auto v_id{0}; v_id<_vertices.size(); ++v_id){
        if(_vertices[v_id] == std::nullopt) continue;
        std::cout<<"\t"<<*_vertices[v_id]<<": ";
        
        for(auto& to_edge : _all_edge_list[v_id]){
            std::cout<<'('<<*_vertices[to_edge.to_id]
            <<','<<to_edge.weight<<"), ";
        }
        
        std::cout<<'\n';
    }
}

template <typename T>
auto hbut::Graph<T>::get_vertex_by_id(const unsigned int index) -> std::optional<T>&{
    return _vertices[index];
}

template <typename T>
void hbut::Graph<T>::remove_edge_by_id(
    const unsigned int from_id,
    const unsigned int to_id
){
    auto& edge_list {_all_edge_list[from_id]};
    for(auto iter{edge_list.begin()}; 
        iter != edge_list.end();
        ++iter
    ){
        if(iter->to_id == to_id){
            edge_list.erase(iter);
            --_edge_num;
            return;
        }
    }
}

template <typename T>
void hbut::Graph<T>::remove_edge(const T& from, const T& to){
    const auto opt_from_id = get_vertex_id(from);
    const auto opt_to_id = get_vertex_id(to);
    assert(opt_from_id != std::nullopt && "from不存在！");
    assert(opt_to_id != std::nullopt && "to不存在！");
    
    remove_edge_by_id(*opt_from_id, *opt_to_id);
}

template <typename T>
void hbut::Graph<T>::remove_vertex_by_id(
    const unsigned int v_id
){
    //删除v_id的出边
    _all_edge_list[v_id].clear();
    
    //删除v_id的入边
    for(auto& edge_list: _all_edge_list){
        for(auto iter{edge_list.begin()};
            iter != edge_list.end();
            ++iter){
            if(iter->to_id == v_id){
                edge_list.erase(iter);
                --_edge_num;
                break;
            }
        }
    }
    
    //删除v_id
    _vertices[v_id] = std::nullopt;
    --_vertex_num;
}

template <typename T>
void hbut::Graph<T>::remove_vertex(const T& v){
    const auto opt_v_id {get_vertex_id(v)};
    assert(opt_v_id != std::nullopt && "顶点不存在");
    
    remove_vertex_by_id(*opt_v_id);
}

template <typename T>
void hbut::Graph<T>::BFS_print(const T& start)const{
    const auto opt_start_id {get_vertex_id(start)};
    assert(opt_start_id != std::nullopt && "顶点不存在");
    const auto start_id {*opt_start_id};
    
    vector_bool visited(_vertices.size(), false);
    queue_uint Q;
    Q.push(start_id);
    
    while(!Q.empty()){
        const auto curr {Q.front()}; Q.pop();
        if(visited[curr]) continue;
        std::cout<<*_vertices[curr]<<' ';
        visited[curr] = true;
        for(const auto& to_edge : _all_edge_list[curr]){
            Q.push(to_edge.to_id);
            //思考：是否能在此处判断visited后再入队列
        }
    }
}

template <typename T>
void hbut::Graph<T>::DFS_print_iterative(const T& start)const{
    const auto opt_start_id {get_vertex_id(start)};
    assert(opt_start_id != std::nullopt && "顶点不存在");
    const auto start_id {*opt_start_id};
    
    vector_bool visited(_vertices.size(), false);
    stack_uint S;
    S.push(start_id);
    
    while(!S.empty()){
        const auto curr {S.top()}; S.pop();
        if(visited[curr]) continue;
        std::cout<<*_vertices[curr]<<' ';
        visited[curr] = true;
        for(const auto& to_edge : _all_edge_list[curr]){
            S.push(to_edge.to_id);
            //思考：是否能在此处判断visited后再入栈
        }
    }
}


template <typename T>
auto hbut::Graph<T>::find_min_unvisited_v(
    const vector_bool& visited,
    const vector_double& D
) const -> std::optional<unsigned int>{
    unsigned int min_index;
    double min_weight {INFINITY};
    
    for(auto i{0}; i<visited.size(); ++i){
        if(!visited[i] && D[i] < min_weight){
            min_weight = D[i];
            min_index = i;
        }
    }
    return min_weight == INFINITY ?
        std::nullopt
        :
        std::optional<unsigned int>(min_index);
}

template <typename T>
auto hbut::Graph<T>::Dijkstra(
    const unsigned int start_id
) const ->std::pair<vector_uint, vector_double> {
    vector_uint P(_vertices.size(), UINT_MAX);
    vector_double D(_vertices.size(), INFINITY);
    vector_bool visited(_vertices.size(), false);
    
    D[start_id] = 0;
    
    while(true){
        const auto opt_v_id {find_min_unvisited_v(visited, D)};
        if (opt_v_id == std::nullopt) break;
        
        const auto v_id {*opt_v_id};
        visited[v_id] = true;
        for(const auto& to_edge : _all_edge_list[v_id]){
            const auto u_id {to_edge.to_id};
            if(visited[u_id]) continue;
            const auto alt_weight {D[v_id] + to_edge.weight};
            if(alt_weight < D[u_id]){
                D[u_id] = alt_weight;
                P[u_id] = v_id;
            }
        }
    }
    return std::make_pair(P, D);
}

template <typename T>
auto hbut::Graph<T>::shortest_path(
    const T& start, const T& end
)const -> std::pair<vector_T, double>{
    const auto opt_start_id {get_vertex_id(start)};
    assert(opt_start_id != std::nullopt && "顶点不存在");
    const auto opt_end_id {get_vertex_id(end)};
    assert(opt_end_id != std::nullopt && "顶点不存在");
    
    const auto start_id {*opt_start_id};
    const auto end_id {*opt_end_id};
    
    auto [P, D] {Dijkstra(start_id)};
    
    vector_T v_path;
    
    auto curr {end_id};
    while(curr != UINT_MAX){
        v_path.push_back(*_vertices[curr]);
        curr = P[curr];
    }
    
    if(!v_path.empty()){
        std::reverse(v_path.begin(), v_path.end()); //TODO: 不支持ds::vector
    }
    
    return std::make_pair(v_path, D[end_id]);
}

template <typename T>
auto hbut::Graph<T>::min_spanning_tree_prim(
    const T& start
)const -> std::pair<vector_Edge, double>{
    const auto opt_start_id {get_vertex_id(start)};
    assert(opt_start_id != std::nullopt && "顶点不存在");
    const auto start_id {*opt_start_id};
    
    vector_uint P(_vertices.size(), UINT_MAX);
    vector_double W(_vertices.size(), INFINITY);
    vector_bool visited(_vertices.size(), false);
    vector_Edge tree_edges;
    double tree_weight{0};
    W[start_id] = 0;
    
    while(true){
        const auto opt_v_id {find_min_unvisited_v(visited, W)};
        if (opt_v_id == std::nullopt) break;
        const auto v_id {*opt_v_id};
        
        //记录找到的最小边
        if(P[v_id] != UINT_MAX){
            tree_edges.push_back(Edge_info{
                .from_vertex = *_vertices[P[v_id]],
                .to_vertex = *_vertices[v_id],
                .weight = W[v_id]
            });
            tree_weight += W[v_id];
        }
        
        visited[v_id] = true;
        for(const auto& to_edge : _all_edge_list[v_id]){
            const auto u_id {to_edge.to_id};
            if(visited[u_id]) continue;
            if(to_edge.weight < W[u_id]){
                W[u_id] = to_edge.weight;
                P[u_id] = v_id;
            }
        }
    }
    return std::make_pair(tree_edges, tree_weight);
}

template <typename T>
auto hbut::Graph<T>::generate_edge_heap(
) const -> std::priority_queue<
    Edge_id_info,
    std::vector<Edge_id_info>,
    Edge_heap_comparator
>{
    std::priority_queue<Edge_id_info, 
                        std::vector<Edge_id_info>,
                        Edge_heap_comparator>
        heap;
    
    for(unsigned int from_id{0}; from_id < _vertices.size(); ++from_id){
        if(_vertices[from_id] == std::nullopt) continue;
        for(const auto& to_edge : _all_edge_list[from_id]){
            heap.push(Edge_id_info{
                .from_id = from_id,
                .to_id = to_edge.to_id,
                .weight = to_edge.weight
            });
        }
    }
    return heap;
}

template <typename T>
auto hbut::Graph<T>::min_spanning_tree_kruskal(
)const -> std::pair<vector_Edge, double>{
    auto heap {generate_edge_heap()};
    vector_Edge tree_edges;
    double tree_weight{0.0};
    
    vector_int DS(_vertices.size(), -1);
    
    while(!heap.empty()){
        auto edge {heap.top()}; heap.pop();
        
        auto i = edge.from_id;
        while(DS[i] >= 0) i = DS[i];
        
        auto j = edge.to_id;
        while(DS[j] >= 0) j = DS[j];
        
        if(i == j) continue;
        
        //i不等于j，说明此边连接两个不同的子树
        if(i < j){
            DS[i] += DS[j];
            DS[j] = i;
        }else{
            DS[j] += DS[i];
            DS[i] = j;
        }
        tree_edges.push_back(Edge_info{
            .from_vertex = *_vertices[edge.from_id],
            .to_vertex = *_vertices[edge.to_id],
            .weight = edge.weight
        });
        tree_weight += edge.weight;
    }
    
    return std::make_pair(tree_edges, tree_weight);
}

template <typename T>
auto hbut::Graph<T>::in_degree(
    unsigned int v_id
) const -> unsigned int{
    
    unsigned int in_d{0};
    
    for(const auto& edge_list : _all_edge_list){
        for( const auto& to_edge : edge_list) {
            if(to_edge.to_id == v_id){
                ++in_d;
                break;
            }
        }
    }
    return in_d;
}

template <typename T>
auto hbut::Graph<T>::topology_sort() const ->std::optional<vector_uint>{
    vector_uint in_degrees(_vertices.size(), 0);
    queue_uint Q;
    vector_uint id_permutation;
    
    for(auto v_id{0}; v_id < _vertices.size(); ++v_id){
        in_degrees[v_id] = in_degree(v_id);
        if(in_degrees[v_id] == 0){
            Q.push(v_id);
        }
    }
    
    unsigned int count {0};
    
    while(!Q.empty()){
        auto curr_id {Q.front()}; Q.pop();
        id_permutation.push_back(curr_id);
        ++count;
        for(const auto& to_edge : _all_edge_list[curr_id]){
            --in_degrees[to_edge.to_id];
            if(in_degrees[to_edge.to_id] == 0){
                Q.push(to_edge.to_id);
            }
        }
    }
    return count == _vertex_num ?
            std::optional<vector_uint>(id_permutation)
            :
            std::nullopt;
}

template <typename T>
auto hbut::Graph<T>::critical_path_print() const {
    auto opt_topo_sort {topology_sort()};
    assert(opt_topo_sort != std::nullopt && "拓扑排序失败");
    auto& topo_sort {*opt_topo_sort};

    //计算最早发生时间
    vector_double VE(_vertices.size(), 0.0);
    for(auto k{1}; k<topo_sort.size(); ++k){
        auto j {topo_sort[k]};
        double max {0.0};
        for (auto i{0}; i<_vertices.size(); ++i){
            if(_vertices[i] == std::nullopt) continue;
            const auto temp {get_edge_weight_by_id(i, j)};
            if(temp < INFINITY && (VE[i] + temp) > max){
                max = VE[i] + temp;
            }
        }
        VE[j] = max;
    }
    
    //计算最迟发生时间
    vector_double VL(_vertices.size(), INFINITY);
    VL[*(topo_sort.end() - 1)] = VE[*(topo_sort.end() - 1)];
    for(int k = (int)topo_sort.size() - 2; k >= 0; --k){
        auto i {topo_sort[k]};
        double min {INFINITY};
        for(const auto& to_edge : _all_edge_list[i]){
            auto j {to_edge.to_id};
            if(VL[j] - to_edge.weight < min){
                min = VL[j] - to_edge.weight;
            }
        }
        VL[i] = min;
    }
    
    //计算关键路径与时延
    vector_Edge c_path;
    vector_double delays;
    for(auto i{0}; i<_vertices.size(); ++i){
        if(_vertices[i] == std::nullopt) continue;
        for(const auto& to_edge : _all_edge_list[i]){
            const auto j {to_edge.to_id};
            const auto delay {VL[j] - VE[i] - to_edge.weight};
            
            std::cout<<'('<<*_vertices[i]<<','<<*_vertices[j]<<')'
            <<", 时延："<<delay<<'\n';
        }
    }
}

#endif /* hbut_graph_h */
