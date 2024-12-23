//liuzhuang.h

//Sample for room: 杭州刘庄
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRhangzhou_liuzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州刘庄");

	set("resident", "杭州");
	set("capacity", 25);

	//add npcs into the room
	add_npc("pub_guanjia");
	add_npc("pub_jiading");
	add_npc("pub_jiading");

	add_door("杭州沿湖大道3", "杭州沿湖大道3", "杭州刘庄");

	set("long","庄园的大匾上是“刘庄”两个大字。大门(gate)紧闭，里面静悄悄的一点声音都没有。(pond)。朝东就是出寺下山的路。");

};

RESIDENT_END;
