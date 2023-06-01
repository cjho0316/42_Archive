# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>

void printVector(const std::string& msg, const std::vector<int>& v);
void printDeque(const std::string& msg, const std::deque<int>& v);
void mergeSortVector(std::vector<int>& v);
void mergeSortDeque(std::deque<int>& v);

#endif
