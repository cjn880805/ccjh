//shuyuan.h

//Sample for room: 嵩阳书院
//coded by zouwenbin
//data: 2000-11-

ROOM_BEGIN(CRShongShan_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嵩阳书院");
	
	add_npc("pub_shutong");         // add by zdn 2001-07-15


	add_door("嵩山山道2", "嵩山山道2", "嵩山嵩阳书院");
	add_door("嵩山山道3", "嵩山山道3", "嵩山嵩阳书院");

	set("long", "这里原是嵩阳寺。现在文化昌明，就改成了嵩阳书院，和睢阳书院，岳麓书院，白鹿书院合称天下 '四大书院'。北宋程颢程颐曾在此讲学。院内有古柏三株，汉武帝巡游至此，册封为大将军，二将军，三将军。" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao2",
		"northwest" : __DIR__"shandao3",
	]));
********************************************/
};


ROOM_END;
