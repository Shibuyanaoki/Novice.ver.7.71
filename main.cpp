#include <Novice.h>
#include "Vector2.h"
#include "GameScene.h"
#include "Scene.h"
#include "GamePlay.h"
#include "Input.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "GameoverScene.h"
#include "ClearScene.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Input* input = Input::GetInstance();

	TitleScene* titleScene = new TitleScene;
	SelectScene* selectScene = new SelectScene;
	GamePlay* gamePlay = new GamePlay;
	ClearScene* clearScene = new ClearScene;
	GameoverScene* gameoverScene = new GameoverScene;

	Scene scene = Scene::TITLE;

	

	titleScene->Initialize();
	selectScene->Initialize();
	gamePlay->Initialize();
	clearScene->Initialize();
	gameoverScene->Initialize();

	titleScene->Start();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		input->Update();
		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case Scene::TITLE:

			titleScene->Update();

			if (titleScene->IsSceneEnd()) {
				// 次のシーンの値を代入してシーン切り替え
				scene = titleScene->NextScene();
				selectScene->Start();
			}

			break;

		case Scene::SELECT:

			selectScene->Update();

			if (selectScene->IsSceneEndEasy()) {
				// 次のシーンの値を代入してシーン切り替え
				scene = selectScene->NextSceneEasy();
				gamePlay->Start();
			}

			if (selectScene->IsSceneEndNormal()) {
				// 次のシーンの値を代入してシーン切り替え
				scene = selectScene->NextSceneNormal();
			}

			if (selectScene->IsSceneEndHard()) {
				// 次のシーンの値を代入してシーン切り替え
				scene = selectScene->NextSceneHard();
			}

			break;

		case Scene::GAME:

			gamePlay->Update();

			if (gamePlay->GameOver() == true) {
				scene = Scene::GAMEOVER;
			}

			if (gamePlay->GameClear() == true) {
				scene = Scene::GAMECLEAR;
			}

			break;

		case Scene::GAMECLEAR:

			clearScene->Update();

			if (input->PushKey(DIK_SPACE)) {
				titleScene->Initialize();
				selectScene->Initialize();
				scene = Scene::TITLE;
			}

			break;

		case Scene::GAMEOVER:

			gameoverScene->Update();

			if (input->PushKey(DIK_SPACE)) {
				selectScene->Initialize();
				scene = Scene::SELECT;
			}

			break;


		}




		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///



		switch (scene)
		{
		case Scene::TITLE:

			titleScene->Draw();

			break;

		case Scene::SELECT:

			selectScene->Draw();

			break;

		case Scene::GAME:

			gamePlay->Draw();

			break;

		case Scene::GAMECLEAR:

			clearScene->Draw();

			break;

		case Scene::GAMEOVER:

			gameoverScene->Draw();

			break;


		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
