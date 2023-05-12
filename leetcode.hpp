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
    // Accepted
    class UnionFind {
    private:
        std::vector<int> id_;

    private:
        int find(int _p) {
            return id_[_p];
        }
        char replace(char _p) {
            int i { id_[_p - 97] };
            int min { i };
            for (size_t j { }; j < 26; ++j) {
                if (id_[j] == i) {
                    min = min > j ? j : min;
                }
            }

            return min + 97;
        }

        void toId(const std::string &_s1,
                  const std::string &_s2) {         
            id_.resize(26);
            for (size_t i { }; i < 26; ++i) {
                id_[i] = i;
            }
            for (size_t i { }; i < _s1.size(); ++i) {
                int p { _s1[i] - 97 };
                int q { _s2[i] - 97 };
                int temp { find(p) };
                if (temp == id_[q]) {
                    continue;
                }

                for (size_t i { }; i < 26; ++i) {
                    if (id_[i] == temp) {
                        id_[i] = id_[q];
                    }
                }
            }
        }  

    public:       
        std::string smallestEquivalentString(std::string _s1, 
                                             std::string _s2, 
                                             std::string _base_str) {
            toId(_s1, _s2);
            for (size_t i { }; i < _base_str.size(); ++i) {
                _base_str[i] = replace(_base_str[i]);
            }

            return _base_str;
        }
    };
    // Accepted
    class UnionFind2 {
    private:
        std::vector<int> id_;
        std::vector<int> sz_;

    public:
        int find(int _p) {
            int i { _p };
            for (; i != id_[i]; i = id_[i]);
            while (id_[_p] != i) {
                int parent { id_[_p] };
                id_[_p] = i;
                _p = parent;
            }

            return i;
        }
        char replace(char _p) {
            int root { find(_p - 97) };
            int min { root };
            for (int i { }; i < 26; ++i) {
                int temp { find(i) };
                if ((temp == root) && (min > i)) {
                    min = i;
                }
            }

            return min + 97;
        }

        void toId(const std::string &_s1,
                  const std::string &_s2) {
            id_.resize(26);
            sz_.resize(26);
            for (int i { }; i < 26; ++i) {
                id_[i] = i;
                sz_[i] = 1;
            }
            for (int i { }; i < _s1.size(); ++i) {
                int p { _s1[i] - 97 };
                int q { _s2[i] - 97 };
                int p_root { find(p) };
                int q_root { find(q) };
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

    public:       
        std::string smallestEquivalentString(std::string _s1, 
                                             std::string _s2, 
                                             std::string _base_str) {
            toId(_s1, _s2);
            for (size_t i { }; i < _base_str.size(); ++i) {
                _base_str[i] = replace(_base_str[i]);
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

