#pragma once
#include"role.h"

class Kula :public role
{
	int count_move_front = 0;
	int count_move_back = 0;
	int count_jumpback = 0;
	
	bool flag = true;//ֻ����һ�ο�Ѫ
	IMAGE stand[2][18];//վ��ͼƬ
	IMAGE jump[2][9];//��ԾͼƬ
	IMAGE move_front[2][10];//ǰ��ͼƬ
	IMAGE move_back[2][10];//����
	IMAGE jumpback[2][5];//˫�����Ƽ�
	IMAGE fist[2][11];//ȭ��ͼƬ
	IMAGE leg[2][10];//�Ȼ�ͼƬ
	IMAGE skill1[2][14];//����1ͼƬ
	IMAGE skill2[2][24];//����2ͼƬ
	IMAGE skill3[2][22];//����3ͼƬ
	IMAGE bepang[2][4];//����
	IMAGE defend[2][2];//����ͼƬ
public:
	Kula()
	{
		name = "Kula";
		this->InitImage();
		y = 330;
	}
	void InitImage()
	{
		char buff[128];//ͼƬ��Դ·��

		//����ͷ��
		//for (int m = 0; m <= 1; m++)
		loadimage(&head[0][0], "source\\Kula\\����2_ͷ��.png", 50, 50);
		loadimage(&head[1][0], "source\\Kula\\����1_ͷ��.png", 50, 50);

		//����վ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 20; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_վ�� (%d).png", m + 1, i + 1);
				loadimage(&stand[m][i], buff);
			}

