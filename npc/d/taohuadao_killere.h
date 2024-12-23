// taohuadao_killere.c ,No greeting, �һ�������, ����
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNtaohuadao_killere);

virtual void create()
{
	set_name("ɱ��",  "killer" );
	set("long","����һ����ĸߴ�Ľ����ˣ����۴�׳��������Բ���������ƺ��������⡣ ");
	
	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "alchemist");
        set("icon",young_man5);
	
	set("age", 20+random(30));
	
	
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));
	
	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50+random(100));
	
	set("combat_exp", 10000+random(100000));
	set("score", 1);
	
	set("startroom","/d/city/dongmen");
	
	set_skill("force", 20+random(80));
	set_skill("bibo_shengong", 20+random(80));
	set_skill("dodge", 20+random(60));
	set_skill("anying_fuxiang", 20+random(60));
	set_skill("unarmed", 20+random(100));
	set_skill("luoying_shenzhang", 20+random(120));
	set_skill("parry", 20+random(80));
	set_skill("sword", 20+random(100));
	set_skill("luoying_shenjian", 10+random(110));
	
	map_skill("force", "bibo_shengong");
	map_skill("dodge", "anying_fuxiang");
	map_skill("parry", "luoying_shenjian");
	map_skill("sword", "luoying_shenjian");
	map_skill("unarmed", "luoying_shenzhang");
	
	set("chat_chance", 20);
	
	carry_object("gangjian")->wield();
}
virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "��ο���Щ��������Ķ��ܡ� ";
	case 1:
		return "ɱ! ɱ! ɱ!!!�� ";
	}
	return "";
}

virtual void init(CChar * me)
{
	if(userp(me))
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 2, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CChar * who = (CChar *)env->Present(param1);

	if(! who) return;

	if (env->query("no_fight"))
		env->set("no_fight", 0l);
	
	me->say("����һﲻҪ�ܣ��ô�ү�������㣡���� ");
	me->kill_ob(who); 
}

NPC_END;