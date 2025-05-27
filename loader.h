#pragma once
#include "pcb.h"
#include <vector>

class Loader {
public:
    static std::vector<pcb> loadData(const std::string& filename);
};
