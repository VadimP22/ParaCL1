#pragma once

#include <vector>
#include <concepts>

namespace pcl {
    using NodeKind = int;

    class Node {
    public:
        static const constexpr NodeKind Kind = -1;

        Node(NodeKind node_kind) : node_kind_(node_kind) {}
        virtual ~Node() {
            for (auto *node: childs_)
                delete(node);
        };

        template <typename T> requires std::derived_from<T, Node>
        T& As() {
            return static_cast<T&>(this);
        }

        template <typename T> requires std::derived_from<T, Node>
        bool Is() {
            if (node_kind_ ==T::Kind)
                return true;

            return false;
        }

        std::vector<Node *>& GetChilds() { return childs_; }
        void AddChild(Node *child) { childs_.push_back(child); }

    private:
        NodeKind node_kind_;
        std::vector<Node *> childs_;
    };
};
