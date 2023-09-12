#pragma once

//#include <cstdint>
//自作ファイル
#include "Scene.h"

class TitleScene
{
public: // メンバ変数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// シーンを終わらせるフラグ
	bool isSceneEnd = false;
	bool IsSceneEnd() { return isSceneEnd; }
	//　シーンが終わったあとの次のシーン(シーンの指定先はScece.hにある)
	Scene NextScene() { return Scene::SELECT; }

private:
	void titleDirection();

private: // メンバ変数
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//タイトルの文字の座標
	float titleCharPosX_ = 0;
	float titleCharPosY_ = -200;

	//小さい文字の座標
	float titleCharBackPosX_ = 500;
	float titleCharBackPosY_ = 800; //320

	//文字の移動先の座標
	float titleCharEndPosX_ = 0;
	float titleCharEndPosY_ = 170;

	//文字のサイズ
	float titleCharSize = 1;
	float titleCharBackSize = 0.5;

	//文字のスピード
	float charSpeed = 8;
	float charBackSpeed = -50;

	//スピードを0にする
	float speedStop = 0;

	//演出の移行のフラグ
	bool tltleCharFlag = false;

	// キーを押されたかのフラグ
	bool keysFlag = false;

	// SEのフラグ
	bool soundsFlag = true;

	//タイトルの画像用変数
	int textureTitle_ = 0;

	int textureTitleChar_ = 0;

	int textureTitleBackChar_ = 0;

	//大砲　音
	int cannonSE_ = 0;

	//暗転
	int color = 0x00000000;

	//暗転画像
	int blackOut_ = 0;

	bool blockOutFlag_ = false;

	int blackOutTimer_ = 30;

	//PushToEnterの画像
	int pushToEnter_ = 0;

	const int kPushToEnterTimer_ = 60;

	int pushToEnterTimer_ = kPushToEnterTimer_;
};

