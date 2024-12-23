//lj_yundaozhu.h	云岛主
//秦波 2002、6、5

NPC_BEGIN(CNlj_yundaozhu);

void create()
{
	set_name("云岛主","yun daozhu");
	set("long", "他面相不俗、英伟过人，可是目光中已无傲气，看来是被生死符折磨得差不多了……");
	set("title", "碧石岛");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("icon",cateran);
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);
	set_weight(50000000);
	set("chat_chance", 80);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

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
	call_out(do_die, 1800);	
};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env;
	env = load_room("武陵春捻金峰");
	if(env->query("lj/wanxuanhuei"))
		tell_room(me->environment(), "\n$BLK万仙大会插血盟誓后，大伙杀上灵鹫宫夺取解药去呀！。\n");
	destruct(me);
}

char * chat_msg()
{
	CContainer * env= load_room("武陵春济楚谷");
	if(env->query("lj/lost"))
		call_out(do_die, 5);
	else if(env->query("lj/win"))
		set("lj/sha",1);
	return "";
}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("lj/renwu7") && query("lj/sha")) 
	{
		tell_object(me, "$HIR众人齐声大喝：“大胆狂徒,敢来万仙大会捣乱，给我将女娃娃留下！”");
		((CUser *)me)->Ready_PK();
		((CUser *)this)->Ready_PK();
		this->kill_ob(me);	
		me->kill_ob(this);
	}
}

virtual void die()
{
	tell_room(environment(), "我们是不会放过你们的！");
	destruct(this);
}

NPC_END;




