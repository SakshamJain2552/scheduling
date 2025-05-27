#include "simulator.h"
#include "loader.h"

// Entry point for the program
int main(int argc, char* argv[]) {
    // Check if the number of arguments provided is correct
    if (argc != 3) {
        std::cerr << "Please use the following Syntax: ./rr quantum datafile" << std::endl;
        return EXIT_FAILURE;  // Return a standardized exit code for failure
    }

    // Convert the first argument to an integer (quantum value)
    int quantum = std::stoi(argv[1]);

    // Check if quantum value lies between 10 and 100
    if (quantum > 100 || quantum < 10){
        std::cerr << "Please input a quantum value between 10 and 100" << std::endl;
        return EXIT_FAILURE;  // Return a standardized exit code for failure

    }
    // Load processes from the provided file path
    std::vector<pcb> processList = Loader::loadData(argv[2]);

    // Initialize the simulator with the loaded processes
     Simulator simulator(processList);

    // Run the round-robin scheduling algorithm with the given quantum
    simulator.runRR(quantum);

    // Return a successful exit code
    return EXIT_SUCCESS; 
}

