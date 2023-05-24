// Header Files
#include "BoxCollider.h"

BoxCollider BoxCollider::GetCollisionRegion(const BoxCollider& secondBox)
{
	BoxCollider collider;

	collider.min[0] = std::max(min[0], secondBox.min[0]);
	collider.min[1] = std::max(min[1], secondBox.min[1]);
	collider.max[0] = std::min(max[0], secondBox.max[0]);
	collider.max[1] = std::max(max[1], secondBox.max[1]);

	return collider;
}

bool BoxCollider::IsColliding(const BoxCollider& secondBox) const
{
	return ((max[0] > secondBox.min[0] && secondBox.max[0] > min[0]) && (max[1] > secondBox.min[1] && secondBox.max[1] > min[1]));
}

bool BoxCollider::IsColliding(const BoxCollider& secondBox, const std::vector<int>& lhsBoxVelocity, const std::vector<int>& rhsBoxVelocity, float maxTime, float* firstTime)
{
    std::vector<int> relativeVelocity = { lhsBoxVelocity[0] - rhsBoxVelocity[0], lhsBoxVelocity[1] - rhsBoxVelocity[1] };

    auto x0 = 0.0f;

    if (secondBox.min[0] > max[0] && relativeVelocity[0] > 0)
    {
        x0 = static_cast<float>(secondBox.min[0] - max[0]) / static_cast<float>(relativeVelocity[0]);
    }
    else if (min[0] > secondBox.max[0] && relativeVelocity[0] < 0)
    {
        x0 = static_cast<float>(secondBox.max[0] - min[0]) / static_cast<float>(relativeVelocity[0]);
    }

    auto x1 = maxTime;

    if (secondBox.max[0] > min[0] && relativeVelocity[0] > 0)
    {
        x1 = static_cast<float>(secondBox.max[0] - min[0]) / static_cast<float>(relativeVelocity[0]);
    }
    else if (max[0] > secondBox.min[0] && relativeVelocity[0] < 0)
    {
        x1 = static_cast<float>(secondBox.min[0] - max[0]) / static_cast<float>(relativeVelocity[0]);
    }

    auto y0 = 0.0f;

    if (secondBox.min[1] > max[1] && relativeVelocity[1] > 0)
    {
        y0 = static_cast<float>(secondBox.min[1] - max[1]) / static_cast<float>(relativeVelocity[1]);
    }
    else if (min[1] > secondBox.max[1] && relativeVelocity[1] < 0)
    {
        y0 = static_cast<float>(secondBox.max[1] - min[1]) / static_cast<float>(relativeVelocity[1]);
    }

    auto y1 = maxTime;

    if (secondBox.max[1] > min[1] && relativeVelocity[1] > 0)
    {
        y1 = static_cast<float>(secondBox.max[1] - min[1]) / static_cast<float>(relativeVelocity[1]);
    }
    else if (max[1] > secondBox.min[1] && relativeVelocity[1] < 0)
    {
        y1 = static_cast<float>(secondBox.min[1] - max[1]) / static_cast<float>(relativeVelocity[1]);
    }

    auto first = std::max(x0, y0);
    auto last = std::min(x1, y1);

    auto intersect = (last > first && first < maxTime);

    if (firstTime)
    {
        *firstTime = first;
    }

    return intersect;
}

void BoxCollider::SetPosition(int x, int y)
{
    position[0] = x;
    position[1] = y;
}

void BoxCollider::SetDimension(int width, int height)
{
    dimension[0] = width;
    dimension[1] = height;
}

void BoxCollider::Update()
{
    min[0] = position[0];
    min[1] = position[1];
    max[0] = position[0] + dimension[0];
    max[1] = position[1] + dimension[1];
}
