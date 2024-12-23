//xy_xuanwu6.h ÐþÎäËþÁù²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_xuanwu6);

virtual void create()
{    
	set_name("ÖòÁú", "zhu long");
	set("long","Ò»Ö»ÈËÃæÉßÉíµÄ³àÉ«ÉñÊÞ£¬¾ßÓÐºô·ç»½ÓêÖ®ÄÜ¡£");	
	
    set("title","ÐþÎäÊØÎÀ");
	
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
	set_skill("club", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);

    set_skill("shenzhao_gong", 300);
	set_skill("duanhun_qiang", 300);
	set_skill("huanhua_bu", 300);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 170);
    set("apply/damage",120);

	carry_object("changqiang")->wield();

}

NPC_END;




