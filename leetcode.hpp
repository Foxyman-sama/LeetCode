#ifndef LEETCODE_HPP
#define LEETCODE_HPP

#include <memory>
#include <string>
#include <vector>

template<
    typename T = int>
using Vec2D = std::vector<std::vector<T>>;

class Solution1061 {
public:
    class UnionFind {
    private:
        std::vector<int> id_;

    private:
        int find(int _p) {
            int index { _p - 97 };
            int i { index };            
            int min { id_[i] };
            for (; i != id_[i]; i = id_[i]) {
                if (min > id_[i]) {
                    min = id_[i];
                }
            }
            while (id_[index] != i) {
                int parent { id_[index] };
                id_[index] = min;
                index = parent;
            }

            return min;
        }

        void toId(const std::string &_s1,
                  const std::string &_s2) {
            for (int i { }; i < _s1.size(); ++i) {
                char p { _s1[i] };
                char q { _s2[i] };
                int p_root { find(p) };
                int q_root { find(q) };
                if (p_root == q_root) {
                    continue;
                }
                if (p < q) {
                    id_[q - 97] = p_root;
                }
                else {
                    id_[p - 97] = q_root;
                }
            }
        }
    public:       
        UnionFind() noexcept
            : id_ { } {
            id_.resize(26);
            for (size_t i { }; i < 26; ++i) {
                id_[i] = i;
            }
        }

        std::string smallestEquivalentString(std::string _s1, 
                                             std::string _s2, 
                                             std::string _base_str) {
            toId(_s1, _s2);
            for (size_t i { }; i < _base_str.size(); ++i) {
                _base_str[i] = find(_base_str[i]) + 97;
            }

            return _base_str;
        }
    };
};
class Solution1971 {
public:
    // Accepted
    class UnionFind {
    private:
        std::vector<int> id_;
        std::vector<int> sz_;

    public:
        int find(int _p) {    
            int i { _p };
            for (; i != id_[i]; i = id_[i]);
            // Path compression
            while (id_[_p] != i) {
                int parent { id_[_p] };
                id_[_p] = i;
                _p = parent;
            }

            return i;
        }
        bool validPath(int _n,
                       std::vector<std::vector<int>> &_edges,
                       int _source,
                       int _dest) {
            toId(_n, _edges);
            if (find(_source) == find(_dest)) {
                return true;
            }

            return false;
        }        

        void toId(int _n,
                           const std::vector<std::vector<int>> &_edges) {
            id_.resize(_n);
            sz_.resize(_n);
            for (size_t i { }; i < _n; ++i) {
                id_[i] = i;
                sz_[i] = 1;
            }

            size_t size { _edges.size() };
            for (size_t i { }; i < size; ++i) {
                int p_root { find(_edges[i][0]) };
                int q_root { find(_edges[i][1]) };
                if (p_root == q_root) {
                    continue;
                }
                if (sz_[p_root] > sz_[q_root]) {
                    id_[q_root] = p_root;
                    sz_[p_root] += sz_[q_root];
                }
                else {
                    id_[p_root] = q_root;
                    sz_[q_root] += sz_[p_root];
                }
            }
        }
    };
};

#endif

