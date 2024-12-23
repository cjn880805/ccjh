// pub_hufei.c 

// code by Fisho
// date:2000-12-17
//这个NPC和我新写的重复
NPC_BEGIN(CNpub_hufei);

virtual void create()
{
	set_name("胡飞","hu fei");

	set("icon", young_man2);
	set("gender", "男性");
	set("nickname", "雪山飞狐");
	set("age", 25);
	set("long","他就是胡大刀之子，因其武功高强神出鬼没。在江湖上人送外号「雪山飞狐」。他身穿一件白色长衫，腰间别着一把看起来很旧的刀。他满腮虬髯，根根如铁，一头浓发，却不结辫。");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 20);
	
	set("hp", 3000);
	set("max_hp", 9000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 190000);
	set("score", 20000);
	 
	set_skill("force", 110);             // 基本内功
	set_skill("hujia_daofa", 150);    // 胡家刀法	
	set_skill("blade", 120);           // 基本刀法
	set_skill("hunyuan_yiqi", 120);   // 混元一气功
	set_skill("dodge", 120);           // 基本躲闪
	set_skill("shaolin_shenfa", 120);   // 胡家身法
	set_skill("parry", 120);             // 基本招架
		
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "hujia_daofa");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");
   	
	set_inquiry("宝刀",ask_me);

	set("baodao_count",1);
	carry_object("cwbdao")->wield();
    carry_object("cloth")->wear();
 
}

virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "胡飞叹了口气道:“不知什么时候还能再见到苗姑娘。";
	case 1:
		return "胡飞恨恨道：“苗天龙是我杀父仇人，我必报此仇！”";
	}
	return "";
}

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer * obj;
	if( me->query("repute") < 0)
	{
		who->call_out(do_kill,1,me->object_id());
		return "";
	}

	if( me->query("repute") < 100000 )
	    return "以你目前的作为是不能拿这把刀的。";

   	if(me->query("baodao_count") > 1)
	{		
    //	call_out(waiting,0,me,ob->object_id());
		me->add("baodao_count", -1);
    	obj = load_item ("cwbdao");//闯王宝刀
    	obj->move(me);
		return " 好吧，这把闯王宝刀就赠与你，希望你好好利用它。";
	}
	
	return "你来晚了, 现在这把刀已不在此处。";
}

static void do_kill(CContainer *ob,LONG param1,LONG param2)
{
	CChar * npc = (CChar *)ob;
	CChar * me=(CChar *)(npc->environment())->Present(param1);
	if (!me) return;
 
    if ((me->environment())->query("no_fight"))
	    (me->environment())->set("no_fight", 0l);
 
    if (userp(me))
    {
        npc->say("你这恶贼竟敢打我宝刀的主意, 给我纳命来！");
		npc->kill_ob(me);
    }
}	

NPC_END;