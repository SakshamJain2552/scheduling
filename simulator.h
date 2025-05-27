#pragma once
#include "pcb.h"
#include <vector>

// Class responsible for simulating different scheduling algorithms
class Simulator {

public:

    // Constructor initializes the simulator with a list of processes
    Simulator(const std::vector<pcb>& processes);

    // Simulate the Round-Robin (RR) scheduling algorithm with a given quantum
    void runRR(int quantum);

    // Simulate the First-In-First-Out (FIFO) scheduling algorithm
    void runFIFO();

    // Simulate the Shortest-Job-First (SJF) scheduling algorithm
    void runSJF();

private:

    // Container holding all the processes for simulation
    std::vector<pcb> processes;
};
