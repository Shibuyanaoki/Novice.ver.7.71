#include "ClearScene.h"
#include <Novice.h>

ClearScene::ClearScene()
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	clearImage_ = Novice::LoadTexture("./Resources/CLEAR.png");

	PushToSpace_ = Novice::LoadTexture("./Resources/PushToSpace.png");
}

void ClearScene::Update()
{
	//点滅のタイマーを減らす
	blinkingTimer--;

	if (blinkingTimer <= 0) {
		blinkingTimer = kBlinkingTimer;
	}
}

void ClearScene::Draw()
{
	Novice::DrawSprite(0, 0, clearImage_, 1, 1, 0.0f, 0xffffffff);

	if (blinkingTimer <= 60 && blinkingTimer >= 30) {
		Novice::DrawSprite(0, 0, PushToSpace_, 1, 1, 0.0f, 0xffffffff);
	}

}
