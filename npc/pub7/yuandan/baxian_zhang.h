//pub_zhangguolao.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_zhangguolao);

void create()
{
	set_name("张果老", "zhang guo lao");
	
	set("title", "八洞神仙");
	set("long","他本是混沌以来白蝙蝠也。其受天地之气，得日月之精，历岁久远，遂化而为人。只见他须眉皆白，倒骑于一白毛驴之上。");
	
	set("icon", old_man1);
	set("per",24);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 30000);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("yuandna/zhang_liwu"))
	{
		if(! strlen(ask))
		{
			say("张果老笑道：“哈哈，这么殷勤的巴结我，可是想上天一游？”",me);
			AddMenuItem("想","yes",me);
			AddMenuItem("不想","no",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "yes") )
		{
			char msg[255];
			tell_object(me,"\n$HIC只见张果老座下毛驴撩起后蹄，猛踢在你身上，你立时腾云驾雾地飞了起来。");
			tell_object(me,"$HIC耳旁风声呼呼，白云遮目，也不知飞了多远。");
			tell_object(me,"$HIC只听“砰”的一声，你像个烂杮子一样，从半空中摔了下来。\n");
			me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
			me->set("yuandna/zhang_liwu",1);
			me->delete_temp("yuandna/zhang_liwu");
			int exp=random(500)+500;
			me->add("combat_exp",exp);
			me->UpdateMe();
			tell_object(me,snprintf(msg,255,"$YEL你获得了张果老的赏识，经验上升了%d点。\n",exp));
		}
		else if(!strcmp(ask, "no") )
		{
			say("\n$HIC张果老“哼”了一声：“无事献殷勤，非奸即盗！”便转头不再理你了。",me);
			SendMenu(me);
			me->set("yuandna/zhang_liwu",1);
			me->delete_temp("yuandna/zhang_liwu");
		}
	}
	else
	{
		say("张果老倒骑毛驴，手执收书卷，皱眉道：“勿扰勿扰！”",me);	
		SendMenu(me);
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() ==1
		&& EQUALSTR(ob->querystr("id"), "yu pian") )
	{
		destruct(ob);
		tell_object(me,"\n$HIC张果老展眉笑道：“多谢多谢，贪财贪财！”\n");

		return 1;
	}
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=3
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/zhang_liwu") )
	{
		destruct(ob);
		me->set_temp("yuandna/zhang_liwu",1);
		tell_object(me,"\n$HIC张果老笑道：“哈哈，这么殷勤的巴结我，可是想上天一游？”");
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
