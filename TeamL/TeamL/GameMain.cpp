/****************************************************************/
/*	プロジェクト名:		Gamejam 　　チームL						*/
/*	ファイル名：　　　　メインCPP									*/
/*	内容：			ゲームのメイン								*/
/*	日付：					2024/02/14							*/
/*	コンパイラ:													*/
/*	note:														*/
/*	作成者：				名嘉真　愛斗						*/
/****************************************************************/
#include"DxLib.h"
#include"GameMain.h"
#include"PadInput.h"
#define _CRT_SECURE_MD_WARNING
#include<stdio.h>
#include"Playerlose.h"
#include"Playerwin.h"

GameMain::GameMain()
{
	
	

	BGM = LoadSoundMem("../BGM/Stage.mp3");

	//ゲーム画面背景読込

	stageimg = LoadGraph("../imege/GameMain.png");

	FILE* fp;

	int block = 0;

	rendering_coodinates_x = 0;

	camerawork = new CameraWork();
	player1 = new Player1();

	player2 = new Player2();

	ui = new UI();

	//読込ファイルを開く
	fopen_s(&fp, "stage.txt", "r");

	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 111; i++)
		{
			fscanf_s(fp, "%d", &block);

			if (block >0)
			{
				stage[j][i] = new Stage(i, j, 40, 40 ,block);
			}
			else
			{
				stage[j][i] = nullptr;
			}
		}
	}
	fclose(fp);


	gMileage = 0;


	
}
GameMain::~GameMain()
{
	for (int j = 0; j < 25; j++)
	{

		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i] != nullptr)
			{
				delete stage[j][i];
			}
		}
	}
	delete player1;

	delete player2;

	delete ui;

	//Player2の弾丸計
	delete p_bullet;
	delete p_vbullet;
	delete p_bom;
	delete camerawork;
	delete explosion;



	DeleteGraph(stageimg);
	DeleteSoundMem(BGM);

}


