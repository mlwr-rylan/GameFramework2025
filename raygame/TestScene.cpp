#include "TestScene.h"
#include "Player.h"
#include "Transform2D.h"
#include "MoveComponent.h"


void TestScene::start()
{
	const char* name = new const char[6] {"Lodis"};

	Component* comp = new Component(nullptr, name);

	delete[] comp;
	// c# base start
	Scene::start();
	
	Player* player = new Player();


	MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	
	player->getTransform()->setScale(scale);

	

	addActor(player);
}
