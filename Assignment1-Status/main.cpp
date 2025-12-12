#include<iostream>
#include<string>
using namespace std;

const int statusSize = 8;
int status[statusSize] = { 0 };
string statusNames[statusSize] = {
	"HP", "MP", "공격력", "방어력", "레벨", "힘", "민첩", "지능"
};

int hpPotion = 0, mpPotion = 0;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	if (p_HPPotion != nullptr) {
		*p_HPPotion = count;
	}

	if (p_MPPotion != nullptr) {
		*p_MPPotion = count;
	}
}

void Init() {
	status[4] = 1;
	while (true) {
		int hp, mp, attack, shield;
		cout << "HP와 MP를 입력해주세요: ";
		cin >> hp >> mp;
		if (hp <= 50 || mp <= 50) {
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
			continue;
		}
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> attack >> shield;
		if (attack <= 0 || shield <= 0) {
			cout << "공격력이나 방어력 값이 너무 작습니다. 다시 입력해주세요.\n";
			continue;
		}
		status[0] = hp;
		status[1] = mp;
		status[2] = attack;
		status[3] = shield;
		break;
	}
	setPotion(5, &hpPotion, &mpPotion);
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
}

void SetStatus(int* status, int inValue) {
	if (status != nullptr) {
		*status = inValue;
	}
}

void PrintStatus(int index) {
	cout << "현재 " << statusNames[index] << ": " << status[index] << "\n";
}

void PrintPlayerAllStatus() {
	cout << "====플레이어 정보====\n";
	for (int i = 0; i < statusSize; i++) {
		PrintStatus(i);
	}

	cout << "남은 HP포션 수: " << hpPotion << "\n";
	cout << "남은 MP포션 수: " << mpPotion << "\n";
}

void LevelUp() {
	SetStatus(&hpPotion, hpPotion + 1);
	SetStatus(&mpPotion, mpPotion + 1);
	SetStatus(&status[4], status[4] + 1);
	SetStatus(&status[5], status[5] + 2);
	SetStatus(&status[6], status[6] + 5);
	SetStatus(&status[7], status[7] + 1);
}

void StartStatusSystem() {
	while (true) {
		cout << "\n\n";
		cout << "=============================================\n< 스탯 관리 시스템 >\n";
		cout << "1. HP UP\n";
		cout << "2. MP UP\n";
		cout << "3. 공격력 UP\n";
		cout << "4. 방어력 UP\n";
		cout << "5. 현재 능력치\n";
		cout << "6. Level UP\n";
		cout << "0. 나가기\n";
		cout << "번호를 선택해주세요: ";
		
		int operNum = 0;
		cin >> operNum;
		system("cls");

		if (operNum == 1) {
			if (hpPotion <= 0) {
				cout << "포션이 부족합니다.\n";
				continue;
			}
			SetStatus(&status[0], status[0] + 20);
			cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
			hpPotion--;
			PrintStatus(0);
			cout << "남은 hp 포션 수: " << hpPotion << "\n";
		}
		else if (operNum == 2) {
			if (mpPotion <= 0) {
				cout << "포션이 부족합니다.\n";
				continue;
			}
			SetStatus(&status[1], status[1] + 20);
			cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
			mpPotion--;
			PrintStatus(1);
			cout << "남은 mp 포션 수: " << mpPotion << "\n";
		}
		else if (operNum == 3) {
			cout << "* 공격력이 2배로 증가되었습니다.\n";
			status[2] = (status[2] << 1);
			PrintStatus(2);
		}
		else if (operNum == 4) {
			cout << "* 방어력 2배로 증가되었습니다.\n";
			status[3] = (status[3] << 1);
			PrintStatus(3);
		}
		else if (operNum == 5) {
			PrintPlayerAllStatus();
		}
		else if (operNum == 6) {
			cout << "레벨업!!!!\n";
			LevelUp();
			PrintPlayerAllStatus();
		}
		else if (operNum == 0) {
			cout << "프로그램을 종료합니다.\n";
			break;
		}
		else {
			cout << "알수없는 명령어 입니다 다시 입력해주세요\n";
		}
		
	}
}
int main() {
	Init();
	StartStatusSystem();

	return 0;
}