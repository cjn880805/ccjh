// shenlong_hong.c 洪安通

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;
//inherit F_MASTER;

NPCSHENLONG_BEGIN(CNshenlong_hong);

virtual void create()
{
	set_name("洪安通",  "hong antong");
	set("title",  "神龙教教主" );
	set("nickname",  "永享仙福" );
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。 ");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
 	set("icon",old_man2);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1500000);
	set("score", 400000);
	
	set_skill("force", 200);
	set_skill("shenlong_xinfa", 200);
	set_skill("dodge", 180);
	set_skill("yixingbu", 160);
	set_skill("unarmed", 200);
	set_skill("strike",400);
//	set_skill("shenlong_quanfa", 200);		//没有该技能 lanwood 2000-12-29
	set_skill("parry", 150);
	set_skill("staff", 200);
	set_skill("shedao_qigong", 180);
	set_skill("literate", 100);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
//	map_skill("unarmed", "shenlong_quanfa");
	map_skill("parry", "shedao_qigong");
	map_skill("staff", "shedao_qigong");
	
	set_inquiry("入教"," 一般人是入不了我神龙教的");
	set_inquiry("洪安通"," 你不想活了是不是? ");
	set_inquiry("教主"," 我就是神龙教教主. ");
	set_inquiry("口号"," 万年不老!永享仙福!寿与天齐!文武仁圣! ");
	
	set("chat_chance_combat", 50);  
	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	add_money( 5000);

}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("usedgao"))          
			set("combat_exp",500000);
		set("hp",10);
	}
	return "";
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	if (strcmp(comm,"join") == 0)
		return do_join(me,arg);

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !me->query_temp("pending/flatter") )
		return 0;
	if( !strlen(arg)) return notify_fail("你说我什么？ ");
	me->delete_temp("pending/flatter");

	message_vision(snprintf(msg,255,"$N大声说道：%s", arg), me);

	if( strstr(arg, "万年不老")
		&&( strstr(arg, "永享仙福") 
		|| strstr(arg, "寿与天齐") 
		|| strstr(arg, "文武仁圣") ))
	{
		command("smile");
		say(" 这还差不多。 ");
		me->set("learnhong", 1);
		command(snprintf(msg,255,"recruit %ld" , me->object_id() ));
	} 
	else
	{
		say(" 你如此不把我放在眼里，我又怎能容你？!");
		kill_ob(me); 
	}
	return 1;
}

int do_join(CChar *me,char * arg)
{
	char msg[255];

	if(me->query("shenlongjiao")) 
	{
		message_vision( "洪安通说道：你已经是神龙教弟子了。 " ,me);
		return 1;
	}
	if (me->query("repute")>-1000)
	{
		message_vision( "洪安通对$N大怒道：还想入教?一看你就不是好人! " ,me);
		kill_ob(me); 
		return 1;
	}
	if (me->query_combat_exp() < 20000)
	{
		message_vision( "洪安通对$N摇头道：你的实战经验太低。 " ,me);
		return 1;
	}
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1))
	{
		me->set("shenlongjiao",1);
		command(snprintf(msg,255,"tell %ld 你现在就是神龙教弟子了. ", me->object_id() ));
		return 1;	
	}
	else 
	{
		message_vision( "洪安通对$N大怒道：还想入教?一看你就不是好人! " ,me);
		kill_ob(me); 
		return 1;
	}
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
    if (ob->query_skill("shenlong_xinfa",1) < 80 ) 
	{
        say("你的本门内功心法太低了,还是努努力先提高一下吧!", ob);
		SendMenu(ob);
		return;
    }
    if (ob->query_skill("shedao_qigong",1) < 80 ) 
	{
        say("你的本门杖法太低了,还是努努力先提高一下吧!", ob);
		SendMenu(ob);
		return;
    }
    if (ob->query("repute") > -10000  )
	{
        say(" 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！", ob);
		SendMenu(ob);
		return;
	}
    say(" 很好，很好。");
    command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}


virtual int prevent_learn(CChar * ob, string arg)
{
	if( ob->query("learnhong")) return 0;
	if (ob->query("repute") > -1000) 
	{
		say("我越看你越象白道派来卧底的。");
		kill_ob(ob); 
		return 1;
	}
	if( ob->query_temp("pending/flatter") ) 
	{
		say("你如此不把我放在眼里，我又怎能容你？!");
		kill_ob(ob); 
		return 1;
	}
	else 
	{
		say("我洪安通比起古往今来的圣人怎么样啊？");
		message_vision("洪安通微闭双眼，手捻长须，一付等人拍马的样子。 ",ob);
		ob->set_temp("pending/flatter", 1);
		return 1;
	}
}

virtual int recognize_apprentice(CChar *ob)
{
	if( ob->query("learnhong")) return 1;
	return 0;
}

NPCSHENLONG_END;