#include "stdafx.h"
#include "../server/Room.h"

//÷ׯ
#include "../d/meizhuang/meizhuang_chufang.h"
#include "../d/meizhuang/meizhuang_dating.h"
#include "../d/meizhuang/meizhuang_gate.h"
#include "../d/meizhuang/meizhuang_huashi.h"
#include "../d/meizhuang/meizhuang_keting.h"
#include "../d/meizhuang/meizhuang_neitang.h"
#include "../d/meizhuang/meizhuang_neiyuan.h"
#include "../d/meizhuang/meizhuang_qhpo.h"
#include "../d/meizhuang/meizhuang_qishi.h"
#include "../d/meizhuang/meizhuang_senlin.h"
#include "../d/meizhuang/meizhuang_shijie.h"
#include "../d/meizhuang/meizhuang_shushi.h"
#include "../d/meizhuang/meizhuang_tianjing.h"
#include "../d/meizhuang/meizhuang_xiaodao.h"
#include "../d/meizhuang/meizhuang_xiaolu.h"
#include "../d/meizhuang/meizhuang_xiaowu.h"
#include "../d/meizhuang/meizhuang_xiaoyuan.h"
#include "../d/meizhuang/meizhuang_xiuxishi.h"
#include "../d/meizhuang/meizhuang_zoulang1.h"
#include "../d/meizhuang/meizhuang_zoulang2.h"
#include "../d/meizhuang/meizhuang_dixiashilao.h"

CRoom * Load_MeiZhuang(string room_name)
{
	CRoom * r = NULL;

	//÷ׯ
	if(room_name == "÷ׯ����2")
		r = new CRMeiZhuang_zoulang2();
	else if(room_name == "÷ׯ����1")
		r = new CRMeiZhuang_zoulang1();
	else if(room_name == "÷ׯ��Ϣ��")
		r = new CRMeiZhuang_xiuxishi();
	else if(room_name == "÷ׯ����СԺ")
		r = new CRMeiZhuang_xiaoyuan();
	else if(room_name == "÷ׯС��")
		r = new CRMeiZhuang_xiaowu();
	else if(room_name == "÷ׯ����С��")
		r = new CRMeiZhuang_xiaolu();
	else if(room_name == "÷ׯС·")
		r = new CRMeiZhuang_xiaodao();
	else if(room_name == "÷ׯ���쾮")
		r = new CRMeiZhuang_tianjing();
	else if(room_name == "÷ׯ����")
		r = new CRMeiZhuang_shushi();
	else if(room_name == "÷ׯ��ɽʯ��")
		r = new CRMeiZhuang_shijie();
	else if(room_name == "÷ׯ��ľ԰")
		r = new CRMeiZhuang_senlin();
	else if(room_name == "÷ׯ����")
		r = new CRMeiZhuang_qishi();
	else if(room_name == "÷ׯ�滱��")
		r = new CRMeiZhuang_qhpo();
	else if(room_name == "÷ׯ��Ժ")
		r = new CRMeiZhuang_neiyuan();
	else if(room_name == "÷ׯӭ��ͤ")
		r = new CRMeiZhuang_keting();
	else if(room_name == "÷ׯ����")
		r = new CRMeiZhuang_huashi();
	else if(room_name == "÷ׯ����")
		r = new CRMeiZhuang_gate();
	else if(room_name == "÷ׯ�������")
		r = new CRMeiZhuang_dating();
	else if(room_name == "÷ׯ����")
		r = new CRMeiZhuang_chufang();
	else if(room_name == "÷ׯƫ��")
		r = new CRMeiZhuang_neitang();
	else if(room_name == "÷ׯˮ��ʯ��")
		r = new CRMeiZhuang_dixiashilao();

	return r;
}