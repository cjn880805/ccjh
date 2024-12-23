// pub_xiaocui.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_xiaocui);

virtual void create()
{
	set_name("小翠", "xiao cui");

	set("icon", taoistess);
	set("nickname", "伺茶道童");
	set("gender", "女性" );
	set("age", 12+random(6));
	set("long","这是个年年龄不大的小姑娘，但宽松的道袍也遮不住她过早发育的身体。一脸聪明乖巧，满口伶牙俐齿。见有人稍微示意，便过去加茶倒水。");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("class", "taoist");
	
	set("str", 20);
	set("int", 28);
	set("con", 24);
	set("dex", 20);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);
	
	set("combat_exp", 1000+random(800));
	set("score", 1000);
	set("tea_count", 5);
	
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 15+random(10));
	set_skill("parry", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 3);
	
	create_family("武当派", 5, "弟子");
	
	set_inquiry("女儿香","这「女儿香」珍贵得很，连宋大侠的儿子也不能随便喝着．何况是你？");

	carry_object("greenrobe")->wear();
	carry_object("necklace");
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	say(snprintf(msg,255,"这位%s请先入座，我这就给您上茶。",query_respect(ob) ));
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obn;
	char msg[255];
	
	if ( query("tea_count") < 1) return notify_fail("现在只剩大碗茶了。");
	if ( EQUALSTR(ob->querystr("name"), "茶叶")  ||  EQUALSTR(ob->querystr("name"), "金项链" ) ) 
	{
		if ( EQUALSTR( ob->querystr("name"), "金项链" ) )
		{
			command(snprintf(msg,255,"kiss %ld" ,  who->object_id() )); 
			command(snprintf(msg, 255, "wield 0 %ld", ob->object_id()) );
		}
		
		if ( who->query_temp("marks/sit") )
		{
			if ( who->query_temp("tea_cup") > 0)	
			{
				command(snprintf(msg,255,"smile %ld", who->object_id() ));
			}
			else 
			{
				say(snprintf(msg,255,"小翠作了个揖道：%s请稍候，小女子这就给您换香茶。",query_respect(who) ), who);
			}
			
			who->set_temp("tea_cup", 5);
			remove_call_out(serve_tea);
			call_out(serve_tea, 1, who->object_id());
			
		} 
		else 
		{
			who->set_temp("tea_cup", 5);
			say(snprintf(msg,255,"小翠道了个万福：%s请先入上座，小女子这就给您去泡香茶。",query_respect(who) ), who);
		}

		SendMenu(who);
		return 1;
	}
	
	if ( EQUALSTR( ob->querystr("name"), "「女儿香」茶叶") )
	{
		if ( who->query_temp("marks/sit") )
		{
			who->command(snprintf(msg,255,"dance %ld" , who->object_id() ));
		} 
		else 
		{
			message_vision("小翠引$N到窗边风景最好的桌边坐下．", who);
		}
		
		who->set_temp("tea_cup", 10);
		who->set_temp("marks/sit", 1);
		obn = load_item("nuerxiang");//女儿香
		obn->move(who);
		add("tea_count",-1);
		return 1;
	}

	who->command(snprintf(msg,255,"? " , who->object_id() ));
	return 1;
}


static void serve_tea(CContainer *ob,LONG param1,LONG param2)
{
	CContainer * obn;
	CChar * who = (CChar *)(ob->environment())->Present(param1);

	if(! who || !who->query_temp("marks/sit") ) return;
	
	if (  who->query_temp("tea_cup") <= 0 || who->query("tea_count") < 1 )
	{
		obn = load_item("dawancha");//粗磁大碗
		obn->move(who->environment());
		message_vision("小翠搬出个大茶壶来，将桌上的大碗茶倒满．",who);
	} 
	else 
	{
		who->add_temp("tea_cup", -1);
		obn = load_item("xiangcha");//香茶
		who->add("tea_count",-1);
		obn->move(who->environment());
		message_vision("小翠拿出个绍兴小茶壶，沏了杯香茶，放在桌上．",who);
	}
	
	obn = load_item("mitao");//水蜜桃
	obn->move(who->environment());
	message_vision("小翠拿出一碟新鲜的水蜜桃，放在桌上．", who);
	
	return;
}
NPC_END;