#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../std/FightRoom.h"

//ºÚÄ¾ÑÂ
#include "../d/heimuya/heimuyacity.h"
#include "../d/heimuya/heimuya_baihu.h"
#include "../d/heimuya/heimuya_baihudating.h"
#include "../d/heimuya/heimuya_chengdedian.h"
#include "../d/heimuya/heimuya_chufang.h"
#include "../d/heimuya/heimuya_chufang1.h"
#include "../d/heimuya/heimuya_fenglei.h"
#include "../d/heimuya/heimuya_fengleizheng.h"
#include "../d/heimuya/heimuya_lingpai.h"
#include "../d/heimuya/heimuya_neishi.h"
#include "../d/heimuya/heimuya_qingtang.h"
#include "../d/heimuya/heimuya_restroom.h"
#include "../d/heimuya/heimuya_shenggu.h"
#include "../d/heimuya/heimuya_xiaoneishi.h"
#include "../d/heimuya/heimuya_xiaoshe.h"
#include "../d/heimuya/heimuya_dukou.h"
#include "../d/heimuya/heimuya_pingdingzhou.h"
#include "../d/heimuya/heimuya_road1.h"
#include "../d/heimuya/heimuya_road2.h"
#include "../d/heimuya/heimuya_road3.h"
#include "../d/heimuya/heimuya_road4.h"

#include "../d/heimuya/heimuya_changlang.h"
#include "../d/heimuya/heimuya_changlang2.h"
#include "../d/heimuya/heimuya_grass.h"
#include "../d/heimuya/heimuya_house1.h"
#include "../d/heimuya/heimuya_houting.h"
#include "../d/heimuya/heimuya_qingdating.h"
#include "../d/heimuya/heimuya_xiaohuayuan.h"

#include "../d/heimuya/heimuya_changtan.h"
#include "../d/heimuya/heimuya_riyueping.h"
#include "../d/heimuya/heimuya_shandao.h"
#include "../d/heimuya/heimuya_shangu.h"
#include "../d/heimuya/heimuya_shidao1.h"
#include "../d/heimuya/heimuya_shidao2.h"
#include "../d/heimuya/heimuya_shijie.h"
#include "../d/heimuya/heimuya_shimen.h"
#include "../d/heimuya/heimuya_xingxingtan.h"
#include "../d/heimuya/heimuya_xiaodao.h"

#include "../d/heimuya/heimuya_tongdao1.h"
#include "../d/heimuya/heimuya_tongdao2.h"
#include "../d/heimuya/heimuya_tongdao3.h"
#include "../d/heimuya/heimuya_tongdao4.h"
#include "../d/heimuya/heimuya_tongdao5.h"
#include "../d/heimuya/heimuya_tongdao6.h"
#include "../d/heimuya/heimuya_huayuan.h"

