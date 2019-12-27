#pragma once
#include"role.h"

class BenimaruNikaido :public role
{
public:
	bool flag = true;//ֻ����һ�ο�Ѫ
	IMAGE stand[2][8];//վ��ͼƬ
	IMAGE jump[2][6];//��ԾͼƬ
	IMAGE move[2][7];//�ƶ�ͼƬ
	IMAGE fist[2][5];//ȭ��ͼƬ
	IMAGE leg[2][8];//�Ȼ�ͼƬ
	IMAGE skill1[2][20];//����1ͼƬ
	IMAGE skill2[2][16];//����2ͼƬ
	IMAGE skill3[2][23];//����3ͼƬ
	IMAGE beaten[2][10];//����ͼƬ
	IMAGE defend[2][1];//����ͼƬ

public:

	BenimaruNikaido()
	{
		name = "BenimaruNikaido";
		this->InitImage();
		y = 315;
	}

	//��Դ��ʼ��
	void InitImage()
	{
		char buff[128];//ͼƬ��Դ·��

					   //����ͷ��
		loadimage(&head[0][0], "source\\BenimaruNikaido\\�����ú���1_ͷ��.png", 50, 50);
		loadimage(&head[1][0], "source\\BenimaruNikaido\\�����ú���2_ͷ��.png", 50, 50);

		//����վ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 8; i++)
			{
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_վ�� (%d).png", m + 1, i + 1);
				loadimage(&stand[m][i], buff);
			}

		//������ԾͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 6; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_��Ծ (%d).png", m + 1, i + 1);
				loadimage(&jump[m][i], buff);
			}

