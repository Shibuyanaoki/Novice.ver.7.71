#include "SelectScene.h"


SelectScene::SelectScene()
{

}

SelectScene::~SelectScene()
{

}

void SelectScene::Initialize()
{
	//操作説明移行
	key_ = Novice::LoadTexture("./Resources/KeyManual.png");
	//操作説明画像
	manualImage1_ = Novice::LoadTexture("./Resources/setumei1.png");
	manualImage2_ = Novice::LoadTexture("./Resources/setumei2.png");
	manualImage3_ = Novice::LoadTexture("./Resources/setumei3.png");
	manualImage4_ = Novice::LoadTexture("./Resources/setumei4.png");

	easy_ = Novice::LoadTexture("./Resources/Easy.png");
	normal_ = Novice::LoadTexture("./Resources/Normal.png");
	hard_ = Novice::LoadTexture("./Resources/Hard.png");

	//舵
	rudder_ = Novice::LoadTexture("./Resources/rudderR.png");

	//暗転用の画像
	blackOut_ = Novice::LoadTexture("./Resources/blackout.png");

	//望遠鏡の画像
	scope_ = Novice::LoadTexture("./Resources/scope.png");

	//左右キー
	LRkey_ = Novice::LoadTexture("./Resources/LRkey.png");

	//矢印
	arrowL_ = Novice::LoadTexture("./Resources/arrowL.png");
	arrowR_ = Novice::LoadTexture("./Resources/arrowR.png");

	// enter
	enter_ = Novice::LoadTexture("./Resources/enter.png");

	//背景
	background_ = Novice::LoadTexture("./Resources/titleBack.png");
	//黒背景
	blackBack_ = Novice::LoadTexture("./Resources/blackBack.png");

	//初期化
	//選択レベル
	selectNumber_ = 0;
	//回転方向
	rotateDirection = 1;

	manualFlag_ = false;

	manualNumber_ = 0;

	manualTimer_ = kManualTimer_;

	//暗転
	color = 255;

	colorFlag_ = false;


	isSceneEndEasy = false;
	isSceneEndNormal = false;
	isSceneEndHard = false;

	BGM = Novice::LoadAudio("./Resources/BGM/umioiku.mp3");
	BGM2 = Novice::LoadAudio("./Resources/SE/mente.mp3");
	rudderSE_ = Novice::LoadAudio("./Resources/SE/rudder.mp3");


}

void SelectScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//暗転明け
	if (color > 0)
	{
		color -= 3;
		colorFlag_ = false;
	}
	else
	{
		colorFlag_ = true;
	}

	//説明画面じゃないとき
	if (manualFlag_ == false) {

		if (colorFlag_ == true) {
			//選択などの処理
			levelSelect();
		}

		//図形の回転などの処理
		rudderRotate();

		//説明画面
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0 && selectNumber_ == Key) {
			manualFlag_ = true;
		}
		//説明画面のリセット
		manualNumber_ = 0;
		manualTimer_ = kManualTimer_;

		//イージー
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0 && selectNumber_ == Easy) {
			Novice::StopAudio(nowBGM);
			isSceneEndEasy = true;
		}

		//ノーマル
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0 && selectNumber_ == Normal) {
			Novice::PlayAudio(BGM2, false, 0.5f);
			isSceneEndNormal = true;
		}

		//ハード
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0 && selectNumber_ == Hard) {
			Novice::PlayAudio(BGM2, false, 0.5f);
			isSceneEndHard = true;
		}
	}

	//操作説明内の操作
	if (manualFlag_ == true) {

		if (manualTimer_ >= 0) {
			manualTimer_--;
		}

		if (manualTimer_ <= 0) {
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0 && manualNumber_ < 4) {
				manualNumber_ += 1;
			}

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0 && manualNumber_ >= 4) {
				manualFlag_ = false;
			}
		}
	}
}

