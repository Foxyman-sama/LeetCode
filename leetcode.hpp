#ifndef LEETCODE_HPP
#define LEETCODE_HPP

#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <unordered_set>
#include <forward_list>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <random>
#include "definitions.hpp"

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
  // Accepted
  class HashTable {
  public:
    int romanToInt(const std::string &_k_str) {
      std::unordered_map<std::string, int> equals {
        std::pair<std::string, int> { "I", 1 },
        std::pair<std::string, int> { "IV", 4 },
        std::pair<std::string, int> { "V", 5 },
        std::pair<std::string, int> { "IX", 9 },
        std::pair<std::string, int> { "X", 10 },
        std::pair<std::string, int> { "XL", 40 },
        std::pair<std::string, int> { "L", 50 },
        std::pair<std::string, int> { "XC", 90 },
        std::pair<std::string, int> { "C", 100 },
        std::pair<std::string, int> { "CD", 400 },
        std::pair<std::string, int> { "D", 500 },
        std::pair<std::string, int> { "CM", 900 },
        std::pair<std::string, int> { "M", 1000 },
      };
      int result { };
      for (size_t i { }; i < _k_str.size(); ++i) {
        if (i + 1 < _k_str.size()) {
          std::string composed { _k_str[i] };
          composed += _k_str[i + 1];
          if (equals.find(composed) != equals.end()) {
            result += equals[composed];
            ++i;
            continue;
          }
        }

        result += equals[std::string { _k_str[i] }];
      }

      return result;
    }
  };
};
class Solution14 {
public:
  // Accepted
  class String {
  public:
    std::string longestCommonPrefix(const std::vector<std::string> &_k_strs) {
      std::string str { _k_strs[0] };
      std::string result { };
      for (size_t i { }; i < str.size(); ++i) {
        for (size_t j { 1 }; j < _k_strs.size(); ++j) {
          if (str[i] != _k_strs[j][i]) {
            return result;
          }
        }

        result += str[i];
      }

      return result;
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
class Solution34 {
public:
  // Accepted
  class BinarySearch {
  private:
    int binarySearch(const std::vector<int> &_k_nums,
                     int _target) {
      int left { };
      int right { static_cast<int>(_k_nums.size() - 1) };
      while (left <= right) {
        int mid { left + (right - left) / 2 };
        int guess { _k_nums[mid] };
        if (guess == _target) {
          return mid;
        }
        else if (guess > _target) {
          right = mid - 1;
        }
        else {
          left = mid + 1;
        }
      }

      return INT_MIN;
    }

  public:
    std::vector<int> searchRange(const std::vector<int> &_k_nums,
                                 int _target) {
      int pos { binarySearch(_k_nums, _target) };
      if (pos != INT_MIN) {
        int left { pos };
        while ((--left >= 0) && (_k_nums[left] == _target));

        int right { pos };
        while ((++right < _k_nums.size()) && (_k_nums[right] == _target));

        return { left + 1, right - 1 };
      }

      return { -1, -1 };
    }
  };
};
class Solution58 {
public:
  // Accepted
  class String {
  public:
    int lengthOfLastWord(const std::string &_k_str) {
      int i { static_cast<int>(_k_str.size() - 1) };
      while ((i >= 0) && (_k_str[i] == ' ')) {
        --i;
      }

      int count { };
      for (; i >= 0; --i) {
        if (_k_str[i] == ' ') {
          break;
        }

        ++count;
      }

      return count;
    }
  };
};
class Solution66 {
public:
  // Accepted
  class Math {
  public:
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
class Solution67 {
public:
  // Accepted
  class String {
  public:
    std::string addBinary(std::string _a,
                          std::string _b) {
      if (_a.size() > _b.size()) {
        std::string temp { };
        temp.resize(_a.size() - _b.size(), '0');
        _b = temp + _b;
      }
      else if (_b.size() > _a.size()) {
        std::string temp { };
        temp.resize(_b.size() - _a.size(), '0');
        _a = temp + _a;
      }

      std::string result { };
      int rest { };
      for (int i { static_cast<int>(_a.size() - 1) }; i >= 0; --i) {
        int temp { (_a[i] + _b[i]) - 96 };
        int bit { temp + rest };
        result.append(std::to_string((bit) % 2));
        if (bit >= 2) {
          rest = 1;
        }
        else {
          rest = 0;
        }
      }

      if (rest) {
        result += '1';
      }

      std::reverse(result.begin(), result.end());
      return result;
    }
  };
};
class Solution69 {
public:
  // Accepted
  class BinarySearch {
  private:
    double binarySearch(double _l,
                        double _r,
                        int _target) {
      if (_l <= _r) {
        double mid { (_l + _r) / 2 };
        double pow { mid * mid };
        if (std::floor(pow) == _target) {
          return mid;
        }
        else if (pow > _target) {
          return binarySearch(_l, mid, _target);
        }
        else {
          return binarySearch(mid, _r, _target);
        }
      }

      return DBL_MIN;
    }

  public:
    int mySqrt(int _x) {
      return binarySearch(0, _x, _x);
    }
  };
};
class Solution74 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(int _l,
                      int _r,
                      int _target,
                      const std::vector<int> &_k_nums) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        int guess { _k_nums[mid] };
        if (guess == _target) {
          return true;
        }
        else if (guess > _target) {
          return binarySearch(_l, mid - 1, _target, _k_nums);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _k_nums);
        }
      }

      return false;
    }

  public:
    bool searchMatrix(const std::vector<std::vector<int>> &_k_matrix,
                      int _target) {
      for (auto &&vector : _k_matrix) {
        if (binarySearch(0, vector.size() - 1, _target, vector)) {
          return true;
        }
      }

      return false;
    }
  };
};
class Solution108 {
public:
  // Accepted
  class DivideAndConquer {
  private:
    TreeNode *toTreeNode(int _l,
                         int _r,
                         const std::vector<int> &_k_nums) {
      // If the left index more than right index then return nullptr
      if (_l > _r) {
        return nullptr;
      }

      // Finds the middle element
      int mid { (_l + _r) / 2 };
      // Creates the root based on mid element
      TreeNode *p_root { new TreeNode { _k_nums[mid] } };
      // Recursively does the same for the left tree
      p_root->left = toTreeNode(_l, mid - 1, _k_nums);
      // Recursively does the same for the right tree
      p_root->right = toTreeNode(mid + 1, _r, _k_nums);
      // Return the root
      return p_root;
    }

