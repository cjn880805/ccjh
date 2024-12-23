#include "stdafx.h"
#include "../server/Room.h"

//Ã·×¯
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

	//Ã·×¯
	if(room_name == "Ã·×¯×ßÀÈ2")
		r = new CRMeiZhuang_zoulang2();
	else if(room_name == "Ã·×¯×ßÀÈ1")
		r = new CRMeiZhuang_zoulang1();
	else if(room_name == "Ã·×¯ÐÝÏ¢ÊÒ")
		r = new CRMeiZhuang_xiuxishi();
	else if(room_name == "Ã·×¯ÇÙÒôÐ¡Ôº")
		r = new CRMeiZhuang_xiaoyuan();
	else if(room_name == "Ã·×¯Ð¡ÎÝ")
		r = new CRMeiZhuang_xiaowu();
	else if(room_name == "Ã·×¯òêÑÑÐ¡¾¶")
		r = new CRMeiZhuang_xiaolu();
	else if(room_name == "Ã·×¯Ð¡Â·")
		r = new CRMeiZhuang_xiaodao();
	else if(room_name == "Ã·×¯´óÌì¾®")
		r = new CRMeiZhuang_tianjing();
	else if(room_name == "Ã·×¯ÊéÊÒ")
		r = new CRMeiZhuang_shushi();
	else if(room_name == "Ã·×¯¹ÂÉ½Ê¯¼¶")
		r = new CRMeiZhuang_shijie();
	else if(room_name == "Ã·×¯°ÙÄ¾Ô°")
		r = new CRMeiZhuang_senlin();
	else if(room_name == "Ã·×¯ÆåÊÒ")
		r = new CRMeiZhuang_qishi();
	else if(room_name == "Ã·×¯Ææ»±ÆÂ")
		r = new CRMeiZhuang_qhpo();
	else if(room_name == "Ã·×¯ÄÚÔº")
		r = new CRMeiZhuang_neiyuan();
	else if(room_name == "Ã·×¯Ó­¿ÍÍ¤")
		r = new CRMeiZhuang_keting();
	else if(room_name == "Ã·×¯»­ÊÒ")
		r = new CRMeiZhuang_huashi();
	else if(room_name == "Ã·×¯´óÃÅ")
		r = new CRMeiZhuang_gate();
	else if(room_name == "Ã·×¯ËÄÑÅÇå·ç")
		r = new CRMeiZhuang_dating();
	else if(room_name == "Ã·×¯³ø·¿")
		r = new CRMeiZhuang_chufang();
	else if(room_name == "Ã·×¯Æ«·¿")
		r = new CRMeiZhuang_neitang();
	else if(room_name == "Ã·×¯Ë®ÏÂÊ¯ÀÎ")
		r = new CRMeiZhuang_dixiashilao();

	return r;
}