#include "loader.h"
#include <fstream>
#include <sstream>

// Function to load process data from a given filename
std::vector<pcb> Loader::loadData(const std::string& filename) {
    // Container to hold the process data
    std::vector<pcb> processList;

    // Open the file for reading
    std::ifstream dataFile(filename);

    // Check if file opened successfully
    if (!dataFile) {
        std::cerr << "Error: Failed to open the datafile." << std::endl;
        exit(EXIT_FAILURE); // Use EXIT_FAILURE for a standardized exit code
    }

    // Read each line from the file
    std::string currentLine;
    while (std::getline(dataFile, currentLine)) {
        std::istringstream lineStream(currentLine);

        // Variables to store the ID and burst time
        osp2023::id_type processID;
        osp2023::time_type burstDuration;
        char delimiter;

        // Parse the line and check for proper format (ID, burst time)
        if (lineStream >> processID >> delimiter >> burstDuration && delimiter == ',') {
            // Add the process to the list
            processList.emplace_back(processID, burstDuration);
        } else {
            std::cerr << "Warning: Skipping malformed line in the datafile: " << currentLine << std::endl;
        }
    }

    // Return the list of processes
    return processList;
}
