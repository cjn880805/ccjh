//xiaohun_miji.h 
//2001-12-10
//取得销魂秘籍

ITEM_BEGIN(CIxiaohun_miji);

virtual void create(int nFlag = 0)		
{
	static struct{
		char name[20];
		char id[20];
	} miji[12] = {
		{"销魂秘籍第一残篇", "xiaohun miji1",},
		{"销魂秘籍第二残篇", "xiaohun miji2",},
		{"销魂秘籍第三残篇", "xiaohun miji3",},
		{"销魂秘籍第四残篇", "xiaohun miji4",},
		{"销魂秘籍第五残篇", "xiaohun miji5",},
		{"销魂秘籍第六残篇", "xiaohun miji6",},
		{"销魂秘籍第七残篇", "xiaohun miji7",},
		{"销魂秘籍第八残篇", "xiaohun miji8",},
		{"销魂秘籍第九残篇", "xiaohun miji9",},
		{"销魂秘籍第十残篇", "xiaohun miji10",},
		{"销魂秘籍第十一残篇", "xiaohun miji11",},
		{"销魂秘籍第十二残篇", "xiaohun miji12",},
	};

	int lvl = random(12);

	if(nFlag) lvl = nFlag - 1;

	set_name( miji[lvl].name, miji[lvl].id);
	set_weight(0l);	
	set("unit", "篇");
	set("long","据说如果能够集合十二篇销魂秘籍的残篇，就能学会其中的绝世剑法。");
};

virtual int do_look(CChar * me)
{
	say("你拿起残篇看了看，发现上面好像写有东西，当你想看清楚一点时却发现什么都没有。",me);
	say("据说如果能够收集到十二篇不同的秘籍残篇，就有可能学到销魂剑法。",me);
	AddMenuItem("仔细看","$0combine $1",me);
	AddMenuItem("算了","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "combine") == 0)
		return do_combine(me, arg);
	return 0;
}

int do_combine(CChar *me, char * arg)
{
	char msg[255];
	
	CContainer * miji1;
	miji1=me->present("xiaohun miji1");
	
	CContainer * miji2;
	miji2=me->present("xiaohun miji2");
	
	CContainer * miji3;
	miji3=me->present("xiaohun miji3");
	
	CContainer * miji4;
	miji4=me->present("xiaohun miji4");
	
	CContainer * miji5;
	miji5=me->present("xiaohun miji5");
	
	CContainer * miji6;
	miji6=me->present("xiaohun miji6");
	
	CContainer * miji7;
	miji7=me->present("xiaohun miji7");
	
	CContainer * miji8;
	miji8=me->present("xiaohun miji8");
	
	CContainer * miji9;
	miji9=me->present("xiaohun miji9");

	CContainer * miji10;
	miji10=me->present("xiaohun miji10");

	CContainer * miji11;
	miji11=me->present("xiaohun miji11");

	CContainer * miji12;
	miji12=me->present("xiaohun miji12");
	
	if (miji1)
		tell_object(me,"拼上第一篇残篇");
	if (miji2)
		tell_object(me,"拼上第二篇残篇");
	if (miji3)
		tell_object(me,"拼上第三篇残篇");
	if (miji4)
		tell_object(me,"拼上第四篇残篇");
	if (miji5)
		tell_object(me,"拼上第五篇残篇");
	if (miji6)
		tell_object(me,"拼上第六篇残篇");
	if (miji7)
		tell_object(me,"拼上第七篇残篇");
	if (miji8)
		tell_object(me,"拼上第八篇残篇");
	if (miji9)
		tell_object(me,"拼上第九篇残篇");
	if (miji10)
		tell_object(me,"拼上第十篇残篇");
	if (miji11)
		tell_object(me,"拼上第十一篇残篇");
	if (miji12)
		tell_object(me,"拼上第十二篇残篇");

	if (miji1 && miji2 && miji3 && miji4 && miji5 && miji6 && miji7 && miji8 && miji9 && miji10 && miji11 && miji12)
	{
		destruct(miji1);
		destruct(miji2);
		destruct(miji3);
		
		destruct(miji4);
		destruct(miji5);
		destruct(miji6);
		
		destruct(miji7);
		destruct(miji8);
		destruct(miji9);

		destruct(miji10);
		destruct(miji11);
		destruct(miji12);
		
		message_vision("$HIC忽然发现这些残篇似乎可以连在一起，你急忙仔细观看……$COM",me);
		message_vision("$HIC你终于把这些残篇拼在了一起，然后拿浆糊把他们粘上……$COM",me);

		int i, j, skill, lvl;

		skill = me->query_skill("misssword", 1);

		lvl = me->query("level");
		
		if (lvl < 120)
		{
			j=0;
		}
		else
		{
			i = lvl - 119;
			j = random(i);
		}

		if (j>0  && EQUALSTR(me->querystr("gender"), "男性") )
		{
			tell_object(me,"$HIY恭喜你得到了销魂剑法绝学。$COM");
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n\n$HIC%s%s$HIY闯迷宫，斗恶人，历尽千辛万苦夺得销魂秘籍，并练成销魂剑法。\n\n$COM", me->querystr("family/family_name"),me->name(1)));

			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s学会了销魂剑法。", me->name(1)));
			me->set_skill("misssword", skill + 1);
			me->FlushMySkill(me);
		}
		else
		{
			tell_object(me,"$HIY突然你脸色$HIR发青$HIY，几欲晕眩，原来你不小心把残篇撕破，只剩下一堆碎片。$COM");
		}

		return 1;
	}
	
	tell_object(me,"你把这些残篇左拼右拼，但什么都没拼出来。");
	return 1;
	
}

ITEM_END;








