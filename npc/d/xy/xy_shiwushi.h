//shiwushi.h 石人武士
//12-15

NPC_BEGIN(CNxy_shiwushi);

virtual void create()
{
	set_name("石人武士","shi wus hi");

	set("icon", triggerman2);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "这是守护飞凌九霄阁的石人武士。\n");
	set("combat_exp", 300000+random(10000000));
	set("shen_type", 1);
	set("attitude", "aggressive");
	
	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("hp", 20000+random(10000));
	set("max_hp", 20000+random(10000));
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 100);

	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",250);
	set_skill("strike", 250);
	set_skill("literate", 250);
	set_skill("club", 250);

	set_skill("zhemei_shou",250);
	set_skill("liuyang_zhang",250);
	set_skill("yueying_wubu",250);
	set_skill("bahuang_gong", 250);
	set_skill("duanhun_qiang", 250);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("club", "duanhun_qiang");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	
	set("apply/armor", 100);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);

	carry_object("tiejia")->wear();
	carry_object("changqiang")->wield();

	set("no_kill",1);

};

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * env = environment();
		CContainer * me=env->present(querystr("owner"));
		CContainer * npc;
		
		if(me)
		{
			me->add("xy/renwu6_lost",1);
			tell_object(me,"\n$HIC你倾尽全力，奋力一击，石人武士轰然倒地，但你眼前也是一黑，晕了过去。\n");	
			((CChar *)me)->unconcious();
			me->set("hp",me->query("eff_hp"));
			me->move(load_room("逍遥谷飞凌九宵阁正门"));
			if(me->query_temp("xy/renwu6_5"))
			{
				npc=env->present("li qiou heng");
				me->delete_temp("xy/renwu6_4");
			}
			else
			{
				npc=env->present("li cang hai");
				me->delete_temp("xy/renwu6_1");
			}
			if(npc)
			{
				npc->move(load_room("逍遥谷飞凌九宵阁正门"));
			}
			me->delete_temp("xy/renwu6_2");
		}
	}
	destruct(this);
}

NPC_END;
