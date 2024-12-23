//clubup.h

//Sample for room: 长安乐坊二楼大厅
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_clubup);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安乐坊二楼大厅");

	add_npc("pub_xiaoer1");  // zdn 2001-07-12 add
	add_npc("pub_yicimengzi");

	add_door("长安乐坊", "长安乐坊", "长安乐坊二楼大厅");
	add_door("长安乐府诗社", "长安乐府诗社", "长安乐坊二楼大厅");
	add_door("长安押签房", "长安押签房", "长安乐坊二楼大厅");
	add_door("长安骨骰房", "长安骨骰房", "长安乐坊二楼大厅");
	add_door("长安斗鸡房", "长安斗鸡房", "长安乐坊二楼大厅");
	add_door("长安赛龟房", "长安赛龟房", "长安乐坊二楼大厅");

	set("long", "乐坊楼上显得格外热闹，走廊里人来人往，几间屋子里人声嘈杂，牌签骨骰钱币落盘的声音不绝。看样子，客人们赌得正欢呢。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
CHANGAN_END;




