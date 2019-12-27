#pragma once
#include"role.h"

class MaiShiranui :public role
{
	IMAGE stand[2][18];//վ��ͼƬ
	IMAGE jump[2][12];//��ԾͼƬ
	IMAGE move[2][6];//�ƶ�ͼƬ
	IMAGE fist[2][7];//ȭ��ͼƬ
	IMAGE leg[2][7];//�Ȼ�ͼƬ
	IMAGE skill1[2][22];//����1ͼƬ
	IMAGE skill2[2][20];//����2ͼƬ
	IMAGE skill3[2][13];//����3ͼƬ
	IMAGE defend[2][1];//����ͼƬ
	IMAGE bepang[2][4];//����ͼƬ
	bool flag = true;
public:
	MaiShiranui()
	{
		name = "MaiShiranui";
		this->InitImage();
		y = 330;
	}
	//����ͼƬ
	void InitImage()
	{
		char buff[128];//ͼƬ��Դ·��

					   //����ͷ��
		loadimage(&head[0][0], "source\\MaiShiranui\\��֪����1_ͷ��.png", 50, 50);
		loadimage(&head[1][0], "source\\MaiShiranui\\��֪����2_ͷ��.png", 50, 50);

		//����վ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 18; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_վ�� (%d).png", m + 1, i + 1);
				loadimage(&stand[m][i], buff);
			}

