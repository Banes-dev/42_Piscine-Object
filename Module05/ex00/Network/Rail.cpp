#include "Rail.hpp"


Rail::Rail(Node *aNodeA, Node *aNodeB, double aLength, double aMaxSpeed) : mNodeA(aNodeA), mNodeB(aNodeB), mLength(aLength), mMaxSpeed(aMaxSpeed)
{
}

Node *Rail::GetNodeA() const
{
    return mNodeA;
}

Node *Rail::GetNodeB() const
{
    return mNodeB;
}

double Rail::GetLength() const
{
    return mLength;
}

double Rail::GetMaxSpeed() const
{
    return mMaxSpeed;
}