  public:
    TreeNode *sortedArrayToBST(const std::vector<int> &_k_nums) {
      return toTreeNode(0, _k_nums.size() - 1, _k_nums);
    }
  };
};
class Solution118 {
public:
  // Accepted
  class DynamicProgramming {
  public:
    std::vector<std::vector<int>> generate(int _rows) {
      if (_rows == 1) {
        return std::vector<std::vector<int>> { { 1 } };
      }

      std::vector<std::vector<int>> result { { 1 }, { 1, 1 } };
      for (size_t i { 2 }; i < _rows; ++i) {
        std::vector<int> row { 1 };
        for (size_t j { 1 }; j < i; ++j) {
          row.emplace_back(result[i - 1][j - 1] + result[i - 1][j]);
        }

        row.emplace_back(1);
        result.emplace_back(row);
      }

      return result;
    }
  };
};
class Solution119 {
public:
  // Accepted
  class DynamicProgramming {
  public:
    std::vector<int> getRow(int _index) {
      if (!_index) {
        return { 1 };
      }

      std::vector<std::vector<int>> triangle { { 1 }, { 1, 1 } };
      for (size_t i { 2 }; i <= _index; ++i) {
        std::vector<int> row { 1 };
        for (size_t j { 1 }; j < i; ++j) {
          row.emplace_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
        }

        row.emplace_back(1);
        triangle.emplace_back(row);
      }

      return triangle[_index];
    }
  };
};
class Solution125 {
public:
  // Accepted
  class TwoPointers {
  public:
    bool isPalindrome(const std::string &_k_s) {
      int l { };
      int r { static_cast<int>(_k_s.size() - 1) };
      while (l < r) {
        while ((l < _k_s.size()) && (!isalnum(_k_s[l]))) {
          ++l;
        }
        while ((r >= 0) && (!isalnum(_k_s[r]))) {
          --r;
        }

        if (l > r) {
          break;
        }
        if (tolower(_k_s[l++]) != tolower(_k_s[r--])) {
          return false;
        }
      }

      return true;
    }
  };
};
class Solution151 {
public:
  // Accepted
  class TwoPointers {
  private:
    std::string getFormatedString(const std::string &_k_s) noexcept {
      int amount_of_spaces { 1 };
      size_t i { };
      std::string result { };
      while (i < _k_s.size()) {
        if (_k_s[i] == ' ') {
          ++amount_of_spaces;
        }
        else {
          amount_of_spaces = 0;
        }
        if (amount_of_spaces < 2) {
          result += _k_s[i];
        }

        ++i;
      }

      if (result.back() != ' ') {
        result += ' ';
      }

      return result;
    }

  public:
    std::string reverseWords(const std::string &_k_s) {
      std::string temp { getFormatedString(_k_s) };
      size_t i { temp.size() - 1 };
      size_t j { i };
      std::string result { };
      while (i != std::string::npos) {
        i = temp.rfind(' ', i - 1);
        if (i != std::string::npos) {
          result += std::string { temp.begin() + i + 1, temp.begin() + j };
          result += ' ';
          j = i;
        }
        else {
          result += std::string { temp.begin(), temp.begin() + j };
        }
      }

      return result;
    }
  };
};
class Solution169 {
public:
  // Accepted
  class DivideAndConquer {
  private:
    std::unordered_map<int, int> amounts_;

  private:
    void max(size_t _l,
             size_t _r,
             const std::vector<int> &_k_nums) {
      if (_l == _r) {
        ++amounts_[_k_nums[_l]];
        return;
      }

      size_t mid { (_l + _r) / 2 };
      max(_l, mid, _k_nums);
      max(mid + 1, _r, _k_nums);
    }

  public:
    int majorityElement(std::vector<int> &_nums) {
      max(0, _nums.size() - 1, _nums);

      int number { };
      int max { };
      for (auto &&el : amounts_) {
        if (el.second > max) {
          max = el.second;
          number = el.first;
        }
      }

      return number;
    }
  };
  // Accepted
  class DivideAndConquer2 {
  private:
    int number_;
    int amount_;

  private:
    void max(size_t _l,
             size_t _r,
             const std::vector<int> &_k_nums) {
      if (_l == _r) {
        if (number_ == _k_nums[_l]) {
          ++amount_;
        }
        else {
          if ((--amount_) <= 0) {
            number_ = _k_nums[_l];
            amount_ = 1;
          }
        }

        return;
      }

      size_t mid { (_l + _r) / 2 };
      max(_l, mid, _k_nums);
      max(mid + 1, _r, _k_nums);
    }

  public:
    int majorityElement(std::vector<int> &_nums) {
      max(0, _nums.size() - 1, _nums);
      return number_;
    }
  };
};
class Solution190 { // !
public:
  // Accepted
  class BitManipulation {
  public:
    uint32_t reverseBits(uint32_t _n) {
      uint32_t result { };
      for (size_t i { }; i < 32; ++i) {
        result <<= 1;
        if ((_n >> i) & 1) {
          ++result;
        }
      }

      return result;
    }
  };
};
class Solution191 {
public:
  // Accepted
  class DivideAndConquer {
  private:
    int amount_;

  private:
    void count(size_t _l,
               size_t _r,
               const std::bitset<32> &_k_n) {
      if (_l == _r) {
        if (_k_n[_l]) {
          ++amount_;
        }

        return;
      }

      size_t mid { (_l + _r) / 2 };
      count(_l, mid, _k_n);
      count(mid + 1, _r, _k_n);
    }

