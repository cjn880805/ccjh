// pub_guidao.c
//code by Fisho

NPC_BEGIN(CNpub_guidao);
 
virtual void create()
{
	set_name("王五",   "wang wu"  );

	set("icon", young_man2);
	set("title", "酒客");
	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long","这是个喝得醉醺醺的酒鬼，正盯着手中的酒杯喃喃地念叨着什麽。" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);

	set_skill("blade", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 30);
	set_skill("parry", 50);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();

	set_inquiry("王老五","哈哈哈! 有趣有趣，可惜你认错人了。");
	set_inquiry("鬼刀",ask_me);
}

virtual char * chat_msg_combat()
{
	switch (random(3) )
	{
	case 0:
		return "王五说道: 你当真吃了豹子胆啦 ? 敢跟大爷较量 ! ";
	case 1:
		return "王五忽然挥出一刀，招数精奇，但刀到中途却又急忙收招。";
	case 2:
		return "王五说道: 快滚 ! 算我输了还不行 ?....";
	}
	return "";
}

static char * ask_me(CNpc * who, CChar * me)
{
	if( who->query("revealed") ) 
	{
		if( me->is_killing(who) ) 
			return "你既然知道了我的身分，今日休想活命！";
		else 
		{
			who->kill_ob(me);
			//who->fight_ob(ob);
			return "老子就是鬼刀王五，鬼刀王五就是你老子！纳命来吧！";
		}
	}

	if( (random(10) < 5) || me->is_fighting() )
		return "我…不知道。";

	who->set_temp("apply/attack",  50);
	who->set_temp("apply/defense", 50);
	who->set_temp("apply/damage",  20);
	who->set("title",  "鬼刀" );

	tell_room(me->environment(),"王五眼中突然放出异样的光芒，颤声说道，看来...你都知道了？\n王五大喝一声，叫道，既然如此，老子今天反正豁出去，跟你拼了。\n王五使开单刀，招数精奇，沉猛狠辣，和刚才的醉鬼简直判若两人。" ,me);

	who->set("pursuer", 1);
	who->set("attitude", "aggressive");
	who->set("vendetta/authority", 1);
	who->set("chat_chance", 15);
	who->set("bellicosity", 10000);
	who->set("combat_exp", 80000);
	who->set_skill("blade", 80);
	who->set_skill("dodge", 70);
	who->set_skill("unarmed", 60);
	who->set_skill("parry", 80);

	who->call_out(all_kill_me, 1);

	who->add_money(500);
	who->set("revealed", 1);
	
	return "老子就是鬼刀王五，鬼刀王五就是你老子！纳命来吧！";
}

//杀所有玩家
static void all_kill_me(CContainer * ob, LONG param1, LONG param2)
{
	POSITION p;
	CChar * me = (CChar *)ob;
	DTItemList search;
	CContainer * obj;
	CChar * who = NULL;
			
	CopyList(&search, (me->environment())->Get_ItemList());
		
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if(! userp(obj)) continue;
		
		who = (CChar *)obj;
		me->set_killer(who);
		who->set_killer(me);
	}

	if(who)
		me->kill_ob(who);
}

NPC_END;