//wei_jiguanren.h
NPC_BEGIN(CNwei_jiguanren);

virtual void create()
{
	set_name("机关人","ji guan ren");

	set("icon", triggerman2);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "这是一个铜皮铁骨的机关人。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "aggressive");

	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 500);

	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 10);

	call_out(do_die, 900);	
	set("no_kill",1);
};

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));
		if(me)
		{
			tell_object(me, "\n$HIC只见机关人嘎吱嘎吱一阵乱响，散做一团。\n");
			if(me->query_temp("wei/renwu8_10"))
				me->set_temp("wei/renwu8_11",1);
		}
	}
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

NPC_END;
