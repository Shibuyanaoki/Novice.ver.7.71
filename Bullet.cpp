﻿#include "Bullet.h"

Bullet::Bullet() {
	HP = 3;
	Reset();
}

void Bullet::Initialize() {
	input_ = Input::GetInstance();
	Reset();
	HP = 3;

	button_ = new Button;

	button_->Initialize();

}

void Bullet::Update() {

	/*if (HP <= 4) {
		HP = 3;
		Reset();
	}*/

	if (selectCount == 0 && selectFlag == 0) {


		if (input_->PushKey(DIK_1) && selectFlag == 0) {
			bullet[0].x = location[0].x;
			bullet[0].y = location[0].y;
			locationCount[0] = 0;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_2) && selectFlag == 0) {
			bullet[0].x = location[1].x;
			bullet[0].y = location[1].y;
			locationCount[0] = 1;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_3) && selectFlag == 0) {
			bullet[0].x = location[2].x;
			bullet[0].y = location[2].y;
			locationCount[0] = 2;
			selectFlag = 1;
		}

	}

	if (selectCount == 1 && selectFlag == 0) {

		if (input_->PushKey(DIK_1) && locationCount[0] != 0) {
			bullet[1].x = location[0].x;
			bullet[1].y = location[0].y;
			locationCount[1] = 0;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_2) && locationCount[0] != 1) {
			bullet[1].x = location[1].x;
			bullet[1].y = location[1].y;
			locationCount[1] = 1;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_3) && locationCount[0] != 2) {
			bullet[1].x = location[2].x;
			bullet[1].y = location[2].y;
			locationCount[1] = 2;
			selectFlag = 1;
		}

	}

	if (selectCount == 2 && selectFlag == 0) {

		if (input_->PushKey(DIK_1) && locationCount[0] != 0 && locationCount[1] != 0) {
			bullet[2].x = location[0].x;
			bullet[2].y = location[0].y;
			locationCount[2] = 0;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_2) && locationCount[0] != 1 && locationCount[1] != 1) {
			bullet[2].x = location[1].x;
			bullet[2].y = location[1].y;
			locationCount[2] = 1;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_3) && locationCount[0] != 2 && locationCount[1] != 2) {
			bullet[2].x = location[2].x;
			bullet[2].y = location[2].y;
			locationCount[2] = 2;
			selectFlag = 1;
		}

	}

	if (selectFlag == 1) {
		selectCount += 1;
		selectFlag = 0;
	}



	if (input_->PushKey(DIK_R)) {
		selectCount = 0;
		bullet[0] = { 1052,650 };
		bullet[1] = { 1132,650 };
		bullet[2] = { 1212,650 };
		for (int i = 0; i < 3; i++) {
			locationCount[i] = 0;
		}

		resetFlag = 1;

	}

	IsSelectEnd();
}

void Bullet::Draw() {

	if (enterFlag == 1) {
		enterTimer++;
	}

	if (resetFlag == 1) {
		resetTimer++;
	}

	if (enterTimer >= 10) {
		enterFlag = 0;
		enterTimer = 0;
		button_->Initialize();
	}

	if (resetTimer >= 10) {
		resetTimer = 0;
		resetFlag = 0;
		button_->Initialize();
	}

	Novice::DrawSprite(0, 0, ship, 1, 1, 0.0, WHITE);

	if (enterFlag == 1) {
		Novice::DrawSprite(0, 0, shipFire, 1, 1, 0.0f, WHITE);
		button_->EnterUpdate();
	}

	if (resetFlag == 1) {
		button_->ResetUpdate();
	}

	if (HP >= 3) {
		Novice::DrawSprite(560, 640, heart, 2, 2, 0.0, WHITE);
	}

	if (HP >= 2) {
		Novice::DrawSprite(620, 640, heart, 2, 2, 0.0, WHITE);
	}

	if (HP >= 1) {
		Novice::DrawSprite(680, 640, heart, 2, 2, 0.0, WHITE);
	}

	for (int i = 0; i < 3; i++) {
		Novice::DrawSprite((int)bullet[0].x, (int)bullet[0].y, rock, 1, 1, 0.0, WHITE);
		Novice::DrawSprite((int)bullet[1].x, (int)bullet[1].y, scissors, 1, 1, 0.0, WHITE);
		Novice::DrawSprite((int)bullet[2].x, (int)bullet[2].y, paper, 1, 1, 0.0, WHITE);

	}

	

	button_->Draw();

}

bool Bullet::IsSelectEnd()
{
	if (input_->PushKey(DIK_RETURN)) {

		if (selectCount == 3) {
			enterFlag = 1;
			if (!Novice::IsPlayingAudio(cannonSE_)) {
				Novice::PlayAudio(cannonSE_, false , 0.5f);
			}
			return true;
		}

	}
	return false;
}

void Bullet::Reset()
{
	bullet[0] = { 1052,650 };
	bullet[1] = { 1132,650 };
	bullet[2] = { 1212,650 };
	selectCount = 0;
	for (int i = 0; i < 3; i++) {
		locationCount[i] = 0;

	}
}

bool Bullet::GaneOver()
{
	if (HP <= 0) {
		return true;
	}

	return false;
}

void Bullet::Damage() {
	HP -= 1;
}


