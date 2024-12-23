//maojiabu.h

//Sample for room: 杭州茅家埠
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_maojiabu);

virtual void create()			
{
	set_name( "杭州茅家埠");

	add_npc("pub_oldwoman");
	add_npc("pub_boy");
	add_npc("wei_jhlz");

	add_door("杭州黄泥岭", "杭州黄泥岭", "杭州茅家埠");
	add_door("杭州土路", "杭州土路", "杭州茅家埠");

	set("long","路两旁盖着几座小土房。房门口一位老大娘正在喂鸡，几个小孩正在追逐嬉戏。北边是上黄泥岭。南面是丁家山。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("wei/renwu1") && !me->query("wei/renwu5"))
	{
		say("绿柳杏花丛中有隐藏着一间茅房，四周竹篱掩映，错落有致，门旁竹匾上写着「忘情阁」三个字。",me);
		AddMenuItem("进入忘情阁", "$0jinru $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!strcmp(comm, "jinru"))
	{
		return do_jinru(me, arg);
	}
	return 0;
}

int do_jinru(CChar *me, char * arg)
{
	if (me->query_temp("wei/renwu5_7"))
	{
		if(EQUALSTR(me->querystr_temp("apply/name"),"江湖郎中"))
		{
			CContainer * mianjue=me->present("mian ju");
			if(mianjue)
			{
				me->move(load_room("杭州忘情阁"));
				me->set_temp("wei/renwu5_8",1);//进入忘情阁
			}
		}
	}
	else
	{
		say("主人拒绝访客！", me);
		SendMenu(me);
		return 0;
	}
	return 1;
}
ROOM_END;
