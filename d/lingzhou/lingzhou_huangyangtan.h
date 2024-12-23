//huangyangtan.h

//Sample for room: 灵州黄羊滩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_huangyangtan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州黄羊滩");

	//add npcs into the room
//	add_npc("animal_lamb");/////////////////////////
        add_npc("lingzhou_yun");   //add by zdn 2001-07-20

	add_door("灵州西", "灵州西", "灵州黄羊滩");
	add_door("灵州小坝", "灵州小坝", "灵州黄羊滩");

	set("long", "这里就是灵州西南著名的黄羊滩，本来是黄河边的一大片水泽盐碱地，黄河水泛滥后退去形成了一大片低洼水滩，上面水草丰盛，春秋两季吸引了大批塞北的野生黄羊到这里来饮水嬉戏，休养生息，成为塞上一大景观。");  
	
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
