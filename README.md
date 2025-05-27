# ⏱️ CPP Scheduler Simulator

A console-based C++20 personal project that simulates and compares process‐scheduling algorithms on a single‐CPU system, complete with performance metrics and flexible input handling.

---

## 🔥 Features

- **Three Scheduling Algorithms**  
  - **FIFO** (First-In, First-Out)  
  - **SJF** (Shortest‐Job‐First, non‐preemptive)  
  - **RR** (Round‐Robin, time-slice driven)  
- **Process Control Block (PCB) Management**  
  Encapsulates ProcessID, burst time, turnaround time, waiting time, response time.  
- **Data Loader**  
  Parses comma-separated `<ProcessID>,<BurstTime>` files; supports reproducible random datasets via seed.  
- **Performance Metrics**  
  Reports per‐process and aggregate average turnaround, waiting, and response times.  
- **Configurable Quantum**  
  Pass the time slice for RR at runtime to explore trade-offs.  
- **Modular Design**  
  - `Loader` class for input parsing  
  - `Simulator` class templated by scheduling policy  
  - `PCB` class for process state  
  - Separate executables for each algorithm  
- **Makefile Automation**  
  One-command build for all targets (`fifo`, `sjf`, `rr`); individual targets when needed.

---

## 🛠️ Build & Run

### Prerequisites

- C++20-compatible compiler (e.g. `g++` ≥ 11)  
- Unix-like shell (Linux, macOS)  
- `make` utility  

### Build

```bash
# Build all three simulators
make

# Or build individually
make fifo    # → ./fifo
make sjf     # → ./sjf
make rr      # → ./rr
````

```bash
# Manual compilation without Makefile
g++ -std=c++20 -Wall -Werror -O2 \
  loader.cpp pcb.cpp simulator.cpp fifo.cpp sjf.cpp rr.cpp \
  -o scheduler
# Or compile each executable separately:
g++ -std=c++20 -Wall -Werror -O2 fifo.cpp loader.cpp pcb.cpp simulator.cpp -o fifo
g++ -std=c++20 -Wall -Werror -O2 sjf.cpp  loader.cpp pcb.cpp simulator.cpp -o sjf
g++ -std=c++20 -Wall -Werror -O2 rr.cpp   loader.cpp pcb.cpp simulator.cpp -o rr
```

### Run

```bash
# FIFO: ./fifo <datafile>
./fifo processes.csv

# SJF:  ./sjf  <datafile>
./sjf processes.csv

# RR:   ./rr <quantum-ms> <datafile>
./rr 50 processes.csv
```

* `<datafile>` – text file with lines `ProcessID,BurstTime`
* `<quantum-ms>` – time slice in milliseconds for RR

### Clean Up

```bash
make clean
```

---

## 🧠 C++ Concepts Practiced

* **Abstract Data Types & Class Design**
  Clean separation of `Loader`, `PCB`, and `Simulator` responsibilities.
* **STL Containers & Algorithms**
  `std::vector`, `std::deque`, `std::sort` for SJF queue ordering.
* **File I/O & Parsing**
  Robust reading of CSV inputs with error checking; custom exceptions on malformed data.
* **Program State Management**
  Tracking and updating PCB metrics (turnaround, waiting, response) through simulation loops.
* **Exception Handling**
  Custom `FileLoadError` and `InvalidArgumentError` to ensure safe startup and input validation.
* **Command-Line Argument Parsing**
  Flexible handling of different invocation patterns (`fifo`, `sjf`, `rr`).
* **Performance Experimentation**
  Easy swapping of quantum values and batch runs to collect scheduling statistics.


