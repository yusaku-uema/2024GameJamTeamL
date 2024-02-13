#include "Player2.h";
#include "DxLib.h";

#define PLAYER2_SIZE_X   (30.0f)

Player2::Player2()
{
	x = 100.0f;
	y = 100.0f;
}

void Player2::Update()
{

}

void Player2::Draw()
{
	DrawBoxAA(x - PLAYER2_SIZE_X, y, x + PLAYER2_SIZE_X, y + 10.0f, GetColor(255, 255, 255),TRUE);
}