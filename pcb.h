#include <iostream>
#include "types.h"

// Use '#pragma once' to avoid multiple inclusions
#pragma once

// Class to represent a Process Control Block (PCB)

class pcb {
private:
    
    // Process ID
    osp2023::id_type id;
    
    // Total required execution time for the process
    osp2023::time_type total_time;

    // Time that has been used so far by the process
    osp2023::time_type time_used = 0;

    // Total time the process had to wait
    osp2023::time_type total_wait_time = 0;

public:

    // Default constructor
    pcb() = default;

    // Parametric constructor
    pcb(osp2023::id_type pid, osp2023::time_type totalTime) : id(pid), total_time(totalTime) {}

    // Getter and Setter 

    // Retrieve the total waiting time of the process
    osp2023::time_type getWaitDuration() const { return total_wait_time; }

    // Retrieve total required execution time for the process
    osp2023::time_type getExecutionDuration() const { return total_time; }

    osp2023::id_type getProcessId() const { return id; }

    // Retrieve time that has been used so far by the process
    osp2023::time_type getConsumedTime() const { return time_used; }

    // Increase the consumed time of the process
    void addConsumedTime(osp2023::time_type time) { time_used += time; }

    // Constants defining the maximum and minimum duration of the process
    static constexpr osp2023::time_type MAX_DURATION = 100;
    static constexpr osp2023::time_type MIN_DURATION = 10;
};
