#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Npc.h"
#include "../std/FightRoom.h"

//少林寺
#include "../d/shaolinsi/shaolinsicity.h"
#include "../d/shaolinsi/shaolinsi_zhonglou1.h"
#include "../d/shaolinsi/shaolinsi_yaopinku.h"
#include "../d/shaolinsi/shaolinsi_wuqiku.h"
#include "../d/shaolinsi/shaolinsi_twdian.h"
#include "../d/shaolinsi/shaolinsi_shanmen.h"
#include "../d/shaolinsi/shaolinsi_qfdian.h"
#include "../d/shaolinsi/shaolinsi_luohan9.h"
#include "../d/shaolinsi/shaolinsi_luohan8.h"
#include "../d/shaolinsi/shaolinsi_luohan7.h"
#include "../d/shaolinsi/shaolinsi_luohan6.h"
#include "../d/shaolinsi/shaolinsi_luohan5.h"
#include "../d/shaolinsi/shaolinsi_luohan4.h"
#include "../d/shaolinsi/shaolinsi_luohan3.h"
#include "../d/shaolinsi/shaolinsi_luohan2.h"
#include "../d/shaolinsi/shaolinsi_luohan1.h"
#include "../d/shaolinsi/shaolinsi_jlyuan.h"
#include "../d/shaolinsi/shaolinsi_hsyuan6.h"
#include "../d/shaolinsi/shaolinsi_hsyuan5.h"
#include "../d/shaolinsi/shaolinsi_hsyuan4.h"
#include "../d/shaolinsi/shaolinsi_hsyuan3.h"
#include "../d/shaolinsi/shaolinsi_hsyuan2.h"
#include "../d/shaolinsi/shaolinsi_hsyuan1.h"
#include "../d/shaolinsi/shaolinsi_houdian.h"
#include "../d/shaolinsi/shaolinsi_gulou.h"
#include "../d/shaolinsi/shaolinsi_fzlou.h"
#include "../d/shaolinsi/shaolinsi_fanting.h"
#include "../d/shaolinsi/shaolinsi_fangzhangshi.h"
#include "../d/shaolinsi/shaolinsi_fangjuku.h"
#include "../d/shaolinsi/shaolinsi_dzdian.h"
#include "../d/shaolinsi/shaolinsi_dxbdian.h"
#include "../d/shaolinsi/shaolinsi_dmyuan.h"
#include "../d/shaolinsi/shaolinsi_dmyuan2.h"
#include "../d/shaolinsi/shaolinsi_damodong.h"
#include "../d/shaolinsi/shaolinsi_cjlou1.h"
#include "../d/shaolinsi/shaolinsi_cjlou.h"
#include "../d/shaolinsi/shaolinsi_chufang.h"
#include "../d/shaolinsi/shaolinsi_chashi.h"
#include "../d/shaolinsi/shaolinsi_bydian.h"
#include "../d/shaolinsi/shaolinsi_banruo1.h"
#include "../d/shaolinsi/shaolinsi_banruo2.h"
#include "../d/shaolinsi/shaolinsi_banruo3.h"
#include "../d/shaolinsi/shaolinsi_banruo4.h"
#include "../d/shaolinsi/shaolinsi_banruo5.h"
#include "../d/shaolinsi/shaolinsi_banruo6.h"
#include "../d/shaolinsi/shaolinsi_banruo7.h"
#include "../d/shaolinsi/shaolinsi_banruo8.h"
#include "../d/shaolinsi/shaolinsi_banruo9.h"
#include "../d/shaolinsi/shaolinsi_shijie.h"

#include "../d/shaolinsi/shaolinsi_dongxiaodao.h"
#include "../d/shaolinsi/shaolinsi_xixiaodao.h"
#include "../d/shaolinsi/shaolinsi_taijie.h"
#include "../d/shaolinsi/shaolinsi_qinxiu.h"
#include "../d/shaolinsi/shaolinsi_lianwu.h"
#include "../d/shaolinsi/shaolinsi_jingjin.h"
#include "../d/shaolinsi/shaolinsi_guangchang.h"
#include "../d/shaolinsi/shaolinsi_zhulin.h"
#include "../d/shaolinsi/shaolinsi_murenxiang.h"


