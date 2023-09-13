#include<stdlib.h>
#include"Button.h"

Button::Button() {
	
}

void Button::Initialize() {
	//初期化
	if (buttonResetTimer <= 0) {
		buttonResetTimer = animationTimer;
		buttonResetFlag = false;
		buttonResetSize = 32;
	}

	if (buttonEnterTimer <= 0) {
		buttonEnterTimer = animationTimer;
		buttonEnterFlag = false;
		buttonEnterSize = 32;
	}


}

void Button::ResetUpdate() {
	////Rボタン押すとフラグオン
	//if (keys[DIK_R] && preKeys[DIK_R] == 0) {
	//	buttonResetFlag = true;
	//}
	//
	////Enterボタン押すとフラグオン
	//if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
	//	buttonEnterFlag = true;
	//}
	//ボタン挙動
	/*if (buttonResetFlag == true) {

		

	}*/

	buttonResetTimer -= 1.0f;
	buttonResetSize = TimerChangeSize(buttonResetTimer, 0, 2, buttonResetSize, 31);
	buttonResetSize = TimerChangeSize(buttonResetTimer, 3, 4, buttonResetSize, 30);
	buttonResetSize = TimerChangeSize(buttonResetTimer, 5, 7, buttonResetSize, 28);
	buttonResetSize = TimerChangeSize(buttonResetTimer, 8, 10, buttonResetSize, 27);

}

void Button::EnterUpdate() {
	buttonEnterTimer -= 1.0;
	buttonEnterSize = TimerChangeSize(buttonEnterTimer, 0, 2, buttonEnterSize, 31);
	buttonEnterSize = TimerChangeSize(buttonEnterTimer, 3, 4, buttonEnterSize, 30);
	buttonEnterSize = TimerChangeSize(buttonEnterTimer, 5, 7, buttonEnterSize, 28);
	buttonEnterSize = TimerChangeSize(buttonEnterTimer, 8, 10, buttonEnterSize, 27);

}


void Button::Draw() {
	Novice::DrawQuad(
		//キャスト
		(int)(buttonResetPosX - buttonResetSize), (int)(buttonResetPosY - buttonResetSize),
		(int)(buttonResetPosX + buttonResetSize), (int)(buttonResetPosY - buttonResetSize),
		(int)(buttonResetPosX - buttonResetSize), (int)(buttonResetPosY + buttonResetSize),
		(int)(buttonResetPosX + buttonResetSize), (int)(buttonResetPosY + buttonResetSize),
		(int)0, (int)0,
		(int)AKB64, (int)AKB64,
		buttonResetGh, WHITE);

	Novice::DrawQuad(
		//キャスト
		(int)(buttonEnterPosX - buttonEnterSize), (int)(buttonEnterPosY - buttonEnterSize),
		(int)(buttonEnterPosX + buttonEnterSize), (int)(buttonEnterPosY - buttonEnterSize),
		(int)(buttonEnterPosX - buttonEnterSize), (int)(buttonEnterPosY + buttonEnterSize),
		(int)(buttonEnterPosX + buttonEnterSize), (int)(buttonEnterPosY + buttonEnterSize),
		(int)0, (int)0,
		(int)AKB64, (int)AKB64,
		buttonEnterGh, WHITE);

}

float Button::TimerChangeSize(float timer, float numIn, float numOver, float buttonSize, float buttonSizeNum) {
	if (timer >= numIn && timer <= numOver) {
		buttonSize = buttonSizeNum;
	}

	return buttonSize;
}


