#include"Control.h"

IMAGE bg[5][20];//���ؼ��ױ������Ա����ѡ��
int count_bg = 0;
IMAGE hp;//Ѫ��
IMAGE pau;//��ͣ

int win = 0;

void loadbg()
{
	char buff[128];
	for (int m = 0; m < 2; m++)
		for (int i = 0; i < 8; i++)
		{
			sprintf(buff, "source\\background\\bg%d (%d).bmp", m + 1, i + 1);
			loadimage(&bg[m][i], buff, 640, 480);
		}
	loadimage(&hp, "source\\1.png");
}

//��Ѫ����ͷ��ʱ�䡢������
void draw_fight(role* p1, role* p2)
{
	//����ͼ
	if (bg_num == 0)
		if (count_bg == 8)
			count_bg = 0;
	else if (bg_num == 1)
		if (count_bg == 12)
			count_bg = 0;
	
	putimage(0, 0, &bg[bg_num][count_bg++]);


	//���ܵ�hp��ͷ��
	transparentimage(NULL, 10, 30, &hp, 0x000000);//�ܵ�Ѫ��

												  //P1ͷ��Ѫ��
	transparentimage(NULL, 0, 30, &p1->head[0][0], 0x000000);

	//P2ͷ��Ѫ��
	int x1 = 640 - p2->head[0][0].getwidth();
	transparentimage(NULL, x1, 30, &p2->head[1][0], 0x000000);

	fillpoly(4, p1->point);
	fillpoly(4, p2->point);
	setfillcolor(RED);

	//P1Ѫ���仯
	int p1_change = 100 - p1->blood;
	if (p1->blood < 0) //Ѫ��Ϊ��
	{
		p1->blood = 0;
		p1->point[0] = 51;
		p1->point[2] = 61;
	}
	else //δ����
	{
		p1->point[0] = 250 - (p1_change / 10) * 20;
		p1->point[2] = 260 - (p1_change / 10) * 20;
	}

	//P2Ѫ���仯
	int p2_change = 100 - p2->blood;
	if (p2->blood < 0) {
		p2->blood = 0;
		p2->point[4] = 590;
		p2->point[6] = 600;
	}
	else {
		p2->point[4] = 391 + (p2_change / 10) * 20;
		p2->point[6] = 401 + (p2_change / 10) * 20;
	}

	//һ����Ϸ����
	if (p1->blood <= 0)
		win = 2;
	else if (p2->blood <= 0)
		win = 1;

}

//����˫���������Ҫ����ʹ������������
void command(role* p1, role* p2) {
	BeginBatchDraw();

	draw_fight(p1, p2);//��ս����������Ѫ���仯������ͼ������ͷ��

					   /*action˵��
					   *	switch(action)
					   *		case 1:��Ծ;	case 2:ȭ��;
					   *		case 3:�Ȼ�;	case 4:����1;
					   *		case 5:����2;	case 6:����3;
					   *		case 7:�ƶ�;	case 8:����;
					   *		case 0:վ��;	case 9:����
					   */

					   //ʹP1�ĸ������첽��ʹP2�ĸ������첽
					   //P1����
	if (GetAsyncKeyState('S') & 0x8000 && (p1->action == 8 || p1->action == 0))
	{
		p1->action = 8;
		p1->Defend(p2);
	}
	else if (!(GetAsyncKeyState('S') & 0x8000) && p1->action == 8)
		p1->action = 0;


	//����״̬
	if (p1->action == 9) {
		p1->Beaten(p2);
		if (p1->count_beaten != 0)
			p1->action = 9;
		else
			p1->action = 0;
	}

	//������Ծ״̬ ��������Ծ��� coun_jump==0ʱ���
	if ((GetAsyncKeyState('W') & 0x8000 && p1->action == 0) || p1->action == 1) {
		p1->Jump(p2);
		if (p1->count_jump != 0)
			p1->action = 1;
		else
			p1->action = 0;
	}

	//���������Ծ״̬��������빥�����ͷż���״̬ 
	if (GetAsyncKeyState('J') & 0x8000 && p1->action == 0 || p1->action == 2) {
		p1->fistAttack(p2);
		if (p1->count_fist != 0)
			p1->action = 2;
		else
			p1->action = 0;
	}

	if (GetAsyncKeyState('K') & 0x8000 && p1->action == 0 || p1->action == 3) {
		p1->legAttack(p2);
		if (p1->count_leg != 0)
			p1->action = 3;
		else
			p1->action = 0;
	}

	//���ܱ�����ȫ�ͷ�
	if (GetAsyncKeyState('U') & 0x8000 && p1->action == 0 || p1->action == 4) {
		p1->skill_I(p2);
		if (p1->count_skill1 != 0)
			p1->action = 4;
		else
			p1->action = 0;
	}
	if (GetAsyncKeyState('I') & 0x8000 && p1->action == 0 || p1->action == 5) {
		p1->skill_II(p2);
		if (p1->count_skill2 != 0)
			p1->action = 5;
		else
			p1->action = 0;
	}
	if (GetAsyncKeyState('O') & 0x8000 && p1->action == 0 || p1->action == 6) {
		p1->skill_III(p2);
		if (p1->count_skill3 != 0)
			p1->action = 6;
		else
			p1->action = 0;
	}

	//���������Ծ�򹥻�ʩ��״̬ ������ƶ�
	if (GetAsyncKeyState('A') & 0x8000 && (p1->action == 0 || p1->action == 7)) {
		p1->LeftMove(p2);
		p1->action = 7;
	}

	if (GetAsyncKeyState('D') & 0x8000 && (p1->action == 0 || p1->action == 7)) {
		p1->RightMove(p2);
		p1->action = 7;
	}

	if (p1->action == 0) {
		p1->Stand(p2);
	}
	else if (p1->action == 7)
		p1->action = 0;



	//P2����
	//����״̬
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && (p2->action == 8 || p2->action == 0))
	{
		p2->action = 8;
		p2->Defend(p1);
	}
	else if (!(GetAsyncKeyState(VK_DOWN) & 0x8000) && p2->action == 8)
		p2->action = 0;

	//����״̬
	if (p2->action == 9) {
		p2->Beaten(p1);
		if (p2->count_beaten != 0)
			p2->action = 9;
		else
			p2->action = 0;
	}
	//������Ծ״̬ ��������Ծ��� coun_jump==0ʱ���
	if ((GetAsyncKeyState(VK_UP) & 0x8000 && p2->action == 0) || p2->action == 1) {
		p2->Jump(p1);
		if (p2->count_jump != 0)
			p2->action = 1;
		else
			p2->action = 0;
	}

	//���������Ծ״̬��������빥�����ͷż���״̬ 
	if (GetAsyncKeyState('Z') & 0x8000 & 0x8000 && p2->action == 0 || p2->action == 2) {
		p2->fistAttack(p1);
		if (p2->count_fist != 0)
			p2->action = 2;
		else
			p2->action = 0;
	}

	if (GetAsyncKeyState('X') & 0x8000 && p2->action == 0 || p2->action == 3) {
		p2->legAttack(p1);
		if (p2->count_leg != 0)
			p2->action = 3;
		else
			p2->action = 0;
	}

	//���ܱ�����ȫ�ͷ�
	if (GetAsyncKeyState('C') & 0x8000 && p2->action == 0 || p2->action == 4) {
		p2->skill_I(p1);
		if (p2->count_skill1 != 0)
			p2->action = 4;
		else
			p2->action = 0;
	}
	if (GetAsyncKeyState('V') & 0x8000 && p2->action == 0 || p2->action == 5) {
		p2->skill_II(p1);
		if (p2->count_skill2 != 0)
			p2->action = 5;
		else
			p2->action = 0;
	}
	if (GetAsyncKeyState('B') & 0x8000 && p2->action == 0 || p2->action == 6) {
		p2->skill_III(p1);
		if (p2->count_skill3 != 0)
			p2->action = 6;
		else
			p2->action = 0;
	}

	//���������Ծ�򹥻�ʩ��״̬ ������ƶ�
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && (p2->action == 0 || p2->action == 7)) {
		p2->LeftMove(p1);
		p2->action = 7;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && (p2->action == 0 || p2->action == 7)) {
		p2->RightMove(p1);
		p2->action = 7;
	}

	if (p2->action == 0) {
		p2->Stand(p1);
	}
	else if (p2->action == 7)
		p2->action = 0;
	EndBatchDraw();
}




