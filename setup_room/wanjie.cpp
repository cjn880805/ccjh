#include "stdafx.h"
#include "../server/Room.h"


//��ٹ�
#include "../d/wanjie/wanjiecity.h"
#include "../d/wanjie/wanjie_bed_room.h"
#include "../d/wanjie/wanjie_bridge.h"
#include "../d/wanjie/wanjie_entrance.h"
#include "../d/wanjie/wanjie_grassland.h"
#include "../d/wanjie/wanjie_port.h"
#include "../d/wanjie/wanjie_port2.h"
#include "../d/wanjie/wanjie_riverside1.h"
#include "../d/wanjie/wanjie_riverside2.h"
#include "../d/wanjie/wanjie_riverside3.h"
#include "../d/wanjie/wanjie_shan_road1.h"
#include "../d/wanjie/wanjie_shan_road2.h"
#include "../d/wanjie/wanjie_shan_road3.h"
#include "../d/wanjie/wanjie_shan_road4.h"
#include "../d/wanjie/wanjie_slide.h"
#include "../d/wanjie/wanjie_stone_room.h"
#include "../d/wanjie/wanjie_xiaoting.h"
#include "../d/wanjie/wanjie_yaofang.h"

CRoom * Load_WanJie(string room_name)
{
	CRoom * r = NULL;

	//��ٹ�
    if(room_name == "��ٹ�")
		r = new CRWanJiecity();
    else if(room_name == "��ٹ�С��")
		r = new CRWanJie_xiaoting();
    else if(room_name == "��ٹ�ɽ��")
		r = new CRWanJie_slide();
    else if(room_name == "��ٹ�ɽ·4")
		r = new CRWanJie_shan_road4();
    else if(room_name == "��ٹ�ɽ·3")
		r = new CRWanJie_shan_road3();
    else if(room_name == "��ٹ�ɽ·2")
		r = new CRWanJie_shan_road2();
    else if(room_name == "��ٹ�ɽ·1")
		r = new CRWanJie_shan_road1();
    else if(room_name == "��ٹȽ���С·3")
		r = new CRWanJie_riverside3();
    else if(room_name == "��ٹȽ���С·2")
		r = new CRWanJie_riverside2();
    else if(room_name == "��ٹȽ���С·1")
		r = new CRWanJie_riverside1();
    else if(room_name == "��ٹ����׽���")
		r = new CRWanJie_port2();
    else if(room_name == "��ٹ����˶�")
		r = new CRWanJie_port();
    else if(room_name == "��ٹȲݵ�")
		r = new CRWanJie_grassland();
    else if(room_name == "��ٹȴ�ɭ��")
		r = new CRWanJie_entrance();
    else if(room_name == "��ٹ�����")
		r = new CRWanJie_bed_room();
    else if(room_name == "��ٹ�ҩ��")
		r = new CRWanJie_yaofang();
    else if(room_name == "��ٹ�ʯ��")
		r = new CRWanJie_stone_room();
    else if(room_name == "��ٹ�������")
		r = new CRWanJie_bridge();

	return r;
}