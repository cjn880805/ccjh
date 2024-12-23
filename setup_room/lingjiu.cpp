#include "stdafx.h"
#include "../server/Room.h"


//ÁéğÕ
#include "../d/lingjiu/lingjiu_biguan.h"
#include "../d/lingjiu/lingjiu_caifeng.h"
#include "../d/lingjiu/lingjiu_changl1.h"
#include "../d/lingjiu/lingjiu_changl10.h"
#include "../d/lingjiu/lingjiu_changl11.h"
#include "../d/lingjiu/lingjiu_changl13.h"
#include "../d/lingjiu/lingjiu_changl14.h"
#include "../d/lingjiu/lingjiu_changl15.h"
#include "../d/lingjiu/lingjiu_changl3.h"
#include "../d/lingjiu/lingjiu_changl4.h"
#include "../d/lingjiu/lingjiu_changl5.h"
#include "../d/lingjiu/lingjiu_changl6.h"
#include "../d/lingjiu/lingjiu_changl7.h"
#include "../d/lingjiu/lingjiu_changl8.h"
#include "../d/lingjiu/lingjiu_changl9.h"
#include "../d/lingjiu/lingjiu_changlang12.h"
#include "../d/lingjiu/lingjiu_changlang2.h"
#include "../d/lingjiu/lingjiu_chufang.h"
#include "../d/lingjiu/lingjiu_daban.h"
#include "../d/lingjiu/lingjiu_dadao1.h"
#include "../d/lingjiu/lingjiu_dadao2.h"
#include "../d/lingjiu/lingjiu_damen.h"
#include "../d/lingjiu/lingjiu_dating.h"
#include "../d/lingjiu/lingjiu_huanyuan.h"
#include "../d/lingjiu/lingjiu_jian.h"
#include "../d/lingjiu/lingjiu_men1.h"
#include "../d/lingjiu/lingjiu_men2.h"
#include "../d/lingjiu/lingjiu_men3.h"
#include "../d/lingjiu/lingjiu_restroom.h"
#include "../d/lingjiu/lingjiu_shanjiao.h"
#include "../d/lingjiu/lingjiu_wuqiku.h"
#include "../d/lingjiu/lingjiu_xianchou.h"
#include "../d/lingjiu/lingjiu_xiaodao1.h"
#include "../d/lingjiu/lingjiu_xiaodao2.h"
#include "../d/lingjiu/lingjiu_xuanbing.h"
#include "../d/lingjiu/lingjiu_ya.h"
#include "../d/lingjiu/lingjiu_yan.h"
#include "../d/lingjiu/lingjiu_liangong.h"
#include "../d/lingjiu/lingjiu.h"

#include "../d/lingjiu/lingjiu_mishi.h"
#include "../d/lingjiu/lingjiu_midao1.h"
#include "../d/lingjiu/lingjiu_midao2.h"
#include "../d/lingjiu/lingjiu_midao3.h"

