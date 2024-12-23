#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Npc.h"


// 重阳宫
#include "../d/chongyanggong/chongyang_chanfang.h"
#include "../d/chongyanggong/chongyang_damen.h"
#include "../d/chongyanggong/chongyang_diziju.h"
#include "../d/chongyanggong/chongyang_houshan.h"
#include "../d/chongyanggong/chongyang_jingxiushi.h"
#include "../d/chongyanggong/chongyang_liangong.h"
#include "../d/chongyanggong/chongyang_shantang.h"
#include "../d/chongyanggong/chongyang_xianzhentang.h"
#include "../d/chongyanggong/chongyang_xiaohuayuan1.h"
#include "../d/chongyanggong/chongyang_xiaohuayuan2.h"
#include "../d/chongyanggong/chongyang_xiaohuayuan3.h"
#include "../d/chongyanggong/chongyang_xiaolu.h"
#include "../d/chongyanggong/chongyang_xiuxishi.h"
#include "../d/chongyanggong/chongyang_yuzhengong.h"
#include "../d/chongyanggong/chongyanggong.h"

CRoom * Load_ChongYang(string room_name)
{
	CRoom * r = NULL;

// 重阳宫
	if(room_name == "重阳宫")
		r = new CRChongYang();
	else if(room_name == "重阳宫静修室")
		r = new CRChongYang_jingxiushi();
	else if(room_name == "重阳宫遇真宫")
		r = new CRChongYang_yuzhengong();
	else if(room_name == "重阳宫休息室")
		r = new CRChongYang_xiuxishi();
	else if(room_name == "重阳宫小路")
		r = new CRChongYang_xiaolu();
	else if(room_name == "重阳宫弟子居")
		r = new CRChongYang_diziju();
	else if(room_name == "重阳宫小花园3")
		r = new CRChongYang_xiaohuayuan3();
	else if(room_name == "重阳宫小花园2")
		r = new CRChongYang_xiaohuayuan2();
	else if(room_name == "重阳宫小花园1")
		r = new CRChongYang_xiaohuayuan1();
	else if(room_name == "重阳宫显真堂")
		r = new CRChongYang_xianzhentang();
	else if(room_name == "重阳宫膳堂")
		r = new CRChongYang_shantang();
	else if(room_name == "重阳宫练功房")
		r = new CRChongYang_liangong();
	else if(room_name == "重阳宫禅房")
		r = new CRChongYang_chanfang();
	else if(room_name == "重阳宫大门")
		r = new CRChongYang_damen();
	else if(room_name == "重阳宫后山")
		r = new CRChongYang_houshan();


	return r;
}