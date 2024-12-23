//titian1.h

//Sample for room: 梯田
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_titian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梯田");

	//add npcs into the room
	add_npc("pub_nongfu1");
	add_item("daotian");
	
	add_door("大理城镇雄", "大理城镇雄", "大理城梯田");

	set("long", "东泸水河谷气候较温暖，乌夷先民沿山坡开垦了不少梯田。此间乃是低坡，层层梯田沿坡而上，土地看来并不肥沃，作物较稀疏，乌夷地区农业颇为落后，多行换季轮耕，附近山上的一些梯田在这个季节正荒芜着。" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
