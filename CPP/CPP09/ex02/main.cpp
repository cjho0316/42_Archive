#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> sequenceVector;
    std::deque<int> sequenceDeque;

    // Parse command-line arguments and populate the sequence containers
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cout << "Error: Invalid input. Positive integers only." << std::endl;
            return 1;
        }
        sequenceVector.push_back(num);
        sequenceDeque.push_back(num);
    }

    // Display the unsorted sequence
    printVector("Before: ", sequenceVector);

    // Sort using vector and measure time
    std::clock_t start = std::clock();
    mergeSortVector(sequenceVector);
    std::clock_t end = std::clock();
    double timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // Display the sorted sequence
    printVector("After: ", sequenceVector);

    // Display the time taken for vector sort
    std::cout << "Time to process a range of " << sequenceVector.size() << " elements with std::vector: "
              << timeVector << " sec" << std::endl;

    // Display the unsorted sequence
    printDeque("Before: ", sequenceDeque);

    // Sort using deque and measure time
    std::clock_t start = std::clock();
    mergeSortDeque(sequenceDeque);
    std::clock_t end = std::clock();
    double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    printDeque("After: ", sequenceDeque);
    // Display the time taken for deque sort
    std::cout << "Time to process a range of " << sequenceDeque.size() << " elements with std::deque: "
              << timeDeque << " sec" << std::endl;

    return 0;
}
