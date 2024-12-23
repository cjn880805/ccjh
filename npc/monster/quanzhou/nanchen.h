//NANCHEN.h
//南琛·任务ＮＰＣ·台湾（现泉洲）·做任务·类别：送人·难度３０
//Teapot 2000-01-05

NPC_BEGIN(CNquanzhou_nanchen);

virtual void create()
{
	set_name("南嗔", "nanchen");
	set("long", "一个ＭＭ。");
	set("title", "[收购美男子]");
	set("gender", "女性");
	set("age", 28);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("chat_chance", 2);
	set("cutted",5);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "南嗔一皱眉头，意带幽怜。";
	case 1:
		return "南嗔轻轻的叹了口气。";
	case 2:
		return "南嗔伸了个懒腰，神色娇慵。";
	}

	return 0;
}


virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}



static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

    message_vision(snprintf(msg, 255, "$N看着$n幽幽的道：这位%s, 你能给我个男子吗？", query_respect(who)), me, who);

	return;
}



virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];

	if(! ob->is_character() ) return 0;

	if ( userp(ob) )
	{	
		say("南嗔惊讶的叫了一声：这……我可不敢要啊。", who);
		SendMenu(who);
		return 0;
	}

	if ( DIFFERSTR(ob->querystr("gender"), "男性"))
	{	
		say("南嗔惊讶的叫了一声：这……我可不敢要啊。", who);
		SendMenu(who);
		return 0;
	}
	
	if ( ob->query("age") <16 )
	{	
		say("南嗔微微皱眉道：他……还没成熟呢。", who); 
		SendMenu(who);
		return 0;
	}
    
	if ( ob->query("age") >50 )
	{	 
		say("南嗔唾了一口道：这种老骨头……我要他做什么！", who);
		SendMenu(who);
		return 0;
	}
	
	if ( ob->query("per") <20 )
	{	 
		say("南嗔说道：这……也太难看了点……", who);
		SendMenu(who);
		return 0;
	}
	
	int i;
	i=ob->query("per");
	i=i*(ob->query("age")-16);
	if(userp(ob))	// is user? i don't know that userp() will get or not when a player unconcious.
	{
		i=i*10;
		i=i+random(ob->query("mks"));	// add kill npc num.
	}
	i=random(i)+1;

	if (!userp(ob) && i>who->query("level")*10)	//Limit bonus w.s a npc.
		i=who->query("level")*10;
	
	who->add("combat_exp",i);

	 	i=random(i)+1;

    message_vision(snprintf(msg, 255, "$n对着$N道了个万福道：多谢这位%s。", query_respect(who)), who,this);
    message_vision(snprintf(msg, 255, "$N获得了%d经验！", i), who);

    message_vision("只见南嗔掏出一把精细的手术刀……",this);
    message_vision("……", this);
    message_vision("……", this);
    message_vision("……", this);
    message_vision("喀嚓！", this);
	if(random(query("cutted"))==0)
	{
//失手……:)
	    message_vision("结果……南嗔失手了……", this);
	    message_vision("只见血花……", this);
		if (ob->query("max_hp")>200)
			ob->add("max_hp",-200);
		else
			ob->set("max_hp",1);
	    message_vision("南嗔“呀”了一声，连忙掩盖住情况。", this);
	}
	ob->set("gender","无性");
	ob->set("class", "eneuch");
	ob->set("decided/nanchen",1);
	ob->add("combat_exp", random(3000));
	add("cutted",1);

    return 1;
}


virtual void die()
{
	revive(1);
	message_vision("$N望空中深深的吸了口气。", this);
	set("max_hp", 30000);
	set("eff_hp",30000);
	set("hp",30000);
}

NPC_END;
