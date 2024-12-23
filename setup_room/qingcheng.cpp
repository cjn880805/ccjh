#include "stdafx.h"
#include "../server/Room.h"

//���
#include "../d/qingcheng/qingcheng_chaoyangdong.h"
#include "../d/qingcheng/qingcheng_gulongqiao.h"
#include "../d/qingcheng/qingcheng_huyingting.h"
#include "../d/qingcheng/qingcheng_jianfugong.h"
#include "../d/qingcheng/qingcheng_path1.h"
#include "../d/qingcheng/qingcheng_path2.h"
#include "../d/qingcheng/qingcheng_qcroad1.h"
#include "../d/qingcheng/qingcheng_sandaoshi.h"
#include "../d/qingcheng/qingcheng_shangqing.h"
#include "../d/qingcheng/qingcheng_songfengguan.h"
#include "../d/qingcheng/qingcheng_tianran.h"
#include "../d/qingcheng/qingcheng_tianshidong.h"
#include "../d/qingcheng/qingcheng_tingquanting.h"
#include "../d/qingcheng/qingcheng_xiaoqiao.h"
#include "../d/qingcheng/qingcheng_yinxing.h"
#include "../d/qingcheng/qingcheng_zhuhezhuang.h"
#include "../d/qingcheng/qingcheng_zushidian.h"
#include "../d/qingcheng/qingchengcity.h"

#include "../d/qingcheng/qingcheng_sanwanjiudao.h"

CRoom * Load_QingCheng(string room_name)
{
	CRoom * r = NULL;

	//���
    if(room_name == "���")
		r = new CRQingChengcity();
    else if(room_name == "�����ʦ��")
		r = new CRQingCheng_zushidian();		
    else if(room_name == "���פ��ׯ")
		r = new CRQingCheng_zhuhezhuang();
    else if(room_name == "��ǹ�������")
		r = new CRQingCheng_yinxing();
    else if(room_name == "���С��")
		r = new CRQingCheng_xiaoqiao();
    else if(room_name == "�����Ȫͤ")
		r = new CRQingCheng_tingquanting();
    else if(room_name == "�����ʦ��")
		r = new CRQingCheng_tianshidong();		
    else if(room_name == "�����Ȼͼ��")
		r = new CRQingCheng_tianran();
    else if(room_name == "����ɷ��")
		r = new CRQingCheng_songfengguan();
    else if(room_name == "������幬")
		r = new CRQingCheng_shangqing();
    else if(room_name == "�������ʯ")
		r = new CRQingCheng_sandaoshi();
    else if(room_name == "�����ʯ���")
		r = new CRQingCheng_qcroad1();		
    else if(room_name == "���ɽ·2")
		r = new CRQingCheng_path2();
    else if(room_name == "��ǳ�����")
		r = new CRQingCheng_chaoyangdong();
    else if(room_name == "����̽�����")
		r = new CRQingCheng_jianfugong();
    else if(room_name == "��Ǻ�Ӧͤ")
		r = new CRQingCheng_huyingting();
    else if(room_name == "��ǹ�����")
		r = new CRQingCheng_gulongqiao();		
    else if(room_name == "�����ɽ���")
		r = new CRQingCheng_path1();
    else if(room_name == "�������ŵ�")
		r = new CRQingCheng_sanwanjiudao();
	return r;
}