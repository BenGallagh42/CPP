#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vector = other._vector;
    _deque = other._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return (*this);
}

// Checks if string is a valid positive integer
bool PmergeMe::_isValidNumber(const std::string& str) const
{
    if (str.empty())
        return (false);

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }

    long num = std::atol(str.c_str()); // ascii(string) to long
    if (num < 0 || num > 2147483647)
        return (false);

    return (true);
}

// Parses command line arguments into both containers
void PmergeMe::_parseInput(int argc, char** argv)
{
    // Safety precaution, clearing vectors
    _vector.clear();
    _deque.clear();

    for (int i = 1; i < argc; i++)
    {
        if (!_isValidNumber(argv[i]))
            throw std::runtime_error("Error"); // use std::runtime_error because void method

        int num = std::atoi(argv[i]); // atoi here as we already check for int max in isValidNumber
        _vector.push_back(num);
        _deque.push_back(num);
    }

    if (_vector.empty() || _deque.empty())
        throw std::runtime_error("Error");
}

// Displays sequence with optional truncation
void PmergeMe::_displaySequence(const std::string& label, const std::vector<int>& seq, size_t max) const
{
    std::cout << label;
    for (size_t i = 0; i < seq.size() && i < max; i++)
    {
        std::cout << seq[i];
        if (i + 1 < seq.size() && i + 1 < max) // Add space after if not last element
            std::cout << " ";
    }
    if (seq.size() > max)
        std::cout << " [...]"; // If more elements in vector than max

    std::cout << std::endl;
}

// Generates Jacobsthal sequence for optimal insertion order
std::vector<int> PmergeMe::_generateJacobsthalVector(size_t n)
{
    std::vector<int> jacobsthal;
    if (n == 0)
        return (jacobsthal);

    jacobsthal.push_back(0);
    if (n == 1)
        return (jacobsthal);

    jacobsthal.push_back(1);
    
    while (true)
    {
        size_t size = jacobsthal.size();
        // J(n) = J(n-1) + 2 × J(n-2)
        int next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        // next is int as push_back requires an int, and jacobsthal is an int vector
        if (static_cast<size_t>(next) >= n) // Cast to compare size_t and int
            break;
        jacobsthal.push_back(next);
    }

    return (jacobsthal);
}

// Binary search to find where to insert value in array
// Return an iterator to be able to use insert()
std::vector<int>::iterator PmergeMe::_binarySearchVector(std::vector<int>& arr, int value, size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return (arr.begin() + left);
}

// Ford-Johnson merge-insert sort for vector
void PmergeMe::_mergeInsertSortVector(std::vector<int>& arr)
{
    // No need to sort if vector has 0 or 1 element
    if (arr.size() <= 1)
        return;

    // Step 1: Create and sort pairs using std::pair and std::make_pair
    std::vector<std::pair<int, int> > pairs;        
    bool hasStraggler = false;  // Flag if there is an element that can't be paired
    int straggler = -1;         // Element not paired

    for (size_t i = 0; i + 1 < arr.size(); i += 2) // use size_t as size() returns a size_t
    {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    if (arr.size() % 2 != 0)
    {
        straggler = arr[arr.size() - 1];
        hasStraggler = true;
    }

    // Step 2: Sort pairs by their larger element
    for (size_t i = 0; i < pairs.size(); i++)
    {
        for (size_t j = i + 1; j < pairs.size(); j++)
        {
            if (pairs[i].first > pairs[j].first)
            {
                std::pair<int, int> temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }

    // Step 3: Create main chain
    std::vector<int> mainChain;
    std::vector<int> pending;

    if (!pairs.empty())
        mainChain.push_back(pairs[0].second); // First small element (smallest of the smallest)

    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first); // All large elements

    for (size_t i = 1; i < pairs.size(); i++)
        pending.push_back(pairs[i].second); // Remaining small elements

    if (hasStraggler)
        pending.push_back(straggler);

    // Step 4: Insert pending elements using Jacobsthal order
    std::vector<int> jacobsthal = _generateJacobsthalVector(pending.size() + 1);
    std::vector<bool> inserted(pending.size(), false); // To flag elements already inserted

    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        int jNum = jacobsthal[i];
        int limit;

        if (i > 1)
            limit = jacobsthal[i - 1];
        else
            limit = 0;
    
        for (int pos = jNum - 1; pos >= limit; pos--) // pos is int because can be <0
        {
            if (pos >= 0 && static_cast<size_t>(pos) < pending.size() && !inserted[pos])
            {
                std::vector<int>::iterator insertPos = _binarySearchVector(mainChain, pending[pos], mainChain.size());
                mainChain.insert(insertPos, pending[pos]);
                inserted[pos] = true;
            }
        }
    }

    // Insert any element left in pending
    for (size_t i = 0; i < pending.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator insertPos = _binarySearchVector(mainChain, pending[i], mainChain.size());
            mainChain.insert(insertPos, pending[i]);
        }
    }

    arr = mainChain;
}

