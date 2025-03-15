// Text_RPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

void EnterLobby();
void EnterBattle();
void CreatePlayer();
void CreateRandomMonster();
void EnterShop();
void EnterDungeon();

enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

StatInfo playerStat;
StatInfo monsterStat;
PlayerType playerType;
MonsterType monsterType;

int main()
{
    while (true)
    {
		cout << "게임을 시작하시겠습니까?" << endl;
		cout << "1. 예 2. 아니오" << endl;

		int input;
		cin >> input;

		switch (input)
		{
			case 1:
			cout << "게임을 시작합니다." << endl;
			EnterLobby();
			break;
			case 2:
			cout << "게임을 종료합니다." << endl;
			return 0;
		}
    }
}



void EnterLobby()
{
	cout << "로비에 입장하였습니다." << endl;
	cout << "캐릭터를 생성합니다." << endl;
	CreatePlayer();

	cout << "1. 훈련소 2. 상점 3. 던전 입장" << endl;
	int input;
	cin >> input;
	switch (input)
	{
		case 1:
		cout << "훈련소에 입장하였습니다." << endl;
		EnterBattle();
		break;
		case 2:
		cout << "상점에 입장하였습니다." << endl;
		EnterShop();
		break;
		case 3:
		cout << "던전에 입장하였습니다." << endl;
		EnterDungeon();
		break;
	}
}

void CreatePlayer()
{
	cout << "캐릭터를 선택하세요." << endl;
	cout << "1. 기사 2. 궁수 3. 마법사" << endl;

	int input;
	cin >> input;

	switch (input)
	{
	case PT_Knight:
		playerStat.hp = 100;
		playerStat.attack = 10;
		playerStat.defence = 5;
		playerType = PT_Knight;
		cout << "기사를 선택하였습니다. HP:" << playerStat.hp << " Attack: " << playerStat.attack << " Def: " << playerStat.defence << endl;
		break;
	case PT_Archer:
		playerStat.hp = 50;
		playerStat.attack = 15;
		playerStat.defence = 3;
		playerType = PT_Archer;
		cout << "궁수를 선택하였습니다. HP : " << playerStat.hp << " Attack : " << playerStat.attack << " Def : " << playerStat.defence  << endl;
		break;
	case PT_Mage:
		playerStat.hp = 30;
		playerStat.attack = 20;
		playerStat.defence = 1;
		playerType = PT_Mage; 
		cout << "마법사를 선택하였습니다. HP:" << playerStat.hp << " Attack: " << playerStat.attack << " Def: " << playerStat.defence << endl;
		break;
	}
}

void EnterBattle()
{
	cout << "전투를 시작합니다." << endl;
	CreateRandomMonster();

	while (true)
	{
		cout << "1. 공격 2. 회복" << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			monsterStat.hp -= playerStat.attack;
			cout << "몬스터에게 " << playerStat.attack << "만큼의 피해를 입혔습니다." << endl;
			if (monsterStat.hp <= 0)
			{
				cout << "몬스터를 처치하였습니다." << endl;
				return;
			}
			playerStat.hp -= monsterStat.attack;
			cout << "몬스터에게 " << monsterStat.attack << "만큼의 피해를 입었습니다." << endl;
			if (playerStat.hp <= 0)
			{
				cout << "플레이어가 사망하였습니다." << endl;
				return;
			}
			break;
		case 2:
			playerStat.hp += 20;
			cout << "체력을 20만큼 회복하였습니다." << endl;
			playerStat.hp -= monsterStat.attack;
			cout << "몬스터에게 " << monsterStat.attack << "만큼의 피해를 입었습니다." << endl;
			if (playerStat.hp <= 0)
			{
				cout << "플레이어가 사망하였습니다." << endl;
				return;
			}
			break;
		}
	}
}

void CreateRandomMonster()
{
	int randValue = rand() % 3 + 1;
	switch (randValue)
	{
	case MT_Slime:
		monsterStat.hp = 20;
		monsterStat.attack = 2;
		monsterStat.defence = 1;
		monsterType = MT_Slime;
		cout << "슬라임이 생성되었습니다. HP:" << monsterStat.hp << "Attack: " << monsterStat.attack << "Def: " << monsterStat.defence << endl;
		break;
	case MT_Orc:
		monsterStat.hp = 50;
		monsterStat.attack = 5;
		monsterStat.defence = 3;
		monsterType = MT_Orc;
		cout << "오크가 생성되었습니다. HP:" << monsterStat.hp << "Attack: " << monsterStat.attack << "Def: " << monsterStat.defence << endl;
		break;
	case MT_Skeleton:
		monsterStat.hp = 30;
		monsterStat.attack = 3;
		monsterStat.defence = 2;
		monsterType = MT_Skeleton;
		cout << "해골이 생성되었습니다. HP:" << monsterStat.hp << "Attack: " << monsterStat.attack << "Def: " << monsterStat.defence << endl;
		break;
	}
}

void EnterShop()
{
	cout << "상점에 입장하였습니다." << endl;
	cout << "1. 체력포션 구매 2. 공격력 강화 3. 방어력 강화" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
		playerStat.hp += 20;
		cout << "체력포션을 구매하였습니다. 현재 체력: " << playerStat.hp << endl;
		break;
	case 2:
		playerStat.attack += 5;
		cout << "공격력을 강화하였습니다. 현재 공격력: " << playerStat.attack << endl;
		break;
	case 3:
		playerStat.defence += 2;
		cout << "방어력을 강화하였습니다. 현재 방어력: " << playerStat.defence << endl;
		break;
	}
}

void EnterDungeon()
{
	cout << "던전에 입장하였습니다." << endl;
	cout << "1. 던전 입장 2. 던전 나가기" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "던전에 입장하였습니다." << endl;
		EnterBattle();
		break;
	case 2:
		cout << "던전에서 나왔습니다." << endl;
		break;
	}
}