		//�����ƶ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 7; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_�ƶ� (%d).png", m + 1, i + 1);
				loadimage(&move[m][i], buff);
			}

		//����ȭ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 5; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_ȭ�� (%d).png", m + 1, i + 1);
				loadimage(&fist[m][i], buff);
			}

		//�����Ȼ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 8; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_�Ȼ� (%d).png", m + 1, i + 1);
				loadimage(&leg[m][i], buff);
			}

		//���ؼ���1ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 20; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_����I (%d).png", m + 1, i + 1);
				loadimage(&skill1[m][i], buff);
			}

		//���ؼ���2ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 16; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_����II (%d).png", m + 1, i + 1);
				loadimage(&skill2[m][i], buff);
			}

		//���ؼ���3ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 23; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_����III (%d).png", m + 1, i + 1);
				loadimage(&skill3[m][i], buff);
			}

		//���ذ���ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 10; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_���� (%d).png", m + 1, i + 1);
				loadimage(&beaten[m][i], buff);
			}

		//���ط���ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 1; i++) {
				sprintf(buff, "source\\BenimaruNikaido\\�����ú���%d_���� (%d).png", m + 1, i + 1);
				loadimage(&defend[m][i], buff);
			}

		//��ʼ������P1��P2
		if (type == 1)
		{
			x = 30;
			y = 330;
			int a[8] = { 250,40,260,50,261,50,251,40 };
			for (int i = 0; i < 8; i++)
				point[i] = a[i];
		}
		else
		{
			x = 570;
			y = 330;
			int a[8] = { 400,40,390,50,391,50,401,40 };
			for (int i = 0; i < 8; i++)
				point[i] = a[i];
		}
	}


	//����
	void Beaten(role *p2) {
		if (x < p2->x)
			transparentimage(NULL, x, y, &beaten[0][count_beaten++], 0x000000);
		else
			transparentimage(NULL, x, y, &beaten[1][count_beaten++], 0x000000);
		if (count_beaten == 8)count_beaten = 0;
		Sleep(50);
	}


	//վ������
	void Stand(role* p2) {
		if (x<p2->x)
			transparentimage(NULL, x, y, &stand[0][count_stand++], 0x000000);
		else
			transparentimage(NULL, x, y, &stand[1][count_stand++], 0x000000);
		if (count_stand == 8)count_stand = 0;
		Sleep(50);
	}

	//��ɫ����
	void RightMove(role* p2) {
		x += 15;//����
		if (x >= 560) x = 560;//�߽�
		if (x<p2->x)
			transparentimage(NULL, x, y, &move[0][count_move++], 0x000000);
		else
			transparentimage(NULL, x, y, &move[1][count_move++], 0x000000);
		if (count_move == 7)count_move = 0;
		Sleep(50);
	}

	//��ɫ����
	void LeftMove(role* p2) {
		x -= 15;//����
		if (x <= 0)x = 0;//�߽�
		if (x < p2->x)
			transparentimage(NULL, x, y, &move[0][count_move++], 0x000000);
		else
			transparentimage(NULL, x, y, &move[1][count_move++], 0x000000);
		if (count_move == 7)count_move = 0;
		Sleep(50);
	}

	//��ɫ��Ծ
	void Jump(role* p2) {
		if (count_jump <= 2)//��Ծ
			y -= 30;
		if (count_jump >= 3)//����
			y += 30;
		//��Ծ;�п������ƺ�����
		if (GetAsyncKeyState('A') & 0x8000) {
			x -= 20;
			if (x <= 0)x = 0;//�߽�
		}
		if (GetAsyncKeyState('D') & 0x8000) {
			x += 20;
			if (x >= 560)x = 560;//�߽�
		}
		if (x < p2->x)
			transparentimage(NULL, x, y, &jump[0][count_jump++], 0x000000);
		else
			transparentimage(NULL, x, y, &jump[1][count_jump++], 0x000000);
		if (count_jump == 6)count_jump = 0;
		Sleep(30);
	}

	//ȭ��
	void fistAttack(role* p2) {
		img_x = fist[0][count_fist].getwidth();//��ǰͼƬ�Ŀ�ȣ�����ߡ��ұ�ͼƬ���һ��
		if (x < p2->x)
		{
			transparentimage(NULL, x, y, &fist[0][count_fist++], 0x000000);
			//ͼƬ�����Ҳ�Ϊ����״̬
			if (p2->x<x + img_x&&p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ��һ�ζ�����Ҫ��λ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			if (count_fist == 0 || count_fist == 3 || count_fist == 4)
				transparentimage(NULL, x, y, &fist[1][count_fist++], 0x000000);
			else
				transparentimage(NULL, x - 30, y, &fist[1][count_fist++], 0x000000);
			//ͬ��
			if (x - 20<p2->x + p2->img_x&&p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}

		}
		if (count_fist == 5)
		{
			count_fist = 0;
			flag = true;//��һ��ȭ�����Կ�Ѫ
		}
		Sleep(50);
	}

	//�Ȼ�
	void legAttack(role* p2) {
		img_x = leg[0][count_leg].getwidth();//��ǰͼƬ�Ŀ�ȣ�����ߡ��ұ�ͼƬ���һ��
		if (x < p2->x)
		{
			transparentimage(NULL, x, y, &leg[0][count_leg++], 0x000000);
			if (p2->x<x + img_x&&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			if (count_leg == 0 || count_leg == 1 || count_leg == 5 || count_leg == 6 || count_leg == 7)
				transparentimage(NULL, x, y, &leg[1][count_leg++], 0x000000);
			else
				transparentimage(NULL, x - 30, y, &leg[1][count_leg++], 0x000000);
			if (x - 25<p2->x + p2->img_x&&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_leg == 8)
		{
			count_leg = 0;
			flag = true;//��һ���Ȼ����Կ�Ѫ
		}
		Sleep(50);
	}

	//����1
	void skill_I(role* p2) {
		img_x = skill1[0][count_skill1].getwidth();//���ܿ��
		if (x < p2->x)
		{
			transparentimage(NULL, x, y, &skill1[0][count_skill1++], 0x000000);
			if (count_skill1 >= 5) //������Ч����ʱ����ͼ
			{
				transparentimage(NULL, x + 100, y, &skill1[0][count_skill1 + 5], 0x000000);
				//���ܵ�λ�ü��ϼ��ܿ�ȣ�ȷ����������
				if (p2->x<x + 100 + img_x && p2->action != 8 && flag)
				{
					flag = false;//һ��ֻ��һ��Ѫ
					p2->action = 9;//����״̬
					p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
				}
			}
		}
		else
		{
			transparentimage(NULL, x, y, &skill1[1][count_skill1++], 0x000000);
			if (count_skill1 >= 5) //������Ч����ʱ����ͼ
			{
				transparentimage(NULL, x - 70, y, &skill1[1][count_skill1 + 5], 0x000000);
				if (x<p2->x + 70 + img_x && p2->action != 8 && flag)
				{
					flag = false;//һ��ֻ��һ��Ѫ
					p2->action = 9;//����״̬
					p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
				}
			}
		}
		if (count_skill1 == 9)
		{
			count_skill1 = 0;
			flag = true;//��һ�μ���1���Կ�Ѫ
		}
		Sleep(50);
	}

	//����2
	void skill_II(role* p2) {
		img_x = skill2[0][count_skill2].getwidth();//���ܿ��
		if (x < p2->x) {
			transparentimage(NULL, x, y, &skill2[0][count_skill2++], 0x000000);
			transparentimage(NULL, x + 150, y, &skill2[0][count_skill2 + 7], 0x000000);
			//�뼼��1ͬ�� 
			if (p2->x<x + 150 + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			transparentimage(NULL, x, y, &skill2[1][count_skill2++], 0x000000);
			transparentimage(NULL, x - 120, y, &skill2[1][count_skill2 + 7], 0x000000);
			//ͬ��  
			if (x<p2->x + 120 + img_x && p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill2 == 6)
		{
			count_skill2 = 0;
			flag = true;//��һ�μ���2���Կ�Ѫ
		}
		Sleep(50);
	}

	//����3
	void skill_III(role* p2) {
		if (x < p2->x) {
			transparentimage(NULL, x, y, &skill3[0][count_skill3++], 0x000000);
			transparentimage(NULL, x + 200, y + 50, &skill3[0][count_skill3 + 9], 0x000000);
			//�ز����������迼���Ƿ�p2������Ծ״̬
			if (p2->x<x + 200 + img_x && p2->action != 8 && p2->action != 1 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			transparentimage(NULL, x, y, &skill3[1][count_skill3++], 0x000000);
			transparentimage(NULL, x - 260, y + 50, &skill3[1][count_skill3 + 9], 0x000000);
			//ͬ��
			if (x<p2->x + 260 + img_x && p2->action != 8 && p2->action != 1 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				p2->action = 9;//����״̬
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}

		}
		if (count_skill3 == 9)
		{
			count_skill3 = 0;
			flag = true;//��һ�μ���3���Կ�Ѫ
		}
		Sleep(30);
	}

	//����
	void Defend(role* p2) {
		if (x < p2->x)
			transparentimage(NULL, x, y + 20, &defend[0][0], 0x000000);
		else
			transparentimage(NULL, x, y + 20, &defend[1][0], 0x000000);
		Sleep(50);
	}


};
