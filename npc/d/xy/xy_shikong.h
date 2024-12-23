//xy_shima.h 司空子虚
//秦波 2003、1、25

NPC_BEGIN(CNxy_shikong);

virtual void create()
{    
    set_name("司空子虚", "shikong zixu");
    set("long","他面目慈和，唇上三缕黑色长髭直垂及胸，一袭宽大的灰色道袍随风飘扬，宛如得道之仙人。");	
	set("gender", "男性");
	set("age", 63);
	set("foolid",127);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);
	set("icon",taoist);	
	
	set("hp",30000);
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 70000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 400);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_kill",1);

}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(EQUALSTR(environment()->querystr("base_name"),"逍遥谷追月观静思庭" ))
	{
		if(me->query("xy/renwu5_3") && !me->query("xy/renwu6") )
		{
			say(snprintf(msg, 255, "司空子虚对你点了点头：“%s乃上佳玉璞，如不嫌弃，拜入我们下，何如？”",query_respect(me)), me);
			say("你忙道：“蒙前辈错爱，晚辈感激不尽，只是我已立誓终身不侍二师，故未敢他投别派，还请前辈见谅。”", me);
			say("司空子虚见你执意甚坚，唯有叹了口气：“或许你我本该无缘，自不可强求，送你一句话‘八方三才四海流，一唱五咏九霄愁。六贤七圣二道开，河图洛书逍遥游’！”", me);
			say(snprintf(msg, 255, "司空子虚又对你说道：“我见你那丁师弟眼中骛气甚重，须小心提防。好了，你我缘尽于此，%s请便吧！”",query_respect(me)), me);
			me->set("xy/renwu6",1);//逍遥任务任务第六部分：智入琅擐福地
			SendMenu(me);
		}
		return 1;
	}
	else if(EQUALSTR(environment()->querystr("base_name"),"逍遥谷追月观怀月庭" ))
	{
		if(!me->query("xy/renwu5_3"))
		{
			if(me->query("xy/renwu5_2") )
			{
				say(snprintf(msg, 255, "司空子虚道：“不知%s是否已经准备好与我徒清风一决高下呢？”",query_respect(me)), me);
				SendMenu(me);
			}
			else if(me->query("xy/renwu5_1") && me->query_temp("xy/renwu5_1") )
			{
				if(!me->query_temp("xy/renwu5_2"))
				{
					if(! strlen(ask))
					{
						say(snprintf(msg, 255, "司空子虚道：“%s可否先回答贫道几个问题？”",query_respect(me)), me);
						AddMenuItem("愿意", "yes", me);
						AddMenuItem("算了", "", me);
					}
					else if(!strcmp(ask, "yes") )
					{
						say("司空子虚点了点头。", me);
						me->set_temp("xy/renwu5_2",1);//准备回答问题
					}
				}
				else
				{
					switch(me->query_temp("xy/renwu5_3"))
					{
					case 0:
						say("司空子虚问道：“三才者，何也？”", me);
						break;
					case 1:
						say("司空子虚问道：“四象者，何也？”", me);
						break;
					case 2:
						say("司空子虚问道：“五调者，何也？”", me);
						break;
					case 3:
						say("司空子虚问道：“六艺者，何也？”", me);
						break;
					case 4:
						say("司空子虚问道：“梅傲何季？”", me);
						break;
					case 5:
						say("司空子虚问道：“兰秀何时？”", me);
						break;
					case 6:
						say("司空子虚问道：“竹茂何季？”", me);
						break;
					case 7:
						say("司空子虚问道：“菊芳何时？”", me);
						break;
					}
					AddMenuItem("回答", "$2flatter $1 $2", me);
				}
			}
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}  

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if(me->query("xy/renwu5") && !me->query("xy/renwu6") )
	{
		if (!strcmp(comm,"flatter") && me->query_temp("xy/renwu5_2") )
			return do_flatter(me,arg);
	}

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("你什么？ ");

	tell_object(me,snprintf(msg,255,"你朗声说道：“%s”", arg));
	me->add_temp("xy/renwu5_3",1);//回答问题的数目
	
	switch(me->query_temp("xy/renwu5_3"))
	{
	case 1:
		if(strstr(arg, "天") && strstr(arg, "地") && strstr(arg, "人"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 2:
		if(strstr(arg, "东青龙") && strstr(arg, "北玄武") && strstr(arg, "西白虎") && strstr(arg, "南朱雀"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 3:
		if(strstr(arg, "宫") && strstr(arg, "商") && strstr(arg, "角") 
			&& strstr(arg, "徵")&& strstr(arg, "羽"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 4:
		if(strstr(arg, "诗") && strstr(arg, "书") && strstr(arg, "礼") 
			&& strstr(arg, "乐")&& strstr(arg, "易")&& strstr(arg, "春秋"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 5:
		if(strstr(arg, "冬"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 6:
		if(strstr(arg, "春"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 7:
		if(strstr(arg, "夏"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		break;
	case 8:
		if(strstr(arg, "秋"))
			me->add_temp("xy/renwu5_4",1);//回答正确问题的数目
		if(me->query_temp("xy/renwu5_3")==8 && me->query_temp("xy/renwu5_4")==8)
		{
			tell_object(me,snprintf(msg, 255, "\n$HIR司空子虚点头道：“逍遥贤弟果然没看错人，这位%s天资聪颖，博学多闻，且筋骨奇佳，乃学武之材。”",query_respect(me)));
			tell_object(me,"$HIR司空子虚点头道：“看来今天的赌约我徒清风是难有胜算了。\n");
			me->set("xy/renwu5_2",1);//通过司空子虚的考验
		}
		break;
	}
	return 1;
}


NPC_END;