//xy_baihu6.h 白虎塔六层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_baihu6);

virtual void create()
{    
	set_name("夔", "kui");
	set("long","形异兽，状如牛，苍身而无角，仅一足，出入水则必风雨，其光如日月，其声如雷。");	
	
    set("title","白虎守卫");
	
	set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 30);

	set("icon",random(46)+1);

    set("max_hp", 20000);
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 110); 
    set("combat_exp", 7000000); 
	
	set("no_kill",1);

    set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);

    set_skill("shenzhao_gong", 300);
	set_skill("celestrike", 300);
	set_skill("tiexue_steps", 300);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 170);
    set("apply/damage",120);

}

NPC_END;