CRoom * Load_LingJiu(string room_name)
{
	CRoom * r = NULL;

	//ÁéğÕ
	if(room_name == "ÁéğÕÊ§×ãÑÒ")
		r = new CRLingJiu_yan();
	else if(room_name == "ÁéğÕ¶Ï»êÑÂ")
		r = new CRLingJiu_ya();
	else if(room_name == "ÁéğÕĞş±ùÊÒ")
		r = new CRLingJiu_xuanbing();
	else if(room_name == "ÁéğÕĞ¡µÀ2")
		r = new CRLingJiu_xiaodao2();
	else if(room_name == "ÁéğÕĞ¡µÀ1")
		r = new CRLingJiu_xiaodao1();
	else if(room_name == "ÁéğÕÏÉ³îÃÅ")
		r = new CRLingJiu_xianchou();
	else if(room_name == "ÁéğÕŞ¤·çĞù")
		r = new CRLingJiu_wuqiku();
	else if(room_name == "ÁéğÕçÎç¿·åÉ½½Å")
		r = new CRLingJiu_shanjiao();
	else if(room_name == "ÁéğÕí¬·ï¸ó")
		r = new CRLingJiu_restroom();
	else if(room_name == "ÁéğÕ±Õ¹ØÊÒ´óÃÅ")
		r = new CRLingJiu_men3();
	else if(room_name == "ÁéğÕÊé·¿´óÃÅ")
		r = new CRLingJiu_men2();
	else if(room_name == "ÁéğÕÇôÊÒ´óÃÅ")
		r = new CRLingJiu_men1();
	else if(room_name == "ÁéğÕÏ··ï¸ó")
		r = new CRLingJiu_liangong();
	else if(room_name == "ÁéğÕ°ÙÕÉ½§")
		r = new CRLingJiu_jian();
	else if(room_name == "ÁéğÕ»¨Ô°")
		r = new CRLingJiu_huanyuan();
	else if(room_name == "ÁéğÕ¶À×ğÌü")
		r = new CRLingJiu_dating();
	else if(room_name == "ÁéğÕ¶À×ğÌü´óÃÅ")
		r = new CRLingJiu_damen();
	else if(room_name == "ÁéğÕÇàÊ¯´óµÀ2")
		r = new CRLingJiu_dadao2();
	else if(room_name == "ÁéğÕÇàÊ¯´óµÀ1")
		r = new CRLingJiu_dadao1();
	else if(room_name == "ÁéğÕ×º½õ¸ó")
		r = new CRLingJiu_daban();
	else if(room_name == "ÁéğÕÅºÏãé¿")
		r = new CRLingJiu_chufang();
	else if(room_name == "ÁéğÕ»­ÀÈ2")
		r = new CRLingJiu_changlang2();
	else if(room_name == "ÁéğÕ»­ÀÈ12")
		r = new CRLingJiu_changlang12();
	else if(room_name == "ÁéğÕ»­ÀÈ9")
		r = new CRLingJiu_changl9();
	else if(room_name == "ÁéğÕ»­ÀÈ8")
		r = new CRLingJiu_changl8();
	else if(room_name == "ÁéğÕ»­ÀÈ7")
		r = new CRLingJiu_changl7();
	else if(room_name == "ÁéğÕ»­ÀÈ6")
		r = new CRLingJiu_changl6();
	else if(room_name == "ÁéğÕ»­ÀÈ5")
		r = new CRLingJiu_changl5();
	else if(room_name == "ÁéğÕ»­ÀÈ4")
		r = new CRLingJiu_changl4();
	else if(room_name == "ÁéğÕ»­ÀÈ3")
		r = new CRLingJiu_changl3();
	else if(room_name == "ÁéğÕ»­ÀÈ15")
		r = new CRLingJiu_changl15();
	else if(room_name == "ÁéğÕ»­ÀÈ14")
		r = new CRLingJiu_changl14();
	else if(room_name == "ÁéğÕ»­ÀÈ13")
		r = new CRLingJiu_changl13();
	else if(room_name == "ÁéğÕ±Õ¹ØÊÒ")
		r = new CRLingJiu_biguan();
	else if(room_name == "ÁéğÕ»­ÀÈ10")
		r = new CRLingJiu_changl10();
	else if(room_name == "ÁéğÕ»­ÀÈ1")
		r = new CRLingJiu_changl1();
	else if(room_name == "ÁéğÕäìÏæ¹İ")
		r = new CRLingJiu_caifeng();
	else if(room_name == "ÁéğÕ»­ÀÈ11")
		r = new CRLingJiu_changl11();
	else if(room_name == "ÁéğÕºóÉ½ÃÜµÀ1")
		r = new CRLingJiu_midao1();
	else if(room_name == "ÁéğÕºóÉ½ÃÜµÀ2")
		r = new CRLingJiu_midao2();
	else if(room_name == "ÁéğÕºóÉ½ÃÜµÀ3")
		r = new CRLingJiu_midao3();
	else if(room_name == "ÁéğÕºóÉ½Ê¯ÊÒ")
		r = new CRLingJiu_mishi();
	else if(room_name == "ÁéğÕ")
		r = new CRLingJiu();

	return r;
}