//hongniang.h
//code by zwb
//12-25


VENDOR_BEGIN(CNpub3_hongniang);


virtual void create()
{
	
	set_name("老板娘","LBN");

	set("icon", young_woman2);
	set("title", "情人庄");
	set("gender", "女性" );
	set("age", 16);
	set("per", 36);
	set("long","一位明眸皓齿的小姑娘。");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	
	carry_good("marry_1", 100, 1);
	carry_good("marry_1", 100, 2);
	carry_good("marry_1", 100, 3);
	carry_good("marry_1", 100, 4);
	carry_good("marry_1", 100, 5);
	carry_good("marry_1", 100, 6);
	carry_good("marry_1", 100, 7);
	carry_good("marry_1", 100, 8);
	carry_good("marry_1", 100, 9);
	carry_good("marry_1", 100, 10);
	carry_good("marry_1", 100, 11);
	carry_good("marry_1", 100, 12);
	carry_good("marry_1", 100, 13);
	carry_good("marry_1", 100, 14);
	carry_good("marry_1", 100, 15);

	carry_object("cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	AddMenuItem("结婚", "$0getinfo $1", me);
	AddMenuItem("离婚", "$0askquest $1", me);
	SendMenu(me);
	return 1;
}
virtual int handle_action(char *comm, CChar *me, char * arg)
{
		if(strcmp(comm, "getinfo") == 0)
			return do_gi(me);
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);

		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return 1;

	return CVendor::handle_action(comm, me, arg);

}

int do_gi(CChar * me)
{

		if (me->query("couple_betray") > 1)
		{
			say("ＬＢＮ叹道：抱歉，你已经无法再婚了。", me);
			SendMenu(me);
			return 1;
		}

		if (me->querymap("couple"))
		{
			say("ＬＢＮ笑道：你不是已经结婚吗？重婚是犯法的。", me);
			SendMenu(me);
			return 1;
		}


		say("ＬＢＮ笑道：这位可是想结婚了？", me);
		say("ＬＢＮ笑道：只需要５０万就能成为天人眷属，一世相依……", me);
		SendMenu(me);
		return 1;
}

int do_aq(CChar * me)
{
		if (!me->querymap("couple") && me->query("couple_betray"))
		{
			say("ＬＢＮ叹道：你已经离婚了。", me);
			SendMenu(me);
			return 1;
		}

		if (!me->querymap("couple"))
		{
			say("ＬＢＮ笑道：你还没有结婚呢，就想离婚了？", me);
			SendMenu(me);
			return 1;
		}

		CUser * targetx;
		char idd[255];
		snprintf(idd,255,"%s",me->querystr("couple/id"));
		targetx=find_online(idd);

		if (!targetx)
		{
			say("ＬＢＮ叹道：你的伴侣现在不在线上，再忍忍吧。", me);
			SendMenu(me);
			return 1;
		}

		say("ＬＢＮ叹了口气：又一对。。。", me);
		say("ＬＢＮ道：你可想好了，决定一下，就再也没有机会后悔。。。", me);
		say("ＬＢＮ道：而且离婚之后，亦无法再复婚，绝不可能破镜重圆。", me);
		say("ＬＢＮ道：你决定了么？", me);
	AddMenuItem("我决心已下……", "$0report $1", me);
	AddMenuItem("……再考虑考虑吧。", "$0fail $1", me);
		SendMenu(me);
		return 1;
}

int do_r(CChar * me)
{
		CUser * targetx;
		char idd[255];
		snprintf(idd,255,"%s",me->querystr("couple/id"));
		targetx=find_online(idd);

		if (!targetx)
		{
			say("ＬＢＮ叹道：你的伴侣现在不在线上，再忍忍吧。", me);
			SendMenu(me);
			return 1;
		}

		
		say("ＬＢＮ叹道：天下花痴出我辈，一入江湖岁月催……", me);
		say("ＬＢＮ叹道：昔日红颜今何在？不胜人生一场醉！", me);
		say("ＬＢＮ叹道：缘聚缘散，皆由天定啊。。。", me);

		command("chat 天下花痴出我辈，一入江湖岁月催……");
		command("chat 昔日红颜今何在？不胜人生一场醉！");
		command("chat 缘聚缘散，皆由天定啊。。。");
		g_Channel.do_channel(me, NULL, "chat", "\n\n$HIW天下花痴出我辈，一入江湖岁月催，\n昔日红颜今何在？不胜人生一场醉！\n缘聚缘散，皆由天定，勉强不来啊。。。\n\n\n");

		char msg[255];
		g_Channel.do_channel(&g_Channel, 0, "news", 
				snprintf(msg, 255, "%s与%s缘分尽于今日，脱离夫妻名分，从此%s、%s之间，再无瓜葛。。。" ,me->querystr("name"),targetx->querystr("name"),me->querystr("name"),targetx->querystr("name") ) );


/*
		me->set("couple/id", "block");
		me->set("couple/name", "已离婚");
		me->set("couple/gender", "无");
*/
		me->set("last_couple_name",me->querystr("couple/name"));
		me->set("last_couple_id",me->querystr("couple/id"));

		targetx->set("last_couple_name",targetx->querystr("couple/name"));
		targetx->set("last_couple_id",targetx->querystr("couple/id"));

		me->del("couple");
		(CChar *)me->add("couple_betray",1);
		targetx->del("couple");
		(CChar *)targetx->add("couple_betray",1);

		SendMenu(me);
		return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{

		if (who->query("couple_betray") > 1)
		{
			say("ＬＢＮ叹道：抱歉，你已经无法再婚了。", who);
			SendMenu(who);
			return 0;
		}

		if (who->querymap("couple"))
		{
			say("ＬＢＮ笑道：你不是已经结婚吗？重婚是犯法的。", who);
			SendMenu(who);
			return 0;
		}


	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")>=500000 )
	{
		destruct(ob);
		message_vision("只见ＬＢＮ微微一笑，塞给$N一块什么东西。",who);
		ob=load_item("tongxinyin");
		ob->move(who);
		return 1;
	}

return 0;
}

VENDOR_END;