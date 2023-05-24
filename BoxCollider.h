// Header Guard
#pragma once

// C++ Libraries
#include <vector>

class BoxCollider
{
public:
	// Getters
	BoxCollider GetCollisionRegion(const BoxCollider& secondBox);
	bool IsColliding(const BoxCollider& secondBox) const;
	bool IsColliding(const BoxCollider& secondBox, const std::vector<int>& lhsBoxVelocity, const std::vector<int>& rhsBoxVelocity, float maxTime, float* firstTime = nullptr);

	// Setters
	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	// Update
	void Update();

private:
	std::vector<int> min;
	std::vector<int> max;
	std::vector<int> position;
	std::vector<int> dimension{ 1, 1 };
};