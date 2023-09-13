#pragma once
#include<Novice.h>
//#include "Bullet.h"


class Button
{
public:

	Button();

	void Initialize();
	void ResetUpdate();
	void EnterUpdate();
	void Draw();
	//タイマーごとにサイズを決める。
	float TimerChangeSize(float timer, float numIn, float numOver, float buttonSize, float buttonSizeNum);


private:
	int buttonResetGh = Novice::LoadTexture("./Resources/buttonReset.png");
	int buttonEnterGh = Novice::LoadTexture("./Resources/buttonEnter.png");

	//アニメーション用タイマー
	const float animationTimer = 10.0f;

	//座標は左上ではなく矩形の中心
	float buttonResetPosX = 68.0f;
	float buttonResetPosY = 682.0f;

	float buttonEnterPosX = 148.0f;
	float buttonEnterPosY = 682.0f;

	//ボタンのサイズは画像サイズの半分
	float buttonResetSize = 32.0f;
	float buttonEnterSize = 32.0f;

	float buttonResetTimer = 0.0f;
	float buttonEnterTimer = 0.0f;

	bool buttonResetFlag = false;
	bool buttonEnterFlag = false;

	const float AKB64 = 64;
};