int main()
{
	initgraph(640, 480);
	loadbg();

	/*  1P wasd ѡ�����jȷ��.jkluio������
	*	2P �������� ѡ�����1ȷ��,zxcvbn������
	*/
	Control c;
	c.start();
	bool repate = true;//�״�Ϊtrue
	while (repate)
	{
		c.select();//����ѡ��
		/*c.r1 = new Kula();
		c.r1->type = 1;
		//��ʼ������P1
		c.r1->x = 30;
		c.r1->y = 330;
		int a[8] = { 250,40,260,50,261,50,251,40 };
		for (int i = 0; i < 8; i++)
			c.r1->point[i] = a[i];

		c.r2 = new MaiShiranui();
		c.r2->type = 2;
		c.r2->x = 520;
		c.r2->y = 330;
		int b[8] = { 400,40,390,50,391,50,401,40 };
		for (int i = 0; i < 8; i++)
			c.r2->point[i] = b[i];*/
		while (1)
		{
			//��ͣ
			command(c.r1, c.r2);
			if (win != 0)break;
		}
		repate = c.end(win);
		win = 0;
		//����ֵΪtrue��������Ϸ
		//����ֵΪfalse���˳���Ϸ
	}
	return 0;
}
/*
�ȱ�һ�����Ȼ��
��������һ���ڰ��Լ�ѡ��������ƶ�������������д��
Ȼ���ڽ������������ƹ���

1����ʼ\�������������
��Ϸ�������(����ѡ�񣬽�����Ϸ���˳�������㱳�����֣�)
ѡ���������(����չʾ��ѡ��ͬ��)
��Ϸ��ʼǰ(Ѫ����ʱ�䡢����ѡ�񣬴��ڱ���Сͼչʾ)
��Ϸ������KO��ʱ�䵽0��ʤ��������ͼƬչʾ��Ȼ�����������Ϸ���˳�)

2����ս���������
������չʾ
���ϲ�����ͷ��Ѫ����ʱ����ʾ
��������С��ť(��ͣ�����ء�����)
����(������)��ô�仯

3����ս
P1\P2����λ�õı仯
��ײ���
�����벻����״̬��Ѫ��������

��ʱ�뵽��ô�࣬��ʱ���ٷֹ���
Ŷ�Ի��У�
����������ĩҪ��ʼд�ڶ����ĵ�����������
����Ҳ�������ˣ�����Ҫ����һ��д��
�����һ�β��Լƻ��ĵ���6����2����һ����
*/
