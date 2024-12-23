#include "stdafx.h"
#include "../server/Room.h"

//青城
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

	//青城
    if(room_name == "青城")
		r = new CRQingChengcity();
    else if(room_name == "青城祖师殿")
		r = new CRQingCheng_zushidian();		
    else if(room_name == "青城驻鹤庄")
		r = new CRQingCheng_zhuhezhuang();
    else if(room_name == "青城古银杏树")
		r = new CRQingCheng_yinxing();
    else if(room_name == "青城小桥")
		r = new CRQingCheng_xiaoqiao();
    else if(room_name == "青城听泉亭")
		r = new CRQingCheng_tingquanting();
    else if(room_name == "青城天师洞")
		r = new CRQingCheng_tianshidong();		
    else if(room_name == "青城天然图画")
		r = new CRQingCheng_tianran();
    else if(room_name == "青城松风观")
		r = new CRQingCheng_songfengguan();
    else if(room_name == "青城上清宫")
		r = new CRQingCheng_shangqing();
    else if(room_name == "青城三岛石")
		r = new CRQingCheng_sandaoshi();
    else if(room_name == "青城青石大道")
		r = new CRQingCheng_qcroad1();		
    else if(room_name == "青城山路2")
		r = new CRQingCheng_path2();
    else if(room_name == "青城朝阳洞")
		r = new CRQingCheng_chaoyangdong();
    else if(room_name == "青城盘建福宫")
		r = new CRQingCheng_jianfugong();
    else if(room_name == "青城呼应亭")
		r = new CRQingCheng_huyingting();
    else if(room_name == "青城古龙桥")
		r = new CRQingCheng_gulongqiao();		
    else if(room_name == "青城盘山磴道")
		r = new CRQingCheng_path1();
    else if(room_name == "青城三弯九倒")
		r = new CRQingCheng_sanwanjiudao();
	return r;
}