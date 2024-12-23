//gongmen.h

//Sample for room: 宫门
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_gongmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "宫门");

	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");     //zdn 2001-07-12 add

	add_door("大理城西", "大理城西", "大理城皇宫宫门");
	add_door("大理城皇宫前殿", "大理城皇宫前殿", "大理城皇宫宫门");

	set("long", "这里是大理皇宫的宫门，门口放着两个高大石狮，大理皇帝没有一点架子，从来不禁止人们进入皇宫，往南是御街，往北就进入皇宫了。" );

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
