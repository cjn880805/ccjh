//lj_shuxia.h	灵鹫宫属下
//秦波 2002、6、1

NPC_BEGIN(CNlj_shuxia1);

void create()
{
	if(random(2))
		set_name("岛主","dao zhu");
	else
		set_name("洞主","dong zhu");

	set("title", "灵鹫宫属下");
	if(random(2))
	{
		set("gender", "男性");
	}
	else
	{
		set("gender", "女性");
	}
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",random(53));
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);
	set("no_kill",1);
	set("chat_chance", 80);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");

	call_out(do_die, 300);
	set("no_kill",1);
	
};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

virtual void die()
{
	tell_room(environment(), "我们是不会放过你们的！");
	destruct(this);
}

NPC_END;