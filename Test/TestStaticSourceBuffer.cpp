#include "StaticSourceBuffer.h"
#include "Ut.h"

int main() {
    using namespace boost::ut;
    
    pcl::StaticSourceBuffer buffer{"Hello, static source buffer!"};
    const char *str = "Hello, static source buffer!";

    int counter = 0;
    for (auto it = buffer.Begin(), end = buffer.End(); it != end; ++it) {
        expect(*it == str[counter]);
        counter += 1;
    }
    
    return 0;
}
