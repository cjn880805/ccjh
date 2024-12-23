// shaolin_daoseng.c
//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_daoseng);

virtual void create()
{
	set_name("刀僧", "daoseng");
	set("title", "少林刀僧");
	set("long","他是一位云游四方的行者，风霜满面，行色匆匆，似乎正在办一件急事。" );
	
	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "bonze");
 	set("icon",old_monk);
	
	set("age", 35);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 6000);
	set("hp", 2000);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50);
	set("combat_exp", 200000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("shaolin_shenfa", 100);
	set_skill("xiuluo_dao", 100);
	set_skill("hunyuan_yiqi", 100);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "xiuluo_dao");
	map_skill("parry", "xiuluo_dao");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	add_money( 5000);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if (userp(me)
        && !( (me->environment())->query("no_fight") ) 
		&& EQUALSTR(me->querystr("gender"), "男性")
        && ( ( me->querymap("family")) 
		&& DIFFERSTR(me->querystr("family/family_name"), "少林派") 
		&& EQUALSTR(me->querystr("class"), "bonze")) )
	{
		say(" 你这个无耻少林叛徒，纳命来吧！！！");
		kill_ob(me);
	}
}
NPC_END;