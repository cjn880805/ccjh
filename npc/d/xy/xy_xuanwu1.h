//xy_xuanwu1.h ÐþÎäËþËþµ×ÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_xuanwu1);

virtual void create()
{    
	set_name("ÇÙ³æ", "qing cong");
	set("long","Ò»Ö»ÊÞÃæÉßÉíµÄ¹ÖÎï¡£");	
	
    set("title","ÐþÎäÊØÎÀ");

    set("str", 20); 
    set("int", 20);
    set("con", 20);
    set("dex", 20);

    set("icon",random(46)+1);

    set("max_hp", 10000);
    set("mp", 5000);
    set("max_mp", 5000);
    set("mp_factor", 60); 
    set("combat_exp", 2000000); 
	
	set("no_kill",1);

    set_skill("force", 50);
	set_skill("club", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

    set_skill("shenzhao_gong", 50);
	set_skill("duanhun_qiang", 50);
	set_skill("huanhua_bu", 50);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 100);
    set("apply/damage", 50);

	carry_object("changqiang")->wield();

}


NPC_END;




