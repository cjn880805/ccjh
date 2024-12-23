//pub_lvdongbing.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_lvdongbing);

void create()
{
	set_name("吕洞宾", "lv dong bing");
	
	set("title", "八洞神仙");
	set("long","生而金形玉质，道骨仙凤，鹤顶猿背。虎体龙腮；凤眼朝天，双眉入鬓；颈修颧露，身材雄伟；鼻梁耸直，面色白黄。左眉有一点黑子，足下纹如龟。身长八尺二寸，顶中阳巾，衣黄褴衫，系八皂绦，状类处子。");
	
	set("icon", taoist_with_sword);
	set("per",40);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 1200);

	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

    set("max_hp", 80000);
    set("mp", 20000);
    set("max_mp", 20000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 

	set_skill("force", 350);
	set_skill("sword", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("misssword", 350);
	set_skill("feixian_bu", 350);
	set_skill("celestrike", 350);
	
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("sword", "misssword");
    map_skill("parry", "celestrike");

	carry_object("changjian")->wield();

	set("bigboss",1);
	set("no_chan",1);
	set_temp("apply/no_黯然消魂",1);
	set("no_kill",1);
	set_temp("apply/no_连字诀",1);
	set_temp("apply/no_千环套狗",1);
	set_temp("apply/no_相思无用",1);
	set_temp("apply/no_势合形离",1);
	set_temp("apply/no_点字决",1);
	set_temp("apply/no_天外飞龙",1);
	set_temp("apply/no_拼命",1);
	set_temp("apply/no_祭血神刀",1);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query_temp("yuandna/lv_liwu") )
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"吕洞宾说道：“这位%s，可知当日云房先生渡我时，于长安酒肆题壁之三绝？”",query_respect(me)),me);
			AddMenuItem("知道","yes",me);
			AddMenuItem("不知道","no",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yes") )
		{
			switch(me->query_temp("yuandna/lv_quiz"))
			{
			case 0:
				say("吕洞宾说道：“其一曰:”", me);
				break;
			case 1:
				say("吕洞宾说道：“其二曰:”", me);
				break;
			case 2:
				say("吕洞宾说道：“其三曰:”", me);
				break;
			}
			AddMenuItem("回答", "$2flatter $1 $2", me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "no") )
		{
			say("吕洞宾给了你10块玉块，并说道：“你我无缘！”",me);
			SendMenu(me);

			CContainer * yupian=load_item("yupian");
			yupian->set_amount(10);
			yupian->move(me);
			if(me->query_temp("yuandna/lv_quiz"))
				me->delete_temp("yuandna/lv_quiz");
			if(me->query_temp("yuandna/lv_count"))
				me->delete_temp("yuandna/lv_count");
			me->delete_temp("yuandna/lv_liwu");
		}
	}
	else
	{
		say("吕洞宾抚须微笑：“节日快乐！”",me);
		/*
		if(!me->query("yuandna/lv"))
		{
			if(! strlen(ask))
			{
				say(snprintf(msg, 255,"吕洞宾说道：“这位%s，可有兴趣与我比比剑？”",query_respect(me)),me);
				AddMenuItem("愿意","yes",me);
				AddMenuItem("不愿意","",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				snprintf(msg, 255, "%s与%s的比试", me->name(), name());
				me->set_temp("fight_ok", 1);
				Do_BiShi(me, this, msg, 20);
			}
		}
		*/
	}
	return 1;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("什么？ ");

	if(!me->query_temp("yuandna/lv_quiz"))
	{
		tell_object(me,snprintf(msg,255,"你答道：%s", arg));
		me->set_temp("yuandna/lv_quiz",1);

		if(strstr(arg, "坐卧常携酒一壶")
		&& strstr(arg, "不教双眼识皇都")
		&& strstr(arg, "乾坤许久无名姓")
		&& strstr(arg, "疏散人间一丈夫"))
		{
			me->set_temp("yuandna/lv_count",1);
		} 
	}
	else if(me->query_temp("yuandna/lv_quiz")==1)
	{
		tell_object(me,snprintf(msg,255,"你答道：%s", arg));
		me->set_temp("yuandna/lv_quiz",2);

		if(strstr(arg, "传道真仙不易逢")
		&& strstr(arg, "几时归去愿相从")
		&& strstr(arg, "自言住处连东海")
		&& strstr(arg, "别是蓬莱第一峰"))
		{
			me->add_temp("yuandna/lv_count",1);
			me->set_temp("yuandna/lv_quiz",2);
		} 
	}
	else if(me->query_temp("yuandna/lv_quiz")==2)
	{
		tell_object(me,snprintf(msg,255,"你答道：%s", arg));
		

		if(strstr(arg, "寞厌追欢笑话频")
		&& strstr(arg, "寻思离乱可伤神")
		&& strstr(arg, "闲来屈指从头数")
		&& strstr(arg, "得到清平有几人"))
		{
			me->add_temp("yuandna/lv_count",1);
		} 
		if(me->query_temp("yuandna/lv_count")==3)
		{
			tell_object(me,snprintf(msg,255,"\n$HIR吕洞宾微笑道：“不错不错，%s可谓知己，本仙有一薄礼相赠。”\n",query_respect(me)));
			load_item("cunyang_sword")->move(me);
		}
		else
		{
			tell_object(me,snprintf(msg,255,"\n$HIR吕洞宾说道：“得不足喜，失何足悲。%s且自斟酌！”\n",query_respect(me)));
		}
		me->delete_temp("yuandna/lv_quiz");
		me->delete_temp("yuandna/lv_count");
		me->delete_temp("yuandna/lv_liwu");
		me->set("yuandna/lv_liwu",1);
		
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian") && !me->query("yuandna/lv_liwu") )
	{
		me->set_temp("yuandna/lv_liwu",1);
		destruct(ob);
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N看了看，呵呵一笑，“自从渡过东海之后，近千年来我早已不再与人动手了。”", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}
/*
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//获胜,设置标记.延迟呼叫,以便从战斗中脱身.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		me = winner;

		tell_object(me,"\n$HIC吕洞宾微笑收剑，露出赞许的眼光。\n");
		int exp=random(500)+500;
		me->add("combat_exp",exp);
		me->UpdateMe();
		me->set("yuandna/lv",1);

		char msg[255];
		tell_object(me,snprintf(msg,255,"$YEL你得吕洞宾指点剑术，经验上升了%d点。\n",exp));
	}
}
*/
NPC_END;
