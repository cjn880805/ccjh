#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//     ÏåÑô³Ç
#include "../d/xiangyang/xiangyangcity.h"
#include "../d/xiangyang/xiangyang_anfugate.h"
#include "../d/xiangyang/xiangyang_biaoju.h"
#include "../d/xiangyang/xiangyang_bingying1.h"
#include "../d/xiangyang/xiangyang_bingying2.h"
#include "../d/xiangyang/xiangyang_bingying3.h"
#include "../d/xiangyang/xiangyang_bingying4.h"
#include "../d/xiangyang/xiangyang_chaguan.h"
#include "../d/xiangyang/xiangyang_dangpu.h"
#include "../d/xiangyang/xiangyang_daxiaochang.h"
#include "../d/xiangyang/xiangyang_duchang.h"
#include "../d/xiangyang/xiangyang_guofugate.h"
#include "../d/xiangyang/xiangyang_jiangjungate.h"
#include "../d/xiangyang/xiangyang_juyiguan.h"
#include "../d/xiangyang/xiangyang_kedian.h"
#include "../d/xiangyang/xiangyang_majiu.h"
#include "../d/xiangyang/xiangyang_minju1.h"
#include "../d/xiangyang/xiangyang_minju2.h"
#include "../d/xiangyang/xiangyang_mixianglou.h"
#include "../d/xiangyang/xiangyang_mujiang.h"
#include "../d/xiangyang/xiangyang_qianzhuang.h"
#include "../d/xiangyang/xiangyang_shudian.h"
#include "../d/xiangyang/xiangyang_tiejiangpu.h"
#include "../d/xiangyang/xiangyang_xinluofang.h"
#include "../d/xiangyang/xiangyang_xuetang.h"
#include "../d/xiangyang/xiangyang_yaopu.h"
#include "../d/xiangyang/xiangyang_zhonglie.h"
#include "../d/xiangyang/xiangyang_caodi.h"
#include "../d/xiangyang/xiangyang_caodi1.h"

#include "../d/xiangyang/xiangyang_dongbei.h"
#include "../d/xiangyang/xiangyang_dongnan.h"
#include "../d/xiangyang/xiangyang_xinan.h"
#include "../d/xiangyang/xiangyang_xibei.h"

//ÔØÈëÏåÑô³Ç
CRoom * Load_XiangYang(string room_name)
{
	CRoom * r =NULL;

	//     ÏåÑô³Ç
	if(room_name == "ÏåÑô³Ç")
		r = new CRXiangYangCity();
	else if(room_name == "ÏåÑô°²¸§Ê¹ÑÃÃÅ")
		r = new CRXiangYang_anfugate();
	else if(room_name == "ÏåÑô¸£ÍşïÚ¾Ö")
		r = new CRXiangYang_biaoju();
	else if(room_name == "ÏåÑô±±±øÓª")
		r = new CRXiangYang_bingying1();
	else if(room_name == "ÏåÑô¶«±øÓª")
		r = new CRXiangYang_bingying2();
	else if(room_name == "ÏåÑôÄÏ±øÓª")
		r = new CRXiangYang_bingying3();
	else if(room_name == "ÏåÑôÎ÷±øÓª")
		r = new CRXiangYang_bingying4();
	else if(room_name == "ÏåÑô²è¹İ")
		r = new CRXiangYang_chaguan();
	else if(room_name == "ÏåÑôµ±ÆÌ")
		r = new CRXiangYang_dangpu();
	else if(room_name == "ÏåÑô´óĞ£³¡")
		r = new CRXiangYang_daxiaochang();
	else if(room_name == "ÏåÑô¶Ä³¡")
		r = new CRXiangYang_duchang();
	else if(room_name == "ÏåÑô¹ù¸®´óÃÅ")
		r = new CRXiangYang_guofugate();
	else if(room_name == "ÏåÑô½«¾ü¸®´óÃÅ")
		r = new CRXiangYang_jiangjungate();
	else if(room_name == "ÏåÑô¾ÛÒå¹İ")
		r = new CRXiangYang_juyiguan();
	else if(room_name == "ÏåÑôÂí¾Ç")
		r = new CRXiangYang_majiu();
	else if(room_name == "ÏåÑô¿ÍÕ»")
		r = new CRXiangYang_kedian();
	else if(room_name == "ÏåÑôÃñ¾Ó1")
		r = new CRXiangYang_minju1();
	else if(room_name == "ÏåÑôÃñ¾Ó2")
		r = new CRXiangYang_minju2();
	else if(room_name == "ÏåÑôÃÙÏãÂ¥")
		r = new CRXiangYang_mixianglou();
	else if(room_name == "ÏåÑôÄ¾½³ÆÌ")
		r = new CRXiangYang_mujiang();
	else if(room_name == "ÏåÑôÇ®×¯")
		r = new CRXiangYang_qianzhuang();
	else if(room_name == "ÏåÑôÊéµê")
		r = new CRXiangYang_shudian();
	else if(room_name == "ÏåÑôÌú½³ÆÌ")
		r = new CRXiangYang_TieJiangPu();
	else if(room_name == "ÏåÑôĞÂÂŞ·»")
		r = new CRXiangYang_xinluofang();
	else if(room_name == "ÏåÑôÑ§ÌÃ")
		r = new CRXiangYang_xuetang();
	else if(room_name == "ÏåÑôÒ©ÆÌ")
		r = new CRXiangYang_yaopu();
	else if(room_name == "ÏåÑôÖÒÁÒìô")
		r = new CRXiangYang_zhonglie();
	else if(room_name == "ÏåÑô²İµØ")
		r = new CRXiangYang_caodi();
	else if(room_name == "ÏåÑô²İµØ1")
		r = new CRXiangYang_caodi1();
		
	else if(room_name == "ÏåÑô¶«±±")
		r = new CRXiangYang_dongbei();
	else if(room_name == "ÏåÑô¶«ÄÏ")
		r = new CRXiangYang_dongnan();
	else if(room_name == "ÏåÑôÎ÷±±")
		r = new CRXiangYang_xibei();
	else if(room_name == "ÏåÑôÎ÷ÄÏ")
		r = new CRXiangYang_xinan();

	return r;
}