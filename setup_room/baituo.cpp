#include "stdafx.h"
#include "../std/RField.h"

//����ɽ
#include "../d/baituoshan/baituoshancity.h"
#include "../d/baituoshan/baituoshan_houmen.h"
#include "../d/baituoshan/baituoshan_houyuan.h"
#include "../d/baituoshan/baituoshan_huayuan.h"
#include "../d/baituoshan/baituoshan_jiudian.h"
#include "../d/baituoshan/baituoshan_liangong.h"
#include "../d/baituoshan/baituoshan_menlang.h"
#include "../d/baituoshan/baituoshan_neishi.h"
#include "../d/baituoshan/baituoshan_nongshe.h"
#include "../d/baituoshan/baituoshan_restroom.h"
#include "../d/baituoshan/baituoshan_shanlu.h"
#include "../d/baituoshan/baituoshan_shanlu1.h"
#include "../d/baituoshan/baituoshan_sheyuan.h"
#include "../d/baituoshan/baituoshan_shijie.h"
#include "../d/baituoshan/baituoshan_shoushe.h"
#include "../d/baituoshan/baituoshan_shulin.h"
#include "../d/baituoshan/baituoshan_shulin1.h"
#include "../d/baituoshan/baituoshan_storeroom.h"
#include "../d/baituoshan/baituoshan_tuyuan.h"
#include "../d/baituoshan/baituoshan_wuqiku.h"
#include "../d/baituoshan/baituoshan_xiaolu1.h"
#include "../d/baituoshan/baituoshan_xiaolu2.h"
#include "../d/baituoshan/baituoshan_xiaolu3.h"
#include "../d/baituoshan/baituoshan_xiaolu4.h"
#include "../d/baituoshan/baituoshan_xijie.h"
#include "../d/baituoshan/baituoshan_ximen.h"
#include "../d/baituoshan/baituoshan_yaofang.h"
#include "../d/baituoshan/baituoshan_yuanzi.h"
#include "../d/baituoshan/baituoshan_zhulin.h"
#include "../d/baituoshan/baituoshan_zhuyuan.h"
#include "../d/baituoshan/baituoshan_bridge.h"
#include "../d/baituoshan/baituoshan_caifang.h"
#include "../d/baituoshan/baituoshan_cao1.h"
#include "../d/baituoshan/baituoshan_cao2.h"
#include "../d/baituoshan/baituoshan_caomeide.h"
#include "../d/baituoshan/baituoshan_caoping.h"
#include "../d/baituoshan/baituoshan_cave.h"
#include "../d/baituoshan/baituoshan_changlang.h"
#include "../d/baituoshan/baituoshan_chufang.h"
#include "../d/baituoshan/baituoshan_damen.h"
#include "../d/baituoshan/baituoshan_datiepu.h"
#include "../d/baituoshan/baituoshan_dating.h"
#include "../d/baituoshan/baituoshan_dongjie.h"
#include "../d/baituoshan/baituoshan_dongkou.h"
#include "../d/baituoshan/baituoshan_dongnei.h"
#include "../d/baituoshan/baituoshan_fang.h"
#include "../d/baituoshan/baituoshan_fende.h"
#include "../d/baituoshan/baituoshan_gebi.h"
#include "../d/baituoshan/baituoshan_guangchang.h"

CRoom * Load_BaiTuo(string room_name)
{
	CRoom * r = NULL;

	//����ɽ
	if(room_name == "����ɽ")
		r = new CRBaiTuoShancity();
	else if(room_name == "����ɽ��԰")
		r = new CRBaiTuoShan_zhuyuan();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_zhulin();
	else if(room_name == "����ɽԺ��")
		r = new CRBaiTuoShan_yuanzi();
	else if(room_name == "����ɽҩ��")
		r = new CRBaiTuoShan_yaofang();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_ximen();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_xijie();
	else if(room_name == "����ɽ������")
		r = new CRBaiTuoShan_wuqiku();
	else if(room_name == "����ɽ��Է")
		r = new CRBaiTuoShan_tuyuan();
	else if(room_name == "����ɽ������")
		r = new CRBaiTuoShan_storeroom();
	else if(room_name == "����ɽ����1")
		r = new CRBaiTuoShan_shulin1();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_shulin();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_shoushe();
	else if(room_name == "����ɽʯ��")
		r = new CRBaiTuoShan_shijie();
	else if(room_name == "����ɽ��԰")
		r = new CRBaiTuoShan_sheyuan();
	else if(room_name == "����ɽɽ·1")
		r = new CRBaiTuoShan_shanlu1();
	else if(room_name == "����ɽɽ·")
		r = new CRBaiTuoShan_shanlu();
	else if(room_name == "����ɽ��Ϣ��")
		r = new CRBaiTuoShan_restroom();
	else if(room_name == "����ɽũ��")
		r = new CRBaiTuoShan_nongshe();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_neishi();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_menlang();
	else if(room_name == "����ɽ������")
		r = new CRBaiTuoShan_liangong();
	else if(room_name == "����ɽ�Ƶ�")
		r = new CRBaiTuoShan_jiudian();
	else if(room_name == "����ɽ��԰")
		r = new CRBaiTuoShan_huayuan();
	else if(room_name == "����ɽ��Ժ")
		r = new CRBaiTuoShan_houyuan();
	else if(room_name == "����ɽ�㳡")
		r = new CRBaiTuoShan_guangchang();
	else if(room_name == "����ɽ������")
		r = new CRBaiTuoShan_fang();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_dongjie();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_dating();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_damen();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_chufang();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_changlang();
	else if(room_name == "����ɽ�Ҷ�")
		r = new CRBaiTuoShan_cave();
	else if(room_name == "����ɽ��ƺ")
		r = new CRBaiTuoShan_caoping();
	else if(room_name == "����ɽ��ݮ��")
		r = new CRBaiTuoShan_caomeide();
	else if(room_name == "����ɽ�ݴ�2")
		r = new CRBaiTuoShan_cao2();
	else if(room_name == "����ɽ�ݴ�1")
		r = new CRBaiTuoShan_cao1();
	else if(room_name == "����ɽ��")
		r = new CRBaiTuoShan_caifang();
	else if(room_name == "����ɽС��")
		r = new CRBaiTuoShan_bridge();
	else if(room_name == "����ɽ������")
		r = new CRBaiTuoShan_datiepu();
	else if(room_name == "����ɽС·3")
		r = new CRBaiTuoShan_xiaolu3();
	else if(room_name == "����ɽС·2")
		r = new CRBaiTuoShan_xiaolu2();
	else if(room_name == "����ɽС·1")
		r = new CRBaiTuoShan_xiaolu1();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_houmen();
	else if(room_name == "����ɽ���")
		r = new CRBaiTuoShan_gebi();
	else if(room_name == "����ɽ�ص�")
		r = new CRBaiTuoShan_fende();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_dongnei();
	else if(room_name == "����ɽ����")
		r = new CRBaiTuoShan_dongkou();
	else if(room_name == "����ɽС·4")
		r = new CRBaiTuoShan_xiaolu4();

	return r;
}