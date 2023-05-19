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
class Solution9 {
public:
    // Accepted
    class Math {
        bool isPalindrome(int _x) {
            if (_x < 0) {
                return false;
            }

            long temp { _x };
            long reverse { };
            while (temp) {
                reverse *= 10;
                reverse += temp % 10;
                temp /= 10;
            }

            return reverse == _x;
        }
    };
};
class Solution13 {
public:
    class HashTable {
    public:
        int romanToInt(std::string _str) {
            std::unordered_map<char, int> equals {
                std::pair<char, int> { 'I', 1 },
                std::pair<char, int> { 'IV', 4 },
                std::pair<char, int> { 'V', 5 },
                std::pair<char, int> { 'IX', 9 },
                std::pair<char, int> { 'X', 10 },
                std::pair<char, int> { 'XL', 40 },
                std::pair<char, int> { 'L', 50 },
                std::pair<char, int> { 'XC', 90 },
                std::pair<char, int> { 'C', 100 },
                std::pair<char, int> { 'CD', 400 },
                std::pair<char, int> { 'D', 500 },
                std::pair<char, int> { 'CM', 900 },
                std::pair<char, int> { 'M', 1000 },
            };
            int result { };
            for (size_t i { }; i < _str.size(); ++i) {
                if (i + 1 < _str.size()) {
                    std::string composed { _str[i] };
                    composed += _str[i + 1];
                }
                if (_str[i] == 'I')
                result += equals[i];
            }
        }
    };
};
class Solution26 {
public:
    // Accepted
    class TwoPointers {
    public:
        int removeDuplicates(std::vector<int> &_nums) {
            std::vector<int> uniques { _nums[0] };
            size_t j { };
            for (size_t i { }; i < _nums.size(); ++i) {
                if (_nums[i] != _nums[j]) {
                    uniques.emplace_back(_nums[i]);
                    j = i;
                }
            }
            
            return uniques.size();
        }
    };
};
class Solution27 {
public:
    // Accepted
    class TwoPointers {
    public:
        int removeElement(std::vector<int> &_nums, 
                          int _val) {
            int i { };
            int j { static_cast<int>(_nums.size() - 1) };
            while (i < j) {
                while ((i < j) && (_nums[i] != _val)) {
                    ++i;
                }
                while ((i < j) && (_nums[j] == _val)) {
                    --j;
                }

                std::swap(_nums[i++], _nums[j--]);
            }

            int amount { };
            for (int i { static_cast<int>(_nums.size() - 1) }; i >= 0; --i) {
                if (_nums[i] != _val) {
                    break;
                }

                ++amount;
            }

            return _nums.size() - amount;
        }
    };
};
class Solution66 {
public:
    class Math {
    public:
        // Accepted
        std::vector<int> plusOne(std::vector<int> &_digits) {
            _digits.back() += 1;

            int rest { };
            for (int i { static_cast<int>(_digits.size() - 1) }; i >= 0; --i) {
                _digits[i] += rest;
                rest = 0;
                if (_digits[i] > 9) {
                    rest = _digits[i] / 10;
                    _digits[i] = _digits[i] % 10;
                }
            }

            if (rest) {
                _digits.insert(_digits.begin(), rest);
            }

            return _digits;
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
class Solution200 {
public:
    // Accepted
    class UnionFind {
    private:
        size_t size_;
        std::vector<int> id_;
        std::vector<int> sz_;

    private:
        int find(int _p) {
            int root { _p };
            for (; (root != -1) && (root != id_[root]); root = id_[root]);
            if (root != -1) {
                while (id_[_p] != root) {
                    int parent { id_[_p] };
                    id_[_p] = root;
                    _p = parent;
                }
            }

            return root;
        }
        int count(const std::vector<std::vector<char>> &_k_grid) {
            std::unordered_map<int, int> sizes { };
            for (size_t i { }; i < size_; ++i) {
                if (id_[i] != -1) {
                    int root { find(i) };
                    ++sizes[root];
                }
            }

            return sizes.size();
        }

        void merge(int _p,
                   int _q) {
            int p_root { find(_p) };
            int q_root { find(_q) };
            if (p_root == q_root) {
                return;
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
        void toId(const std::vector<std::vector<char>> &_k_grid) {
            size_ = _k_grid.size() * _k_grid[0].size();
            id_.resize(size_);
            sz_.resize(size_, 1);
            for (size_t i { }; i < size_; ++i) {
                id_[i] = i;
            }

            size_t row_count { _k_grid.size() };
            size_t column_count { _k_grid[0].size() };
            for (int i { }; i < row_count; ++i) {
                for (int j { }; j < column_count; ++j) {
                    int current_index { static_cast<int>(i * column_count + j) };
                    if (_k_grid[i][j] == '0') {
                        id_[current_index] = -1;
                    }
                    else {
                        if ((i - 1 >= 0) && (_k_grid[i - 1][j] == '1')) {
                            merge(current_index, (i - 1) * column_count + j);
                        }
                        if ((j + 1 < column_count) && (_k_grid[i][j + 1] == '1')) {
                            merge(current_index, i * column_count + (j + 1));
                        }
                        if ((i + 1 < row_count) && (_k_grid[i + 1][j] == '1')) {
                            merge(current_index, (i + 1) * column_count + j);
                        }
                        if ((j - 1 >= 0) && (_k_grid[i][j - 1] == '1')) {
                            merge(current_index, i * column_count + j - 1);
                        }
                    }
                }
            }
        }

    public:
        int numIslands(std::vector<std::vector<char>> &_grid) {
            toId(_grid);
            return count(_grid);
        }
    };
};
class Solution695 {
public:
    // Accepted
    class UnionFind {
    private:
        size_t rows_count_;
        size_t columns_count_;
        std::vector<int> id_;
        std::vector<int> sz_;

    private:
        int find(int _p) {
            int root { _p };
            for (; root != id_[root]; root = id_[root]);
            while (id_[_p] != root) {
                int parent { id_[_p] };
                id_[_p] = root;
                _p = parent;
            }

            return root;
        }
        int max(const std::vector<std::vector<int>> &_k_grid) {
            int max { };
            for (size_t i { }; i < rows_count_; ++i) {
                for (size_t j { }; j < columns_count_; ++j) {
                    if (_k_grid[i][j]) { 
                        int current_index { static_cast<int>(i * columns_count_ + j) };
                        if (max < sz_[current_index]) {
                            max = sz_[current_index];
                        }
                    }
                }
            }

            return max;
        }

        void toId(const std::vector<std::vector<int>> &_k_grid) {
            rows_count_ = _k_grid.size();
            columns_count_ = _k_grid[0].size();

            size_t size { rows_count_ * columns_count_ };
            id_.resize(size);
            sz_.resize(size, 1);
            for (size_t i { }; i < size; ++i) {
                id_[i] = i;
            }
            for (int i { }; i < rows_count_; ++i) {
                for (int j { }; j < columns_count_; ++j) {
                    if (_k_grid[i][j]) {
                        int current_index { static_cast<int>(i * columns_count_ + j) };
                        if ((i - 1 >= 0) && (_k_grid[i - 1][j])) {
                            merge(current_index, (i - 1) * columns_count_ + j);
                        }
                        if ((j + 1 < columns_count_) && (_k_grid[i][j + 1])) {
                            merge(current_index, i * columns_count_ + (j + 1));
                        }
                        if ((i + 1 < rows_count_) && (_k_grid[i + 1][j])) {
                            merge(current_index, (i + 1) * columns_count_ + j);
                        }
                        if ((j - 1 >= 0) && (_k_grid[i][j - 1])) {
                            merge(current_index, i * columns_count_ + (j - 1));
                        }
                    }
                }
            }
        }
        void merge(int _p,
                   int _q) {
            int p_root { find(_p) };
            int q_root { find(_q) };
            if (p_root == q_root) {
                return;
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

    public:
        int maxAreaOfIsland(const std::vector<std::vector<int>> &_k_grid) {
            toId(_k_grid);
            return max(_k_grid);
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
class Solution1267 {
public:
    // Accepted but it`s a bad answer
    class UnionFind {
    private:
        size_t rows_count_;
        size_t columns_count_;
        size_t size_;
        std::vector<int> id_;
        std::vector<int> sz_;

    private:
        int find(int _p) {
            int root { _p };
            for (; root != id_[root]; root = id_[root]);
            while (id_[_p] != root) {
                int parent { id_[_p] };
                id_[_p] = root;
                _p = parent;
            }

            return root;
        }
        int count() {
            std::unordered_map<int, int> sizes { };
            for (size_t i { }; i < size_; ++i) {
                int root { find(i) };
                if ((sizes.find(root) == sizes.end()) && (sz_[root] > 1)) {
                    sizes[root] = sz_[root];
                }
            }

            int amount { };
            for (auto &&el : sizes) {
                amount += el.second;
            }

            return amount;
        }

        void toId(const std::vector<std::vector<int>> &_k_grid) {
            rows_count_ = _k_grid.size();
            columns_count_ = _k_grid[0].size();
            size_ = rows_count_ * columns_count_;
            id_.resize(size_);
            sz_.resize(size_, 1);
            for (size_t i { }; i < size_; ++i) {
                id_[i] = i;
            }
            for (int i { }; i < rows_count_; ++i) {
                for (int j { }; j < columns_count_; ++j) {
                    if (_k_grid[i][j]) {
                        int current_index { static_cast<int>(i * columns_count_ + j) };
                        for (int k { i - 1 }; k >= 0; --k) {              
                            if (_k_grid[k][j]) {
                                merge(current_index, k * columns_count_ + j);
                            }
                        }                       
                        for (int k { j + 1 }; k < columns_count_; ++k) {              
                            if (_k_grid[i][k]) {
                                merge(current_index, i * columns_count_ + k);
                            }
                        }                       
                        for (int k { i + 1 }; k < rows_count_; ++k) {              
                            if (_k_grid[k][j]) {
                                merge(current_index, k * columns_count_ + j);
                            }
                        }                       
                        for (int k { j - 1 }; k >= 0; --k) {              
                            if (_k_grid[i][k]) {
                                merge(current_index, i * columns_count_ + k);
                            }
                        }
                    }
                }
            }
        }
        void merge(int _p,
                   int _q) {
            int p_root { find(_p) };
            int q_root { find(_q) };
            if (p_root == q_root) {
                return;
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

    public:
        int countServers(std::vector<std::vector<int>> &_grid) {
            toId(_grid);
            return count();
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

#endif

