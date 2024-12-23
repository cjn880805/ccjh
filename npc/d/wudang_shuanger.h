// wudang_shuanger.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;

NPC_BEGIN(CNwudang_shuanger);

virtual void create()
{
	set_name("蝉儿",  "shuang er");
	set("title",  "天下无双" );
	set("nickname",  "大功告成" );
	set("gender", "女性");
	set("age", 15);
        set("icon",girl2);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("taiji_jian", 70);
	set_skill("taiji_quan", 70);
	set_skill("tiyunzong",50);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	
	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);

	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
}
/*
	set_inquiry("你愿不愿意跟我走",ask_go);
	set_inquiry("大功告成",ask_kiss);
*/
/*
static char * ask_kiss(CNpc *who,CChar *me)
{
	char msg[255];
//	string host_id;

	if(querystr("id")!="shuang er")
	{
//		sscanf(query("id"),"%s's shuang er",host_id);
//		if(me->query("id")==host_id)
		if( ( me->query("id") ) == ( who->query("id") ))
		{
			if(random(10)<1)	          
			{
				who->say(snprintf(msg,255, "%s满脸羞得通红,垂下头来,缓缓的点了点头. ",query("name") ));
			}
			else 
				who->say(snprintf(msg,255,"%s啊的一声,一下子跳将开去,说:不嘛,不要. ",query("name") ));
			return "";
		}
	}
	who->say(snprintf(msg,255,"%s说道:呸,我不干.",query("name") ));
	return "";
}

static char * ask_go(CNpc *who,CChar *me)
{
	char msg[255];
 	string new_name,new_id,host_id;
 	if(querystr("id")!="shuang er")
	{
//		sscanf(query("id"),"%s's shuang er",host_id);
		if(query("id")==host_id)
		{
			say(snprintf(msg,255,query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说:当然愿意啦,我都听你的。 ");
			return 1;
		}
		if(me->query("id")!=host_id)
		{
			say(snprintf(msg,255,query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说:不行的,我得听我主人的。 ");
			return 1;
		}
	}
	if (this_player()->query("weiwang")>=70)
	{
		write(  "蝉儿道:夫人待我恩重如山,主人对我庄家又有大恩。 " );
		write(  "夫人要我服侍主人,我一定尽心。 " );
		command("nod");	
		set_leader(me);
		new_name = me->query("name")+"的丫环蝉儿";
		new_id=me->query("id")+"'s shuang er";
		set_name(new_name);
		set("id",new_id);
		write( "可用指令: attack sb 攻击某人. sha sb 杀死某人. stop 停止战斗. sendto sb.--把蝉儿送给sb. ");
		set("long","这是"+new_name+"。 "
			"她是一个十分清秀的少女,大约十四五岁年纪; "
			"一张雪白的脸庞,眉弯嘴小,笑靥如花,正笑嘻嘻地看着你。 ");
	}
	else say(snprintf(msg,255,query("name")+"睁大眼睛看着"+
		me->query("name")+"，说:不行的,夫人没有同意。 ");
	return 1;
}
*/
/*
int init()
{
	add_action("do_attack","attack");
	add_action("do_stop","stop");
	add_action("do_send","sendto");
	add_action("do_sha","sha");
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"attack") == 0)
		return do_attack();
	if (strcmp(comm,"stop") == 0)
		return do_stop();
	if (strcmp(comm,"sendto") == 0)
		return do_sendto();
	if (strcmp(comm,"sha") == 0)
		return do_sha();
	return 0;
}

int do_attack(string arg)
{
	object ob; 
	string host_id;
	object me=this_player();
	if(query("id")=="shuang er")
	{
		say("你无权使用此命令。 ");
		return 0;
	}
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("蝉儿连理都不理你！ ");
	if(!arg||!(ob=present(arg,environment(me))))
		return notify_fail("蝉儿傻傻地望着你，不明白你的意思。 ");
	if(!living(ob)) 
		return notify_fail("蝉儿说:"
		+ob->query("name")+"已经这样啦你还要...??!! ");
	if(ob->query("age")< 16 ) 
		return notify_fail("蝉儿说:"
		+ob->query("name")+"还是个小孩子, 算了吧...!! ");
	if(!(ob->environment())->query("no_fight"))
	{
		message_vision("蝉儿对主人$N点头道: 嗯,好的.. ",me);
		fight_ob(ob);
	}
	return 1;
}

int do_stop()
{
	string host_id;
	object me=this_player();
	if(query("id")=="shuang er") return notify_fail("你无权使用此命令。 ");
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("蝉儿连理都不理你！ ");
	if(!is_fighting()) return notify_fail("蝉儿现在没和人打斗.. ");
	command("halt");
	message_vision("蝉儿对主人$N微微一笑。 ",me);
	return 1;
}

int do_send(string arg)
{
	object ob; string host_id,new_name,new_id;
	object me=this_player();
	if(query("id")=="shuang er") return notify_fail("你无权使用此命令。 ");
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("蝉儿连理都不理你！ ");
	if(!arg||!(ob=present(arg,environment(me))))
		return notify_fail("你要把蝉儿送给谁？ ");
	if(!living(ob)) 
		return notify_fail("你只能把蝉儿给活人! ");
	message_vision("蝉儿眼泪汪汪地望着主人$N，说: 主人待我好,是我命好;主人待我不好,是我命苦罢了. ",me);
	set_leader(ob);
	new_name = ob->query("name")+"的丫环蝉儿";
	set("long","这是"+new_name+"。 "
		"她是一个十分清秀的少女,大约十四五岁年纪; "
		"一张雪白的脸庞,眉弯嘴小,却象是刚受人欺负,眼泪汪汪地看着你。 ");
	new_id=ob->object_id()+"'s shuang er";
	set_name(new_name,new_id);
	write(  "蝉儿对新主人"+ob->query("name")+"楚楚可怜地盈盈一拜。 " );
	message_vision("可用指令: attack sb 攻击某人. sha sb 杀死某人. stop 停止战斗. sendto sb.--把蝉儿送给sb. ",me);
	return 1;
}

int do_sha(string arg)
{
	int i ;
	object me,ob;
	object* obj;
	me = this_object();
	if(!arg||!(ob=present(arg,environment(me))))
		return notify_fail("蝉儿说: 主人你要蝉儿杀谁？ ");
	if(ob->query("age")< 16 ) 
		return notify_fail("蝉儿说:"
		+ob->query("name")+"还是个小孩子, 算了吧...!! ");
	if(!(ob->environment())->query("no_fight"))
	{
		message_vision("蝉儿对$N点头说道: 嗯, 好的.  ",me);
		say(" 哼, 主人要我杀了你! ");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
	return 1;
}       
*/
NPC_END;