  public:
    int hammingWeight(uint32_t _n) {
      count(0, 31, _n);
      return amount_;
    }
  };
  // Accepted
  class BitManipulation {
  public:
    int hammingWeight(uint32_t _n) {
      int amount { };
      while (_n) {
        uint32_t current_bit { _n & 1 };
        if (current_bit) {
          ++amount;
        }

        _n >>= 1;
      }

      return amount;
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
class Solution215 {
public:
  // Accepted
  class DivideAndConquer {
  private:
    void merge(size_t _l,
               size_t _m,
               size_t _r,
               std::vector<int> &_nums) {
      size_t size { _r - _l + 1 };
      size_t lpos { _l };
      size_t rpos { _m + 1 };
      std::vector<int> temp { };
      temp.resize(size);

      size_t tpos { };
      while ((lpos <= _m) && (rpos <= _r)) {
        if (_nums[lpos] < _nums[rpos]) {
          temp[tpos++] = _nums[lpos++];
        }
        else {
          temp[tpos++] = _nums[rpos++];
        }
      }
      while (lpos <= _m) {
        temp[tpos++] = _nums[lpos++];
      }
      while (rpos <= _r) {
        temp[tpos++] = _nums[rpos++];
      }
      for (size_t i { }; i < size; ++i) {
        _nums[_l + i] = temp[i];
      }
    }
    void mergeSort(size_t _l,
                   size_t _r,
                   std::vector<int> &_nums) {
      if (_l < _r) {
        size_t mid { (_l + _r) / 2 };
        mergeSort(_l, mid, _nums);
        mergeSort(mid + 1, _r, _nums);
        merge(_l, mid, _r, _nums);
      }
    }

  public:
    int findKthLargest(std::vector<int> &_nums,
                       int _k) {
      size_t size { _nums.size() };
      mergeSort(0, size - 1, _nums);
      return _nums[size - _k];
    }
  };
};
class Solution238 {
public:
  // Accepted, but TO DO
  class PrefixAndPostfixSum {
  public:
    std::vector<int> productExceptSelf(const std::vector<int> &nums) {
      std::vector<int> result { };
      result.resize(nums.size(), 1);

      int prefix { 1 };
      for (size_t i { }; i < nums.size(); ++i) {
        result[i] = prefix;
        prefix *= nums[i];
      }

      int postfix { 1 };
      for (size_t i { }; i < nums.size(); ++i) {
        result[nums.size() - i - 1] *= postfix;
        postfix *= nums[nums.size() - i - 1];
      }

      return result;
    }
  };
};
class Solution240 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(int _l,
                      int _r,
                      const std::vector<int> &_k_matrix,
                      int _target) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        if (_k_matrix[mid] == _target) {
          return true;
        }
        else if (_k_matrix[mid] > _target) {
          return binarySearch(_l, mid - 1, _k_matrix, _target);
        }
        else {
          return binarySearch(mid + 1, _r, _k_matrix, _target);
        }
      }

      return false;
    }

  public:
    bool searchMatrix(const std::vector<std::vector<int>> &_k_matrix,
                      int _target) {
      for (auto &&row : _k_matrix) {
        if (binarySearch(0, row.size() - 1, row, _target)) {
          return true;
        }
      }

      return false;
    }
  };
};
class Solution242 {
public:
  // Accepted
  class HashTable {
  public:
    bool isAnagram(const std::string &_k_s,
                   const std::string &_k_t) {
      std::unordered_map<char, int> hash { };
      for (auto &&el: _k_s) {
        ++hash[el];
      }
      for (auto &&el: _k_t) {
        --hash[el];
      }
      for (auto &&[key, value]: hash) {
        if (value) {
          return false;
        }
      }

      return true;
    }
  };
};
class Solution268 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(int _l,
                      int _r,
                      int _target,
                      const std::vector<int> &_k_nums) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        if (_k_nums[mid] == _target) {
          return true;
        }
        else if (_k_nums[mid] > _target) {
          return binarySearch(_l, mid - 1, _target, _k_nums);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _k_nums);
        }
      }

      return false;
    }

    void merge(int _l,
               int _m,
               int _r,
               std::vector<int> &_nums) {
      int size { (_r - _l) + 1 };
      int lpos { _l };
      int rpos { _m + 1 };
      int tpos { };
      std::vector<int> temp { };
      temp.resize(size);
      while ((lpos <= _m) && (rpos <= _r)) {
        if (_nums[lpos] < _nums[rpos]) {
          temp[tpos++] = _nums[lpos++];
        }
        else {
          temp[tpos++] = _nums[rpos++];
        }
      }
      while (lpos <= _m) {
        temp[tpos++] = _nums[lpos++];
      }
      while (rpos <= _r) {
        temp[tpos++] = _nums[rpos++];
      }
      for (size_t i { }; i < size; ++i) {
        _nums[_l + i] = temp[i];
      }
    }
    void mergeSort(int _l,
                   int _r,
                   std::vector<int> &_nums) {
      if (_l < _r) {
        int mid { (_l + _r) / 2 };
        mergeSort(_l, mid, _nums);
        mergeSort(mid + 1, _r, _nums);
        merge(_l, mid, _r, _nums);
      }
    }

  public:
    int missingNumber(std::vector<int> &_nums) {
      int left_bound { };
      int right_bound { static_cast<int>(_nums.size() - 1) };
      mergeSort(left_bound, right_bound, _nums);
      for (int num { }; num <= _nums.back(); ++num) {
        if (!binarySearch(left_bound, right_bound, num, _nums)) {
          return num;
        }
      }

      return _nums.back() + 1;
    }
  };
  // Accepted
  class HashTable {
  private:
    int findMax(int _l,
                int _r,
                const std::vector<int> &_k_nums) {
      if (_l == _r) {
        return _k_nums[_l];
      }

      int mid { (_l + _r) / 2 };
      int p { findMax(_l, mid, _k_nums) };
      int q { findMax(mid + 1, _r, _k_nums) };
      return std::max(p, q);
    }

  public:
    int missingNumber(const std::vector<int> &_k_nums) {
      size_t size { _k_nums.size() };
      int right_bound { findMax(0, size - 1, _k_nums) };
      std::unordered_map<int, bool> hash { };
      for (size_t i { }; i < size; ++i) {
        hash[_k_nums[i]] = true;
      }

      int num { };
      for (; num < right_bound; ++num) {
        if (hash.find(num) == hash.end()) {
          return num;
        }
      }

      return num + 1;
    }
  };
};
class Solution345 {
public:
  // Accepted
  class TwoPointers {
  private:
    bool isVowel(char _ch) noexcept {
      constexpr char k_vowels[] { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
      for (auto &&el: k_vowels) {
        if (_ch == el) {
          return true;
        }
      }

      return false;
    }

  public:
    std::string reverseVowels(std::string &_s) {
      size_t i { };
      size_t j { _s.size() - 1 };
      while (i < j) {
        while ((i < j) && (!isVowel(_s[i]))) {
          ++i;
        }
        while ((i < j) && (!isVowel(_s[j]))) {
          --j;
        }

        if (i >= j) {
          break;
        }

        std::swap(_s[i++], _s[j--]);
      }

      return _s;
    }
  };
};
class Solution347 {
public:
  // Accepted
  class DivideAndConquer {
  private:
    void merge(size_t _l,
               size_t _m,
               size_t _r,
               std::vector<int> &_nums) {
      size_t size { _r - _l + 1 };
      size_t lpos { _l };
      size_t rpos { _m + 1 };
      size_t tpos { };
      std::vector<int> temp { };
      temp.resize(size);
      while ((lpos <= _m) && (rpos <= _r)) {
        if (_nums[lpos] < _nums[rpos]) {
          temp[tpos++] = _nums[lpos++];
        }
        else {
          temp[tpos++] = _nums[rpos++];
        }
      }
      while (lpos <= _m) {
        temp[tpos++] = _nums[lpos++];
      }
      while (rpos <= _r) {
        temp[tpos++] = _nums[rpos++];
      }
      for (size_t i { }; i < size; ++i) {
        _nums[_l + i] = temp[i];
      }

    }
    void mergeSort(size_t _l,
                   size_t _r,
                   std::vector<int> &_nums) {
      if (_l < _r) {
        size_t mid { (_l + _r) / 2 };
        mergeSort(_l, mid, _nums);
        mergeSort(mid + 1, _r, _nums);
        merge(_l, mid, _r, _nums);
      }
    }

