//�w�X�}�����
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

//����������
void Game::Initialize()
{
	playerlife = 2;
	enemylife = 2;
	playerNum = 0;
	selectNum = 0;
	playerFin = 0;
	enemyFin = 0;
}

//�Q�[�����[�v�̏���
void Game::RunLoop()
{
	while (isRunGame)
	{
		//�Q�[���I��
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

//���͏���
void Game::ProcessInput()
{
	printf("������w�̐����w�肵�Ă��������B\n");
	scanf_s("%d", playerFin);
	printf("�������w�肵�Ă��������B\n");
	scanf_s("%d", playerNum);

	UpdatePlayerTurn(playerFin, playerNum);
}

//�v���C���[���̍X�V����
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

//�o�͏���
void Game::GenerateOutput()
{

}

//�I������
void Game::ShutDown()
{
	isRunGame = false;
}