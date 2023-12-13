#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

MoveComponent::MoveComponent(float maxSpeed, Actor* owner) : Component(owner, "MoveComponent")
{
	m_maxSpeed = maxSpeed;
	
}
//Store what the current position is.
void MoveComponent::update(float deltaTime)
{
	//if the celovity is over the maximum speed
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();

	// normalize the velocity and scale it by the max speed to clamp it.
	if(getVelocity().getMagnitude() > getMaxSpeed())
	{
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}

	position = position + getVelocity() * deltaTime;
}
