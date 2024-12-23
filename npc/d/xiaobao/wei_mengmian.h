// wei_mengmian.h 蒙面女郎

NPC_BEGIN(CNwei_mengmian);

virtual void create()
{
	set_name("蒙面女郎", "nv lang");
	set("long","这是个身材娇好的女郎, 轻纱遮面,一双秀目中透出一丝杀气。");
	set("gender", "女性");
	set("age", 20);
	
	set("attitude", "peaceful");
 	set("icon",young_woman11);
	
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("hp", 5000);
	set("max_hp", 5000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 100000);

	set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
	set_skill("unarmed", 100);
    set_skill("jiuyang_shengong", 100);
	set_skill("lingfa", 100);
	set_skill("shenghuo_lingfa", 100);
	set_skill("qiankun_danuoyi", 100);
	set_skill("shenghuo_xinfa", 100);
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	
	carry_object("shenghuo_ling")->wield();

	call_out(do_die, 900);	
	set("no_kill",1);
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));
		if(me)
		{
			me->set_temp("wei/renwu6_10",1);
			tell_object(me, "\n$YEL蒙面女子咯咯一笑，道：今天你有帮手，不和你玩了。\n");
			tell_object(me, "$YEL说罢，跳出圈外，几个闪身就不见踪影。");
		}
	}
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}
NPC_END;