//pub_caoguojiou.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_caoguojiou);

void create()
{
	set_name("曹国舅", "cao guo jiou");
	
	set("title", "八洞神仙");
	set("long","宋曹太后之弟也，朝服官帽，腰系大红辟水犀宝带，手中持玉版，相貌堂堂。");
	
	set("icon", officer);
	set("per",40);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 1000);
	set("no_huan",1);
	
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(!me->query_temp("yuandna/cao"))
		say("曹国舅笑呵呵地拍拍你的头，“节日快乐！”",me);

	if(!me->query("yuandna/cao"))
	{
		if(! strlen(ask))
		{
			say(snprintf(msg, 255,"曹国舅说道：“%s可有兴趣答我两问？”",query_respect(me)),me);
			AddMenuItem("愿意","yes",me);
			AddMenuItem("不愿意","",me);
			me->set_temp("yuandna/cao",1);
		}
		else if(!strcmp(ask, "yes") )
		{
			say("曹国舅曰：“道安在？”",me);
			AddMenuItem("天","11",me);
			AddMenuItem("地","12",me);
			AddMenuItem("人","13",me);
			AddMenuItem("心","14",me);
		}
		else if(!strcmp(ask, "11") )
		{
			say("曹国舅曰：“天安在？”",me);
			AddMenuItem("天","21",me);
			AddMenuItem("地","22",me);
			AddMenuItem("人","23",me);
			AddMenuItem("心","24",me);
		}
		else if(!strcmp(ask, "12") ||!strcmp(ask, "13")||!strcmp(ask, "14"))
		{
			me->set("yuandna/cao_cuo",1);

			say("曹国舅曰：“天安在？”",me);
			AddMenuItem("天","21",me);
			AddMenuItem("地","22",me);
			AddMenuItem("人","23",me);
			AddMenuItem("心","24",me);
		}
		else if(!strcmp(ask, "24") )
		{
			if(!me->query("yuandna/cao_cuo"))
			{
				me->del("yuandna/cao_cuo");
				say("曹国舅笑曰：“心即天，天即道，却识本来面目矣。”",me);
				int exp=random(500)+500;
				me->add("combat_exp",exp);
				me->UpdateMe();
				tell_object(me,snprintf(msg,255,"\n$YEL你获得了曹国舅的赏识，经验上升了%d点。\n",exp));
			}
			else
			{
				say("曹国舅叹道：“天道未分，不可渡也！”",me);
			}
			me->delete_temp("yuandna/cao");
			me->set("yuandna/cao",1);
			
		}
		else if(!strcmp(ask, "21") ||!strcmp(ask, "22")||!strcmp(ask, "23"))
		{
			say("曹国舅叹道：“天道未分，不可渡也！”",me);
			if(me->query("yuandna/cao_cuo"))
				me->del("yuandna/cao_cuo");
			me->delete_temp("yuandna/cao");
			me->set("yuandna/cao",1);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/cao_liwu") )
	{
		char msg[255];
		
		destruct(ob);
		me->set("yuandna/cao_liwu",1);
		tell_object(me,snprintf(msg,255,"\n$HIC曹国舅笑道：多谢这位%s！本仙也有一点薄礼相赠！\n",query_respect(me)));
		load_item("guanfu")->move(me);
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

NPC_END;