CRoom * Load_HeiMuYa(string room_name)
{
	CRoom * r = NULL;

	//ºÚÄ¾ÑÂ
	if(room_name == "ºÚÄ¾ÑÂ")
		r = new CRHeiMuYacity();
	else if(room_name == "ºÚÄ¾ÑÂ·çÀ×ÌÃ´óÌü")
		r = new CRHeiMuYa_fenglei();
	else if(room_name == "ºÚÄ¾ÑÂ·çÀ×ÌÃ³ø·¿")
		r = new CRHeiMuYa_chufang1();
	else if(room_name == "ºÚÄ¾ÑÂĞ¡Éá")
		r = new CRHeiMuYa_xiaoshe();
	else if(room_name == "ºÚÄ¾ÑÂĞ¡ÉáÄÚÊÒ")
		r = new CRHeiMuYa_xiaoneishi();
	else if(room_name == "ºÚÄ¾ÑÂÊ¥¹ÃÌÃ")
		r = new CRHeiMuYa_shenggu();
	else if(room_name == "ºÚÄ¾ÑÂĞİÏ¢ÊÒ")
		r = new CRHeiMuYa_restroom();
	else if(room_name == "ºÚÄ¾ÑÂÇàÁúÌÃ")
		r = new CRHeiMuYa_qingtang();
	else if(room_name == "ºÚÄ¾ÑÂ°×»¢ÌÃ")
		r = new CRHeiMuYa_baihu();
	else if(room_name == "ºÚÄ¾ÑÂÁîÅÆÌÃ")
		r = new CRHeiMuYa_lingpai();
	else if(room_name == "ºÚÄ¾ÑÂ·çÀ×ÌÃ")
		r = new CRHeiMuYa_fengleizheng();
	else if(room_name == "ºÚÄ¾ÑÂ³ø·¿")
		r = new CRHeiMuYa_chufang();
	else if(room_name == "ºÚÄ¾ÑÂ³ÉµÂµî")
		r = new CRHeiMuYa_chengdedian();
	else if(room_name == "ºÚÄ¾ÑÂ°×»¢ÌÃ´óÌü")
		r = new CRHeiMuYa_baihudating();
	else if(room_name == "ºÚÄ¾ÑÂÄÚÊÒ")
		r = new CRHeiMuYa_neishi();
	else if(room_name == "ºÚÄ¾ÑÂ»ÆÍÁÂ·4")
		r = new CRHeiMuYa_road4();
	else if(room_name == "ºÚÄ¾ÑÂ»ÆÍÁÂ·3")
		r = new CRHeiMuYa_road3();
	else if(room_name == "ºÚÄ¾ÑÂ»ÆÍÁÂ·2")
		r = new CRHeiMuYa_road2();
	else if(room_name == "ºÚÄ¾ÑÂÂÒÊ¯ÆÂ")
		r = new CRHeiMuYa_road1();
	else if(room_name == "ºÚÄ¾ÑÂÁúÃÅ¶É¿Ú")
		r = new CRHeiMuYa_dukou();
	else if(room_name == "ºÚÄ¾ÑÂÆ½¶¨Öİ")
		r = new CRHeiMuYa_pingdingzhou();

	else if(room_name == "ºÚÄ¾ÑÂ³¤ÀÈ")
		r = new CRHeiMuYa_changlang();
	else if(room_name == "ºÚÄ¾ÑÂÇàÁúÌÃ")
		r = new CRHeiMuYa_qingtang();
	else if(room_name == "ºÚÄ¾ÑÂÇàÁúÌÃ´óÌü")
		r = new CRHeiMuYa_qingdating();
	else if(room_name == "ºÚÄ¾ÑÂºóÌü")
		r = new CRHeiMuYa_houting();
	else if(room_name == "ºÚÄ¾ÑÂÄÚÊÒ")
		r = new CRHeiMuYa_house();
	else if(room_name == "ºÚÄ¾ÑÂ²İµØ")
		r = new CRHeiMuYa_grass();
	else if(room_name == "ºÚÄ¾ÑÂ³¤ÀÈ2")
		r = new CRHeiMuYa_changlang2();
	else if(room_name == "ºÚÄ¾ÑÂĞ¡»¨Ô°")
		r = new CRHeiMuYa_xiaohuayuan();

	else if(room_name == "ºÚÄ¾ÑÂÁÖ¼äĞ¡µÀ")
		r = new CRHeiMuYa_xiaodao();
	else if(room_name == "ºÚÄ¾ÑÂĞÉĞÉÌ²")
		r = new CRHeiMuYa_xngxingtan();
	else if(room_name == "ºÚÄ¾ÑÂÊ¯ÃÅ")
		r = new CRHeiMuYa_shimen();
	else if(room_name == "ºÚÄ¾ÑÂÊ¯½×")
		r = new CRHeiMuYa_shijie();
	else if(room_name == "ºÚÄ¾ÑÂÊ¯µÀ2")
		r = new CRHeiMuYa_shidao2();
	else if(room_name == "ºÚÄ¾ÑÂ³¤Ì²")
		r = new CRHeiMuYa_changtan();
	else if(room_name == "ºÚÄ¾ÑÂÉ½¹È")
		r = new CRHeiMuYa_shangu();
	else if(room_name == "ºÚÄ¾ÑÂÉ½µÀ")
		r = new CRHeiMuYa_shandao();
	else if(room_name == "ºÚÄ¾ÑÂÈÕÔÂÆº")
		r = new CRHeiMuYa_riyueping();
	else if(room_name == "ºÚÄ¾ÑÂÊ¯µÀ1")
		r = new CRHeiMuYa_shidao1();

	else if(room_name == "ºÚÄ¾ÑÂ¶¥Í¨µÀ1²ã")
		r = new CRHeiMuYa_tongdao1();
	else if(room_name == "ºÚÄ¾ÑÂ¶¥Í¨µÀ2²ã")
		r = new CRHeiMuYa_tongdao2();
	else if(room_name == "ºÚÄ¾ÑÂ¶¥Í¨µÀ3²ã")
		r = new CRHeiMuYa_tongdao3();
	else if(room_name == "ºÚÄ¾ÑÂ¶¥Í¨µÀ4²ã")
		r = new CRHeiMuYa_tongdao4();
	else if(room_name == "ºÚÄ¾ÑÂ¶¥Í¨µÀ5²ã")
		r = new CRHeiMuYa_tongdao5();
	else if(room_name == "ºÚÄ¾ÑÂ¶¥Í¨µÀ6²ã")
		r = new CRHeiMuYa_tongdao6();
	else if(room_name == "ºÚÄ¾ÑÂ¶¥Ğ¡»¨Ô°")
		r = new CRHeiMuYa_huayuan();

	return r;
}