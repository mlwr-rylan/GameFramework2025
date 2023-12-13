#pragma once
class Actor;

class Component
{

public:
	Component();
	Component(Actor* owner, const char* name);
	virtual ~Component();
	virtual void start() {}
	/// <summary>
	/// Happens every loop.
	/// </summary>
	/// <param name="deltaTime">The time between frames.</param>
	virtual void update(float deltaTime) {}
	/// <summary>
	/// called after the update to finish drawing
	/// </summary>
	virtual void draw() {}
	/// <summary>
	/// called when the scene ends
	/// or when an actor gets removed 
	/// </summary>
	virtual void end() {}
	/// <summary>
	/// called when the owner collides with the actor
	/// </summary>
	/// <param name="other">the actor overlapped</param>
	virtual void onCollision(Actor* other) {}

	/// <summary>
	///called before actor destruction
	/// </summary>
	virtual void onDestroy(){}
	/// <summary>
	/// gets the components name
	/// </summary>
	/// <returns> the name of the comp</returns>
	const char* getName() { return m_name; };
	/// <summary>
	/// gets the owner
	/// </summary>
	/// <returns>the owner</returns>
	Actor* getOwner() { return m_owner; }
private:
	const char* m_name;
	Actor* m_owner;
};

