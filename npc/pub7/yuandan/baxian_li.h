//pub_tieguaili.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_tieguaili);

void create()
{
	//set_name("铁拐李", "tie guai li");
	set_name("烂脚丐者", "qi gai");
	//set("title", "八洞神仙");
	set("long","他蓬首垢面，躬背跛足，一手拄紫色拐杖，一手拿着个紫色的大葫芦。他的双脚又肿又烂。");
	
	set("icon", old_man2);
	set("per",23);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 3000);

	set("chat_chance", 2);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(! is_fighting() && userp(me) && !me->query("yuandna/li_liwu"))
	{
		tell_object(me,"\n$HIC烂脚丐者哀呼道：“脚痛哉，谁与我摩摩脚。”");
	}
}


virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "烂脚丐者哀呼道：“脚痛哉，谁与我摩摩脚。”";
	case 1:
		random_move();
		return 0;
	case 2:
		return "烂脚丐者哀呼道：“脚痛哉，谁与我摩摩脚。”";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(!me->query("yuandna/li_liwu"))
	{
		if(!me->query("yuandna/li"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("为其摩脚","yes",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				say("虽然烂脚丐者肮脏不堪，且双脚红肿腐烂。但出于善心，你蹲下身去，为其轻轻搓揉双脚。",me);
				say(snprintf(msg, 255,"良久，烂脚丐者呻吟声渐弱，你起身欲走，烂脚丐者一把拉住你：“这位%s行行好，可否赏我一些财物？”",query_respect(me)),me);
				me->set_temp("yuandna/li_liwu",1);
				SendMenu(me);
			}
		}
		else
		{
			say("烂脚丐者却不感激，只问道：“谁把红炉大冶调？陶将皮袋出英豪。男儿识得机关巧，脱出风尘便是高。你可知此人是谁？”",me);
			AddMenuItem("回答", "$2flatter $1 $2", me);
			SendMenu(me);
		}
	}
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=10
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/li_liwu") && me->query_temp("yuandna/li_liwu") )
	{
		destruct(ob);
		tell_object(me,"\n$HIC烂脚丐者却不感激，只问道：“$HIR谁把红炉大冶调？陶将皮袋出英豪。男儿识得机关巧，脱出风尘便是高。你可知此人是谁？$HIC”\n");
		me->set("yuandna/li",1);
		return 1;
	}
	else
	{
		tell_object(me,"\n$HIC烂脚丐者为难道：“这也太少了点吧！”\n");
	}
	return 0;
}


int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("什么？ ");
	
	if(strstr(arg, "铁拐李"))
	{
		
		if(!me->query("yuandna/li_liwu") )
		{
			tell_object(me,"\n$HIC烂脚丐者忽大笑，长身而起，却原来是八仙之首铁拐李。");
			tell_object(me,snprintf(msg, 255,"$HIC铁拐李解下身上的紫色葫芦，递到你的手上：“%s真乃善人，日后当有善报！”复大笑，腾云而去。",query_respect(me)));
			tell_object(me,"$HIC葫芦在你手中竟然迎风而缩，变成了一个十分称手的小紫葫芦。\n");
			random_move();
			load_item("zihulu")->move(me);
			me->set("yuandna/li_liwu",1);
			me->delete_temp("yuandna/li_liwu");
		}
	} 
	else
	{
		me->set("yuandna/li_liwu",1);
		me->delete_temp("yuandna/li_liwu");
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N看了看，呵呵一笑，“自从渡过东海之后，近千年来我早已不再与人动手了。”", me, this);
		me->start_busy(2);
		return 1;
	}
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);
	
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;
