#pragma once
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <DxLib.h>

class Game
{
public:
	//������
	void Initialize();
	//�Q�[�����[�v
	void RunLoop();
	//�Q�[���̃V���b�g�_�E�����s��
	void ShutDown();
	//�v���C���[�^�[���̍X�V
	void UpdatePlayerTurn(int fin,int num);
	//�G�̃^�[���X�V
	void UpdateEnemyTurn();
	//���͏���
	void ProcessInput();
	//�o�͏���
	void GenerateOutput();
	//�Q�[�����[�v�̎��s�̔���
	bool isRunGame;
	//�G�̃^�[�����̔���
	bool isEnemyTurn;
	//�v���C���[�̎w�肵������
	int playerNum;
	//�v���C���[���������w�̐�
	int playerFin = 0;
	//�G�̎w�肵������
	int enemyNum;
	//�G���������w�̐�
	int enemyFin = 0;
	//�w�肳�ꂽ����
	int selectNum;
	//���C�t
	int playerlife = 2;
	//�G�̃��C�t
	int enemylife = 2;
};