		//������ԾͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 9; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_��Ծ (%d).png", m + 1, i + 1);
				loadimage(&jump[m][i], buff);
			}
		//�����ƶ�ͼƬ
		for (int m = 0; m <= 1; m++)//��
			for (int i = 0; i < 10; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_ǰ�� (%d).png", m + 1, i + 1);
				loadimage(&move_front[m][i], buff);
			}
		for (int m = 0; m <= 1; m++)//��
			for (int i = 0; i < 10; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_���� (%d).png", m + 1, i + 1);
				loadimage(&move_back[m][i], buff);
			}
		//����
		for (int m = 0; m <= 1; m++)//��
			for (int i = 0; i < 5; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_���� (%d).png", m + 1, i + 1);
				loadimage(&jumpback[m][i], buff);
			}
		//����ȭ��ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 11; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_ȭ�� (%d).png", m + 1, i + 1);
				loadimage(&fist[m][i], buff);
			}
		//�����Ȼ�ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 10; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_�Ȼ� (%d).png", m + 1, i + 1);
				loadimage(&leg[m][i], buff);
			}
		//���ؼ���1ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 14; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_ ����I (%d).png", m + 1, i + 1);
				loadimage(&skill1[m][i], buff);
			}

		//���ؼ���2ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 24; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_����II (%d).png", m + 1, i + 1);
				loadimage(&skill2[m][i], buff);
			}

		//���ؼ���3ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 22; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_����III (%d).png", m + 1, i + 1);
					loadimage(&skill3[m][i], buff);
			}
		

		//���ر���ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 4; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_���� (%d).png", m + 1, i + 1);
				loadimage(&bepang[m][i], buff);
			}

		//���ط���ͼƬ
		for (int m = 0; m <= 1; m++)
			for (int i = 0; i < 2; i++)
			{
				sprintf(buff, "source\\Kula\\����%d_ ���� (%d).png", m + 1, i + 1);
				loadimage(&defend[m][i], buff);
			}

	}

	void Stand(role* p2)
	{
		img_x = stand[0][count_stand].getwidth();
		if (x < p2->x)//�����
		{			
			if (count_stand >= 7 && count_stand < 13)
				transparentimage(NULL, x - 3, y - 10, &stand[0][count_stand++], 0x000000);
			else
				transparentimage(NULL, x, y - 10, &stand[0][count_stand++], 0x000000);
		}
		else//���ұ�
		{
			if (count_stand >= 7 && count_stand < 13)
				transparentimage(NULL, x - 3, y - 10, &stand[1][count_stand++], 0x000000);
			else
				transparentimage(NULL, x, y - 10, &stand[1][count_stand++], 0x000000);
		}
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
		{
			img_x = move_front[0][count_move_front].getwidth();
			transparentimage(NULL, x, y - 10, &move_front[0][count_move_front++], 0x000000);
		}
		else//���ұߣ������
		{
			img_x = move_back[1][count_move_back].getwidth();
			transparentimage(NULL, x, y - 10, &move_back[1][count_move_back++], 0x000000);
		}
		if (count_move_front == 10)count_move_front = 0;
		if (count_move_back == 10)count_move_back = 0;
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
		{
			img_x = move_back[0][count_move_back].getwidth();
			transparentimage(NULL, x, y - 10, &move_back[0][count_move_back++], 0x000000);
		}
		else//���ұߣ������
		{
			img_x = move_front[1][count_move_front].getwidth();
			transparentimage(NULL, x, y - 10, &move_front[1][count_move_front++], 0x000000);
		}
		if (count_move_front == 10)count_move_front = 0;
		if (count_move_back == 10)count_move_back = 0;
		Sleep(50);
	}

	
	void Jump(role* p2)
	{
		img_x = jump[0][count_jump].getwidth();
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
			transparentimage(NULL, x, y - 10, &jump[0][count_jump++], 0x000000);
		else
			transparentimage(NULL, x, y - 10, &jump[1][count_jump++], 0x000000);
		if (count_jump == 9)count_jump = 0;
		Sleep(50);
	}

	void fistAttack(role* p2)
	{
		img_x = fist[0][count_fist].getwidth();
		if (x < p2->x) {
			if (count_fist >= 2 && count_fist<10)
				transparentimage(NULL, x, y -5, &fist[0][count_fist++], 0x000000);
			else
				transparentimage(NULL, x, y - 10, &fist[0][count_fist++], 0x000000);

			//ͼƬ�����Ҳ�Ϊ����״̬
			//img_xΪ��ʱͼƬ�Ŀ��,��leg[0][count_leg].getWidth()������
			//ifcollide(p2) &&p2->x<x + img_x
			if (ifcollide(p2) &&p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			if (count_fist >= 2 && count_fist<10)
				transparentimage(NULL, x - 20, y -5, &fist[1][count_fist++], 0x000000);
			else
				transparentimage(NULL, x - 20, y - 10, &fist[1][count_fist++], 0x000000);

			//p1���ұߣ�ȭ�����
			//img_xΪ��ʱͼƬ�Ŀ��
			//  x - 20<p2->x + p2->img_x
			if (ifcollide(p2) &&p2->action != 8 && flag)
			{
				flag = false;//һ��ȭ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_fist == 11)
		{
			count_fist = 0;
			flag = true;//��һ��ȭ�����Կ��˺�
		}
		Sleep(10);
	}

	void legAttack(role* p2)
	{
		img_x = leg[0][count_leg].getwidth();
		int dis_y;
		dis_y = leg[0][count_leg].getheight() - leg[0][0].getheight();
		if (x < p2->x)
		{
			if (count_leg >= 3 && count_leg < 7)
				if (x>25)
					transparentimage(NULL, x - 25, y - dis_y - 2, &leg[0][count_leg++], 0x000000);
				else
					transparentimage(NULL, 0, y - dis_y - 2, &leg[0][count_leg++], 0x000000);
			else
				if (x > 25)
					transparentimage(NULL, x - 25, y - dis_y - 2, &leg[0][count_leg++], 0x000000);
				else
					transparentimage(NULL, 0, y - dis_y - 2, &leg[0][count_leg++], 0x000000);

			//ͼƬ�����Ҳ�Ϊ����״̬   
			//img_xΪ��ʱͼƬ�Ŀ��
			//ifcollide(p2)  p2->x <x + img_x
			if (ifcollide(p2) &&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else
		{
			if (count_leg >= 3 && count_leg < 7)
				if (x>25)
					transparentimage(NULL, x - 25, y - dis_y - 2 , &leg[1][count_leg++], 0x000000);
				else
					transparentimage(NULL, 0, y - dis_y - 2, &leg[1][count_leg++], 0x000000);
			else
				if (x > 25)
					transparentimage(NULL, x - 25, y - dis_y - 2, &leg[1][count_leg++], 0x000000);
				else
					transparentimage(NULL, 0, y - dis_y - 2, &leg[1][count_leg++], 0x000000);

			//ͼƬ�����Ҳ�Ϊ����״̬   
			//ifcollide(p2)  x - 25<p2->x + p2->img_x
			if (ifcollide(p2) &&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}

		if (count_leg == 10)
		{
			count_leg = 0;
			flag = true;
		}
		Sleep(10);
	}

	void skill_I(role* p2)
	{
		img_x = skill1[0][count_skill1].getwidth();
		if (x < p2->x) {
			x += 10;
			transparentimage(NULL, x, y - 22, &skill1[0][count_skill1++], 0x000000);
			//ͼƬ�����Ҳ�Ϊ����״̬   
			//ifcollide(p2)  p2->x<x + img_x
			if (ifcollide(p2) &&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			x -= 10;
			transparentimage(NULL, x, y - 22, &skill1[1][count_skill1++], 0x000000);
			//ͼƬ�����Ҳ�Ϊ����״̬   
			//ifcollide(p2)  x<p2->x + p2->img_x
			if (ifcollide(p2) &&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 10;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill1 == 14)
		{
			count_skill1 = 0;
			flag = true;
		}
		Sleep(20);
	}

	void skill_II(role* p2)
	{
		img_x = skill2[0][count_skill2].getwidth();
		int ex = 0;
		int dis_y;
		dis_y = skill2[0][count_skill2].getheight() - skill2[0][0].getheight();
		if (x < p2->x) {
			if (count_skill2 <= 7)
				transparentimage(NULL, x, y - dis_y - 17, &skill2[0][count_skill2++], 0x000000);
			else
			{
				if (count_skill2 == 14)
					transparentimage(NULL, x - 35, y - dis_y + 3, &skill2[0][count_skill2++], 0x000000);
				else if (count_skill2 == 8)
					transparentimage(NULL, x - 35, y - dis_y + 3, &skill2[0][count_skill2++], 0x000000);
				else
					transparentimage(NULL, x - 10, y - dis_y - 17, &skill2[0][count_skill2++], 0x000000);

				if (x + 400 < 530)
				{
					ex = 400;
					transparentimage(NULL, x + 400, y - dis_y + 3, &skill2[0][count_skill2 + 8], 0x000000);
				}
				else
				{
					ex = 530 - skill2[0][count_skill2 + 8].getwidth();//��ȥͼƬ�Ŀ��
					transparentimage(NULL, 530, y - dis_y + 3, &skill2[0][count_skill2 + 8], 0x000000);
				}

				if (count_skill2 == 14)
					Sleep(200);
			}
			//�����з��������������������������Ҳ�Ϊ����״̬
			//��������Ƿ�һ�������ж��˺�ʱӦ�Ǳ��������˶����Ҳ�������exΪ�����뱾���λ��    
			if (x + ex + skill2[0][count_skill2 + 8].getwidth()>p2->x//����ͼ�ұ߳�������x
				&&x + ex<p2->x + p2->img_x//����ͼ��ߣ�δ��������ͼ���
				&&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			if (count_skill2 <= 7)
			{
				transparentimage(NULL, x, y - dis_y - 17, &skill2[1][count_skill2++], 0x000000);
			}
			else
			{
				if (count_skill2 == 14)
					transparentimage(NULL, x - 35, y - dis_y + 3, &skill2[1][count_skill2++], 0x000000);
				else if (count_skill2 == 8)
					transparentimage(NULL, x - 35, y - dis_y + 3, &skill2[1][count_skill2++], 0x000000);
				else
					transparentimage(NULL, x - 10, y - dis_y - 17, &skill2[1][count_skill2++], 0x000000);

				if (x - 400 > 0)
				{
					ex = 400;
					transparentimage(NULL, x - 400, y - dis_y + 3, &skill2[1][count_skill2 + 8], 0x000000);
				}
				else
				{
					ex = x-skill2[0][count_skill2 + 8].getwidth();//0+ͼƬ�Ŀ��
					transparentimage(NULL, 0, y - dis_y + 3, &skill2[1][count_skill2 + 8], 0x000000);
				}
				if (count_skill2 == 14)
					Sleep(200);
			}
			//�����з��������������������������Ҳ�Ϊ����״̬
			//��������Ƿ�һ�������ж��˺�ʱӦ�Ǳ��������˶����Ҳ�������exΪ�����뱾���λ��    
			if (x - ex<p2->x + p2->img_x//����ͼ��������ͼ�ұ�
				&&x - ex - skill2[1][count_skill2 + 8].getwidth()>p2->x//����ͼ�ұ�δ��������ͼ���
				&&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill2 == 16)
		{
			flag = true;
			count_skill2 = 0;
		}
		Sleep(20);
	}

	void skill_III(role* p2)
	{
		img_x = skill3[0][count_skill3].getwidth();
		int dis_x, dis_y1, dis_y2;
		dis_y1 = skill3[0][count_skill3].getheight() - skill3[0][0].getheight();
		dis_y2 = skill3[0][count_skill3 + 10].getheight() - skill3[0][14].getheight();
		dis_x = count_skill3 - 3>0 ? count_skill3 - 3 : 0;
		if (x < p2->x) {
			if (count_skill3 < 4)
				transparentimage(NULL, x, y - 11 - dis_y1, &skill3[0][count_skill3++], 0x000000);
			else if (count_skill3 >= 4 && count_skill3 <= 11)
			{
				transparentimage(NULL, x, y - 11 - dis_y1, &skill3[0][count_skill3++], 0x000000);
				//����ͼ
				if (count_skill3 == 7 || count_skill3 == 8)
					transparentimage(NULL, x + (dis_x + 2) * 30, y - dis_y2 + 22, &skill3[0][count_skill3 + 10], 0x000000);
				else if (count_skill3 == 11)
					transparentimage(NULL, x + (dis_x + 2) * 30, y - dis_y2 + 42, &skill3[0][count_skill3 + 10], 0x000000);
				else
					transparentimage(NULL, x + (dis_x + 2) * 30, y - dis_y2 + 32, &skill3[0][count_skill3 + 10], 0x000000);
				Sleep(100);
			}
			else
				transparentimage(NULL, x, y - 12 - dis_y1, &skill3[0][count_skill3++], 0x000000);
			//�����������ײ
			if (x + (dis_x + 2) * 30>p2->x&&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		else {
			if (count_skill3 < 4)
				transparentimage(NULL, x, y - 12 - dis_y1, &skill3[1][count_skill3++], 0x000000);
			else if (count_skill3 >= 4 && count_skill3 <= 11)
			{
				dis_x = count_skill3 - 3>0 ? count_skill3 - 3 : 0;
				transparentimage(NULL, x, y - 25 - dis_y1, &skill3[1][count_skill3++], 0x000000);
				if (count_skill3 == 7 || count_skill3 == 8)
					transparentimage(NULL, x - (dis_x + 2) * 30, y - dis_y2 + 22, &skill3[1][count_skill3 + 10], 0x000000);
				else if (count_skill3 == 11)
					transparentimage(NULL, x - (dis_x + 2) * 30, y - dis_y2 + 42, &skill3[1][count_skill3 + 10], 0x000000);
				else
					transparentimage(NULL, x - (dis_x + 2) * 30, y - dis_y2 + 32, &skill3[1][count_skill3 + 10], 0x000000);
				Sleep(100);
			}
			else
				transparentimage(NULL, x, y - 12 - dis_y1, &skill3[1][count_skill3++], 0x000000);
			//�����������ײ
			if (x - (dis_x + 2) * 30<p2->x+p2->img_x&&p2->action != 8 && flag)
			{
				flag = false;//һ��ֻ��һ��Ѫ
				//p2->Beaten(this);//��ʾ����
				p2->action = 9;
				p2->blood -= 20;//��Ѫ�������Ѫ������Ѫ��
			}
		}
		if (count_skill3 == 14)
		{
			flag = true;
			count_skill3 = 0;
		}
		Sleep(30);
	}


	void Beaten(role *p2)
	{
		if (x < p2->x) {
			transparentimage(NULL, x, y - 11, &bepang[0][count_beaten++], 0x000000);
		}
		else {
			transparentimage(NULL, x, y - 11, &bepang[1][count_beaten++], 0x000000);
		}
		
		if (count_beaten == 4)count_beaten = 0;
		Sleep(30);
	}
	void Defend(role* p2)
	{
		img_x = defend[0][0].getwidth();
		if (x < p2->x)//�����
		{
			transparentimage(NULL, x, y - 11, &defend[0][0], 0x000000);
			transparentimage(NULL, x + img_x, y - 11, &defend[0][1], 0x000000);
		}
		else//���ұ�
		{
			img_x = defend[0][0].getwidth()-20;
			transparentimage(NULL, x, y - 11, &defend[1][0], 0x000000);
			transparentimage(NULL, x - img_x, y - 11, &defend[1][1], 0x000000);
		}
		//if (count_stand == 18)count_stand = 0;//�ظ�
		Sleep(50);
	}

		/*void Combine1(role *p2)
		{
			if (x < p2->x) {
				x += 15;
				transparentimage(NULL, x, y - 30, &combine1[0][count_combine1++], 0x000000);
			}
			else {
				x -= 15;
				transparentimage(NULL, x, y - 30, &combine1[1][count_combine1++], 0x000000);

			}
			if (count_combine1 == 7)count_combine1 = 0;
			Sleep(30);
		}

		void Combine2(role *p2)
		{
			int dis_x = combine2[0][1].getwidth();
			int dis_y = combine2[0][1].getheight() / 6;
			if (x < p2->x) {
				if (count_combine2 <= 1)
					transparentimage(NULL, x, y - 13, &combine2[0][count_combine2++], 0x000000);
				else
				{
					transparentimage(NULL, x, y - 13, &combine2[0][1], 0x000000);
					transparentimage(NULL, x + dis_x - 2, y - dis_y + 12, &combine2[0][count_combine2++], 0x000000);
				}
			}
			else {
				if (count_combine2 <= 1)
					transparentimage(NULL, x, y - 13, &combine2[1][count_combine2++], 0x000000);
				else
				{
					dis_x = x - combine2[1][count_combine2].getwidth();
					transparentimage(NULL, x, y - 13, &combine2[1][1], 0x000000);
					transparentimage(NULL,dis_x - 2, y - dis_y + 12, &combine2[1][count_combine2++], 0x000000);
				}

			}
			if (count_combine2 == 15)count_combine2 = 0;
			Sleep(10);
		}
		void JumpBack(role* p2)
	{
		if (x < p2->x)//�����,���ұ�
		{
			x -= 25;//��������
			if (x <= 0)x = 0;//�߽��ж�
			transparentimage(NULL, x, y - 13, &jumpback[0][count_jumpback++], 0x000000);
		}
		else//���ұߣ������
		{
			x += 25;//��������
			if (x >= 540)x = 540;//�߽��ж�
			transparentimage(NULL, x, y - 13, &jumpback[1][count_jumpback++], 0x000000);
		}
		if (count_jumpback == 5)count_jumpback = 0;
		Sleep(50);
	}
	
		*/
};