//shibian.h
//code by zwb
//12-16

NPC_BEGIN(CNBingQi_shibian);

virtual void create()
{
	set_name("侍鞭","shi bian");

	set("nickname","鞭");
	set("gender", "女性" );
	set("age", 20);
	set("long","她头上包着天青色纱巾，一领天青色布袍，没有一丝褶皱。");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	
	set("max_mp",500);
	set("mp_factor",50);
 	set("icon",young_woman4);

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
        
	set_inquiry("铸鞭","师傅命我帮助别人铸鞭，但到现在也不见一个人影。谁要铸鞭呢？");
	set_inquiry("原料","铸鞭可用寒丝羽竹，海底金母，千年神木。但效果各不一样。");

	carry_object("cloth")->wear();
	set("no_huan",1);
};

virtual int accept_object(CChar * player,CContainer * ob)
{
	char msg[255];
	string name;

	if(!(player->query_temp("staff")))
	{
		say("师傅没有同意为你铸鞭，您请回吧！",player);
		SendMenu(player);
		return 1;
	}
	player->delete_temp("staff");
	player->set_temp("m_staff",1);
	name=ob->querystr("id");

	if(name=="hanzhu")
	{
		player->add_temp("hanzhu",1);
	}
	else
	{
		say("这是什么！师傅说这不能用来打造长鞭！",player);
		SendMenu(player);
		return 0;
	}

	say(snprintf(msg,255,"侍鞭低头检视了一下手中的%s点了点头说：。。。好我们现在就开始铸鞭",ob->query("name")),player);
	say(snprintf(msg,255,"请这位%s给鞭起名字吧！(zhu 鞭的名字)",query_respect(player)),player);

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
		say("侍鞭一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？");
		return 2;
	}

	if(!arg)
		return notify_fail("侍鞭认真的说：想好鞭的名称再对我说。");
	sscanf(arg,"%s",w_name);

	if(player->query_temp("shen mu")) strcpy(o_name,"千年神木");
	if(player->query_temp("jin mu")) strcpy(o_name,"海底金母");
	if(player->query_temp("hanzhu")) strcpy(o_name,"寒丝羽竹");

//	make_time=NATURE_D->game_time();

	message_vision(snprintf(msg,255,"%s沉吟了一会，对侍鞭悄声说了几句话。侍鞭点了点头。说：好吧！",player->name()),player);
	message_vision("$N双手紧紧握住匕首，用尽全身的力气向竹杆削去！",player);
	message_vision("只听得嗤的一声轻响，匕首一滑竟刺到了$N的手上！",player);
	message_vision("$N只觉得手背的伤口一热，随着鲜血的流出，浑身的血液似乎都沸腾了起来！" ,player);
	message_vision("一身精血胶合着汩汩的内气，源源不断的向侍鞭手中的寒丝羽竹涌去",player); 

	if((player->query("hp")) < (player->query("max_hp")) || (player->query("mp")) < (player->query("max_mp")))
	{
		message_vision("突然$N觉得气血一阵翻涌，一口真气接不上来。。。。",player);
		player->set("mp",0l);
		player->unconcious();
		return 1;
	}

	message_vision("只听咯的一声轻响，一柄巨鞭从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！",player);
	message_vision("侍鞭见状大叫：神鞭初成，人血以祭！！闪开！",player);
	message_vision("$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。",player);
	message_vision("巨鞭透胸穿出，侍鞭惨号一声，鲜血溅得你满脸都是！",player);
	message_vision("侍鞭脚下一个不稳，倒在了地上。侍鞭已经奄奄一息了。",player);

	npc->set("max_hp",10);

	message_vision("巨鞭又飞了起来，飞到半空，当的一声落回到地上。炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。",player);

	player->set("hp",10);
	player->set("mp",0l);

	player->set("weapon/make",1);		
	player->set("weapon/name",w_name);	
//	player->set("weapon/id",id);		
	player->set("weapon/lv",1);    	
	player->set("weapon/or",o_name);	
	player->set("weapon/value",0l);	      		
	player->set("weapon/type","鞭");
//	player->set("weapon/time",make_time);

	staff=load_item("m_staff");	
	staff->move(player);
	message_vision("侍鞭摸起地上，带着斑斑血迹还有些烫手的巨鞭，说：鞭。。已。。成。。，侍鞭的任务。。。也就完成了。。。。",player );
	message_vision("侍鞭艰难的说：鞭。。您。。收好，我该走了。。。",player);
	message_vision("侍鞭说完。倏的便不见了。",player);
	npc->die();
	return 1;
}
NPC_END;
