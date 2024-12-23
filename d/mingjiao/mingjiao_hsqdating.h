//hsqdating.h



//Sample for room: 洪水旗大厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_hsqdating);

virtual void create()			//Call it when Room Create
{

	set_name( "明教洪水旗大厅");

	add_npc("mingjiao_tangyang");
	add_npc("pub_huiyue");
	
	add_door("明教青石大道6", "明教青石大道6", "明教洪水旗大厅");

	set("long", "这里是洪水旗的大厅，厅中四壁漆墨，连桌案台椅俱为黑色，枪曳黑缨，剑垂玄穗，布置得冷漠森严。厅中央摆有茶几，洪水旗掌旗使唐洋正襟而坐，面带杀气。" );

};

ROOM_END;
