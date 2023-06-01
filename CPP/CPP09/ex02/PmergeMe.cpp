#include "PmergeMe.hpp"

void printVector(const std::string& msg, const std::vector <int> &v) {
    std::cout << msg << std::endl;
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void printDeque(const std::string& msg, const std::deque <int> &v) {
    std::cout << msg << std::endl;
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void mergeSortVector(std::vector<int>& v) {
    if (v.size() <= 1) {
        return;
    }

    size_t middle = v.size() / 2;
    std::vector<int> left(v.begin(), v.begin() + middle);
    std::vector<int> right(v.begin() + middle, v.end());

    mergeSortVector(left);
    mergeSortVector(right);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }

    while (i < left.size())
        v[k++] = left[i++];

    while (j < right.size())
        v[k++] = right[j++];
}

void mergeSortDeque(std::deque<int>& dq) {
    if (dq.size() <= 1) {
        return;
    }
    size_t middle = dq.size() / 2;
    std::deque<int> left(dq.begin(), dq.begin() + middle);
    std::deque<int> right(dq.begin() + middle, dq.end());

    mergeSortDeque(left);
    mergeSortDeque(right);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            dq[k++] = left[i++];
        else
            dq[k++] = right[j++];
    }

    while (i < left.size())
        dq[k++] = left[i++];
    while (j < right.size())
        dq[k++] = right[j++];
}

void printDeque(const std::string& msg, const std::deque <int> &v) {
    std::cout << msg << std::endl;
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}