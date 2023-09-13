#pragma once
#include "Vector2.h"
#include <Novice.h>
#include "Input.h"
#include "Button.h"
class Bullet
{
public:

	Bullet();

	void Initialize();

	void Update();

	void Draw();

	void Damage();

	bool IsSelectEnd();

	void Reset();

	bool GaneOver();

	int GetLocationCount(int index) {
		return locationCount[index];
	}

private:

	Vector2 bullet[3] = {
		{1052,650},
		{1132,650},
		{1212,650},
	};
	Vector2 location[3] = {
		{300,540},
		{760,540},
		{1140,540},
	};


	//弾がどこに設置されたか確認する変数
	int locationCount[3] = {};
	//弾を設置したときに立つフラグ
	int selectFlag = 0;
	//弾を設置したか確認する変数
	int selectCount = 0;
	Input* input_ = nullptr;

	Button* button_ = nullptr;

	int rock = Novice::LoadTexture("./Resources/bulletGB.png");
	int paper = Novice::LoadTexture("./Resources/bulletPB.png");
	int scissors = Novice::LoadTexture("./Resources/bulletCB.png");

	int HP = 3;
	int enterTimer = 0;
	int resetTimer = 0;
	int enterFlag = 0;
	int resetFlag = 0;
	int SEFlag = 0;
	int ship = Novice::LoadTexture("./Resources/Ship.png");
	int shipFire = Novice::LoadTexture("./Resources/ShipFire.png");
	int heart = Novice::LoadTexture("./Resources/player heart.png");
	int cannonSE_ = Novice::LoadAudio("./Resources/SE/cannon.wav");
	int BGM = 0;
	int nowBGM = 0;

};

