#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
    std::deque<int> inputDeque;
    std::list<int> inputList;

    for (int i = 1; i < ac; ++i) {
        int value = atoi(av[i]);
        if (value <= 0) {
            std::cerr << "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
            exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
    }
    std::cout << "Before: ";
    display(inputDeque);

    clock_t start1 = clock();
    mergeInsertSortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(inputDeque);
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (inputDeque == std::deque<int>(inputList.begin(), inputList.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

template <typename T>
void PmergeMe::display(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::mergeInsertSort(T& arr) {
    if (arr.size() <= 1) return;

    // Step 1: Pair elements
    std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
    typename T::iterator it = arr.begin();
    while (it != arr.end() && std::next(it) != arr.end()) {
        typename T::value_type first = *it;
        typename T::value_type second = *std::next(it);
        if (first > second) std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
        std::advance(it, 2);
    }

    // Handle odd element if present
    typename T::value_type odd_element;
    bool has_odd = (arr.size() % 2 != 0);
    if (has_odd) odd_element = *it;

    // Step 2: Recursively sort larger elements
    T larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        larger_elements.push_back(pairs[i].second);
    }
    mergeInsertSort(larger_elements);

    // Step 3: Construct result
    arr.clear();
    arr.push_back(pairs[0].first);
    typename T::iterator insert_pos = arr.begin();
    for (typename T::iterator it = larger_elements.begin(); it != larger_elements.end(); ++it) {
        insert_pos = arr.insert(std::upper_bound(arr.begin(), arr.end(), *it), *it);
    }

    // Step 4: Insert smaller elements
    for (size_t i = 1; i < pairs.size(); ++i) {
        insert_pos = std::upper_bound(arr.begin(), arr.end(), pairs[i].first);
        arr.insert(insert_pos, pairs[i].first);
    }

    // Insert odd element if present
    if (has_odd) {
        insert_pos = std::upper_bound(arr.begin(), arr.end(), odd_element);
        arr.insert(insert_pos, odd_element);
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    mergeInsertSort(arr);
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    mergeInsertSort(arr);
}