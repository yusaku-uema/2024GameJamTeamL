#include"Player1.h"
#include"DxLib.h"

Player1::Player1()
{
	PlayerX = 0.0f;
	PlayerY = 0.0f;
	PlayerR = 30.0f;
}

Player1::~Player1()
{

}

void Player1::Update()
{

}

void Player1::Draw() const
{
	DrawCircle(PlayerX, PlayerY, PlayerR, 0xffffff, TRUE);
}