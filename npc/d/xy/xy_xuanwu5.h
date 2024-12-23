//xy_xuanwu5.h ÐþÎäËþÎå²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_xuanwu5);

virtual void create()
{    
	set_name("ÈÖÐûÍõÊ¬", "wang shi");
	set("long","Ò»Ö»Í¨Ìå³àºìµÄ¹ÖÊÞ£¬Âí×´ÎÞÊ×¡£");	
	
    set("title","ÐþÎäÊØÎÀ");
	
    set("str", 28); 
    set("int", 28);
    set("con", 28);
    set("dex", 28);

	set("icon",random(46)+1);

    set("max_hp", 18000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 100); 
    set("combat_exp", 6000000); 
	
	set("no_kill",1);

    set_skill("force", 250);
	set_skill("club", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);

    set_skill("shenzhao_gong", 250);
	set_skill("duanhun_qiang", 250);
	set_skill("huanhua_bu", 250);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 160);
    set("apply/damage",110);

	carry_object("changqiang")->wield();

}

NPC_END;