void SelectScene::Draw()
{
	//説明画面じゃないとき
	if (manualFlag_ == false) {
		//背景
		Novice::DrawSprite(0, 0, background_, 1, 1, 0.0f, 0xffffffff);
		//黒背景
		Novice::DrawSprite(0, 0, blackBack_, 1, 1, 0.0f, 0xffffffff);

		//望遠鏡
		Novice::DrawSprite((int)scopePosX_, (int)scopePosY_, scope_, 1.4f, 1.4f, 0.0f, 0xffffffff);

		//操作説明
		if (selectNumber_ == Key) {
			Novice::DrawSprite((int)keyPosX_, (int)keyPosY_, key_, 1, 1, 0.0f, 0xffffffff);
		}
		//イージー
		if (selectNumber_ == Easy) {
			Novice::DrawSprite((int)easyPosX_, (int)easyPosY_, easy_, 1, 1, 0.0f, 0xffffffff);
		}
		//ノーマル
		if (selectNumber_ == Normal) {
			Novice::DrawSprite((int)normalPosX_, (int)normalPosY_, normal_, 1, 1, 0.0f, 0xffffffff);
		}
		//ハード
		if (selectNumber_ == Hard) {
			Novice::DrawSprite((int)hardPosX_, (int)hardPosY_, hard_, 1, 1, 0.0f, 0xffffffff);
		}

		///舵
		Novice::DrawQuad(
			(int)rotateLeftTop.x,
			(int)rotateLeftTop.y,
			(int)rotateRightTop.x,
			(int)rotateRightTop.y,
			(int)rotateLeftBottom.x,
			(int)rotateLeftBottom.y,
			(int)rotateRightBottom.x,
			(int)rotateRightBottom.y,
			0,
			0,
			(int)kRectWidth,
			(int)kRectHeight,
			rudder_, 0xFFFFFFFF);

		//左右キー
		Novice::DrawSprite(922, 630, LRkey_, 1, 1, 0.0f, 0xffffffff);

		//エンターキー
		Novice::DrawSprite(1150, 615, enter_, 1, 1, 0.0f, 0xffffffff);

		//矢印
		Novice::DrawSprite(35, 325, arrowL_, 1.2f, 1.2f, 0.0f, 0xffffffff);
		Novice::DrawSprite(670, 325, arrowR_, 1.2f, 1.2f, 0.0f, 0xffffffff);



#ifdef _DEBUG

		Novice::ScreenPrintf(0, 0, "Number = %d", selectNumber_);

#endif // _DEBUG
	}
	else {
		//一枚目
		if (manualNumber_ == 0) {
			Novice::DrawSprite(0, 0, manualImage1_, 1, 1, 0.0f, 0xffffffff);
		}
		//二枚目
		if (manualNumber_ == 1) {
			Novice::DrawSprite(0, 0, manualImage2_, 1, 1, 0.0f, 0xffffffff);
		}
		//三枚目
		if (manualNumber_ == 2) {
			Novice::DrawSprite(0, 0, manualImage3_, 1, 1, 0.0f, 0xffffffff);
		}
		//四枚目
		if (manualNumber_ == 3) {
			Novice::DrawSprite(0, 0, manualImage4_, 1, 1, 0.0f, 0xffffffff);
		}

		//エンターキー
		Novice::DrawSprite(1150, 615, enter_, 1, 1, 0.0f, 0xffffffff);


	}

	//暗転用描画
	Novice::DrawSprite(0, 0, blackOut_, 1, 1, 0.0f, color);
}

void SelectScene::rudderRotate()
{
	theta += rotateAngle * rotateDirection;

	rotateMatrix = MakeRotateMatrix(theta);

	rotateLeftTop = Multiply(leftTop, rotateMatrix);
	rotateLeftTop.x += rudderPosX_;
	rotateLeftTop.y += rudderPosY_;

	rotateRightTop = Multiply(rightTop, rotateMatrix);
	rotateRightTop.x += rudderPosX_;
	rotateRightTop.y += rudderPosY_;

	rotateLeftBottom = Multiply(leftBottom, rotateMatrix);
	rotateLeftBottom.x += rudderPosX_;
	rotateLeftBottom.y += rudderPosY_;

	rotateRightBottom = Multiply(rightBottom, rotateMatrix);
	rotateRightBottom.x += rudderPosX_;
	rotateRightBottom.y += rudderPosY_;
}

void SelectScene::levelSelect()
{
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		Novice::PlayAudio(rudderSE_, false, 0.5f);
		selectNumber_ -= 1;
		rotateDirection = 1;
		rotateFlag = true;
		rotateTimer_ = kRotateTimer;

	}
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		Novice::PlayAudio(rudderSE_,false,0.5f);
		selectNumber_ += 1;
		rotateDirection = -1;
		rotateFlag = true;
		rotateTimer_ = kRotateTimer;
	}

	if (rotateFlag == true) {
		rotateAngle = 1.0f / 32.0f * float(pi);
		rotateTimer_--;
	}

	if (rotateTimer_ <= 0) {
		rotateFlag = false;
		rotateAngle = 1.0f / 640.0f * float(pi);
	}

	if (selectNumber_ <= -1) {
		selectNumber_ = Hard;
	}
	if (selectNumber_ >= 4) {
		selectNumber_ = Key;
	}
}

void SelectScene::manualDray()
{
	//一枚目
	if (manualNumber_ == 0) {
		Novice::DrawSprite(0, 0, manualImage1_, 1.2f, 1.2f, 0.0f, 0xffffffff);
	}
	//二枚目
	if (manualNumber_ == 1) {
		Novice::DrawSprite(0, 0, manualImage2_, 1.2f, 1.2f, 0.0f, 0xffffffff);
	}
	//三枚目
	if (manualNumber_ == 2) {
		Novice::DrawSprite(0, 0, manualImage3_, 1.2f, 1.2f, 0.0f, 0xffffffff);
	}
	//四枚目
	if (manualNumber_ == 3) {
		Novice::DrawSprite(0, 0, manualImage4_, 1.2f, 1.2f, 0.0f, 0xffffffff);
	}
}

void SelectScene::Start() {
	nowBGM = Novice::PlayAudio(BGM, true, 0.3f);
}