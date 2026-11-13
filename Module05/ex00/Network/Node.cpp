#include "Node.hpp"


Node::Node(const std::string &aName) : mName(aName)
{
}

const std::string &Node::GetName() const
{
    return mName;
}
