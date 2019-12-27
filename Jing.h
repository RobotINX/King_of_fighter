#pragma once
#include"role.h"

class Jing :public role {
	IMAGE stand[2][10];//վ��ͼƬ
	IMAGE jump[2][13];//��ԾͼƬ
	IMAGE move[2][6];//�ƶ�ͼƬ
	IMAGE fist[2][4];//��ȭͼƬ
	IMAGE leg[2][6];//���ͼƬ
	IMAGE skill1[2][21];//����1ͼƬ
	IMAGE skill2[2][40];//����2ͼƬ
	IMAGE skill3[2][55];//����3ͼƬ
	IMAGE bepang[2][4];
	IMAGE defend[2][1];
	int horizon;
	bool flag = true;
public:
	Jing()
	{
		name = "Jing";
		this->InitImage();
		y = 315;
	}
	void InitImage() {
		char buff[128];//ͼƬ��Դ·��

					   //����ͷ��
		loadimage(&head[0][0], "source\\Jing\\Jing1.png", 50, 50);
		loadimage(&head[1][0], "source\\Jing\\Jing2.png", 50, 50);


		//����վ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 10; i++) {
				sprintf_s(buff, "source\\Jing\\stand%d\\%d.jpg", m + 1, i + 1);
				loadimage(&stand[m][i], buff);
			}

