//qsdadao3.h
//Sample for room: 刑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_qsdadao3);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教青石大道3");

	add_npc("mingjiao_gaoshanwang");

	add_door("明教山门", "明教山门", "明教青石大道3");
	add_door("明教悬天崖", "明教悬天崖", "明教青石大道3");

	set("long", "这里大道平坦，地势开阔，两旁树林中鸟语花香，一片和平安祥的气氛。此时又有谁能想到，这条大道上撒下过多少江湖中人的血，这片林中又埋有多少惨死于武林争斗的冤魂的骨。远处，隐约传来叮叮咚咚的打铁声，偶尔能让人追忆起刀戈铁马的沙场景象。    冷谦执掌明教刑堂。");
    

/*****************************************************

********************************************/

};


ROOM_END;
