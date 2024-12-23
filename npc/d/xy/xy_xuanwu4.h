//xy_xuanwu4.h 玄武塔四层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_xuanwu4);

virtual void create()
{    
	set_name("黄帝女魃", "nv ba");
	set("long","一只修炼成形的精怪，身着青衣，如女子模样。");	
	
    set("title","玄武守卫");
	
    set("str", 26); 
    set("int", 26);
    set("con", 26);
    set("dex", 26);

    set("icon",young_woman12);

    set("max_hp", 16000);
    set("mp", 8000);
    set("max_mp", 8000);
    set("mp_factor", 90); 
    set("combat_exp", 5000000); 
	
	set("no_kill",1);

    set_skill("force", 200);
	set_skill("club", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

    set_skill("shenzhao_gong", 200);
	set_skill("duanhun_qiang", 200);
	set_skill("huanhua_bu", 200);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 150);
    set("apply/damage",100);

	carry_object("changqiang")->wield();

}

NPC_END;




