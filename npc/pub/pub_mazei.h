// pub_mazei.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_mazei);

virtual void create()
{
	set_name("����",  "ma zei");

	set("icon", cateran);
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("per", 16);
	set("long", "һ���뺷��������");
	set("combat_exp", 50000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 10);
	
	carry_object("gangjian")->wield();
	carry_object("tiejia")->wear();
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if (userp(me) && !is_fighting())
	{
		if(! me->query_temp("mazei"))
		{
			remove_call_out(do_greeting);
			call_out(do_greeting, 1, me->object_id());
				
			remove_call_out(do_killing);
			call_out(do_killing, 10, me->object_id());
		}
		else
			call_out(do_killing, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)(ob->environment())->Present(param1);
	if(! me) return;

	message_vision( "�����ᵶ������һ���󺰣���ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n�����ȵ���ʶ������������������������С���ߣ�", me);
	me->set_temp("mazei", 1);
}

static void do_killing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who || ! who->query_temp("mazei")) return;
	
	message_vision("$N����$n����㾹�Ҳ��������������㣡", me, who);
	me->kill_ob(who);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000) 
	{
		message_vision("$N��������Ȼ����Ǯ��������ǰ����", this);
		who->delete_temp("mazei");
		destruct(ob);
		return 1;
	}

	message_vision("$N��ŭ������ô��Ǯ��", this);
	destruct(ob);
	return 1;
}

NPC_END;