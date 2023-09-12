#pragma once
enum class Scene {
	TITLE,   // タイトル
	SELECT,  // セレクトシーン
	GAME, // ゲームシーン
	GAMECLEAR,    //　クリアシーン
	GAMEOVER, //ゲームオーバーシーン
};

enum class Phase {
	CHOOSE,	//弾の配置選択
	FIREDRAW,	//弾を撃った時の描画シーン
	FIRE,	//敵の弾と自分の弾の処理
	ENEMYDAMAGE	//敵がダメージを受けた時の描画
};