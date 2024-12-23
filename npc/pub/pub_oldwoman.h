// pub_oldwoman.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_oldwoman);

virtual void create()
{
	set_name("老大娘", "old woman");

	set("icon", old_woman);
	set("gender", "女性" );
	set("age", 63);
	set("long", "一个满脸风霜之色的老婆婆。");
 	set("shen_type", 1);
	set("combat_exp", 150);
	set("nkgain", 40);
	set("env/wimpy", 60);
	set("chat_chance_combat", 50 );
 	set("str", 13);
	set("dex", 12);
	set("con", 14);
	set("int", 13);
	set("attitude", "friendly");
 	set("chat_chance", 10);
	carry_object("cloth")->wear();
	add_money( 100);
	set_inquiry ("鸡" , "我那老母鸡啊...一定是那几个不务正业的小流氓干的。" );
	set_inquiry ("流氓" , "那几个小流氓正天不务正业，就在小胡同里喝酒赌钱。" );
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "老大娘伤心的说道：那个天杀的，偷了我的老母鸡。";
	case 1:
		return "老大娘叹了口气，说道：这是个什麽世道啊。";
	case 2:
		return "老大娘呆呆的望着鸡笼，发起愣来了。";
	}
	return "";
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(environment()->querystr("base_name"),"杭州茅家埠" ))
	{
		if(me->query("wei/renwu1") )
		{
			if(! strlen(ask))
			{
				AddMenuItem("打听沐剑屏的消息","mu",me);
				AddMenuItem("打听方瑜的消息","fang",me);
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "fang") && !me->query("wei/renwu6"))
			{
				say("老大娘面带不快，说道：这丫头我可不喜欢！一个女孩子家，成天凶巴巴的，还学男人舞刀弄剑，这不，今天一早提着把剑，又不知道上哪儿去了！",me);
				me->set_temp("wei/renwu6_1",1);//向老大娘打听关于方瑜的消息
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "mu") && !me->query("wei/renwu5") && !me->query_temp("wei/renwu5_7"))
			{
				if(me->query_temp("wei/renwu5_3") )
				{
					say("老大娘叹了口气，说道：除非你是个江湖郎中，否则她是不会见你的！",me);
					me->set_temp("wei/renwu5_4",1);//向老大娘打听关于沐剑屏的消息2
					SendMenu(me);
					return 1;
				}
				else if(!me->query_temp("wei/renwu5_1"))
				{
					say("老大娘叹了口气，说道：这小姑娘呀，模样可真是俊，可就是不知道为什么，一天到晚苦着个脸。大娘我啊，看着都心疼！对了，最近她不知道是不是得什么病了，托旁边这江湖郎中到处收购药材呢！",me);
					me->set_temp("wei/renwu5_1",1);//向老大娘打听关于沐剑屏的消息1
					SendMenu(me);
					return 1;
				}
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;