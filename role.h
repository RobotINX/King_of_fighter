#pragma once
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<windows.h>
// ���øÿ����ʹ�� TransparentBlt ����
#pragma comment(lib, "MSIMG32.LIB")

/* ͸����ͼ����
   ������
		dstimg: Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
		x, y:	Ŀ����ͼλ��
		srcimg: Դ IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
		transparentcolor: ͸��ɫ��srcimg �ĸ���ɫ�����Ḵ�Ƶ� dstimg �ϣ��Ӷ�ʵ��͸����ͼ
*/
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// ʹ�� Windows GDI ����ʵ��͸��λͼ
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}
using namespace std;

class role {
public:
	int type = 1;//��ɫ����P1/P2
	string name;
	int x, y;//λ��;
	int img_x;//��ǰͼƬ���ͼƬ
	int point[8];
	int fan_x;
	int blood = 100;//Ѫ��
	int direction;//վ������
	int count_stand = 0;
	int count_move = 0;
	int count_jump = 0;
	int count_fist = 0;
	int count_leg = 0;
	int count_skill1 = 0;
	int count_skill2 = 0;
	int count_skill3 = 0;
	int count_beaten = 0;
	int count_defend = 0;
	int action = 0;//���и��ֻ�ı�ʶ
	IMAGE head[2][1];//ͷ����ͼ
public:
	virtual void InitImage() = 0;//��Դ��ʼ��
	virtual void Stand(role* p2) = 0;//վ������
	virtual void RightMove(role* p2) = 0;//��ɫ����
	virtual void LeftMove(role* p2) = 0;//��ɫ����
	virtual void Jump(role* p2) = 0;//��ɫ��Ծ
	virtual void fistAttack(role* p2) = 0;//ȭ��
	virtual void legAttack(role* p2) = 0;//�Ȼ�
	virtual void skill_I(role* p2) = 0;//����1
	virtual void skill_II(role* p2) = 0;//����2
	virtual void skill_III(role* p2) = 0;//����3
	//virtual void JumpBack(role *p2) = 0;
	//virtual void Combine1(role *p2) = 0;
	//virtual void Combine2(role *p2) = 0;
	virtual void Beaten(role *p2) = 0;
	virtual void Defend(role* p2) = 0;//����
	bool ifcollide(role* p2)
	{
		return (abs(x - p2->x) <= 70 && abs(y - p2->y) <= 50);
	}

	role()
	{

	}
};
