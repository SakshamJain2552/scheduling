#include <algorithm>
#include <iostream>
#include <queue>
#include "simulator.h"

// Constructor: Initializes the simulator with a list of processes
Simulator::Simulator(const std::vector<pcb>& processList) : processes(processList) {}


// runRR: Simulate the Round-Robin (RR) scheduling algorithm using a given quantum
void Simulator::runRR(int quantum) {
    std::queue<pcb> processes_queue;

    // Enqueue all processes
    for (const pcb& process : processes) {
        processes_queue.push(process);
    }

    // Metrics initialization
    osp2023::time_type total_turnaround_time = 0;
    osp2023::time_type total_waiting_time = 0;
    osp2023::time_type total_response_time = 0;
    osp2023::time_type current_time = 0;

    // Header for the output
    std::cout << "Process ID |  Burst Time |  Turnaround Time |  Waiting Time |  Response Time" << std::endl;
    while (!processes_queue.empty()) {
        pcb& process = processes_queue.front();

        // Calculate response time if the process hasn't been executed yet
        if (process.getConsumedTime() == 0) {
            osp2023::time_type response_time = current_time;
            total_response_time += response_time;
        }

        // Determine the time a process will run in this cycle, limited by the quantum
        osp2023::time_type run_time = std::min(static_cast<osp2023::time_type>(quantum), process.getExecutionDuration() - process.getConsumedTime());

        // Update times
        current_time += run_time;
        process.addConsumedTime(run_time);

        // If process is finished, calculate and display its metrics
        if (process.getConsumedTime() == process.getExecutionDuration()) {
            osp2023::time_type turnaround_time = current_time;
            osp2023::time_type waiting_time = turnaround_time - process.getExecutionDuration();

            // Display metrics
            std::cout << process.getProcessId() << " |  "
                      << process.getExecutionDuration() << " |  "
                      << turnaround_time << " |  "
                      << waiting_time << " |  "
                      << (waiting_time + process.getExecutionDuration()) << std::endl;  // Response time

            // Accumulate metrics
            total_turnaround_time += turnaround_time;
            total_waiting_time += waiting_time;

            processes_queue.pop();
        } else {
            // If process is not finished, put it to the back of the queue
            processes_queue.pop();
            processes_queue.push(process);
        }
    }

    // Output average metrics
    size_t num_processes = processes.size();
    std::cout << "Average Turnaround Time: " << total_turnaround_time / num_processes << std::endl;
    std::cout << "Average Waiting Time: " << total_waiting_time / num_processes << std::endl;
    std::cout << "Average Response Time: " << total_response_time / num_processes << std::endl;
}

// runFIFO: Simulate the First-In-First-Out (FIFO) scheduling algorithm
void Simulator::runFIFO() {

    // Metrics initialization
    osp2023::time_type total_turnaround_time = 0;
    osp2023::time_type total_waiting_time = 0;
    osp2023::time_type total_response_time = 0;
    osp2023::time_type current_time = 0;

    // Header for the output
    std::cout << "Process ID |  Burst Time |  Turnaround Time |  Waiting Time |  Response Time" << std::endl;


    for (pcb& process : processes) {
        // Compute per-process metrics
        osp2023::time_type turnaround_time = current_time + process.getExecutionDuration();
        osp2023::time_type waiting_time = current_time;
        osp2023::time_type response_time = waiting_time;  // For FIFO, response time equals waiting time

        // Display the per-process metrics
        std::cout << process.getProcessId() << " |  "
                  << process.getWaitDuration() << " |  "
                  << turnaround_time << " |  "
                  << waiting_time << " |  "
                  << response_time << std::endl;

        // Accumulate total metrics
        total_turnaround_time += turnaround_time;
        total_waiting_time += waiting_time;
        total_response_time += response_time;

        // Update the current time
        current_time += process.getExecutionDuration();
    }

    // Output the average metrics
    size_t num_processes = processes.size();
    std::cout << "Average Turnaround Time: " << total_turnaround_time / num_processes << std::endl;
    std::cout << "Average Waiting Time: " << total_waiting_time / num_processes << std::endl;
    std::cout << "Average Response Time: " << total_response_time / num_processes << std::endl;
}

// runSJF: Simulate the Shortest-Job-First (SJF) scheduling algorithm
void Simulator::runSJF() {

    // Sort processes based on their execution duration (ascending)
    std::sort(processes.begin(), processes.end(), [](const pcb& a, const pcb& b) {
        return a.getExecutionDuration() < b.getExecutionDuration();
    });
        // Similar approach as FIFO but with processes sorted based on burst times
    runFIFO();

}