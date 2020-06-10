#define _CRTDBG_MAP_ALLOC

#include "Engine/Engine.h"
#include "Useful/Vec.h"

#include <stdlib.h>
#include <crtdbg.h>
#include <Windows.h>
#include <math.h>
#include <d3dx9.h>

// ゲーム処理
//void GameProcessing();

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmpLine,
	_In_ INT       nCmdShow)
{
	// エンジンの初期化
	// ゲームループ開始前に1度だけ実行する
	if (InitEngine(640, 480, "Sample") == false)
	{
		return 0;
	}

	// テクスチャ読み込み
	// 第一引数の文字列で読み込んだテクスチャを登録する
	// 描画や取得は登録した文字列で指定する

	LoadTexture("Player", "Res/Enemy.png");
	LoadTexture("Enemy", "Res/Enemy2.png");

	// サウンド読み込み
	// 第一引数の文字列で読み込んだサウンドを登録する
	// 描画や取得は登録した文字列で指定する
	LoadSoundFile("Bgm", "Res/Bgm.wav");
	LoadSoundFile("Se", "Res/Se.wav");

	// サウンド再生
	// 指定されたキーワードのサウンドファイルを再生する
	PlayMusic("Bgm", true);

	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			StartDraw(0);
			// ゲーム処理



			FinishDraw();
		}
	}

	// エンジン終了
	// ゲームループ終了後に1度だけ実行する
	// テクスチャとサウンドファイルも全て解放する
	ReleaseEngine();

	// メモリリーク検出
	_CrtDumpMemoryLeaks();

	return 0;
}


//void GameProcessing()
//{
//	// 入力データの更新
//	UpdateInput();
//	// 重複サウンドの削除
//	EraseDuplicateMusic();
//
//	float speed = 2.0f;
//
//
//	// ゲームパッドの入力取得
//	if (IsHeldGamePad(GamePadKind::GamePadKindUp))
//	{
//		player_point.Position.Y -= speed;
//	}
//	else if (IsHeldGamePad(GamePadKind::GamePadKindDown))
//	{
//		player_point.Position.Y += speed;
//	}
//
//	// マウスの入力取得
//	if (IsPushedMouse(MouseButton::Left))
//	{
//		player_point.Position = Vec2(200, 200);
//	}
//	else if (IsPushedMouse(MouseButton::Right))
//	{
//		player_point.Position = Vec2(400, 300);
//	}
//
//	if (IsReleasedKeyboard(DIK_A))
//	{
//		// 重複再生
//		// 指定されたキーワードのサウンドファイル再生する
//		// StartPlayingDuplicateSoundでは同じサウンドファイルでも重複して再生可能
//		PlayDuplicateMusic("Se");
//		PlayDuplicateMusic("Se");
//	}
//}
