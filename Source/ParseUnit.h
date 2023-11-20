#pragma once

#include <vector>

#include "Node.h"

namespace pcl {
    class ParseUnit {
    public:
        ~ParseUnit() {
            for(auto node : nodes_)
                delete(node);
        }

        std::vector<Node*>& GetNodes() { return nodes_; }
        void PushNode(Node *node) { nodes_.push_back(node); }

    private:
        std::vector<Node*> nodes_;
    };
};
