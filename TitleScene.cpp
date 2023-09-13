#include "TitleScene.h"


TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	// キー入力結果を受け取る箱
	keys[256] = { 0 };
	preKeys[256] = { 0 };

	//タイトルの画像
	textureTitle_ = Novice::LoadTexture("./Resources/titleBack.png");
	//タイトルの文字の画像
	textureTitleChar_ = Novice::LoadTexture("./Resources/titleReal.png");
	//小さい文字
	textureTitleBackChar_ = Novice::LoadTexture("./Resources/titleDot.png");

	//暗転用の画像
	blackOut_ = Novice::LoadTexture("./Resources/blackout.png");

	//プッシュトゥエンター
	pushToEnter_ = Novice::LoadTexture("./Resources/PushToEnter.png");

	//大砲のSE
	cannonSE_ = Novice::LoadAudio("./Resources/SE/cannon.wav");

	BGM = Novice::LoadAudio("./Resources/BGM/wave.mp3");

	// シーンを終わらせるフラグ
	isSceneEnd = false;

	//暗転用のタイマー
	blackOutTimer_ = 30;

	//暗転用のタイマー
	blockOutFlag_ = false;

	//カラー
	color = 0;

	//タイトルの文字の座標
	titleCharPosX_ = 0;
	titleCharPosY_ = -200;

	//小さい文字の座標
	titleCharBackPosX_ = 500;
	titleCharBackPosY_ = 800; //320

	//演出の移行のフラグ
	tltleCharFlag = false;

	// キーを押されたかのフラグ
	keysFlag = false;

	// SEのフラグ
	soundsFlag = true;

	//文字のスピード
	charSpeed = 8;
	charBackSpeed = -50;

}

void TitleScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//タイトルの文字の演出の関数
	titleDirection();

	if (keysFlag == true) {
		pushToEnterTimer_--;
		if (pushToEnterTimer_ <= 0) {
			pushToEnterTimer_ = kPushToEnterTimer_;
		}
	}

	// キーを押して演出をスキップ
	if (keysFlag == false) {
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
			tltleCharFlag = true;
			titleCharPosY_ = titleCharEndPosY_;
			keysFlag = true;
		}
	}
	else {
		// enterキーを押すとタイトルシーンが終わり次のシーンへいく(切り替え先はヘッダーにある)
		// enterキーを押すと暗転用のフラグが立つ
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
			blockOutFlag_ = true;
		}
	}

	//暗転の処理
	if (blockOutFlag_ == true)
	{
		if (color < 255)
		{
			color += 3;
		}
	}

	//暗転が終わったあとの切り替えの時間
	if (color >= 255) {
		blackOutTimer_--;
	}

	//　暗転が終わるとシーン切り替え
	if (blackOutTimer_ <= 0) {
		Novice::StopAudio(nowBGM);
		isSceneEnd = true;
	}

}

void TitleScene::Draw()
{
	//タイトルの画像の描画
	Novice::DrawSprite(0, 0, textureTitle_, 1, 1, 0.0f, 0xffffffff);

	if (tltleCharFlag == false) {
		Novice::DrawSprite((int)titleCharBackPosX_, (int)titleCharBackPosY_, textureTitleBackChar_, titleCharBackSize, titleCharBackSize, 0.0f, 0xffffffff);
	}

	if (tltleCharFlag == true) {
		Novice::DrawSprite((int)titleCharPosX_, (int)titleCharPosY_, textureTitleChar_, titleCharSize, titleCharSize, 0.0f, 0xffffffff);
	}

	if (blockOutFlag_ == false) {
		if (keysFlag == true) {
			if (pushToEnterTimer_ <= 60 && pushToEnterTimer_ >= 30) {
				Novice::DrawSprite(0, 0, pushToEnter_, 1, 1, 0.0f, 0xffffffff);
			}
		}
	}

	//暗転用描画
	Novice::DrawSprite(0, 0, blackOut_, 1, 1, 0.0f, color);


#ifdef _DEBUG
	Novice::ScreenPrintf(0, 0, "%d", tltleCharFlag);

	Novice::ScreenPrintf(0, 20, "%d", color);
#endif // _DEBUG
}

void TitleScene::titleDirection()
{
	//小さい文字の打ち上げ(上移動)
	if (tltleCharFlag == false) {
		titleCharBackPosY_ += charBackSpeed;


		if (soundsFlag == true) {
			Novice::PlayAudio(cannonSE_, false, 0.5f);
			soundsFlag = false;
		}

		if (titleCharBackPosY_ <= -8000) {
			charBackSpeed = speedStop;
			tltleCharFlag = true;
		}
	}

	//大きい文字が降ってくる
	if (tltleCharFlag == true) {
		titleCharPosY_ += charSpeed;

		if (titleCharPosY_ >= titleCharEndPosY_) {
			charSpeed = speedStop;
			keysFlag = true;
		}
	}
}

void TitleScene::Start() {
	nowBGM = Novice::PlayAudio(BGM, true, 0.5f);
}