// xiaoyao_fengas.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxiaoyao_fengas);

virtual void create()
{
	set_name("公输车", "feng asan");
	set("long", "据说他就是鲁班的后人，当代的第一机关巧匠。 ");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("class", "alchemist");
	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
 	set("icon",young_man4);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("blade",50);
	set_skill("xiaoyao_dao",50);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("lingboweibu", 50);
	set_skill("beiming_shengong",50);
	set_skill("liuyang_zhang", 50);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");
	
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","巧匠");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();		//将blade改为gangdao，lanwood 2000-12-31
	set("no_talk",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		AddMenuItem("向公输车请教关于机关的问题", "jiguan",me);	
		AddMenuItem("向公输车请教关于绝招的问题", "jingling",me);

		if(me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_63"))
		{
			AddMenuItem("转告公输车关于七夕相聚之事","qixi",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jiguan") )
	{
		if (random(100)<70)
			say( "我在设计机关方面是有点特长，让大家见笑了。",me);   
		else
			say("别吵着我，我在看书呢。哈哈，芝麻开门。。。。这书真好笑 ",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if (me->query("xiaoyao/挨骂")>=1)
		{
			me->del("xiaoyao/挨骂");
			if(random(4))
			{
				CContainer * ob = load_item("blade_1");
				ob->move(me);
				message_vision(snprintf(msg, 255, "$n说道：哈哈，又挨师父骂了是不是？\n$n给$N数量1的%s。",  ob->name()), me, this);
			}
			else
			{
				say( "你来的太迟了，东西都给别人拿光了。",me);
				SendMenu(me);
			}
		}
		else
		{
			if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
			{
				say("你不是我们逍遥派的门人，打听这些做什么？",me);
			}
			else if(me->query_temp("xiaoyao/禁令")==2)
			{
				me->add_temp("xiaoyao/禁令",1);
				say("「刀神一笑」我曾见过师祖使用过一次，那绚丽夺目、宛如流星飞坠的场面，我至今都还记得清清楚楚。",me);
			}
			else
			{
				me->delete_temp("xiaoyao/禁令");
				say( "本门武功听说有一招至强招式，天下无敌。不过师尊有令，如果未经许可，擅自使用几次后就会终生禁用。",me);
			}
			SendMenu(me);
		}
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61") )
		{
			if(!me->query_temp("xy/renwu1_63") )
				me->set_temp("xy/renwu1_63",1);//通知公输参加七夕相聚
			say(snprintf(msg, 255,"公输车呵呵一笑，道：“好啊，我们「函谷八友」总算又可以再次相聚了，烦劳%s再尽快转告一下我的其他师兄弟！”",query_respect(me)),me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);
}
NPC_END;




