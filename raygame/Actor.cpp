#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
}

Component* Actor::addComponent(Component* component)
{
    Actor* owner = component->getOwner();



    if (owner && owner != this)
    {
        return nullptr;
    }

    Component** temp = new Component * [m_componentCount];


    for (int i = 0; i < m_componentCount; i++)
    {
        temp[i] = m_components[i];
    }

    delete[] m_components;

    temp[m_componentCount] = component;

    m_components = temp;
}
bool Actor::removeComponent(const char* componentName) 
{
    if (!componentName)
        return false;

    bool componentRemoved = false;

    Component** temp = new Component * [m_componentCount + 1];

        int j = 0;

        
    //Copy values from the old array to the new array except the actor to delete
   for(int i = 0; i < m_componentCount; i++) 
   {   
       if (m_components[i]->getName() == componentName)
       {
               componentRemoved = true;
               continue;
       }
           temp[j] = m_components[i];
           j++;
   }
   if (componentRemoved)
   {
       delete[] m_components;
       m_components = temp;
       m_componentCount--;
   }
   return componentRemoved;
}
void Actor::update(float deltaTime)
{
    m_transform->updateTransforms();
}

void Actor::draw()
{
}

void Actor::end()
{
    m_started = false;
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
    for (int i = 0; i < m_componentCount; i++) 
    {
        m_components[i]->onDestroy();
    }
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}