  public:
    std::vector<int> topKFrequent(std::vector<int> &_nums,
                                  int _k) {
      mergeSort(0, _nums.size() - 1, _nums);

      std::unordered_map<int, int> hash { };
      for (auto &&el : _nums) {
        ++hash[el];
      }

      std::vector<int> result { };
      result.reserve(_k);
      for (size_t i { }; i < _k; ++i) {
        int max { INT_MIN };
        int num { INT_MIN };
        for (auto &&[key, val] : hash) {
          if (max < val) {
            max = val;
            num = key;
          }
        }

        hash.erase(num);
        result.emplace_back(num);
      }

      return result;
    }
  };
};
class Solution349 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(int _l,
                      int _r,
                      int _target,
                      const std::vector<int> &_k_nums) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        int guess { _k_nums[mid] };
        if (guess == _target) {
          return true;
        }
        else if (guess > _target) {
          return binarySearch(_l, mid - 1, _target, _k_nums);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _k_nums);
        }
      }

      return false;
    }

    void merge(int _l,
               int _m,
               int _r,
               std::vector<int> &_vec) {
      int size { _r - _l + 1 };
      int lpos { _l };
      int rpos { _m + 1 };
      int tpos { };
      std::vector<int> temp { };
      temp.resize(size);
      while ((lpos <= _m) && (rpos <= _r)) {
        if (_vec[lpos] < _vec[rpos]) {
          temp[tpos++] = _vec[lpos++];
        }
        else {
          temp[tpos++] = _vec[rpos++];
        }
      }
      while (lpos <= _m) {
        temp[tpos++] = _vec[lpos++];
      }
      while (rpos <= _r) {
        temp[tpos++] = _vec[rpos++];
      }
      for (size_t i { }; i < size; ++i) {
        _vec[_l + i] = temp[i];
      }
    }
    void mergeSort(int _l,
                   int _r,
                   std::vector<int> &_vec) {
      if (_l < _r) {
        int mid { (_l + _r) / 2 };
        mergeSort(_l, mid, _vec);
        mergeSort(mid + 1, _r, _vec);
        merge(_l, mid, _r, _vec);
      }
    }

  public:
    std::vector<int> intersection(std::vector<int> &_nums1,
                                  std::vector<int> &_nums2) {
      mergeSort(0, _nums1.size() - 1, _nums1);
      mergeSort(0, _nums2.size() - 1, _nums2);

      std::vector<int> result { };
      for (auto &&el : _nums1) {
        bool is_first { binarySearch(0, _nums2.size() - 1, el, _nums2) };
        bool is_second { !binarySearch(0, result.size() - 1, el, result) };
        if ((is_first) && (is_second)) {
          result.emplace_back(el);
        }
      }

      return result;
    }
  };
};
class Solution350 {
public:
  // Accepted
  class Sorting {
  private:
    int partition(int _l,
                  int _r,
                  std::vector<int> &_nums) {
      int value { _nums[(_l + _r) / 2] };
      while (_l <= _r) {
        while (_nums[_l] < value) {
          ++_l;
        }
        while (_nums[_r] > value) {
          --_r;
        }

        if (_l >= _r) {
          break;
        }

        std::swap(_nums[_l++], _nums[_r--]);
      }

      return _r;
    }
    int binarySearch(int _l,
                     int _r,
                     int _target,
                     const std::vector<int> &_k_nums) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        int guess { _k_nums[mid] };
        if (_k_nums[mid] == _target) {
          return mid;
        }
        else if (guess > _target) {
          return binarySearch(_l, mid - 1, _target, _k_nums);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _k_nums);
        }
      }

      return INT_MIN;
    }

    void quickSort(int _l,
                   int _r,
                   std::vector<int> &_nums) {
      if (_l < _r) {
        int q { partition(_l, _r, _nums) };
        quickSort(_l, q, _nums);
        quickSort(q + 1, _r, _nums);
      }
    }

  public:
    std::vector<int> intersect(std::vector<int> &_nums1,
                               std::vector<int> &_nums2) {
      quickSort(0, _nums1.size() - 1, _nums1);
      quickSort(0, _nums2.size() - 1, _nums2);

      std::vector<int> result { };
      if ((_nums1.size() == _nums2.size()) || (_nums1.size() < _nums2.size())) {
        for (auto &&el : _nums1) {
          int pos { binarySearch(0, _nums2.size() - 1, el, _nums2) };
          if (pos != INT_MIN) {
            result.emplace_back(el);
            _nums2.erase(_nums2.begin() + pos);
          }
        }
      }
      else {
        for (auto &&el : _nums2) {
          int pos { binarySearch(0, _nums1.size() - 1, el, _nums1) };
          if (pos != INT_MIN) {
            result.emplace_back(el);
            _nums1.erase(_nums1.begin() + pos);
          }
        }
      }

      return result;
    }
  };
  // Accepted
  class HashTable {
  public:
    std::vector<int> intersect(std::vector<int> &_nums1,
                               std::vector<int> &_nums2) {
      std::unordered_map<int, int> hash { };
      for (auto &&el : _nums1) {
        ++hash[el];
      }

      std::vector<int> result { };
      for (auto &&el : _nums2) {
        if (hash[el]) {
          result.emplace_back(el);
          --hash[el];
        }
      }

      return result;
    }
  };
};
class Solution367 {
public:
  // Accepted
  class BinarySearch {
  public:
    bool isPerfectSquare(int _num) {
      int l { };
      int r { _num };
      while (l <= r) {
        long long mid { (l + r) / 2 };
        long long pow { mid * mid };
        if (pow == _num) {
          return true;
        }
        else if (pow > _num) {
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }

      return false;
    }
  };
};
class Solution374 {
public:
  // Accepted
  class BinarySearch {
  private:
    int binarySearch(int _l,
                     int _r,
                     int _target) {
      if (_l < _r) {
        int mid { _l + (_r - _l) / 2 };
        int guess_num { /* guess(mid) */ };
        if (!guess_num) {
          return mid;
        }
        else if (guess_num == -1) {
          return binarySearch(_l, mid - 1, _target);
        }
        else {
          return binarySearch(mid + 1, _r, _target);
        }
      }

      return 0;
    }

