#include "Enemy.h"

Enemy::Enemy() {
	HP = 10;
	Reset();
}

void Enemy::Initialize()
{
	//ランダム関数
	srand((unsigned int)time(NULL));
	
}

void Enemy::Update()
{
	while (enemyCount < 3) {
		if (enemyCount == 0) {
			count[0] = rand() % 3;
			enemyCount += 1;
		}

		if (enemyCount == 1) {
			temp = rand() % 3;
			if (temp != count[0]) {
				count[1] = temp;
				enemyCount += 1;
			}
		}

		if (enemyCount == 2) {
			temp = rand() % 3;
			if (temp != count[0] && temp != count[1]) {
				count[2] = temp;
				enemyCount += 1;
			}

		}
	}

	if (enemyCount == 3) {
		for (int i = 0; i < 3; i++) {

			enemy[i].x = location[count[i]].x;
			enemy[i].y = location[count[i]].y;

			locationCount[i] = count[i];
		}
	}
}

void Enemy::Draw()
{
	if (flag == 1) {
		timer++;
	}

	if (timer >= 30) {
		flag = 0;
		timer = 0;
	}

	if (flag == 0) {
		Novice::DrawSprite(0, 0, ika, 1.7f, 1.5f, 0.0, WHITE);
	}

	if (flag == 1) {
		Novice::DrawSprite(0, 0, ika2, 1.7f, 1.5f, 0.0, WHITE);
	}



	Novice::DrawSprite((int)enemy[0].x, (int)enemy[0].y, scissors, 1.5, 1.5, 0.0, WHITE);
	Novice::DrawSprite((int)enemy[1].x, (int)enemy[1].y, paper, 1.5, 1.5, 0.0, WHITE);
	Novice::DrawSprite((int)enemy[2].x, (int)enemy[2].y, rock, 1.5, 1.5, 0.0, WHITE);


	if (HP >= 10) {
		Novice::DrawSprite(20, 100, HPBar[2], 1, 1, 0.0, WHITE);	//0
	}

	if (HP >= 9) {
		Novice::DrawSprite(20, 100 + 32 * 1, HPBar[1], 1, 1, 0.0, WHITE);	//1
	}

	if (HP >= 8) {
		Novice::DrawSprite(20, 100 + 32 * 2, HPBar[1], 1, 1, 0.0, WHITE);	//2
	}

	if (HP >= 7) {
		Novice::DrawSprite(20, 100 + 32 * 3, HPBar[1], 1, 1, 0.0, WHITE);	//3
	}

	if (HP >= 6) {
		Novice::DrawSprite(20, 100 + 32 * 4, HPBar[1], 1, 1, 0.0, WHITE);	//4
	}

	if (HP >= 5) {
		Novice::DrawSprite(20, 100 + 32 * 5, HPBar[1], 1, 1, 0.0, WHITE);	//5
	}

	if (HP >= 4) {
		Novice::DrawSprite(20, 100 + 32 * 6, HPBar[1], 1, 1, 0.0, WHITE);	//6
	}

	if (HP >= 3) {
		Novice::DrawSprite(20, 100 + 32 * 7, HPBar[1], 1, 1, 0.0, WHITE);	//7
	}

	if (HP >= 2) {
		Novice::DrawSprite(20, 100 + 32 * 8, HPBar[1], 1, 1, 0.0, WHITE);	//8
	}

	if (HP >= 1) {
		Novice::DrawSprite(20, 100 + 32 * 9, HPBar[0], 1, 1, 0.0, WHITE);	//9
	}

}

void Enemy::Damage()
{
	HP -= 1;
	flag = 1;
}

void Enemy::Reset() {
	enemyCount = 0;

}

bool Enemy::GameClear() {

	if (HP <= 0) {
		return true;
	}
	return false;
}

void Enemy::SEFlag() {
		
			Novice::PlayAudio(screaming, false, 0.5f);
		
}