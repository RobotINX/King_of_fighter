#pragma once
#include"role.h"

class K :public role {
	IMAGE stand[2];//վ��ͼƬ
	IMAGE jump[2][8];//��ԾͼƬ
	IMAGE move[2][12];//�ƶ�ͼƬ
	IMAGE fist[2][25];//ȭ��ͼƬ
	IMAGE leg[2][19];//�Ȼ�ͼƬ
	IMAGE skill1[2][18];//����1ͼƬ
	IMAGE skill2[2][25];//����2ͼƬ
	IMAGE skill3[2][24];//����3ͼƬ
	IMAGE defend[2];//����ͼƬ
	IMAGE bepang[2][6];//����ͼƬ
	bool flag = true;//ֻ����һ�ο�Ѫ

public:
	K()
	{
		name = "K";
		this->InitImage();
		y = 315;
	}
	void InitImage() {
		char buff[128];//ͼƬ��Դ·��

					   //����ͷ��
		loadimage(&head[0][0], "source\\K\\K1_ͷ��.png", 50, 50);
		loadimage(&head[1][0], "source\\K\\K2_ͷ��.png", 50, 50);


		//����վ��ͼƬ
		for (int m = 0; m <= 1; m++)
		{
			sprintf(buff, "source\\K\\K%d_վ��.png", m + 1);
			loadimage(&stand[m], buff);
		}

		//������ԾͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 8; i++) {
				sprintf(buff, "source\\K\\K%d_��Ծ (%d).png", m + 1, i + 1);
				loadimage(&jump[m][i], buff);
			}

