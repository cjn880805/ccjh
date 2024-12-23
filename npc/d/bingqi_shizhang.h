//shizhang.h
//code by zwb
//12-16

NPC_BEGIN(CNBingQi_shizhang);

virtual void create()
{
	set_name("侍杖","shi zhang");

	set("nickname","杖");
	set("gender", "男性" );
	set("age", 20);
	set("long","他头上包着紫布头巾，一袭紫衫，没有一丝褶皱。");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	
	set("max_mp",500);
	set("mp_factor",50);
 	set("icon",young_man1);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	
	
	set("attitude", "peaceful");
        
	set_inquiry("铸杖","师傅命我帮助别人铸杖，但到现在也不见一个人影。谁要铸杖呢？");
	set_inquiry("原料","铸杖可用寒丝羽竹，海底金母，千年神木。但效果各不一样。");

	carry_object("cloth")->wear();
	set("no_huan",1);
};



virtual int accept_object(CChar * player,CContainer * ob)
{
	string name;
	char msg[255];

	if(!(player->query_temp("staff")))
	{
		say("师傅没有同意为你铸杖，您请回吧！",player);
		SendMenu(player);
		return 1;
	}
	player->delete_temp("staff");
	player->set_temp("m_staff",1);
	name = ob->querystr("id");

	if(name == "shen mu")
	{
		player->add_temp("shen mu",1);
	}
	else if(name == "jin mu")
	{
		player->add_temp("jin mu",1);
	}
	else if(name == "hanzhu")
	{
		player->add_temp("hanzhu",1);
	}
	else
	{
		say("这是什么！师傅说这不能用来打造兵器！",player);
		SendMenu(player);
		return 0;
	}

	say(snprintf(msg,255,"侍杖低头检视了一下手中的%s点了点头说：。。。好我们现在就开始铸杖",ob->query("name")),player);
	say(snprintf(msg,255,"请这位%s给杖起名字吧！",query_respect(player)),player);
	AddMenuItem("决定给杖起个名字！", "$2zhu $1 $2", player);
	AddMenuItem("你改变主意不打算铸杖了。", "", player);
	SendMenu(player);
	return 2;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(comm == "zhu")
		return do_zhu(me, arg);

	return 0;
}

int do_zhu(CChar * player, char * arg)
{
	CContainer * staff;
	CChar * npc=(CChar *)this;
	char		o_name[40],w_name[40];
	char		msg[255];


	if(!(player->query_temp("m_staff")))
		return notify_fail("什么?");
	player->delete_temp("m_staff");
	player->delete_temp("get_orc");
	player->delete_temp("or");

	if(player->query("weapon/make"))
	{
		say("侍杖一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？", player);
		SendMenu(player);
		return 2;
	}

	if(! strlen(arg) )
		return notify_fail("侍杖认真的说：想好杖的名称再对我说。");

	sscanf(arg,"%s",w_name);

	if(player->query_temp("shen mu")) strcpy(o_name,"千年神木");
	if(player->query_temp("jin mu")) strcpy(o_name,"海底金母");
	if(player->query_temp("hanzhu")) strcpy(o_name,"寒丝羽竹");

//	make_time=NATURE_D->game_time();

	message_vision(snprintf(msg,255,"%s沉吟了一会，对侍杖悄声说了几句话。侍杖点了点头。说：好吧！",player->name()),player);
	message_vision(snprintf(msg,255,"$N双手握住一个巨大的铁杖，猛的向炉中渐渐红热起来的%s挥去！",o_name),player);
	message_vision(snprintf(msg,255,"只听得棚的一声巨响，杖头和%s粘在了一起。",o_name ),player);
	message_vision("$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！" ,player);
	message_vision(snprintf(msg,255,"一身精血胶合着汩汩的内气，源源不断的向炉中的涌去！",o_name),player); 

	if((player->query("hp")) < (player->query("max_hp")) || (player->query("mp")) < (player->query("max_mp")))
	{
		message_vision("突然$N觉得气血一阵翻涌，一口真气接不上来。。。。",player);
		player->set("mp",0l);
		player->unconcious();
		return 1;
	}

	message_vision("只听咯的一声轻响，一柄巨杖从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！",player);
	message_vision("侍杖见状大叫：神杖初成，人血以祭！！闪开！",player);
	message_vision("$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。",player);
	message_vision("巨杖透胸穿出，侍杖惨号一声，鲜血溅得你满脸都是！",player);
	message_vision("侍杖脚下一个不稳，倒在了地上。侍杖已经奄奄一息了。",player);

	npc->set("max_hp",10);

	message_vision("巨杖又飞了起来，飞到半空，当的一声落回到地上。炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。",player);

	player->set("hp",10);
	player->set("mp",0l);

	player->set("weapon/make",1);		
	player->set("weapon/name",w_name);	
//	player->set("weapon/id",id);		
	player->set("weapon/lv",1);    	
	player->set("weapon/or",o_name);	
	player->set("weapon/value",0l);	      		
	player->set("weapon/type","杖");
//	player->set("weapon/time",make_time);

	staff=load_item("m_staff");	
	staff->move(player);
	message_vision("侍杖摸起地上，带着斑斑血迹还有些烫手的巨杖，说：杖。。已。。成。。，侍杖的任务。。。也就完成了。。。。",player );
	message_vision("侍杖艰难的说：杖。。您。。收好，我该走了。。。",player);
	message_vision("侍杖说完。倏的便不见了。",player);
	npc->die();
	return 1;
}
NPC_END;
