#include "simulator.h"
#include "loader.h"

// Entry point for the program
int main(int argc, char* argv[]) {

    // Check if the number of arguments provided is correct
    if (argc != 2) {
        std::cerr << "Please use the following Syntax: ./fifo datafile" << std::endl;
        return 1;
    }

    // Load processes from the provided file path
    std::vector<pcb> processList = Loader::loadData(argv[1]);

    // Initialize the simulator with the loaded processes
    Simulator simulator(processList);

    // Run the round-robin scheduling algorithm with the given quantum
    simulator.runFIFO();

    // Return a successful exit code
    return EXIT_SUCCESS;
}