// Deque versions (identical logic, different container)
void PmergeMe::_displaySequence(const std::string& label, const std::deque<int>& seq, size_t max) const
{
    std::cout << label;
    for (size_t i = 0; i < seq.size() && i < max; i++)
    {
        std::cout << seq[i];
        if (i + 1 < seq.size() && i + 1 < max)
            std::cout << " ";
    }
    if (seq.size() > max)
        std::cout << " [...]";

    std::cout << std::endl;
}

std::vector<int> PmergeMe::_generateJacobsthalDeque(size_t n)
{
    return (_generateJacobsthalVector(n));
}

std::deque<int>::iterator PmergeMe::_binarySearchDeque(std::deque<int>& arr, int value, size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return (arr.begin() + left);
}

void PmergeMe::_mergeInsertSortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    if (arr.size() % 2 != 0)
    {
        straggler = arr[arr.size() - 1];
        hasStraggler = true;
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        for (size_t j = i + 1; j < pairs.size(); j++)
        {
            if (pairs[i].first > pairs[j].first)
            {
                std::pair<int, int> temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }

    std::deque<int> mainChain;
    std::vector<int> pending;

    if (!pairs.empty())
        mainChain.push_back(pairs[0].second);

    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first);

    for (size_t i = 1; i < pairs.size(); i++)
        pending.push_back(pairs[i].second);

    if (hasStraggler)
        pending.push_back(straggler);

    std::vector<int> jacobsthal = _generateJacobsthalDeque(pending.size() + 1);
    std::vector<bool> inserted(pending.size(), false);

    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        int jNum = jacobsthal[i];
        
        for (int pos = jNum - 1; pos >= (i > 1 ? jacobsthal[i - 1] : 0); pos--)
        {
            if (pos >= 0 && static_cast<size_t>(pos) < pending.size() && !inserted[pos])
            {
                std::deque<int>::iterator insertPos = _binarySearchDeque(mainChain, pending[pos], mainChain.size());
                mainChain.insert(insertPos, pending[pos]);
                inserted[pos] = true;
            }
        }
    }

    for (size_t i = 0; i < pending.size(); i++)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator insertPos = _binarySearchDeque(mainChain, pending[i], mainChain.size());
            mainChain.insert(insertPos, pending[i]);
        }
    }

    arr = mainChain;
}

// Main sorting function with timing
void PmergeMe::sort(int argc, char** argv)
{
    // Parsing + Display
    _parseInput(argc, argv);
    _displaySequence("Vector before: ", _vector, 5);
    _displaySequence("Deque before: ", _deque, 5);
    std::cout << std::endl;

    // Sort with vector
    clock_t startVector = clock();
    _mergeInsertSortVector(_vector);
    clock_t endVector = clock();
    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

    // Sort with deque
    clock_t startDeque = clock();
    _mergeInsertSortDeque(_deque);
    clock_t endDeque = clock();
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    _displaySequence("Vector after: ", _vector, 5);
    _displaySequence("Deque after: ", _deque, 5);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << timeDeque << " us" << std::endl;
}