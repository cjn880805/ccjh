//club3.h

//Sample for room: 长安聚义厅
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_club3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安聚义厅");

	add_npc("pub_xiaoer1");  // zdn 2001-07-12 add

	add_door("长安乐府诗社", "长安乐府诗社", "长安聚义厅");
	add_door("长安三楼拱猪房", "长安三楼拱猪房", "长安聚义厅");
	add_door("长安入神坐照室", "长安入神坐照室", "长安聚义厅");

	set("long", "这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱子上贴满了各种广告：有换房的，有卖家具的，但其中最多的还是找打牌搭档的广告。厅的东南西北各有个门，里面传出“拱啊！”“毙了！”等的叫声。" );
    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);  

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
