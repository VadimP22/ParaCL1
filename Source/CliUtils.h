#pragma once

#include <vector>
#include <string>

namespace pcl {
    using CliArgs = std::vector<std::string>;
    
    CliArgs MakeCliArgs(int argc, char** argv);
    bool FindFlag(CliArgs &args, const char *name);
};