  public:
    int guessNumber(int _n) {
      return binarySearch(0, _n, _n);
    }
  };
};
class Solution389 {
public:
  // Accepted
  class Sorting {
  private:
    int partition(std::string &_str,
                  int _l,
                  int _r) {
      char value { _str[(_l + _r) / 2] };
      while (_l <= _r) {
        while (_str[_l] < value) {
          ++_l;
        }
        while (_str[_r] > value) {
          --_r;
        }

        if (_l >= _r) {
          break;
        }

        std::swap(_str[_l++], _str[_r--]);
      }

      return _r;
    }

    void quickSort(std::string &_str,
                   int _l,
                   int _r) {
      if (_l < _r) {
        int q { partition(_str, _l, _r) };
        quickSort(_str, _l, q);
        quickSort(_str, q + 1, _r);
      }
    }

  public:
    char findTheDifference(std::string &_fstr,
                           std::string &_sstr) {
      quickSort(_fstr, 0, _fstr.size() - 1);
      quickSort(_sstr, 0, _sstr.size() - 1);
      for (size_t i { }; i < _fstr.size(); ++i) {
        if (_fstr[i] != _sstr[i]) {
          return _sstr[i];
        }
      }

      return _sstr.back();
    }
  };
  // Accepted
  class HashTable {
  public:
    char findTheDifference(const std::string &_k_s,
                           const std::string &_k_t) {
      std::unordered_map<char, int> hash { };
      for (auto &&el: _k_t) {
        ++hash[el];
      }
      for (auto &&el: _k_s) {
        --hash[el];
      }
      for (auto &&[key, value]: hash) {
        if (value) {
          return value;
        }
      }

      return CHAR_MIN;
    }
  };
};
class Solution509 {
public:
  // Accepted
  class DynamicProgramming {
  public:
    int fib(int _n) {
      static std::unordered_map<int, int> s_cache {
        std::pair { 0, 0 }, std::pair { 1, 1 }
      };
      if (!s_cache[_n]) {
        for (size_t i { 2 }; i <= _n; ++i) {
          s_cache[i] = s_cache[i - 1] + s_cache[i - 2];
        }
      }

      return s_cache[_n];
    }
  };
};
class Solution535 {
public:
  // Accepted
  class HashTable {
  private:
    static constexpr std::string_view sk_symbols_ {
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    };
    static constexpr std::string_view sk_url_ { "http://tinyurl.com/" };
    static inline std::unordered_map<std::string, std::string> s_references_ { };

  public:
    std::string encode(const std::string &_k_long_url) {
      std::string result { };
      size_t iter { _k_long_url.size() - 1 };
      while (_k_long_url[iter] != '/') {
        result += sk_symbols_[_k_long_url[iter] % 62];
      }

      result = sk_url_.data() + result;
      s_references_[result] = _k_long_url;
      return result;
    }
    std::string decode(const std::string &_k_short_url) {
      return s_references_[_k_short_url];
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
class Solution605 {
public:
  // Accepted
  class Array {
  private:
    int getElem(const std::vector<int> &_k_flowerbed,
                size_t _index) noexcept {
      if ((_index >= 0) && (_index < _k_flowerbed.size())) {
        return _k_flowerbed[_index];
      }

      return 0;
    }

  public:
    bool canPlaceFlowers(std::vector<int> &_flowerbed,
                         int _n) {
      for (size_t i { }; i < _flowerbed.size(); ++i) {
        if ((getElem(_flowerbed, i) == 0) &&
            (getElem(_flowerbed, i - 1) == 0) &&
            (getElem(_flowerbed, i + 1) == 0)) {
          _flowerbed[i] = 1;
          --_n;
        }
      }

      if (_n > 0) {
        return false;
      }

      return true;
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
class Solution705 {
public:
  // Accepted
  class MyHashSet {
  private:
    std::list<int> set_;

  private:
    auto find(int _target) {
      auto it { set_.begin() };
      while (it != set_.end()) {
        if (*it == _target) {
          return it;
        }

        ++it;
      }

      return it;
    }

  public:
    MyHashSet() noexcept
      : set_ { } { }

    bool contains(int _key) {
      return find(_key) == set_.end() ? false : true;
    }

    void add(int _key) {
      if (find(_key) == set_.end()) {
        set_.emplace_back(_key);
      }
    }
    void remove(int _key) {
      auto pos { find(_key) };
      if (pos != set_.end()) {
        set_.erase(pos);
      }
    }
  };
  // Accepted
  class MyHashSet2 {
  private:
    std::vector<bool> set_;

  public:
    MyHashSet2() noexcept
      : set_ { } {
      set_.resize(1'000'001);
    }

    bool contains(int _key) {
      return set_[_key];
    }

    void add(int _key) {
      set_[_key] = true;
    }
    void remove(int _key) {
      set_[_key] = false;
    }
  };
};
class Solution744 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(int _l,
                      int _r,
                      char _target,
                      const std::vector<char> &_k_letters) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        char guess { _k_letters[mid] };
        if (guess == _target) {
          return true;
        }
        else if (guess > _target) {
          return binarySearch(_l, mid - 1, _target, _k_letters);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _k_letters);
        }
      }

      return false;
    }

  public:
    char nextGreatestLetter(const std::vector<char> &_k_letters,
                            char _target) {
      int limit { 26 + 97 };
      int it { _target + 1 };
      while (true) {
        if (it >= limit) {
          it = 97;
        }
        if (binarySearch(0, _k_letters.size() - 1, it, _k_letters)) {
          return it;
        }

        ++it;
      }

      return CHAR_MAX;
    }
  };
};
class Solution771 {
public:
  // Accepted
  class HashTable {
  public:
    int numJewelsInStones(const std::string &_k_jewels,
                          const std::string &_k_stones) {
      std::unordered_map<int, int> hash { };
      for (auto &&el : _k_jewels) {
        ++hash[el];
      }

      int amount { };
      for (auto &&el : _k_stones) {
        if (hash[el]) {
          ++amount;
        }
      }

      return amount;
    }
  };
};
class Solution959 {
public:
  // Accepted
  class UnionFind {
  private:
    class DisjointSet {
    private:
      std::vector<size_t> id_;
      std::vector<size_t> sz_;

