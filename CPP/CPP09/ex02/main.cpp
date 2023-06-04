#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: No input sequence provided." << std::endl;
        return (1);
    }

    std::vector<int> sequenceVector;
    std::deque<int> sequenceDeque;
    // Parse command-line arguments and populate the sequence containers
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cout << "Error: Invalid input. Positive integers only." << std::endl;
            return (1);
        }
        sequenceVector.push_back(num);
        sequenceDeque.push_back(num);
    }
    {
        // Display the unsorted sequence
        printing("Before: ", sequenceVector);
        // Display the time taken for vector sort
        calcTime(sequenceVector);
        printing("After: ", sequenceVector);
        calcTime(sequenceDeque);
    }
    return 0;
}