CRoom * Load_ShaoLin(string room_name)
{
	CRoom * r = NULL;

	//少林寺
	if(room_name == "少林寺")
		r = new CRShaoLinSicity();
	else if(room_name == "少林寺钟楼一层")
		r = new CRShaoLinSi_zhonglou1();
	else if(room_name == "少林寺药品库")
		r = new CRShaoLinSi_yaopinku();
	else if(room_name == "少林寺武器库")
		r = new CRShaoLinSi_wuqiku();
	else if(room_name == "少林寺天王殿")
		r = new CRShaoLinSi_twdian();
	else if(room_name == "少林寺山门殿")
		r = new CRShaoLinSi_shanmen();
	else if(room_name == "少林寺千佛殿")
		r = new CRShaoLinSi_qfdian();
	else if(room_name == "少林寺罗汉堂九部")
		r = new CRShaoLinSi_luohan9();
	else if(room_name == "少林寺罗汉堂八部")
		r = new CRShaoLinSi_luohan8();
	else if(room_name == "少林寺罗汉堂七部")
		r = new CRShaoLinSi_luohan7();
	else if(room_name == "少林寺罗汉堂六部")
		r = new CRShaoLinSi_luohan6();
	else if(room_name == "少林寺罗汉堂五部")
		r = new CRShaoLinSi_luohan5();
	else if(room_name == "少林寺罗汉堂四部")
		r = new CRShaoLinSi_luohan4();
	else if(room_name == "少林寺罗汉堂三部")
		r = new CRShaoLinSi_luohan3();
	else if(room_name == "少林寺罗汉堂二部")
		r = new CRShaoLinSi_luohan2();
	else if(room_name == "少林寺罗汉堂一部")
		r = new CRShaoLinSi_luohan1();
	else if(room_name == "少林寺戒律院")
		r = new CRShaoLinSi_jlyuan();
	else if(room_name == "少林寺和尚院六部")
		r = new CRShaoLinSi_hsyuan6();
	else if(room_name == "少林寺和尚院五部")
		r = new CRShaoLinSi_hsyuan5();
	else if(room_name == "少林寺和尚院四部")
		r = new CRShaoLinSi_hsyuan4();
	else if(room_name == "少林寺和尚院三部")
		r = new CRShaoLinSi_hsyuan3();
	else if(room_name == "少林寺和尚院二部")
		r = new CRShaoLinSi_hsyuan2();
	else if(room_name == "少林寺和尚院一部")
		r = new CRShaoLinSi_hsyuan1();
	else if(room_name == "少林寺后殿")
		r = new CRShaoLinSi_houdian();
	else if(room_name == "少林寺鼓楼小院")
		r = new CRShaoLinSi_gulou();
	else if(room_name == "少林寺方丈楼")
		r = new CRShaoLinSi_fzlou();
	else if(room_name == "少林寺斋厅")
		r = new CRShaoLinSi_fanting();
	else if(room_name == "少林寺方丈室")
		r = new CRShaoLinSi_fangzhangshi();
	else if(room_name == "少林寺地藏殿")
		r = new CRShaoLinSi_dzdian();
	else if(room_name == "少林寺大雄宝殿")
		r = new CRShaoLinSi_dxbdian();
	else if(room_name == "少林寺达摩院二楼")
		r = new CRShaoLinSi_dmyuan2();
	else if(room_name == "少林寺达摩院")
		r = new CRShaoLinSi_dmyuan();
	else if(room_name == "少林寺达摩洞")
		r = new CRShaoLinSi_damodong();
	else if(room_name == "少林寺藏经阁二楼")
		r = new CRShaoLinSi_cjlou1();
	else if(room_name == "少林寺藏经阁一楼")
		r = new CRShaoLinSi_cjlou();
	else if(room_name == "少林寺厨房")
		r = new CRShaoLinSi_chufang();
	else if(room_name == "少林寺茶室")
		r = new CRShaoLinSi_chashi();
	else if(room_name == "少林寺白衣殿")
		r = new CRShaoLinSi_bydian();
	else if(room_name == "少林寺般若堂九部")
		r = new CRShaoLinSi_banruo9();
	else if(room_name == "少林寺般若堂八部")
		r = new CRShaoLinSi_banruo8();
	else if(room_name == "少林寺般若堂七部")
		r = new CRShaoLinSi_banruo7();
	else if(room_name == "少林寺般若堂六部")
		r = new CRShaoLinSi_banruo6();
	else if(room_name == "少林寺般若堂五部")
		r = new CRShaoLinSi_banruo5();
	else if(room_name == "少林寺般若堂四部")
		r = new CRShaoLinSi_banruo4();
	else if(room_name == "少林寺般若堂三部")
		r = new CRShaoLinSi_banruo3();
	else if(room_name == "少林寺般若堂二部")
		r = new CRShaoLinSi_banruo2();
	else if(room_name == "少林寺般若堂一部")
		r = new CRShaoLinSi_banruo1();
	else if(room_name == "少林寺防具库")
		r = new CRShaoLinSi_fangjuku();
	else if(room_name == "少林寺石阶")
		r = new CRShaoLinSi_shijie();

	else if(room_name == "少林寺东竹林小道")
		r = new CRShaoLinSi_dongxiaodao();
	else if(room_name == "少林寺西竹林小道")
		r = new CRShaoLinSi_xixiaodao();
	else if(room_name == "少林寺台阶")
		r = new CRShaoLinSi_taijie();
	else if(room_name == "少林寺精进场")
		r = new CRShaoLinSi_jingjin();
	else if(room_name == "少林寺练武场")
		r = new CRShaoLinSi_lianwu();
	else if(room_name == "少林寺勤修场")
		r = new CRShaoLinSi_qinxiu();
	else if(room_name == "少林寺广场")
		r = new CRShaoLinSi_guangchang();
	else if(room_name == "少林寺竹林")
		r = new CRShaoLinSi_zhulin();
	else if(room_name == "少林寺木人巷")
		r = new CRShaoLinSi_murenxiang();

	return r;
}