		//�����ƶ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 12; i++) {
				sprintf(buff, "source\\K\\K%d_�ƶ� (%d).png", m + 1, i + 1);
				loadimage(&move[m][i], buff);
			}

		//����ȭ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 25; i++) {
				sprintf(buff, "source\\K\\K%d_ȭ�� (%d).png", m + 1, i + 1);
				loadimage(&fist[m][i], buff);
			}

		//�����Ȼ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 19; i++) {
				sprintf(buff, "source\\K\\K%d_���� (%d).png", m + 1, i + 1);
				loadimage(&leg[m][i], buff);
			}

		//���ؼ���1ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 18; i++) {
				sprintf(buff, "source\\K\\K%d_����I (%d).png", m + 1, i + 1);
				loadimage(&skill1[m][i], buff);
			}

		//���ؼ���2ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 25; i++) {
				sprintf(buff, "source\\K\\K%d_����II (%d).png", m + 1, i + 1);
				loadimage(&skill2[m][i], buff);
			}

		//���ؼ���3ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 24; i++) {
				sprintf(buff, "source\\K\\K%d_����III (%d).png", m + 1, i + 1);
				loadimage(&skill3[m][i], buff);
			}

		//���ط���ͼƬ
		for (int m = 0; m <= 1; m++) {
			sprintf(buff, "source\\K\\K%d_����.png", m + 1);
			loadimage(&defend[m], buff);
		}

		//���ذ���ͼƬ
		for (int m = 0; m <= 1; m++)
		{
			for (int i = 0; i < 4; i++)
			{
				sprintf(buff, "source\\K\\K%d_���� (%d).png", m + 1, i + 1);
				loadimage(&bepang[m][i], buff);
			}
			sprintf(buff, "source\\K\\K%d_���� (3).png", m + 1);
			loadimage(&bepang[m][4], buff);
			sprintf(buff, "source\\K\\K%d_���� (2).png", m + 1);
			loadimage(&bepang[m][5], buff);
		}

	}

	void Stand(role* p2) {
		if (x < p2->x)
			transparentimage(NULL, x, y, &stand[0], 0x000000);
		else
			transparentimage(NULL, x, y, &stand[1], 0x000000);
		if (count_stand == 18)count_stand = 0;
		Sleep(50);
	}

	void RightMove(role* p2) {
		if (x < p2->x && ifcollide(p2));
		else
			x += 15;//����λ������
		if (x >= 560) x = 560;//�߽��ж�
		transparentimage(NULL, x, y, &move[0][count_move++], 0x000000);
		if (count_move == 12)count_move = 0;
		Sleep(30);
	}

	void LeftMove(role* p2) {
		if (x > p2->x&& ifcollide(p2));
		else
			x -= 15;//��������
		if (x <= 0)x = 0;//�߽��ж�
		transparentimage(NULL, x, y, &move[1][count_move++], 0x000000);
		if (count_move == 12)count_move = 0;
		Sleep(30);
	}

	void Jump(role* p2) {
		if (count_jump <= 3)//��Ծ����
			y -= 20;
		if (count_jump >= 5)//���
			y += 20;
		if (type == 2)
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (x > p2->x&& ifcollide(p2));
				else
					x -= 20;
				if (x <= 0)x = 0;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (x < p2->x && ifcollide(p2));
				else
					x += 20;
				if (x >= 560)x = 560;
			}
		}
		else
		{
			if (GetAsyncKeyState('A') & 0x8000) {
				if (x > p2->x&& ifcollide(p2));
				else
					x -= 20;
				if (x <= 0)x = 0;
			}
			if (GetAsyncKeyState('D') & 0x8000) {
				if (x < p2->x && ifcollide(p2));
				else
					x += 20;
				if (x >= 560)x = 560;
			}
		}
		if (x < p2->x)
			transparentimage(NULL, x, y, &jump[0][count_jump++], 0x000000);
		else
			transparentimage(NULL, x, y, &jump[1][count_jump++], 0x000000);
		if (count_jump == 9)count_jump = 0;
		Sleep(30);
	}

	void fistAttack(role* p2) {
		if (x < p2->x) {
			transparentimage(NULL, x, y, &fist[0][count_fist++], 0x000000);
		}
		else {
			if (count_fist == 1)
				transparentimage(NULL, x - 20, y, &fist[1][count_fist++], 0x000000);
			else if (count_fist == 2)
				transparentimage(NULL, x - 30, y, &fist[1][count_fist++], 0x000000);
			else if (count_fist == 3)
				transparentimage(NULL, x - 20, y, &fist[1][count_fist++], 0x000000);
			else
				transparentimage(NULL, x, y, &fist[1][count_fist++], 0x000000);
		}
		if (ifcollide(p2) && p2->action != 8 && flag)
		{
			flag = false;//һ��ȭ��ֻ��һ��Ѫ
			p2->action = 9;//����״̬
			p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
		}
		if (count_fist == 5)
		{
			count_fist = 0;
			flag = true;//��һ��ȭ�����Կ��˺�
		}
		Sleep(30);
	}

	void legAttack(role* p2) {
		int dis_y;
		dis_y = leg[0][count_leg].getheight() - leg[0][0].getheight();
		if (x < p2->x)
		{
			transparentimage(NULL, x, y, &leg[0][count_leg++], 0x000000);
		}
		else
		{
			transparentimage(NULL, x, y, &leg[1][count_leg++], 0x000000);
		}
		if (ifcollide(p2) && p2->action != 8 && flag)
		{
			flag = false;//һ��ȭ��ֻ��һ��Ѫ
			p2->action = 9;//����״̬
			p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
		}
		if (count_leg == 7)
		{
			count_leg = 0;
			flag = true;//��һ��ȭ�����Կ��˺�
		}
		Sleep(30);
	}

	void skill_I(role* p2) {
		if (x < p2->x) {
			transparentimage(NULL, x + 70, y, &skill1[0][count_skill1 + 9], 0x000000);
			transparentimage(NULL, x, y, &skill1[0][count_skill1++], 0x000000);
			if (p2->x < x + 120 && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			transparentimage(NULL, x - 70, y, &skill1[1][count_skill1 + 9], 0x000000);
			transparentimage(NULL, x, y, &skill1[1][count_skill1++], 0x000000);
			if (x < p2->x + 120 && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill1 == 9)
		{
			count_skill1 = 0;
			flag = true;
		}
		Sleep(30);
	}

	void skill_II(role* p2) {
		if (count_skill2 <= 4)
			y = y - 16;
		else if (count_skill2 > 6 && count_skill2 < 12)
			y = y + 16;
		if (x < p2->x) {
			if (count_skill2 >= 4)
			{
				if (count_skill2 == 4)
					fan_x = x + 20;
				if (fan_x + 20 > 830)
					fan_x = 830;
				else
					fan_x += 20;
				transparentimage(NULL, fan_x, y + 20, &skill2[0][count_skill2 + 10], 0x000000);
				if (fan_x + 70 >= p2->x && fan_x <= p2->x + 70 && y + 40 >= p2->y && y <= p2->y + 100
					&& flag && p2->action != 8)
				{
					flag = false;//һ��ֻ��һ��Ѫ
					p2->action = 9;//����״̬
					p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
				}
			}
			if (x - 8 < 0)
				x = 0;
			else if (count_skill2 <= 12)
				x = x - 8;
			transparentimage(NULL, x, y, &skill2[0][count_skill2++], 0x000000);
		}
		else {
			if (count_skill2 >= 4)
			{
				if (count_skill2 == 4)
					fan_x = x - 20;
				if (fan_x - 20 <= 0)
					fan_x = 0;
				else
					fan_x -= 20;
				transparentimage(NULL, fan_x, y + 20, &skill2[0][count_skill2 + 10], 0x000000);
				if (fan_x <= p2->x + 70 && fan_x + 70 >= p2->x && y + 40 >= p2->y && y <= p2->y + 100
					&& flag && p2->action != 8)
				{
					flag = false;//һ��ֻ��һ��Ѫ
					p2->action = 9;//����״̬
					p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
				}
			}
			if (x + 8 > 560)
				x = 560;
			else if (count_skill2 <= 12)
				x = x + 8;
			transparentimage(NULL, x, y, &skill2[1][count_skill2++], 0x000000);
		}
		if (count_skill2 == 14)
		{
			count_skill2 = 0;
			flag = true;
		}
		Sleep(30);
	}

	void skill_III(role* p2) {
		if (count_skill3 <= 7 && count_skill3 >= 4)
			y = y - 25;
		else if (count_skill3 >= 8 && count_skill3 <= 11)
			y = y + 25;
		if (x < p2->x) {
			if (x + 8 > 560)
				x = 560;
			else
				x = x + 8;
			transparentimage(NULL, x + 30, y - 30, &skill3[0][count_skill3 + 12], 0x000000);
			transparentimage(NULL, x, y, &skill3[0][count_skill3++], 0x000000);
			if (x + 70 >= p2->x && flag && p2->action != 8)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			if (x - 8 < 0)
				x = 0;
			else
				x = x - 8;
			transparentimage(NULL, x - 30, y - 30, &skill3[1][count_skill3 + 12], 0x000000);
			transparentimage(NULL, x, y, &skill3[1][count_skill3++], 0x000000);
			if (x <= p2->x + 50 && flag && p2->action != 8)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill3 == 12) {
			count_skill3 = 0;
			flag = true;
		}
		Sleep(30);
	}

	void Defend(role* p2)
	{
		if (x < p2->x)
			transparentimage(NULL, x, y, &defend[0], 0x000000);
		else
			transparentimage(NULL, x, y, &defend[1], 0x000000);
		Sleep(30);
	}

	void Beaten(role* p2)
	{
		if (x < p2->x) {
			transparentimage(NULL, x, y, &bepang[0][count_beaten++], 0x000000);
		}
		else {
			transparentimage(NULL, x, y, &bepang[1][count_beaten++], 0x000000);
		}

		if (count_beaten == 6)count_beaten = 0;
		Sleep(50);
	}
};

