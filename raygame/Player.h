#pragma once
#include "Actor.h"
#include "raylib.h"
class Player :
    public Actor
{
public:
    void draw() override;
};

