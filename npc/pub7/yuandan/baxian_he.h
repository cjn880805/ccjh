//pub_hexiangu.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hexiangu);

void create()
{
	set_name("何仙姑", "he xian gu");
	
	set("title", "八洞神仙");
	set("long","她容貌端丽，手持莲花，白衫飘飘，立于五色云中。");
	
	set("icon", young_woman11);
	set("per",40);
	
	set("gender", "女性");
	set("level", 300);
	set("age", 1000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	say("何仙姑微微一笑：“节日快乐！”",me);

	if(!me->query("yuandna/he") && !me->query_temp("yuandna/play"))
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"何仙姑向你嘻嘻一笑道：“这位%s，要不要和本仙姑比比谁跑得快？”",query_respect(me)),me);
			AddMenuItem("愿意","yes",me);
			AddMenuItem("不愿意","",me);
		}
		else if(!strcmp(ask, "yes") )
		{
			do_play(me);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=5
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/he_liwu") )
	{
		char msg[255];
		destruct(ob);
		me->set("yuandna/he_liwu",1);
		tell_object(me,snprintf(msg, 255,"\n$HIC何仙姑微笑道：“多谢%s，本仙姑也有一份薄礼相赠！”",query_respect(me)));
		load_item("yanhua")->move(me);
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N看了看，呵呵一笑，“自从渡过东海之后，近千年来我早已不再与人动手了。”", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

void do_play(CChar * me)
{
	tell_object(me,"\n$HIR何仙姑在「凝眸阁」中轻盈地奔跑了起来，点尘不惊。");
	tell_object(me,"$HIR你不甘示弱，也跟随着跑了起来。\n");
	me->set_temp("yuandna/play",1);
	me->call_out(do_game, 5);
}

static void do_game(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	if(EQUALSTR((me->environment())->querystr("base_name"),"武陵春凝眸阁" ))
	{
		char msg[255];
		if(random(3))
		{
			if(random(2))
			{
				tell_object(me,"\n$HIR你展开身法双脚点地，全身化为一道白影如轻鸿般向前飞去，心想这下总赢定了吧。");
				tell_object(me,"$HIR向前一看何仙姑依然不疾不忙的领先你几步之遥。\n");
			}
			else
			{
				tell_object(me,"\n$HIR你使出十二分的身法快如闪电的向前激跃而去，只见何仙姑仙姿飘飘在你身前，距离触手可及但始终无法超越。");
				tell_object(me,"$HIR你不由得脚步变慢心头一阵失落。\n");
			}
			me->add_temp("yuandna/he1",1);
			me->call_out(do_game, 5);
		}
		else
		{
			tell_object(me,"$HIR你使尽全力，仍见何仙姑在前面不远处不徐不急地跑着，你自愧弗如，含羞停步。\n");

			if(me->query("dex")>=20)
			{
				tell_object(me,"$HIR何仙姑对你微微一笑：“还不错哦！”\n");
				int exp=random(500)+500+me->query_temp("yuandna/he1")*100;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"$YEL你获得了何仙姑的赏识，经验上升了%d点。\n",exp));
			}
			if(me->query_temp("yuandna/he1"))
				me->delete_temp("yuandna/he1");
			me->set("yuandna/he",1);
			me->delete_temp("yuandna/play");
		}
	}
	else
	{
		if(me->query_temp("yuandna/he1"))
			me->delete_temp("yuandna/he1");
		me->delete_temp("yuandna/play");
	}
}

NPC_END;
