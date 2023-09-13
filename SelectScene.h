#pragma once
//自作ファイル
#include "Scene.h"
#include "MT.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include<Novice.h>

class SelectScene
{
public: // メンバ変数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	SelectScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SelectScene();

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

	void Start();

	// シーンを終わらせるフラグ
	bool isSceneEndEasy = false;
	bool IsSceneEndEasy() { return isSceneEndEasy; }
	//　シーンが終わったあとの次のシーン(シーンの指定先はScece.hにある)
	Scene NextSceneEasy() { return Scene::GAME; }

	// シーンを終わらせるフラグ
	bool isSceneEndNormal = false;
	bool IsSceneEndNormal() { return isSceneEndNormal; }
	//　シーンが終わったあとの次のシーン(シーンの指定先はScece.hにある)
	Scene NextSceneNormal() { return Scene::SELECT; }

	// シーンを終わらせるフラグ
	bool isSceneEndHard = false;
	bool IsSceneEndHard() { return isSceneEndHard; }
	//　シーンが終わったあとの次のシーン(シーンの指定先はScece.hにある)
	Scene NextSceneHard() {
		return Scene::SELECT;
	}

private:
	void rudderRotate();

	void levelSelect();

	void manualDray();

private: // メンバ変数
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//背景
	int background_ = 0;

	//透過黒
	int blackBack_ = 0;

	//選択レベル
	int selectNumber_ = 0;

	//左右キー
	int LRkey_ = 0;

	//arrow
	//矢印
	int arrowL_ = 0;
	int arrowR_ = 0;

	// enter
	int enter_ = 0;

	enum select
	{
		Key,
		Easy,
		Normal,
		Hard
	};

	//舵画像
	int rudder_ = 0;

	float rudderPosX_ = 370;
	float rudderPosY_ = 340;

#pragma region 舵の回転
	//回転方向
	int rotateDirection = 1;

	const float kRectWidth = 576; //576 288
	const float kRectHeight = 576;

	Vector2 leftTop = { -kRectWidth / 2, -kRectHeight / 2 };
	Vector2 rightTop = { kRectWidth / 2,-kRectHeight / 2 };
	Vector2 leftBottom = { -kRectWidth / 2, kRectHeight / 2 };
	Vector2 rightBottom = { kRectWidth / 2, kRectHeight / 2 };

	float theta = 0;
	float rotateAngle = 0.0f;

	bool rotateFlag = false;

	const int kRotateTimer = 60;
	int rotateTimer_ = kRotateTimer;

	Matrix2x2 rotateMatrix = MakeRotateMatrix(theta);

	Vector2 rotateLeftTop = { 0,0 };

	Vector2 rotateRightTop = { 0,0 };

	Vector2 rotateLeftBottom = { 0,0 };

	Vector2 rotateRightBottom = { 0,0 };

#pragma endregion

	//難易度用画像
	int easy_ = 0;
	int normal_ = 0;
	int hard_ = 0;

	float easyPosX_ = 840;
	float easyPosY_ = 330;

	float normalPosX_ = 840;
	float normalPosY_ = 330;

	float hardPosX_ = 840;
	float hardPosY_ = 330;

	//操作説明移行の画像
	int key_ = 0;

	float keyPosX_ = 840;
	float keyPosY_ = 330;

	bool manualFlag_ = false;

	int manualNumber_ = 0;

	int manualImage1_;

	int manualImage2_;

	int manualImage3_;

	int manualImage4_;

	const float kManualTimer_ = 5;

	float manualTimer_ = kManualTimer_;

	//望遠鏡
	int scope_ = 0;

	float scopePosX_ = 800;
	float scopePosY_ = 150;

	//暗転
	int color = 255;

	bool colorFlag_ = false;

	//暗転画像
	int blackOut_ = 0;

	float pi = 3.14f;

	//BGM
	int BGM = 0; 
	int BGM2 = 0;
	//int BGMStop_= Novice::PlayAudio(BGM, true, 0.8f);
	int nowBGM = 0;

	int rudderSE_ = 0;

};

