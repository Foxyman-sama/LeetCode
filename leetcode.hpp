#ifndef LEETCODE_HPP
#define LEETCODE_HPP

#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

template<
    typename T = int>
using Vec2D = std::vector<std::vector<T>>;

class Solution1 {
public:
    // Accepted
    class HashTable {
    public:
        std::vector<int> twoSum(std::vector<int> &_nums, 
                                int _target) {
            std::unordered_map<int, int> hash { };
            for (int i { }; i < _nums.size(); ++i) {
                int needed { _target - _nums[i] };
                if (hash.find(needed) != hash.end()) {
                    return { hash[needed], i };
                }

                hash[_nums[i]] = i;
            }

            return { };
        }
    };
};
class Solution547 {
public:
    // Accepted
    class UnionFind {
    protected:
        std::vector<int> id_;

    protected:
        int find(int _p) {
            for (; _p != id_[_p]; _p = id_[_p]);

            return _p;
        }
        int count() {
            std::vector<int> sizes { };
            sizes.resize(id_.size());
            for (int i { }; i < id_.size(); ++i) {
                int temp { find(i) };
                ++sizes[temp];
            }

            int count { };
            for (auto &&el : sizes) {
                if (el) {
                    ++count;
                }
            }

            return count;
        }

        void toId(const std::vector<std::vector<int>> &_k_is_connected) {
            size_t size { _k_is_connected.size() };
            id_.resize(size);
            for (int i { }; i < size; ++i) {
                id_[i] = i;
            }
            for (int i { }; i < size; ++i) {
                for (int j { }; j < _k_is_connected[i].size(); ++j) {
                    if (!_k_is_connected[i][j]) {
                        continue;
                    }

                    int p { i };
                    int q { j };
                    int p_root { find(p) };
                    int q_root { find(q) };
                    if (p_root == q_root) {
                        continue;
                    }

                    id_[p_root] = q_root;
                }
            }
        }

    public:
        int findCircleNum(std::vector<std::vector<int>> &_is_connected) {
            toId(_is_connected);
            return count();
        }
    };
    // Accepted
    class UnionFind2 
        : public UnionFind {
    protected:
        std::vector<int> sz_;

    protected:
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

        void toId(const std::vector<std::vector<int>> &_k_is_connected) {
            size_t size { _k_is_connected.size() };
            id_.resize(size);
            sz_.resize(size);
            for (int i { }; i < size; ++i) {
                id_[i] = i;
                sz_[i] = 1;
            }
            for (int i { }; i < size; ++i) {
                for (int j { }; j < _k_is_connected[i].size(); ++j) {
                    if (!_k_is_connected[i][j]) {
                        continue;
                    }

                    int p { i };
                    int q { j };
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
        }
    };
};
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

        void toId(const std::string &_k_s1,
                  const std::string &_k_s2) {         
            id_.resize(26);
            for (size_t i { }; i < 26; ++i) {
                id_[i] = i;
            }
            for (size_t i { }; i < _k_s1.size(); ++i) {
                int p { _k_s1[i] - 97 };
                int q { _k_s2[i] - 97 };
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

        void toId(const std::string &_k_s1,
                  const std::string &_k_s2) {
            id_.resize(26);
            sz_.resize(26);
            for (int i { }; i < 26; ++i) {
                id_[i] = i;
                sz_[i] = 1;
            }
            for (int i { }; i < _k_s1.size(); ++i) {
                int p { _k_s1[i] - 97 };
                int q { _k_s2[i] - 97 };
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
                  const std::vector<std::vector<int>> &_k_edges) {
            id_.resize(_n);
            sz_.resize(_n);
            for (size_t i { }; i < _n; ++i) {
                id_[i] = i;
                sz_[i] = 1;
            }

            size_t size { _k_edges.size() };
            for (size_t i { }; i < size; ++i) {
                int p_root { find(_k_edges[i][0]) };
                int q_root { find(_k_edges[i][1]) };
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
class Solution2316 {
public:
    // Accepted
    class UnionFind { 
    private:
        size_t n_;
        std::vector<size_t> id_;
        std::vector<size_t> sz_;

    private:
        size_t find(size_t _p) {
            size_t root { _p };
            for (; root != id_[root]; root = id_[root]);
            while (id_[_p] != root) {
                size_t parent { id_[_p] };
                id_[_p] = root;
                _p = parent;
            }

            return root;
        }
        size_t count() {
            std::unordered_map<size_t, size_t> sizes { };
            for (size_t i { }; i < n_; ++i) {
                ++sizes[find(i)];
            }

            size_t remaining_nodes { n_ };
            size_t amount { };
            for (auto &&el : sizes) {
                auto temp { el.second };
                amount += temp * (remaining_nodes - temp);
                remaining_nodes -= temp;
            }

            return amount;
        }

        void toId(int _n,
                  const std::vector<std::vector<int>> &_k_edges) {
            n_ = _n;
            id_.resize(_n);
            sz_.resize(_n, 1);
            for (size_t i { }; i < _n; ++i) {
                id_[i] = i;
            }
            for (size_t i { }; i < _k_edges.size(); ++i) {
                size_t p_root { find(_k_edges[i][0]) };
                size_t q_root { find(_k_edges[i][1]) };
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
        long long countPairs(int _n,
                             std::vector<std::vector<int>> &_edges) {
            toId(_n, _edges);
            return count();
        }
    };
};
class Solution2492 {
public:
    class UnionFind {
    private:
        int n_;
        std::vector<int> id_;
        std::vector<int> sz_;

    private:
        int find(int _p) {
            int root { _p - 1 };
            for (; root != id_[root]; root = id_[root]);

            return root;
        }
        int min() {
            int min { sz_[1] };
            for (auto &&el : sz_) {
                if (min > el) {
                    min = el;
                }
            }

            return min;
        }

        void toId(int _n,
                  const std::vector<std::vector<int>> &_k_roads) {
            n_ = _n;
            id_.resize(_n);
            sz_.resize(_n, 1);
            for (int i { }; i < _n; ++i) {
                id_[i] = i;
            }
            for (int i { }; i < _k_roads.size(); ++i) {
                int p_root { find(_k_roads[i][0]) };
                int q_root { find(_k_roads[i][1]) };
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
        int minScore(int _n,
                     std::vector<std::vector<int>> &_roads) {
            toId(_n, _roads);
            return min();
        }
    };
};

#endif

