//指スマを作る
#include "game.h"
#include <DxLib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() < 0) {
		return -1;
	}

	Game game; // Create an instance of the Game class
	game.Initialize(); // Call the Initialize() function on the instance
	game.RunLoop();

	DxLib_End();
	return 0;
}

//初期化処理
void Game::Initialize()
{
	playerlife = 2;
	enemylife = 2;
	playerNum = 0;
	selectNum = 0;
	playerFin = 0;
	enemyFin = 0;
}

//ゲームループの処理
void Game::RunLoop()
{
	while (isRunGame)
	{
		//ゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			ShutDown();
		}
		ProcessInput();
		UpdatePlayerTurn(playerFin, playerNum);
		UpdateEnemyTurn();
		GenerateOutput();
	}
}

//入力処理
void Game::ProcessInput()
{
	printf("挙げる指の数を指定してください。\n");
	scanf_s("%d", playerFin);
	printf("数字を指定してください。\n");
	scanf_s("%d", playerNum);

	UpdatePlayerTurn(playerFin, playerNum);
}

//プレイヤー側の更新処理
void Game::UpdatePlayerTurn(int fin,int num)
{
	int Finger = fin;
	int Number = num;
	selectNum = rand() % 3;
	if (selectNum + fin == Number)
	{
		--playerlife;
		playerFin = 0;
		playerNum = 0;
	}
}

void Game::UpdateEnemyTurn()
{

}

//出力処理
void Game::GenerateOutput()
{

}

//終了処理
void Game::ShutDown()
{
	isRunGame = false;
}