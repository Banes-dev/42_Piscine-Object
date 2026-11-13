#include "Network.hpp"

#include <stdexcept>


void Network::AddNode(const std::string &aName)
{
    if (mNodes.find(aName) != mNodes.end())
        throw std::runtime_error("Node already exists : " + aName);

    mNodes[aName] = std::make_unique<Node>(aName);
}

void Network::AddRail(const std::string &aCityA, const std::string &aCityB, double aLength, double aMaxSpeed)
{
    Node *vNodeA = GetNode(aCityA);
    Node *vNodeB = GetNode(aCityB);

    if (!vNodeA || !vNodeB)
        throw std::runtime_error("Cannot create rail, node missing : " + aCityA + " or " + aCityB);

    mRails.push_back(std::make_unique<Rail>(vNodeA, vNodeB, aLength, aMaxSpeed));
}

Node *Network::GetNode(const std::string &aName) const
{
    auto vIt = mNodes.find(aName);
    if (vIt != mNodes.end())
        return vIt->second.get();

    return nullptr;
}

const std::vector<std::unique_ptr<Rail>> &Network::GetRails() const
{
    return mRails;
}
