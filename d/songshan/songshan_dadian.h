//dadian.h

//Sample for room: 中岳大殿
//coded by zouwenbin
//data: 2000-11-

ROOM_BEGIN(CRSongShan_dadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "中岳大殿");
	
	add_npc("songshan_zuo");      //add by zdn 2001-07-20


	add_door("嵩山崇圣门", "嵩山崇圣门", "嵩山中岳大殿");
	add_door("嵩山山道1", "嵩山山道1", "嵩山中岳大殿");

	set("long", "大殿面阔九间，进深五间，重檐庑殿式屋顶，座落在七尺高的台基上，气势雄伟。大殿中供奉岳神天中王。" );
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
********************************************/
};


ROOM_END;
