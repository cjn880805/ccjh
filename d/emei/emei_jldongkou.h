//jldongkou.h

//Sample for room:  峨嵋九老洞口
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jldongkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋九老洞口");
	
	add_npc("pub_guest");            // add by zdn 2001-07-14
				
	add_door("峨嵋莲花石", "峨嵋莲花石", "峨嵋九老洞口");
	add_door("峨嵋九十九道拐4", "峨嵋九十九道拐4", "峨嵋九老洞口");

	set("long","九老洞在仙峰寺外。传说远古时候，有九位仙叟住在这个洞里，不知他们生于何年，终于何年。轩辕皇帝访道于此，见一老叟，问曰：『有侣乎？』答曰：『九人』。这就是九老洞的来历。这个洞很深，很少有人进去，只有些人站在洞口谈笑呼叫（yell）。这里向西经九十九道拐到千佛庵，一路向北到莲花石。");


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
