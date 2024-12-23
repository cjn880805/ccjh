//xy_licanghai.h

NPC_BEGIN(CNxy_licanghai);

virtual void create()
{    
    set_name("李沧海", "li cang hai");
    set("long","只见她虽然年逾古稀，仍然貌若仙子，岁月并未在她身上留下多少痕迹。");	
    set("gender", "女性"); 
    set("title","逍遥仙子");
    set("age", 75);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 40);
    set("icon",young_woman5);
	create_family("逍遥派", 1, "小师妹");

    set("max_hp", 25500);
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 100); 
    set("combat_exp", 3800000); 
    set("score", 200000);
	
	set("no_kill",1);

    set_skill("force", 300);
    set_skill("beiming_shengong", 300);
    set_skill("dodge", 300);
    set_skill("lingboweibu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 300);
    set("apply/damage", 180);
    carry_object("gangdao")->wield();

}

virtual int do_look(CChar * me)
{
	if(me->querymap("xy") )
	{
		say("只见她虽然年逾古稀，仍然貌若仙子，岁月并未在她身上留下多少痕迹，看着她，你似乎有一种似曾相识的感觉。", me);
		SendMenu(me);
		return 1;
	}
	return CChar::do_look(me);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->querymap("xy") )
	{
		say("只听她翻来覆去的念着：“此情可待成追忆，只是当时已惘然......”", me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}


NPC_END;




