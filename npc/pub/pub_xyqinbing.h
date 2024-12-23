// pub_xyqinbing.h


NPC_BEGIN(CNpub_xyqinbing);

virtual void create()
{
	set_name("亲兵", "qin bing" );

	set("icon", guarder);
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他手握钢刀，目视前方，真是威风凛凛。");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("blade", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	carry_object("gangdao")->wield();
	add_money(random(15)*100);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if (userp(me) &&  me->query_condition("killer")) 
	{
		kill_ob(me);
	}

	if( userp(me) && !is_fighting() ) 
	{
        if(!random(10))
		{ 
			message_vision("亲兵无可奈何的叹气道：赶又赶她不走，打又打她不过，拿她真没办法！", me);
		}
		else if(!me->query_temp("zhang/renwu5_24") && me->query("zhang/renwu5")==2 
			&& !me->query_temp("zhang/renwu5_240") && !me->query("zhang/renwu5_ok"))
		{
			me->set_temp("zhang/renwu5_240",1);
			tell_object(me,"\n$HIR亲兵小声嘀咕：大人好象最近迷上年轻男宠了……\n");
		}
	}
}

NPC_END;