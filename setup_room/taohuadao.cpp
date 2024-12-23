#include "stdafx.h"
#include "../server/Room.h"


//�һ���
#include "../d/taohua/taohuacity.h"
#include "../d/taohua/taohua_bingqi.h"
#include "../d/taohua/taohua_chufang.h"
#include "../d/taohua/taohua_daojufang.h"
#include "../d/taohua/taohua_mudao.h"
#include "../d/taohua/taohua_shandong.h"
#include "../d/taohua/taohua_xiaoyuan.h"
#include "../d/taohua/taohua_wofang.h"
#include "../d/taohua/taohua_xaiowu.h"
#include "../d/taohua/taohua_xiguoshi.h"
#include "../d/taohua/taohua_xiuxishi.h"
#include "../d/taohua/taohua_zhengting.h"
#include "../d/taohua/taohua_shufang.h"
#include "../d/taohua/taohua_damen.h"
#include "../d/taohua/taohua_dahai.h"

CRoom * Load_TaoHuaDao(string room_name)
{
	CRoom * r = NULL;

	//�һ���
	if(room_name == "�һ���")
		r = new CRTaoHuacity();
    else if(room_name == "�һ���ɽׯ����")
		r = new CRTaoHua_zhengting();
    else if(room_name == "�һ����һ���")
		r = new CRTaoHua_xiuxishi();
    else if(room_name == "�һ���˼����")
		r = new CRTaoHua_xiguoshi();
    else if(room_name == "�һ���С��")
		r = new CRTaoHua_xaiowu();
    else if(room_name == "�һ����Է�")
		r = new CRTaoHua_wofang();
    else if(room_name == "�һ�ɽׯСԺ")
		r = new CRTaoHua_xiaoyuan();
    else if(room_name == "�һ���ɽ��")
		r = new CRTaoHua_shandong();
    else if(room_name == "�һ���Ĺ��")
		r = new CRTaoHua_mudao();
    else if(room_name == "�һ������߷�")
		r = new CRTaoHua_daojufang();
    else if(room_name == "�һ�������")
		r = new CRTaoHua_chufang();
    else if(room_name == "�һ���������")
		r = new CRTaoHua_bingqi();
    else if(room_name == "�һ�ɽׯ�鷿")
		r = new CRTaoHua_shufang();
    else if(room_name == "�һ�ɽׯ����")
		r = new CRTaoHua_damen();
    else if(room_name == "�һ�����")
		r = new CRTaoHua_dahai();

	return r;
}