AbstractScene* GameMain::Update()
{
	if (CheckSoundMem(BGM) != 1)
	{   //BGMが流れていなかったら再生
		PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, TRUE); //BGM再生
	}


	//カメラ
	camerawork->Update(player1->GetLocation().x);

	//前の座標
	Location oldlocation = player1->GetLocation();


	player1->Update(camerawork->GetViewCharX());
    player2->Update(camerawork->GetViewCharX());
	ui->Update(player1->GetHP());



	for (int j = 0; j < 25; j++)
	{

		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i] != nullptr)
			{
				if (player1->HitBox(stage[j][i]))
				{
					if (stage[j][i]->BlockType() == 1)
					{
						player1->SetGround(stage[j][i]->GetLocation().y- 110);
					}

					if (camerawork->GetCameraX()>4000)
					{
						return new PlayerWin();
					}

				}
			}
		}
	}


	//プレイヤー２の弾丸処理

	if (PadInput::OnButton(1, XINPUT_BUTTON_B) == 1)
	{
		if (p_bullet == nullptr)
		{
			p_bullet = new Bullet(player2->GetLocation().x + camerawork->GetViewCharX(), player2->GetLocation().y);
		}
	}
	if (p_bullet != nullptr)
	{
		p_bullet->Update();

		//当たり判定

		

		if (p_bullet->GetLocation().x <= -100.0f)
		{
			delete p_bullet;
			p_bullet = nullptr;
		}
		else
		{
			if (player1->HitBox(p_bullet))
			{
				player1->Damage();
				delete p_bullet;
				p_bullet = nullptr;
			}
		}
	}

	if (PadInput::OnButton(1, XINPUT_BUTTON_A) == 1)
	{
		if (p_bom == nullptr)
		{
			p_bom = new Bom(player2->GetLocation().x + camerawork->GetViewCharX(), player2->GetLocation().y);
		}
	}
	if (p_bom != nullptr)
	{

		if (p_bom->GetLocation().x <= -100.0f)
		{
			explosion = new Explosion(p_bom->GetLocation().x, p_bom->GetLocation().y);
			delete p_bom;
			p_bom = nullptr;
		}
		else
		{
			p_bom->Update();

			for (int j = 0; j < 25; j++)
			{

				for (int i = 0; i < 111; i++)
				{
					if (stage[j][i] != nullptr)
					{
						if (p_bom->HitBox(stage[j][i]))
						{
							if (stage[j][i]->BlockType() == 1)
							{
								p_bom->Setdescent();
							}
							
						}
					}
				}
			}
			//当たり判定
			if (player1->HitBox(p_bom))
			{

				explosion = new Explosion(p_bom->GetLocation().x, p_bom->GetLocation().y);
				delete p_bom;
				p_bom = nullptr;
			}
		}

	}

	if (PadInput::OnButton(1, XINPUT_BUTTON_Y) == 1|| PadInput::OnButton(1, XINPUT_BUTTON_X) == 1)
	{
		if (p_vbullet == nullptr)
		{
			if (PadInput::OnButton(1, XINPUT_BUTTON_Y) == 1)
			{
				p_vbullet = new VBullet(player2->GetLocation().x + camerawork->GetViewCharX(), player2->GetLocation().y, -20.0f, -20.0f,45);
			}
			else
			{
				p_vbullet = new VBullet(player2->GetLocation().x + camerawork->GetViewCharX(), player2->GetLocation().y, -20.0f, 20.0f,-45);
			}
		}
	}
	if (p_vbullet != nullptr)
	{
		p_vbullet->Update();

		if (p_vbullet->GetLocation().x <= -100.0f)
		{
			delete p_vbullet;
			p_vbullet = nullptr;
		}
		else
		{
			//当たり判定
			if (player1->HitBox(p_vbullet))
			{
				delete p_vbullet;
				p_vbullet = nullptr;
				player1->Damage();
			}
		}
	}

	
	//爆発
	if (explosion != nullptr)
	{
		explosion->Update();
		if (explosion->HitBox(player1)&&explosion->GetDamage()==true)
		{
			player1->Damage();
			explosion->SetDamage();
		}
		else
		{
			if (explosion->GetEnd() == true)
			{
				delete explosion;
				explosion = nullptr;
			}
		}
	}


	if (player1->GetLocation().x > oldlocation.x)
	{
		rendering_coodinates_x++;
	}




	

	for (int j = 0; j < 25; j++)
	{

		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i]!= nullptr)
			{
				stage[j][i]->Update(camerawork->GetCameraX());
			}
		}
	}

	// 走行距離を加算する(仮のスピード)
	gMileage -= 5;

	//BGMを止める
	StopSoundMem(BGM);




	if (player1->GetHP() == 0)
	{
		return new PlayerLose(); //プレイヤー１が敗北の画面
	}


	return this;
}



void GameMain::Draw()const
{
	void BackScrool();

		
	// ステージ画像表示
// 描画可能エリアを設定
	
	// 一枚目の道路標示
	DrawGraph( gMileage % 1200 ,0, stageimg, FALSE);
	// 二枚目の道路標示
	DrawGraph, (gMileage%1200+1200,0, stageimg, FALSE);
	//エリアを戻す


	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 111; i++)
		{
			if (stage[j][i] != nullptr)
			{
				stage[j][i]->Draw();

			}
		}
	}
	player1->Draw();
	DrawFormatString(0, 260, GetColor(255, 255, 255), "X座標：%f", player1->GetLocation().x);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Y座標：%f", player1->GetLocation().y);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "jump：%d", player1->is_jump);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "fly：%d", player1->is_fly);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "fuel：%f", player1->fuel);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "g：%f", player1->g);
	DrawFormatString(0, 240, GetColor(255, 255, 255), "HP：%d", player1->hp);
	DrawFormatString(0, 440, GetColor(255, 255, 255), "いいいいい：%d", camerawork->GetCameraX());


	player2->Draw();


	if (p_bullet != nullptr)
	{
		p_bullet->Draw();
	}
	if (p_vbullet != nullptr)
	{
		p_vbullet->Draw();
	}
	if (p_bom != nullptr)
	{
		p_bom->Draw();
	}

	ui->Draw();

	if (explosion != nullptr)
	{
		explosion->Draw();

	}
}
