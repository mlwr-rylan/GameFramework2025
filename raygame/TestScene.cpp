#include "TestScene.h"
#include "Player.h"
void TestScene::start()
{
	// c# base start
	Scene::start();
	Player* player = new Player();
	addActor(player);
}
