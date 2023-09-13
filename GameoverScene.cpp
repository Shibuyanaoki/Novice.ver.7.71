#include "GameoverScene.h"
#include <Novice.h>

GameoverScene::GameoverScene()
{
}

GameoverScene::~GameoverScene()
{
}

void GameoverScene::Initialize()
{
	gameoverImage_ = Novice::LoadTexture("./Resources/GAMEOVER.png");

	PushToSpace_ = Novice::LoadTexture("./Resources/PushToSpace.png");
}

void GameoverScene::Update()
{
	//点滅のタイマーを減らす
	blinkingTimer--;

	if (blinkingTimer <= 0) {
		blinkingTimer = kBlinkingTimer;
	}
}

void GameoverScene::Draw()
{
	Novice::DrawSprite(0, 0, gameoverImage_, 1, 1, 0.0f, 0xffffffff);

	if (blinkingTimer <= 60 && blinkingTimer >= 30) {
		Novice::DrawSprite(0, 0, PushToSpace_, 1, 1, 0.0f, 0xffffffff);
	}
}