		//������ԾͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 13; i++) {
				sprintf_s(buff, "source\\Jing\\jump%d\\%d.jpg", m + 1, i + 1);
				loadimage(&jump[m][i], buff);
			}
		//�����ƶ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 6; i++) {
				sprintf_s(buff, "source\\Jing\\move%d\\%d.jpg", m + 1, i + 1);
				loadimage(&move[m][i], buff);
			}

		//����ȭ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 4; i++) {
				sprintf_s(buff, "source\\Jing\\hand%d\\%d.jpg", m + 1, i + 1);
				loadimage(&fist[m][i], buff);
			}
		//�����Ȼ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 6; i++) {
				sprintf_s(buff, "source\\Jing\\leg%d\\%d.jpg", m + 1, i + 1);
				loadimage(&leg[m][i], buff);
			}

		//���ؼ���1ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 21; i++) {
				sprintf_s(buff, "source\\Jing\\skill1_%d\\%d.jpg", m + 1, i + 1);
				loadimage(&skill1[m][i], buff);
			}

		//���ؼ���2ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 40; i++) {
				sprintf_s(buff, "source\\Jing\\skill2_%d\\%d.jpg", m + 1, i + 1);
				loadimage(&skill2[m][i], buff);
			}

		//���ؼ���3ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 55; i++) {
				sprintf_s(buff, "source\\Jing\\skill3_%d\\%d.jpg", m + 1, i + 1);
				loadimage(&skill3[m][i], buff);
			}


		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 4; i++) {
				sprintf_s(buff, "source\\Jing\\beaten%d\\%d.jpg", m + 1, i + 1);
				loadimage(&bepang[m][i], buff);
			}

		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 1; i++) {
				sprintf_s(buff, "source\\Jing\\defend%d\\%d.jpg", m + 1, i + 1);
				loadimage(&defend[m][i], buff);
			}
	}
	void Stand(role * p2) {
		if (x < p2->x)
		{
			//putimage(x, y, &stand[0][count_stand++]);
			int yoffer = stand[0][count_stand].getheight() - stand[0][0].getheight();
			transparentimage(NULL, x, y - yoffer, &stand[0][count_stand++], 0x000000);
		}
		else
		{
			//putimage(x, y, &stand[1][count_stand++]);
			int yoffer = stand[1][count_stand].getheight() - stand[1][0].getheight();
			transparentimage(NULL, x, y - yoffer, &stand[1][count_stand++], 0x000000);
		}
		if (count_stand == 10)count_stand = 0;
		Sleep(50);
	}

	void RightMove(role* p2) {
		if (x < p2->x && ifcollide(p2));
		else
			x += 15;//����λ������
		if (x >= 560) x = 560;//�߽��ж�
							  //�����ж�
		if (x < p2->x)
		{
			int yoffer = move[0][count_move].getheight() - stand[0][0].getheight();
			transparentimage(NULL, x, y - yoffer, &move[0][count_move++], 0x000000);
		}
		else
		{
			int yoffer = move[1][count_move].getheight() - stand[1][0].getheight();
			transparentimage(NULL, x, y - yoffer, &move[1][count_move++], 0x000000);
		}
		if (count_move == 6)count_move = 0;
		Sleep(50);
	}

	void LeftMove(role* p2) {
		if (x > p2->x&& ifcollide(p2));
		else
			x -= 15;//��������
		if (x <= 0)x = 0;//�߽��ж�
						 //�����ж�
		if (x < p2->x)
		{
			int yoffer = move[0][count_move].getheight() - stand[0][0].getheight();
			transparentimage(NULL, x, y - yoffer, &move[0][count_move++], 0x000000);
		}
		else
		{
			int yoffer = move[1][count_move].getheight() - stand[1][0].getheight();
			transparentimage(NULL, x, y - yoffer, &move[1][count_move++], 0x000000);
		}
		if (count_move == 6)count_move = 0;
		Sleep(50);
	}

	void Jump(role* p2) {
		img_x = stand[0][count_stand].getwidth();
		if (count_jump <= 5)//��Ծ����
			y -= 20;
		if (count_jump >= 7)//���
			y += 20;
		if (x < p2->x)
		{
			if (GetAsyncKeyState('A') & 0x8000) {
				x -= 20;
				if (x <= 0)x = 0;

			}
			if (GetAsyncKeyState('D') & 0x8000) {
				x += 20;
				if (x >= 560)x = 560;
			}
			int yoffer = jump[0][count_jump].getheight() - stand[0][0].getheight();
			transparentimage(NULL, x, y - yoffer, &jump[0][count_jump++], 0x000000);
		}
		else
		{
			if (GetAsyncKeyState(0x25) & 0x8000) {
				x -= 20;
				if (x <= 0)x = 0;

			}
			if (GetAsyncKeyState(0x27) & 0x8000) {
				x += 20;
				if (x >= 560)x = 560;
			}
			int yoffer = jump[1][count_jump].getheight() - stand[1][0].getheight();
			transparentimage(NULL, x, y - yoffer, &jump[1][count_jump++], 0x000000);
		}
		if (count_jump == 13)count_jump = 0;
		Sleep(20);
	}

	void fistAttack(role* p2) {
		if (x < p2->x)
		{
			img_x = fist[0][count_fist].getwidth();
			transparentimage(NULL, x, y, &fist[0][count_fist++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			img_x = fist[1][count_fist].getwidth();
			transparentimage(NULL, x, y, &fist[1][count_fist++], 0x000000);
			if (x - 20 < p2->x + p2->img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_fist == 4)
		{
			count_fist = 0;
			flag = true;
		}
		Sleep(2);
	}

	void legAttack(role* p2) {
		if (x < p2->x)
		{
			img_x = leg[0][count_leg].getwidth();
			transparentimage(NULL, x, y, &leg[0][count_leg++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			img_x = leg[1][count_leg].getwidth();
			transparentimage(NULL, x, y, &leg[1][count_leg++], 0x000000);
			if (x - 20 < p2->x + p2->img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}

		if (count_leg == 6)
		{
			count_leg = 0;
			flag = true;
		}
		Sleep(20);
	}

	void skill_I(role* p2) {
		if (x < p2->x)
		{
			img_x = skill1[0][count_skill1].getwidth();
			int yoffer = skill1[0][count_skill1].getheight() - skill1[0][0].getheight();
			transparentimage(NULL, x, y - yoffer - 10, &skill1[0][count_skill1++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			img_x = skill1[1][count_skill1].getwidth();
			int yoffer = skill1[1][count_skill1].getheight() - skill1[1][0].getheight();
			transparentimage(NULL, x - 180, y - yoffer - 10, &skill1[1][count_skill1++], 0x000000);
			if (x - img_x + 40 < p2->x + 20 && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill1 == 21)
		{
			count_skill1 = 0;
			flag = true;
		}
	}

	void skill_II(role* p2) {
		if (x < p2->x) {
			img_x = skill2[0][count_skill2].getwidth();
			transparentimage(NULL, x - 50, y - 95, &skill2[0][count_skill2++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
			if (count_skill2 == 40)
			{
				x += 65;
			}
		}
		else
		{
			img_x = skill2[1][count_skill2].getwidth();
			transparentimage(NULL, x - 165, y - 95, &skill2[1][count_skill2++], 0x000000);
			if (x - img_x + 40 < p2->x + 20 && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
			if (count_skill2 == 40)
			{
				x -= 50;
			}
		}

		if (count_skill2 == 40) {
			flag = true;
			count_skill2 = 0;
		}
	}

	void skill_III(role* p2) {
		if (x < p2->x) {
			img_x = skill3[0][count_skill3].getwidth();
			transparentimage(NULL, x - 30, y - 95, &skill3[0][count_skill3++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
			if (count_skill3 == 55)
			{
				x += 120;
			}
		}
		else
		{
			img_x = skill3[1][count_skill3].getwidth();
			transparentimage(NULL, x - 165, y - 95, &skill3[1][count_skill3++], 0x000000);
			if (x - img_x + 40 < p2->x + 20 && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
			if (count_skill3 == 55)
			{
				x -= 100;
			}
		}

		if (count_skill3 == 55) {
			flag = true;
			count_skill3 = 0;
		}
	}

	void Beaten(role* p2)
	{
		if (x < p2->x) {
			transparentimage(NULL, x, y, &bepang[0][count_beaten++], 0x000000);
		}
		else {
			transparentimage(NULL, x, y, &bepang[1][count_beaten++], 0x000000);
		}

		if (count_beaten == 4)count_beaten = 0;
		Sleep(50);
	}

	void Defend(role* p2)
	{
		if (x < p2->x) {
			transparentimage(NULL, x, y, &defend[0][0], 0x000000);
		}
		else {
			transparentimage(NULL, x, y, &defend[1][0], 0x000000);
		}
		Sleep(50);
	}

};