    public:
      explicit DisjointSet(size_t _size) noexcept
        : id_ { }
        , sz_ { } {
        sz_.resize(_size, 1);
        id_.resize(_size);
        for (size_t i { }; i < _size; ++i) {
          id_[i] = i;
        }
      }

      size_t find(size_t _p) noexcept {
        size_t root { _p };
        for (; root != id_[root]; root = id_[root]);
        while (id_[_p] != root) {
          size_t parent { id_[_p] };
          id_[_p] = root;
          _p = parent;
        }

        return root;
      }

      void merge(size_t _p,
                 size_t _q) noexcept {
        size_t i { find(_p) };
        size_t j { find(_q) };
        if (i == j) {
          return;
        }
        if (sz_[i] > sz_[j]) {
          id_[j] = i;
          sz_[i] += sz_[j];
        }
        else {
          id_[i] = j;
          sz_[j] += sz_[i];
        }
      }
    };

  public:
    int regionsBySlashes(const std::vector<std::string> &_k_grid) {
      size_t rows { _k_grid.size() };
      size_t columns { _k_grid[0].size() };
      size_t max_rows { rows + 1 };
      size_t max_columns { columns + 1 };
      DisjointSet set { max_rows * max_columns };
      for (size_t i { }; i <= rows; ++i) {
        for (size_t j { }; j <= columns; ++j) {
          if ((i == 0) || (i == rows) || (j == 0) || (j == columns)) {
            size_t dot { i * (max_rows) +j };
            set.merge(dot, 0);
          }
        }
      }

      int result { 1 };
      for (size_t i { }; i < rows; ++i) {
        for (size_t j { }; j < columns; ++j) {
          if (_k_grid[i][j] == '/') {
            size_t first_dot { (i * max_rows + (j + 1)) };
            size_t second_dot { ((i + 1) * max_rows + j) };
            if (set.find(first_dot) != set.find(second_dot)) {
              set.merge(first_dot, second_dot);
            }
            else {
              ++result;
            }
          }
          else if (_k_grid[i][j] == '\\') {
            size_t first_dot { (i * max_rows + j) };
            size_t second_dot { ((i + 1) * max_rows + (j + 1)) };
            if (set.find(first_dot) != set.find(second_dot)) {
              set.merge(first_dot, second_dot);
            }
            else {
              ++result;
            }
          }
        }
      }

      return result;
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
class Solution1071 {
public:
  // Accepted
  class String {
  public:
    std::string gcdOfStrings(const std::string &_k_str1,
                             const std::string &_k_str2) {
      if (_k_str2.size() > _k_str1.size()) {
        return gcdOfStrings(_k_str2, _k_str1);
      }
      else if (_k_str1.find(_k_str2) != 0) {
        return "";
      }
      else if (_k_str2.empty()) {
        return _k_str1;
      }
      else {
        return gcdOfStrings(_k_str1.substr(_k_str2.size()), _k_str2);
      }
    }
  };
};
class Solution1108 {
public:
  // Accepted
  class String {
    std::string defangIPaddr(const std::string &_k_address) {
      std::string result { };
      for (auto &&el: _k_address) {
        if (el == '.') {
          result += "[.]";
        }
        else {
          result += el;
        }
      }

      return result;
    }
  };
};
class Solution1137 {
public:
  // Accepted
  class DynamicProgramming {
  public:
    int tribonacci(int _n) {
      static std::unordered_map<int, int> s_cache {
        std::pair { 0, 0 }, std::pair { 1, 1 }, std::pair { 2, 1 }
      };
      if (!s_cache[_n]) {
        for (size_t i { 3 }; i <= _n; ++i) {
          s_cache[i] = s_cache[i - 1] + s_cache[i - 2] + s_cache[i - 3];
        }
      }

      return s_cache[_n];
    }
  };
};
class Solution1237 {
public:
  // Accepted
  class BinarySearch {
  public:
    std::vector<std::vector<int>> findSolution(CustomFunction &_callback,
                                               int _expected) {
      std::vector<std::vector<int>> result { };
      for (int x { 1 }; x <= 1000; ++x) {
        int l { 1 };
        int r { 1000 };
        while (l < r) {
          int mid { (l + r) / 2 };
          int value { _callback.f(x, mid) };
          if (r >= _expected) {
            r = mid;
          }
          else {
            l = mid + 1;
          }
        }

        if (_callback.f(x, l) == _expected) {
          result.emplace_back(std::vector<int> { x, l });
        }
      }

      return result;
    }
  };
  // Accepted O(X + Y)
  class TwoPointers {
  public:
    std::vector<std::vector<int>> findSolution(CustomFunction &_callback,
                                               int _expected) {
      int x { 1 };
      int y { 1000 };
      std::vector<std::vector<int>> result { };
      while ((x <= 1000) && (y >= 1)) {
        int value { _callback.f(x, y) };
        if (value == _expected) {
          result.emplace_back(std::vector<int> { x++, y-- });
        }
        else if (value > _expected) {
          --y;
        }
        else {
          ++x;
        }
      }

      return result;
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
class Solution1365 {
public:
  // Accepted
  class Sorting {
  private:
    int partition(std::vector<int> &_vec,
                  int _l,
                  int _r) {
      int value { _vec[(_l + _r) / 2] };
      while (_l <= _r) {
        while (_vec[_l] < value) {
          ++_l;
        }
        while (_vec[_r] > value) {
          --_r;
        }

        if (_l >= _r) {
          break;
        }

        std::swap(_vec[_l++], _vec[_r--]);
      }

      return _r;
    }

    void quickSort(std::vector<int> &_nums,
                   int _l,
                   int _r) {
      if (_l < _r) {
        int q { partition(_nums, _l, _r) };
        quickSort(_nums, _l, q);
        quickSort(_nums, q + 1, _r);
      }
    }

  public:
    std::vector<int> smallerNumbersThanCurrent(const std::vector<int> &_k_nums) {
      std::vector<int> tvec { _k_nums };
      quickSort(tvec, 0, tvec.size() - 1);

      std::unordered_map<int, int> hash { };
      int counter { };
      for (auto &&el : tvec) {
        if (hash.find(el) == hash.end()) {
          hash[el] = counter;
        }

        ++counter;
      }

      std::vector<int> result { };
      for (auto &&el : _k_nums) {
        result.emplace_back(hash[el]);
      }

      return result;
    }
  };
};
class Solution1382 {
public:
  // Accepted
  class DivideAndConquer {
  private:
    TreeNode* balance(int _l,
                      int _r,
                      const std::vector<TreeNode *> &_k_nodes) {
      if (_l > _r) {
        return nullptr;
      }

      int mid { (_l + _r) / 2 };
      TreeNode *p_root { _k_nodes[mid] };
      p_root->left = balance(_l, mid - 1, _k_nodes);
      p_root->right = balance(mid + 1, _r, _k_nodes);
      return p_root;
    }

    void toVector(TreeNode *_p_root,
                  std::vector<TreeNode *> &_nodes) {
      if (!_p_root) {
        return;
      }

      toVector(_p_root->left, _nodes);
      _nodes.emplace_back(_p_root);
      toVector(_p_root->right, _nodes);
    }

  public:
    TreeNode *balanceBST(TreeNode *_p_root) {
      std::vector<TreeNode *> nodes { };
      toVector(_p_root, nodes);
      return balance(0, nodes.size() - 1, nodes);
    }
  };
};
class Solution1431 {
public:
  // Accepted
  class Array {
  public:
    std::vector<bool> kidsWithCandies(const std::vector<int> &_k_candies,
                                      int _extra_candies) {
      int max { };
      for (auto &&el: _k_candies) {
        if (el > max) {
          max = el;
        }
      }

      std::vector<bool> result { };
      for (auto &&el: _k_candies) {
        if ((el + _extra_candies) >= max) {
          result.emplace_back(true);
        }
        else {
          result.emplace_back(false);
        }
      }

      return result;
    }
  };
};
class Solution1539 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(int _l,
                      int _r,
                      int _target,
                      const std::vector<int> &_k_vec) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        int guess { _k_vec[mid] };
        if (guess == _target) {
          return true;
        }
        else if (guess > _target) {
          return binarySearch(_l, mid - 1, _target, _k_vec);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _k_vec);
        }
      }

      return false;
    }

  public:
    int findKthPositive(const std::vector<int> &_k_vec,
                        int _k) {
      int index { };
      for (int i { 1 }; ; ++i) {
        bool is_finded { };
        if (i <= _k_vec.back()) {
          is_finded = binarySearch(0, _k_vec.size() - 1, i, _k_vec);
        }
        if ((!is_finded) && (++index == _k)) {
          return i;
        }
      }

      return INT_MIN;
    }
  };
};
class Solution1748 {
public:
  // Accepted
  class HashTable {
  public:
    int sumOfUnique(const std::vector<int> &_k_nums) {
      std::unordered_map<int, int> hash { };
      for (auto &&el: _k_nums) {
        ++hash[el];
      }

      int sum { };
      for (auto &&[key, value]: hash) {
        if (value == 1) {
          sum += key;
        }
      }

      return sum;
    }
  };
};
class Solution1768 {
public:
  // Accepted
  class TwoPointers {
  public:
    std::string mergeAlternately(const std::string &_k_word1,
                                 const std::string &_k_word2) {
      std::string result { };
      size_t i { };
      size_t j { };
      while ((i < _k_word1.size()) || (j < _k_word2.size())) {
        if (i < _k_word1.size()) {
          result += _k_word1[i++];
        }
        if (j < _k_word2.size()) {
          result += _k_word2[j++];
        }
      }

      return result;
    }
  };
};
class Solution1832 {
public:
  // Accepted
  class HashTable {
    bool checkIfPangram(const std::string &_k_sentence) {
      std::string alphabet { "abcdefghijklmnopqrstuvwxyz" };
      for (auto &&el: _k_sentence) {
        alphabet[el - 97] = '0';
      }
      for (auto &&el: alphabet) {
        if (el != '0') {
          return false;
        }
      }

      return true;
    }
  };
};
class Solution1920 {
public:
  // Accepted
  class Array {
  public:
    std::vector<int> buildArray(const std::vector<int> &_k_nums) {
      const size_t k_size { _k_nums.size() };
      std::vector<int> result { };
      result.resize(k_size);
      for (size_t i { }; i < k_size; ++i) {
        result[i] = _k_nums[_k_nums[i]];
      }

      return result;
    }
  };
};
class Solution1929 {
public:
  // Accepted
  class Array {
  public:
    std::vector<int> getConcatenation(std::vector<int> &_nums) {
      const size_t k_size { _nums.size() };
      for (size_t i { }; i < k_size; ++i) {
        _nums.emplace_back(_nums[i]);
      }

      return _nums;
    }
  };
  // Accepted
  class Array2 {
  public:
    std::vector<int> getConcatenation(std::vector<int> &_nums) {
      const size_t k_old_size { _nums.size() };
      const size_t k_new_size { _nums.size() * 2 };
      _nums.resize(k_old_size * 2);

      size_t index { k_new_size / 2 };
      for (size_t i { }; i < k_old_size; ++i) {
        _nums[index++] = _nums[i];
      }

      return _nums;
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
class Solution2032 {
  // Accepted
public:
  std::vector<int> twoOutOfThree(const std::vector<int> &_k_nums1,
                                 const std::vector<int> &_k_nums2,
                                 const std::vector<int> &_k_nums3) {
    std::unordered_set<int> set1 { _k_nums1.begin(), _k_nums1.end() };
    std::unordered_set<int> set2 { _k_nums2.begin(), _k_nums2.end() };
    std::unordered_set<int> set3 { _k_nums3.begin(), _k_nums3.end() };
    std::vector<int> result { };
    for (auto &&el: set1) {
      if ((set2.find(el) != set2.end()) ||
          (set3.find(el) != set3.end()) &&
          (std::find(result.begin(), result.end(), el) == result.end())) {
        result.emplace_back(el);
      }
    }
    for (auto &&el: set2) {
      if ((set3.find(el) != set3.end()) &&
          (std::find(result.begin(), result.end(), el) == result.end())) {
        result.emplace_back(el);
      }
    }

    return result;
  }
};
class Solution2089 {
public:
  // Accepted
  class BinarySearch {
  private:
    int binarySearch(int _l,
                     int _r,
                     int _target,
                     const std::vector<int> &_nums) {
      if (_l <= _r) {
        int mid { _l + (_r - _l) / 2 };
        int guess { _nums[mid] };
        if (guess == _target) {
          return mid;
        }
        else if (guess > _target) {
          return binarySearch(_l, mid - 1, _target, _nums);
        }
        else {
          return binarySearch(mid + 1, _r, _target, _nums);
        }
      }

      return INT_MIN;
    }

    void merge(int _l,
               int _m,
               int _r,
               std::vector<int> &_nums) {
      int size { (_r - _l) + 1 };
      int lpos { _l };
      int rpos { _m + 1 };
      int tpos { };
      std::vector<int> temp { };
      temp.resize(size);
      while ((lpos <= _m) && (rpos <= _r)) {
        if (_nums[lpos] < _nums[rpos]) {
          temp[tpos++] = _nums[lpos++];
        }
        else {
          temp[tpos++] = _nums[rpos++];
        }
      }
      while (lpos <= _m) {
        temp[tpos++] = _nums[lpos++];
      }
      while (rpos <= _r) {
        temp[tpos++] = _nums[rpos++];
      }
      for (size_t i { }; i < size; ++i) {
        _nums[_l + i] = temp[i];
      }
    }
    void mergeSort(int _l,
                   int _r,
                   std::vector<int> &_nums) {
      if (_l < _r) {
        int mid { (_l + _r) / 2 };
        mergeSort(_l, mid, _nums);
        mergeSort(mid + 1, _r, _nums);
        merge(_l, mid, _r, _nums);
      }
    }

  public:
    std::vector<int> targetIndices(std::vector<int> &_nums,
                                   int _target) {
      mergeSort(0, _nums.size() - 1, _nums);

      int root { binarySearch(0, _nums.size() - 1, _target, _nums) };
      std::vector<int> result { };
      result.reserve(_nums.size());
      if (root != INT_MIN) {
        result.emplace_back(root);

        int left_board { root };
        while ((--left_board >= 0) && (_nums[left_board] == _target)) {
          result.emplace_back(left_board);
        }

        int right_border { root };
        while ((++right_border < _nums.size()) && (_nums[right_border] == _target)) {
          result.emplace_back(right_border);
        }
      }

      mergeSort(0, result.size() - 1, result);
      return result;
    }
  };
};
class Solution2215 {
public:
  // Accepted
  class HashTable {
  public:
    std::vector<std::vector<int>> findDifference(const std::vector<int> &_k_nums1,
                                                 const std::vector<int> &_k_nums2) {
      std::vector<std::vector<int>> result { std::vector<int> { }, std::vector<int> { } };
      std::unordered_set<int> set1 { _k_nums1.begin(), _k_nums1.end() };
      std::unordered_set<int> set2 { _k_nums2.begin(), _k_nums2.end() };
      for (auto &&el: set1) {
        if (set2.find(el) == set2.end()) {
          result[0].emplace_back(el);
        }
      }
      for (auto &&el: set2) {
        if (set1.find(el) == set1.end()) {
          result[1].emplace_back(el);
        }
      }

      return result;
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
class Solution2325 {
public:
  // Accepted
  class HashTable {
  public:
    std::string decodeMessage(const std::string &_k_key,
                              const std::string &_k_message) {
      std::string result { };
      std::unordered_map<char, char> hash { };
      int index { 97 };
      for (auto &&el : _k_key) {
        if ((!isspace(el)) && (!hash[el])) {
          hash[el] = index++;
        }
      }
      for (auto &&el : _k_message) {
        if (isspace(el)) {
          result += ' ';
        }
        else {
          result += el;
        }
      }

      return result;
    }
  };
};
class Solution2418 {
public:
  // Accepted
  class Sorting {
  private:
    int partition(std::vector<int> &_vec,
                  int _l,
                  int _r) {
      int value { _vec[(_l + _r) / 2] };
      while (_l <= _r) {
        while (_vec[_l] > value) {
          ++_l;
        }
        while (_vec[_r] < value) {
          --_r;
        }

        if (_l >= _r) {
          break;
        }

        std::swap(_vec[_l++], _vec[_r--]);
      }

      return _r;
    }

    void quickSort(std::vector<int> &_vec,
                   int _l,
                   int _r) {
      if (_l < _r) {
        int q { partition(_vec, _l, _r) };
        quickSort(_vec, _l, q);
        quickSort(_vec, q + 1, _r);
      }
    }

  public:
    std::vector<std::string> sortPeople(const std::vector<std::string> &_k_names,
                                        std::vector<int> &_heights) {
      std::unordered_map<int, std::string> hash { };
      for (size_t i { }; i < _k_names.size(); ++i) {
        hash[_heights[i]] = _k_names[i];
      }

      quickSort(_heights, 0, _heights.size() - 1);

      std::vector<std::string> result { };
      for (auto &&el : _heights) {
        result.emplace_back(hash[el]);
      }

      return result;
    }
  };
};
class Solution2540 {
public:
  // Accepted
  class BinarySearch {
  private:
    bool binarySearch(const std::vector<int> &_k_nums,
                      int _target) {
      int l { };
      int r { static_cast<int>(_k_nums.size() - 1) };
      while (l <= r) {
        int mid { l + (r - l) / 2 };
        int guess { _k_nums[mid] };
        if (guess == _target) {
          return true;
        }
        else if (guess > _target) {
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }

      return false;
    }

  public:
    int getCommon(const std::vector<int> &_k_nums1,
                  const std::vector<int> &_k_nums2) {
      for (auto &&el : _k_nums1) {
        if (binarySearch(_k_nums2, el)) {
          return el;
        }
      }

      return -1;
    }
  };
};
class Solution2610 {
public:
  // Accepted
  class HashTable {
  public:
    std::vector<std::vector<int>> findMatrix(std::vector<int> &_nums) {
      std::vector<std::vector<int>> result { };
      for (size_t i { }; i < _nums.size(); ++i) {
        std::unordered_map<int, int> hash { };
        std::vector<int> row { };
        for (size_t j { }; j < _nums.size(); ++j) {
          if ((_nums[i] != INT_MIN) && (hash.find(_nums[i]) == hash.end())) {
            row.emplace_back(_nums[i]);
            _nums[i] = INT_MIN;
          }
        }

        if (row.empty()) {
          break;
        }

        result.emplace_back(row);
      }

      return result;
    }
  };
};

#endif

