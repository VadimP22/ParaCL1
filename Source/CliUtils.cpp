#include "CliUtils.h"


pcl::CliArgs pcl::MakeCliArgs(int argc, char **argv) {
    return std::vector<std::string>(argv + 1, argv + argc);
}

bool pcl::FindFlag(pcl::CliArgs &args, const char *name) {
    return false;
}
