#include "simulator.h"
#include "loader.h"

// Entry point for the program
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments has been provided
    if (argc != 2) {
        std::cerr << "Please use the following syntax: ./sjf datafile" << std::endl;
        return EXIT_FAILURE;  // Return a standardized exit code for failure
    }

    // Load processes from the specified file path
    std::vector<pcb> processList = Loader::loadData(argv[1]);

    // Initialize the scheduling simulator with the loaded processes
    Simulator simulator(processList);

    // Run the Shortest-Job-First (SJF) scheduling algorithm
    simulator.runSJF();

    // Return a successful exit code
    return EXIT_SUCCESS;  // Standardized success exit code
}

