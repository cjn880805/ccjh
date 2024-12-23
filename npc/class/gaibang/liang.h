//liang.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_liang);

virtual void create()
{
	set_name("梁有桥", "liang cuangong");
	set("title", "丐帮九袋长老");
	set("nickname", "传功长老");
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁有桥是丐帮出道最久，武功最高的长老，在武林中享名已久。");

	set("attitude", "peaceful");
	set("icon",begger);
	set("beggarlvl", 9);
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("hp", 900);
	set("max_hp", 2700);
	
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 120);
	set("combat_exp", 250000);
	
	set_skill("force", 150); 
	set_skill("huntian_qigong", 155); 
	set_skill("unarmed", 175); 
	set_skill("xianglong_zhang", 180); 
	set_skill("dodge", 97); 
	set_skill("xiaoyaoyou", 90); 
	set_skill("parry", 80); 
	set_skill("staff", 150); 
	set_skill("dagou_bang", 150); 
	set_skill("begging", 100); 
	//set_skill("checking", 90);
	set_skill("xunshou_shu", 90);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("staff", "dagou_bang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");

	set("chat_chance_combat", 20);
	set("no_huan",1);
	
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	if (me->query_str() < 25) 
	{
		say("我们丐帮的武艺一向以刚猛为主，你臂力太弱，似乎不宜学丐帮的功夫？", me);
		SendMenu(me);
		return;
	}
	else
		accept_student(me);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
        
    if(userp(me) && !is_fighting()) 
	{
		if( DIFFERSTR(me->querystr("family/family_name"), "丐帮"))
		{
			remove_call_out(do_saying);
			call_out(do_saying, 1, me->object_id());
        }
	}
}

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CContainer * env = ob->environment();
	CChar * who = (CChar *)env->Present(param1);

    if (! who) return;
	if(DIFFERSTR(env->querystr("base_name"), "扬州密林5"))
		return;

	message_vision("梁有桥看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！", who);
	
	who->move(load_room("扬州树林"));
	tell_room(who->environment(), 
		snprintf(msg, 255, "只听“乒”地一声，%s从小门里飞了出来。", who->name()), who);
}

NPC_END;
