//sanglin.h

//Sample for room: 大理城桑林
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_sanglin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城桑林");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("pub_caisangnu");
	add_npc("pub_youwuyan");
	
	add_door("大理城阳宗镇", "大理城阳宗镇", "大理城桑林");

	set("long", "一大片桑树林生长在低山的缓坡山腰上。养蚕、纺丝是摆夷族的重要副业，摆夷妇女大都擅织丝，编织自己穿着的短裙，也用来和临近部落交换些其它物品。一群摆夷姑娘正在林间忙着采摘桑叶。" );

};

RESIDENT_END;
