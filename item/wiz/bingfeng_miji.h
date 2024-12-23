//bingfeng_miji.h 
//code by sound
//2001-12-10
//取得冰峰秘籍

ITEM_BEGIN(CIbingfeng_miji);

virtual void create(int nFlag = 0)		
{
	static struct{
		char name[20];
		char id[20];
	} miji[9] = {
		{"冰峰密集第一残篇", "bingfeng miji1",},
		{"冰峰密集第二残篇", "bingfeng miji2",},
		{"冰峰密集第三残篇", "bingfeng miji3",},
		{"冰峰密集第四残篇", "bingfeng miji4",},
		{"冰峰密集第五残篇", "bingfeng miji5",},
		{"冰峰密集第六残篇", "bingfeng miji6",},
		{"冰峰密集第七残篇", "bingfeng miji7",},
		{"冰峰密集第八残篇", "bingfeng miji8",},
		{"冰峰密集第九残篇", "bingfeng miji9",},
	};

	int lvl = random(9);

	if(nFlag) lvl = nFlag - 1;

	set_name( miji[lvl].name, miji[lvl].id);
	set_weight(0l);	
	set("unit", "篇");
	set("long","据说如果能够集合九篇冰峰秘籍的残篇，就能学会其中的绝世剑法。");
};

virtual int do_look(CChar * me)
{
	say("你拿起残篇看了看，发现上面好像写有东西，当你想看清楚一点时却发现什么都没有。",me);
	say("据说如果能够收集到九篇不同的秘籍残篇，就有可能学到冰天剑法。",me);
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
	miji1=me->present("bingfeng miji1");
	
	CContainer * miji2;
	miji2=me->present("bingfeng miji2");
	
	CContainer * miji3;
	miji3=me->present("bingfeng miji3");
	
	CContainer * miji4;
	miji4=me->present("bingfeng miji4");
	
	CContainer * miji5;
	miji5=me->present("bingfeng miji5");
	
	CContainer * miji6;
	miji6=me->present("bingfeng miji6");
	
	CContainer * miji7;
	miji7=me->present("bingfeng miji7");
	
	CContainer * miji8;
	miji8=me->present("bingfeng miji8");
	
	CContainer * miji9;
	miji9=me->present("bingfeng miji9");
	
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

	if (miji1 && miji2 && miji3 && miji4 && miji5 && miji6 && miji7 && miji8 && miji9)
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
		
		message_vision("$HIC忽然发现这些残篇似乎可以连在一起，你急忙仔细观看……$COM",me);
		message_vision("$HIC你终于把这些残篇拼在了一起，然后拿浆糊把他们粘上……$COM",me);

		int i, j, skill, lvl;

		skill = me->query_skill("ice_sword", 1);

		lvl = me->query("level");
		
		if (lvl < 80)
		{
			lvl = 80;
		}

		i = lvl - 79;
		j = random(i);

		if (j == 0)
		{
			tell_object(me,"$HIY恭喜你得到了冰天剑法绝学。$COM");
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n\n$HIC%s$HIY在地狱中求得宝藏，学会了冰天剑法。\n\n$COM", me->name(1)));
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s学会了冰天剑法。", me->name(1)));
			me->set_skill("ice_sword", skill + 1);
		}
		
		else
		{
			tell_object(me,"$HIY突然$N脸色$HIR发青$HIY，几欲晕眩，原来$N不小心把残篇撕破，只剩下一堆碎片。$COM");
		}

		return 1;
	}
	
	tell_object(me,"你把这些残篇左拼右拼，但什么都没拼出来。");
	return 1;
	
}

ITEM_END;








