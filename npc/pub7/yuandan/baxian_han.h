//pub_hanzhongli.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hanzhongli);

void create()
{
	set_name("汉钟离", "han zhong li");
	
	set("title", "八洞神仙");
	set("long","他顶圆额广，耳厚眉长，目深鼻赤，口方颊大，唇脸如丹，乳达臂长，活似一个大肚罗汉。");
	
	set("icon", smith_boss);
	set("per",40);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 2000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	say("汉钟离笑呵呵地拍拍你的头，“节日快乐！”",me);

	if(!me->query("yuandna/han")&& !me->query_temp("yuandna/play"))
	{
		if(! strlen(ask) )
		{
			say(snprintf(msg, 255,"汉钟离说道：“这位%s，来来来，与我比比手劲如何！”",query_respect(me)),me);
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
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/han_liwu") )
	{
		destruct(ob);
		me->set("yuandna/han_liwu",1);
		tell_object(me,"\n$HIC汉钟离哈哈笑道：“大肚吃天下！”");
		tell_object(me,"$HIC说毕，伸指在你肚子上一点，你立时觉得肌肠辘辘起来。\n");
		switch(random(4))
		{
		case 0:
			me->del("yuandna/cai/count");
			me->del("yuandna/cai/get");
			break;
		case 1:
			me->del("yuandna/tang/count");
			me->del("yuandna/tang/get");
			break;
		case 2:
			me->del("yuandna/guo/count");
			me->del("yuandna/guo/get");
			break;
		case 3:
			me->del("yuandna/jiu/count");
			me->del("yuandna/jiu/get");
			break;
		}
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
	tell_object(me,"\n$HIR汉钟离甩了甩大腿般粗细的小臂，然后坐在桌对面挑衅地看着你。");
	tell_object(me,"$HIR你硬起头皮握紧他的大手，用力往下掰。\n");
	me->set_temp("yuandna/play",1);
	me->call_out(do_game, 5);
}

static void do_game(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	if(EQUALSTR((me->environment())->querystr("base_name"),"武陵春酒朋厅" ))
	{
		char msg[255];
		if(random(3))
		{
			if(random(2))
			{
				tell_object(me,"\n$HIR你涨红着脸，吃奶的力气也使出来了，豆大的汗珠顺着你的脸颊滚落下来。");
				tell_object(me,"$HIR可是汉钟离的手纹丝不动，你不禁兴起了蚂蚁撼大山的感觉。\n");
			}
			else
			{
				tell_object(me,"\n$HIR你猛运一口气，汉钟离的手被渐渐的松动了，你大喜。");
				tell_object(me,"$HIR只见汉钟离哈哈大笑一声，你的手又被他扳回到了正中间。\n");
			}
			me->add_temp("yuandna/han_1",1);
			me->call_out(do_game, 5);
		}
		else
		{
			tell_object(me,"$HIR你用尽力气也没有撼动汉钟离的手臂半分，无奈只有满脸通红地退下。");

			if(me->query("str")>=20)
			{
				tell_object(me,"$HIR汉钟离大笑道：“哈哈哈，不错不错，果真有些力气！”\n");
				int exp=random(500)+500+me->query_temp("yuandna/han_1")*100;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"$YEL你获得了汉钟离的赏识，经验上升了%d点。\n",exp));
			}
			if(me->query_temp("yuandna/han_1"))
				me->delete_temp("yuandna/han_1");
			me->set("yuandna/han",1);
			me->delete_temp("yuandna/play");
		}
	}
	else
	{
		if(me->query_temp("yuandna/han_1"))
			me->delete_temp("yuandna/han_1");
		me->delete_temp("yuandna/play");
	}
}

NPC_END;
