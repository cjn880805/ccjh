//xy_xuanwu3.h ÐþÎäËþÈý²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_xuanwu3);

virtual void create()
{    
	set_name("Ç¿Á¼", "qing liang");
	set("long","»¢Ê×ÈËÉíµÄ¹ÖÎï£¬ËÄÖ«ÈçÌã×´¡£");	
	
    set("title","ÐþÎäÊØÎÀ");

    set("str", 24); 
    set("int", 24);
    set("con", 24);
    set("dex", 24);

    set("icon",random(46)+1);

    set("max_hp", 14000);
    set("mp", 7000);
    set("max_mp", 7000);
    set("mp_factor", 80); 
    set("combat_exp", 4000000); 
	
	set("no_kill",1);

    set_skill("force", 150);
	set_skill("club", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);

    set_skill("shenzhao_gong", 150);
	set_skill("duanhun_qiang", 150);
	set_skill("huanhua_bu", 150);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");

    set("apply/armor", 140);
    set("apply/damage", 90);

	carry_object("changqiang")->wield();

}

NPC_END;




