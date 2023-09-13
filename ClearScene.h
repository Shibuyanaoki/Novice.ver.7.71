#pragma once

class ClearScene
{
public: //メンバ変数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	ClearScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ClearScene();

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

private: // メンバ変数
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//演出のタイマー
	const int kBlinkingTimer = 60;

	int blinkingTimer = kBlinkingTimer;

	//画像
	//クリア画面
	int clearImage_ = 0;
	//点滅させる画像
	int PushToSpace_ = 0;

};

