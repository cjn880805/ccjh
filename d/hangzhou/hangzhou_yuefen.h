//yuefen.h

//Sample for room: 杭州岳坟
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuefen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州岳坟");

	add_npc("wei_yilian");

	add_door("杭州岳廊", "杭州岳廊", "杭州岳坟");

	set("long","墓道两旁有石虎，石羊，石马和三对翁仲。正中古柏交柯，便是岳飞的坟墓。墓碑刻着“宋岳鄂王墓”。 岳王墓的左面，便是岳飞之子岳云的墓，墓碑上刻着“宋继忠侯岳云之墓”.  在岳坟前面两边四个铁像(statue)。东首墙上有四个大字(word)。");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query_temp("wei/renwu7_7")&& !me->query_temp(" wei/renwu6_4")
		&& me->query_temp("wei/renwu8_12"))
	{
		tell_object(me,"\n$HIC依恋肃立在岳坟前，双眉紧蹙，似乎有着无限的心事。她好像没有注意到你的到来！");
	}
}

ROOM_END;
