#include "DijkstraPathfinder.hpp"

#include <limits>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include <queue>


std::vector<Rail *> DijkstraPathfinder::CalculatePath(const Network &aNetwork, Node *aStart, Node *aEnd)
{
    // 1. Build a local adjacency list for optimal performance
    std::unordered_map<Node *, std::vector<Rail *>> vAdjacencyList;
    for (const auto &vRailPtr : aNetwork.GetRails())
    {
        Rail *vRail = vRailPtr.get();
        // Assuming rails are bidirectional
        vAdjacencyList[vRail->GetNodeA()].push_back(vRail);
        vAdjacencyList[vRail->GetNodeB()].push_back(vRail);
    }

    // 2. Initialize distances (infinite by default) and paths
    std::unordered_map<Node *, double> vDistances;
    std::unordered_map<Node *, Rail *> vPreviousRail;
    
    // Priority queue to always explore the closest node first
    std::priority_queue<QueueElement, std::vector<QueueElement>, std::greater<QueueElement>> vQueue;

    vQueue.push({aStart, 0.0});
    vDistances[aStart] = 0.0;

    // 3. Main Dijkstra loop
    while (!vQueue.empty())
    {
        Node *vCurrentNode = vQueue.top().mNode;
        double vCurrentDist = vQueue.top().mDistance;
        vQueue.pop();

        // If destination is reached, we can stop
        if (vCurrentNode == aEnd)
            break;

        // Ignore if a shorter path was already found
        if (vDistances.find(vCurrentNode) != vDistances.end() && vCurrentDist > vDistances[vCurrentNode])
            continue;

        // Explore neighbors
        for (Rail *vRail : vAdjacencyList[vCurrentNode])
        {
            Node *vNeighbor = (vRail->GetNodeA() == vCurrentNode) ? vRail->GetNodeB() : vRail->GetNodeA();
            double vNewDist = vCurrentDist + vRail->GetLength();

            if (vDistances.find(vNeighbor) == vDistances.end() || vNewDist < vDistances[vNeighbor])
            {
                vDistances[vNeighbor] = vNewDist;
                vPreviousRail[vNeighbor] = vRail;
                vQueue.push({vNeighbor, vNewDist});
            }
        }
    }

    // 4. Reconstruct the path backwards from the destination
    std::vector<Rail *> vPath;
    Node *vStep = aEnd;

    // If destination was never reached and we are not at the start
    if (vPreviousRail.find(vStep) == vPreviousRail.end() && vStep != aStart)
        throw std::runtime_error("No path found between " + aStart->GetName() + " and " + aEnd->GetName());

    while (vStep != aStart)
    {
        Rail *vRail = vPreviousRail[vStep];
        vPath.push_back(vRail);
        // Move one step back
        vStep = (vRail->GetNodeA() == vStep) ? vRail->GetNodeB() : vRail->GetNodeA();
    }

    // The path was built from end to start, it needs to be reversed
    std::reverse(vPath.begin(), vPath.end());

    return vPath;
}