		//������ԾͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 9; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_��Ծ (%d).png", m + 1, i + 1);
				loadimage(&jump[m][i], buff);
			}
		//�����ƶ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 6; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_�ƶ� (%d).png", m + 1, i + 1);
				loadimage(&move[m][i], buff);
			}

		//����ȭ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 7; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_ȭ�� (%d).png", m + 1, i + 1);
				loadimage(&fist[m][i], buff);
			}
		//�����Ȼ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 7; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_�Ȼ� (%d).png", m + 1, i + 1);
				loadimage(&leg[m][i], buff);
			}

		//���ؼ���1ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 22; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_ ����I (%d).png", m + 1, i + 1);
				loadimage(&skill1[m][i], buff);
			}

		//���ؼ���2ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 20; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_����II (%d).png", m + 1, i + 1);
				loadimage(&skill2[m][i], buff);
			}

		//���ؼ���3ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 13; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_����III (%d).png", m + 1, i + 1);
				loadimage(&skill3[m][i], buff);
			}
		//���ط���ͼƬ
		for (int m = 0; m <= 1; m++)
		{
			sprintf(buff, "source\\MaiShiranui\\��֪����%d_����.png", m + 1);
			loadimage(&defend[m][0], buff);
		}


		//���ذ���ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 4; i++)
			{
				sprintf(buff, "source\\MaiShiranui\\��֪����%d_���� (%d).png", m + 1, i + 1);
				loadimage(&bepang[m][i], buff);
			}

	}

	void Stand(role* p2)
	{
		img_x = stand[0][count_stand].getwidth();
		if (x < p2->x)//�����
			transparentimage(NULL, x, y, &stand[0][count_stand++], 0x000000);
		else//���ұ�
			transparentimage(NULL, x, y, &stand[1][count_stand++], 0x000000);
		if (count_stand == 18)count_stand = 0;//�ظ�
		Sleep(50);
	}

	void RightMove(role* p2)
	{
		if (x < p2->x && ifcollide(p2));
		else
			x += 15;//����λ������
		if (x >= 560) x = 560;//�߽��ж�
							  //�����ж�
		if (x < p2->x)//�����,���ұ�
			transparentimage(NULL, x, y - 5, &move[0][count_move++], 0x000000);
		else//���ұߣ������
			transparentimage(NULL, x, y - 5, &move[1][count_move++], 0x000000);
		if (count_move == 6)count_move = 0;
		Sleep(50);
	}

	void LeftMove(role* p2)
	{
		if (x > p2->x&& ifcollide(p2));
		else
			x -= 15;//��������
		if (x <= 0)x = 0;//�߽��ж�
						 //�����ж�
		if (x < p2->x)//�����,���ұ�
			transparentimage(NULL, x, y - 5, &move[0][count_move++], 0x000000);
		else//���ұߣ������
			transparentimage(NULL, x, y - 5, &move[1][count_move++], 0x000000);
		if (count_move == 6)count_move = 0;
		Sleep(50);
	}

	void Jump(role* p2)
	{
		img_x = stand[0][count_stand].getwidth();
		if (count_jump <= 3)//��Ծ����
			y -= 25;
		if (count_jump >= 5)//���
			y += 25;
		if (type == 1) {
			if (GetAsyncKeyState('A') & 0x8000) {
				if (x > p2->x&& ifcollide(p2));
				else
					x -= 20;//����
				if (x <= 0)x = 0;

			}
			if (GetAsyncKeyState('D') & 0x8000) {
				if (x < p2->x && ifcollide(p2));
				else
					x += 20;//ǰ��
				if (x >= 560)x = 560;
			}
		}
		else {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (x > p2->x&& ifcollide(p2));
				else
					x -= 20;//����
				if (x <= 0)x = 0;

			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (x < p2->x && ifcollide(p2));
				else
					x += 20;//ǰ��
				if (x >= 560)x = 560;
			}
		}
		if (x < p2->x)
			transparentimage(NULL, x, y, &jump[0][count_jump++], 0x000000);
		else
			transparentimage(NULL, x, y, &jump[1][count_jump++], 0x000000);
		if (count_jump == 9)count_jump = 0;
		Sleep(50);
	}

	void fistAttack(role* p2)
	{
		img_x = stand[0][count_stand].getwidth();
		if (x < p2->x) {
			if (count_fist == 3 || count_fist == 4)
				transparentimage(NULL, x, y - 15, &fist[0][count_fist++], 0x000000);
			else
				transparentimage(NULL, x, y, &fist[0][count_fist++], 0x000000);

			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			transparentimage(NULL, x, y, &fist[1][count_fist++], 0x000000);
			if (ifcollide(p2) && p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_fist == 6) {
			count_fist = 0;
			flag = true;//��һ��ȭ�����Կ��˺�
		}
		Sleep(10);
	}

	void legAttack(role* p2)
	{
		img_x = stand[0][count_stand].getwidth();
		if (x < p2->x)
		{
			transparentimage(NULL, x, y, &leg[0][count_leg++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			transparentimage(NULL, x, y, &leg[1][count_leg++], 0x000000);
			if (x - 25 < p2->x + p2->img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_leg == 7)
		{
			count_leg = 0;
			flag = true;
		}
		Sleep(10);
	}

	void skill_I(role* p2)
	{
		img_x = skill1[0][count_skill1 + 11].getwidth();
		bool onetime = false;
		if (count_skill1 == 0)
			fan_x = x;
		if (x < p2->x) {
			fan_x += 40;
			transparentimage(NULL, x, y, &skill1[0][count_skill1++], 0x000000);
			transparentimage(NULL, fan_x, y + 20, &skill1[0][count_skill1 + 11], 0x000000);
			if (p2->x < fan_x + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//��ʾ����
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
				count_skill1 = 10;
			}
		}
		else {
			fan_x -= 40;
			transparentimage(NULL, x, y, &skill1[1][count_skill1++], 0x000000);
			transparentimage(NULL, fan_x, y + 20, &skill1[1][count_skill1 + 11], 0x000000);
			if (fan_x < p2->x + 70 && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//��ʾ����
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
				count_skill1 = 10;
			}
		}
		if (count_skill1 == 10)
		{
			flag = true;
			count_skill1 = 0;
		}
		Sleep(30);
	}

	void skill_II(role* p2)
	{
		img_x = skill2[0][count_skill2 + 10].getwidth();
		if (x < p2->x) {
			transparentimage(NULL, x, y, &skill2[0][count_skill2++], 0x000000);
			transparentimage(NULL, x + 80, y, &skill2[0][count_skill2 + 10], 0x000000);
			if (p2->x < x + 60 + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//��ʾ����
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			transparentimage(NULL, x, y, &skill2[1][count_skill2++], 0x000000);
			transparentimage(NULL, x - 80, y, &skill2[1][count_skill2 + 10], 0x000000);
			if (x - img_x < p2->x + 70 && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//��ʾ����
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill2 == 9)
		{
			flag = true;
			count_skill2 = 0;
		}
		Sleep(30);
	}

	void skill_III(role* p2)
	{
		img_x = skill3[0][count_skill3].getwidth();
		if (x < p2->x) {
			x += 10;
			if (count_skill3 < 9)
				transparentimage(NULL, x, y, &skill3[0][count_skill3++], 0x000000);
			else
				transparentimage(NULL, x, y - 40, &skill3[0][count_skill3++], 0x000000);
			if (p2->x < x + img_x && p2->action != 8 && flag)
			{
				flag = false;
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			x -= 10;
			if (count_skill3 < 9)
				transparentimage(NULL, x, y, &skill3[1][count_skill3++], 0x000000);
			else
				transparentimage(NULL, x, y - 40, &skill3[1][count_skill3++], 0x000000);
			if (x < p2->x + 70 && p2->action != 8 && flag)
			{
				flag = false;
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill3 == 13)
		{
			flag = true;
			count_skill3 = 0;
		}
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
		if (count_beaten == 4) count_beaten = 0;
		Sleep(30);
	}

	void Defend(role* p2)
	{
		if (x < p2->x)
			transparentimage(NULL, x, y, &defend[0][0], 0x000000);
		else
			transparentimage(NULL, x, y, &defend[1][0], 0x000000);
		Sleep(30);
	}

};



