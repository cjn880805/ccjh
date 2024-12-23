//xy_qinglong6.h 青龙塔六层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_qinglong6);

virtual void create()
{    
	set_name("鱼妇", "yu fu");
	set("long","状如妇人之怪鱼，据传乃蛇化之，具有不死之生。");	
	
    set("title","青龙守卫");

	set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 30);

	set("icon",young_woman11);

    set("max_hp", 20000);
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 110); 
    set("combat_exp", 7000000); 
	
	set("no_kill",1);

    set_skill("force", 300);
	set_skill("blade", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);

    set_skill("shenzhao_gong", 300);
	set_skill("shengji_blade", 300);
	set_skill("feixian_bu", 300);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 170);
    set("apply/damage",120);

	carry_object("gangdao")->wield();
}

NPC_END;




