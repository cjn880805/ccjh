#include "stdafx.h"
#include "../server/Room.h"

//¹ÅÄ¹
#include "../d/gumu/gumu_fengwu.h"
#include "../d/gumu/gumu_houting.h"
#include "../d/gumu/gumu_liangong.h"
#include "../d/gumu/gumu_xiaowu1.h"
#include "../d/gumu/gumu_xiaowu2.h"
#include "../d/gumu/gumu_xiuxishi.h"
#include "../d/gumu/gumu_mumen.h"
#include "../d/gumu/gumu_caodi2.h"
#include "../d/gumu/gumu_hanshuitan.h"
#include "../d/gumu/gumu_huangshalin.h"
#include "../d/gumu/gumu_kongdi.h"
#include "../d/gumu/gumu_caodi.h"
#include "../d/gumu/gumu_qianting.h"
#include "../d/gumu/gumu_shanlu.h"
#include "../d/gumu/gumu_shulin1.h"
#include "../d/gumu/gumu_xiaoting.h"
#include "../d/gumu/gumu_shulin2.h"
#include "../d/gumu/gumu_zhengting.h"
#include "../d/gumu/gumu_zhufeng.h"

CRoom * Load_GuMu(string room_name)
{
	CRoom * r = NULL;

	//¹ÅÄ¹
	if(room_name == "¹ÅÄ¹ĞİÏ¢ÊÒ")
		r = new CRGuMu_xiuxishi();
	else if(room_name == "¹ÅÄ¹ËïÆÅÆÅĞ¡Îİ")
		r = new CRGuMu_xiaowu2();
	else if(room_name == "¹ÅÄ¹Ğ¡Îİ")
		r = new CRGuMU_xiaowu1();
	else if(room_name == "¹ÅÄ¹Ä¹ÃÅ")
		r = new CRGuMu_mumen();
	else if(room_name == "¹ÅÄ¹Á·¹¦ÊÒ")
		r = new CRGuMu_liangong();
	else if(room_name == "¹ÅÄ¹·äÎİ")
		r = new CRGuMu_fengwu();
	else if(room_name == "¹ÅÄ¹ºóÌü")
		r = new CRGuMu_houting();
	else if(room_name == "¹ÅÄ¹ÖÕÄÏÉ½Ö÷·å")
		r = new CRGuMu_zhufeng();
	else if(room_name == "¹ÅÄ¹ÕıÌü")
		r = new CRGuMu_zhengting();
	else if(room_name == "¹ÅÄ¹Ğ¡Ìü")
		r = new CRGuMu_xiaoting();
	else if(room_name == "¹ÅÄ¹Ê÷ÁÖ2")
		r = new CRGuMu_shulin2();
	else if(room_name == "¹ÅÄ¹²İµØ")
		r = new CRGuMu_caodi();
	else if(room_name == "¹ÅÄ¹É½Â·")
		r = new CRGuMu_shanlu();
	else if(room_name == "¹ÅÄ¹Ç°Ìü")
		r = new CRGuMu_qianting();
	else if(room_name == "¹ÅÄ¹¿ÕµØ")
		r = new CRGuMu_kongdi();
	else if(room_name == "¹ÅÄ¹»ÆÉ³Áë")
		r = new CRGuMu_huangshalin();
	else if(room_name == "¹ÅÄ¹º®Ë®Ì¶")
		r = new CRGuMu_hanshuitan();
	else if(room_name == "¹ÅÄ¹²İµØ2")
		r = new CRGuMu_caodi2();
	else if(room_name == "¹ÅÄ¹Ê÷ÁÖ1")
		r = new CRGuMu_shulin1();

	return r;
}
