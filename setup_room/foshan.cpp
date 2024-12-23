#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../server/Channel.h"

//    ��ɽ
#include "../d/foshan/foshan_beidimiao.h" 
#include "../d/foshan/foshan_dangpu.h" 
#include "../d/foshan/foshan_eastgate.h" 
#include "../d/foshan/foshan_huiguan.h" 
#include "../d/foshan/foshan_nanling.h" 
#include "../d/foshan/foshan_northgate.h" 
#include "../d/foshan/foshan_road1.h" 
#include "../d/foshan/foshan_road10.h" 
#include "../d/foshan/foshan_road11.h" 
#include "../d/foshan/foshan_road12.h" 
#include "../d/foshan/foshan_road13.h" 
#include "../d/foshan/foshan_road14.h" 
#include "../d/foshan/foshan_road2.h" 
#include "../d/foshan/foshan_road3.h" 
#include "../d/foshan/foshan_road4.h" 
#include "../d/foshan/foshan_road5.h" 
#include "../d/foshan/foshan_road6.h" 
#include "../d/foshan/foshan_road7.h" 
#include "../d/foshan/foshan_road8.h" 
#include "../d/foshan/foshan_road9.h" 
#include "../d/foshan/foshan_southgate.h" 
#include "../d/foshan/foshan_westgate.h" 
#include "../d/foshan/foshan_yingxionglou.h" 
#include "../d/foshan/foshan_yingxionglou2.h" 
#include "../d/foshan/foshan_youtiaopu.h" 
#include "../d/foshan/foshan_dahai.h" 
#include "../d/foshan/foshancity.h"

CRoom * Load_FoShan(string room_name)
{
	CRoom * r = NULL;

	//    ��ɽ
	if(room_name == "��ɽ")
		r = new CRfoshancity();
	else if(room_name == "��ɽ�ձ�������")
		r = new CRFoShan_youtiaopu();
	else if(room_name == "��ɽӢ��¥")
		r = new CRFoShan_yingxionglou();
	else if(room_name == "��ɽ����")
		r = new CRFoShan_westgate();
	else if(room_name == "��ɽ����")
		r = new CRFoShan_southgate();
	else if(room_name == "��ɽ�ּ��9")
		r = new CRFoShan_road9();
	else if(room_name == "��ɽ�ּ��8")
		r = new CRFoShan_road8();
	else if(room_name == "��ɽ�ּ��7")
		r = new CRFoShan_road7();
	else if(room_name == "��ɽ�ּ��6")
		r = new CRFoShan_road6();
	else if(room_name == "��ɽ�ּ��5")
		r = new CRFoShan_road5();
	else if(room_name == "��ɽ�ּ��4")
		r = new CRFoShan_road4();
	else if(room_name == "��ɽ�ּ��3")
		r = new CRFoShan_road3();
	else if(room_name == "��ɽ�ּ��2")
		r = new CRFoShan_road2();
	else if(room_name == "��ɽ�ּ��14")
		r = new CRFoShan_road14();
	else if(room_name == "��ɽ�ּ��13")
		r = new CRFoShan_road13();
	else if(room_name == "��ɽ�ּ��12")
		r = new CRFoShan_road12();
	else if(room_name == "��ɽ�ּ��11")
		r = new CRFoShan_road11();
	else if(room_name == "��ɽ�ּ��10")
		r = new CRFoShan_road10();
	else if(room_name == "��ɽ�ּ��1")
		r = new CRFoShan_road1();
	else if(room_name == "��ɽ����")
		r = new CRFoShan_northgate();
	else if(room_name == "��ɽ������")
		r = new CRFoShan_beidimiao();
	else if(room_name == "��ɽӢ�ۻ��")
		r = new CRFoShan_huiguan();
	else if(room_name == "��ɽ����")
		r = new CRFoShan_eastgate();
	else if(room_name == "��ɽӢ�۵䵱")
		r = new CRFoShan_dangpu();
	else if(room_name == "��ɽ����ɽ��")
		r = new CRFoShan_nanling();
	else if(room_name == "��ɽӢ��¥��¥")
		r = new CRFoShan_yingxionglou2();
	else if(room_name == "��ɽ��")
		r = new CRFoShan_dahai();

	return r;
}