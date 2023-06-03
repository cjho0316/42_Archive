# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>

template<typename T>
void printing(const std::string& msg, const T& container) {
	std::cout << msg;
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void mergeSort(T& container) {
	if (container.size() <= 1) {
		return;
	}
	size_t middle = container.size() / 2;
	T left(container.begin(), container.begin() + middle);
	T right(container.begin() + middle, container.end());
	mergeSort(left);
	mergeSort(right);

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while (i < left.size())
		container[k++] = left[i++];
	while (j < right.size())
		container[k++] = right[j++];
}

template<typename T>
void insertionSort(T& container) {
	for (size_t i = 1; i < container.size(); i++) {
		int key = container[i];
		int j = i - 1;
		while (j >= 0 && container[j] > key) {
			container[j + 1] = container[j];
			j--;
		}
		container[j + 1] = key;
	}
}

template<typename T>
void fordJohnsonSort(T& container, int start, int end) {
	if (start < end) {
		if (end - start <= 50) {
			insertionSort(container);
		}
		else {
			int middle = (start + end) / 2;
			fordJohnsonSort(container, start, middle);
			fordJohnsonSort(container, middle + 1, end);
			mergeSort(container);
		}
	}
}

template<typename T>
void calcTime(T& container) {
	std::clock_t start = std::clock();
	fordJohnsonSort(container, 0, container.size() - 1);
	std::clock_t end = std::clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double timeMicroSeconds = time * 1e6;
	std::cout << "Time to process a range of " << container.size() << " elements with std::container type " 
		<< std::fixed << std::setprecision(5) << timeMicroSeconds << " us" << std::endl;}

#endif
