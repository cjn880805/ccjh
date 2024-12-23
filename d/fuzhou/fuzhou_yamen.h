//yamen.h

//Sample for room: 提督衙门
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_yamen);

virtual void create()			//Call it when Room Create
{
	set_name( "提督衙门");

	add_npc("pub_geshiha");
	add_npc("pub_dinli");
	
	add_door("福州南", "福州南", "福州提督衙门");

    set("long", "这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分放两头石狮子的旁边。前面有一个大鼓，几名戈什哈站在门前。" );
	set("no_beg", 1);

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
