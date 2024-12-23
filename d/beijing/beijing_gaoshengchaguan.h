//gaoshengchaguan.h

//Sample for room: 高升茶馆
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_gaoshengchaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "高升茶馆");

	//add npcs into the room
	//add_npc("guanfuzi");
	add_npc("pub_lincong");
	
	add_door("北京皇城", "北京皇城", "北京高升茶馆");

	set("long", "你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，这里是个好所在。" );
 	set("resource/water", 1);

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
