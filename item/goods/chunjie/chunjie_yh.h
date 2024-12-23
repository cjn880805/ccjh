//chunjie_yh.h
ITEM_BEGIN(CIchunjie_yh)

virtual void create(int nFlag = 0)		
{
	set_name("烟花", "yan hua");
	set("long",	"这是一支节日时使用的烟花。不过这支烟花很特别哦！");
	set("unit", "把");
	set_weight(10);
	set("value", 1);
	
	call_out(do_die, 3600);	

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		char msg[512];
		int i,index;
		CContainer * env=me->environment();
		g_Channel.do_channel(&g_Channel, 0, "news", 
				snprintf(msg, 512, "\n\n               $HIR%s(%s)$HIW手中的烟花化为一阵红光，直冲上天际。\n               五彩的光影自空中散开，幻化成无数美丽的图案！\n                         仙乐响起，普天同庆！\n                    光影逐渐浓缩，变为几个明亮的大字：\n                $HIR%s(%s)恭祝江湖全体朋友新年快乐、万事如意！$HIW\n          良久，只闻一缕香气飘过，落下满天花雨，中间还夹杂着几声清脆的叮铛之响，如珠玉坠盘。\n\n",
				me->name(1),me->id(1),me->name(1),me->id(1)));

		for(i=0;i<random(4)+2;i++)
			load_item("huaban")->move(env);
		tell_room(env,"漫天的花瓣悠悠自天而降！");

		for(i=0;i<random(4)+2;i++)
			load_item("zhenzhu")->move(env);
		tell_room(env,"硕大的珍珠悠悠自天而降！");

		for(i=0;i<random(4)+1;i++)
		{
			index=random(MAX_ROOM_NUM);
			env = load_room(global_room_name[index]);
			load_item("huaban")->move(env);
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "花瓣移动到了%s。",env->querystr("base_name")));
			tell_room(env,"漫天的花瓣悠悠自天而降！");
		}
		for(i=0;i<random(2)+1;i++)
		{
			index=random(MAX_ROOM_NUM);
			env = load_room(global_room_name[index]);
			load_item("zhenzhu")->move(env);
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "大珍珠移动到了%s。",env->querystr("base_name")));
			tell_room(env,"硕大的珍珠悠悠自天而降！");
		}
		destruct(this);
		return 1;
	}

	return notify_fail("烟花不能对别人使用。");
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;

	if(month>=2)
	{
		CContainer * env = load_room("jy");
		if(!env->query("活动"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);

}
ITEM_END;
