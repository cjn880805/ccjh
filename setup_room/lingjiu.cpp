#include "stdafx.h"
#include "../server/Room.h"


//����
#include "../d/lingjiu/lingjiu_biguan.h"
#include "../d/lingjiu/lingjiu_caifeng.h"
#include "../d/lingjiu/lingjiu_changl1.h"
#include "../d/lingjiu/lingjiu_changl10.h"
#include "../d/lingjiu/lingjiu_changl11.h"
#include "../d/lingjiu/lingjiu_changl13.h"
#include "../d/lingjiu/lingjiu_changl14.h"
#include "../d/lingjiu/lingjiu_changl15.h"
#include "../d/lingjiu/lingjiu_changl3.h"
#include "../d/lingjiu/lingjiu_changl4.h"
#include "../d/lingjiu/lingjiu_changl5.h"
#include "../d/lingjiu/lingjiu_changl6.h"
#include "../d/lingjiu/lingjiu_changl7.h"
#include "../d/lingjiu/lingjiu_changl8.h"
#include "../d/lingjiu/lingjiu_changl9.h"
#include "../d/lingjiu/lingjiu_changlang12.h"
#include "../d/lingjiu/lingjiu_changlang2.h"
#include "../d/lingjiu/lingjiu_chufang.h"
#include "../d/lingjiu/lingjiu_daban.h"
#include "../d/lingjiu/lingjiu_dadao1.h"
#include "../d/lingjiu/lingjiu_dadao2.h"
#include "../d/lingjiu/lingjiu_damen.h"
#include "../d/lingjiu/lingjiu_dating.h"
#include "../d/lingjiu/lingjiu_huanyuan.h"
#include "../d/lingjiu/lingjiu_jian.h"
#include "../d/lingjiu/lingjiu_men1.h"
#include "../d/lingjiu/lingjiu_men2.h"
#include "../d/lingjiu/lingjiu_men3.h"
#include "../d/lingjiu/lingjiu_restroom.h"
#include "../d/lingjiu/lingjiu_shanjiao.h"
#include "../d/lingjiu/lingjiu_wuqiku.h"
#include "../d/lingjiu/lingjiu_xianchou.h"
#include "../d/lingjiu/lingjiu_xiaodao1.h"
#include "../d/lingjiu/lingjiu_xiaodao2.h"
#include "../d/lingjiu/lingjiu_xuanbing.h"
#include "../d/lingjiu/lingjiu_ya.h"
#include "../d/lingjiu/lingjiu_yan.h"
#include "../d/lingjiu/lingjiu_liangong.h"
#include "../d/lingjiu/lingjiu.h"

#include "../d/lingjiu/lingjiu_mishi.h"
#include "../d/lingjiu/lingjiu_midao1.h"
#include "../d/lingjiu/lingjiu_midao2.h"
#include "../d/lingjiu/lingjiu_midao3.h"

CRoom * Load_LingJiu(string room_name)
{
	CRoom * r = NULL;

	//����
	if(room_name == "����ʧ����")
		r = new CRLingJiu_yan();
	else if(room_name == "���նϻ���")
		r = new CRLingJiu_ya();
	else if(room_name == "����������")
		r = new CRLingJiu_xuanbing();
	else if(room_name == "����С��2")
		r = new CRLingJiu_xiaodao2();
	else if(room_name == "����С��1")
		r = new CRLingJiu_xiaodao1();
	else if(room_name == "�����ɳ���")
		r = new CRLingJiu_xianchou();
	else if(room_name == "����ޤ����")
		r = new CRLingJiu_wuqiku();
	else if(room_name == "������翷�ɽ��")
		r = new CRLingJiu_shanjiao();
	else if(room_name == "�������")
		r = new CRLingJiu_restroom();
	else if(room_name == "���ձչ��Ҵ���")
		r = new CRLingJiu_men3();
	else if(room_name == "�����鷿����")
		r = new CRLingJiu_men2();
	else if(room_name == "�������Ҵ���")
		r = new CRLingJiu_men1();
	else if(room_name == "����Ϸ���")
		r = new CRLingJiu_liangong();
	else if(room_name == "���հ��ɽ�")
		r = new CRLingJiu_jian();
	else if(room_name == "���ջ�԰")
		r = new CRLingJiu_huanyuan();
	else if(room_name == "���ն�����")
		r = new CRLingJiu_dating();
	else if(room_name == "���ն���������")
		r = new CRLingJiu_damen();
	else if(room_name == "������ʯ���2")
		r = new CRLingJiu_dadao2();
	else if(room_name == "������ʯ���1")
		r = new CRLingJiu_dadao1();
	else if(room_name == "����׺����")
		r = new CRLingJiu_daban();
	else if(room_name == "����ź���")
		r = new CRLingJiu_chufang();
	else if(room_name == "���ջ���2")
		r = new CRLingJiu_changlang2();
	else if(room_name == "���ջ���12")
		r = new CRLingJiu_changlang12();
	else if(room_name == "���ջ���9")
		r = new CRLingJiu_changl9();
	else if(room_name == "���ջ���8")
		r = new CRLingJiu_changl8();
	else if(room_name == "���ջ���7")
		r = new CRLingJiu_changl7();
	else if(room_name == "���ջ���6")
		r = new CRLingJiu_changl6();
	else if(room_name == "���ջ���5")
		r = new CRLingJiu_changl5();
	else if(room_name == "���ջ���4")
		r = new CRLingJiu_changl4();
	else if(room_name == "���ջ���3")
		r = new CRLingJiu_changl3();
	else if(room_name == "���ջ���15")
		r = new CRLingJiu_changl15();
	else if(room_name == "���ջ���14")
		r = new CRLingJiu_changl14();
	else if(room_name == "���ջ���13")
		r = new CRLingJiu_changl13();
	else if(room_name == "���ձչ���")
		r = new CRLingJiu_biguan();
	else if(room_name == "���ջ���10")
		r = new CRLingJiu_changl10();
	else if(room_name == "���ջ���1")
		r = new CRLingJiu_changl1();
	else if(room_name == "���������")
		r = new CRLingJiu_caifeng();
	else if(room_name == "���ջ���11")
		r = new CRLingJiu_changl11();
	else if(room_name == "���պ�ɽ�ܵ�1")
		r = new CRLingJiu_midao1();
	else if(room_name == "���պ�ɽ�ܵ�2")
		r = new CRLingJiu_midao2();
	else if(room_name == "���պ�ɽ�ܵ�3")
		r = new CRLingJiu_midao3();
	else if(room_name == "���պ�ɽʯ��")
		r = new CRLingJiu_mishi();
	else if(room_name == "����")
		r = new CRLingJiu();

	return r;
}