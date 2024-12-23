//bingcao.h

//Sample for room: 黄河冰草湾
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_bingcao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河冰草湾");
	
	add_npc("huanghe_liang");    //add by zdn 2001-07-14
	
	add_npc("pub_diaoer");
	add_npc("pub_gousan");
	add_npc("pub_guyi");
	

	add_door("黄河石峡子", "黄河石峡子", "黄河冰草湾");
	add_door("黄河营盘水", "黄河营盘水", "黄河冰草湾");

	set("long","冰草湾在营盘水的西南，平时人迹少至，因为当地沙漠里长着一种神奇的药草----'冰草'而得名。据说这种药草能解百毒，所以偶有人来采这种草，不过沙漠里常有毒虫出没，极为危险。");

};


CHANGAN_END;
