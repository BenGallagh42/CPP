#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

    // Vector implementation
    void                     _mergeInsertSortVector(std::vector<int>& arr);
    std::vector<int>         _generateJacobsthalVector(size_t n);
    std::vector<int>::iterator _binarySearchVector(std::vector<int>& arr, int value, size_t end);

    // Deque implementation
    void                    _mergeInsertSortDeque(std::deque<int>& arr);
    std::vector<int>        _generateJacobsthalDeque(size_t n);
    std::deque<int>::iterator _binarySearchDeque(std::deque<int>& arr, int value, size_t end);

    // Parsing and validation
    bool _isValidNumber(const std::string& str) const;
    void _parseInput(int argc, char** argv);

    // Display
    void _displaySequence(const std::string& label, const std::vector<int>& seq, size_t max) const;
    void _displaySequence(const std::string& label, const std::deque<int>& seq, size_t max) const;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void sort(int argc, char** argv);
};

#endif