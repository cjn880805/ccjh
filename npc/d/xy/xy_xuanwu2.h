//xy_xuanwu2.h ÐþÎäËþ¶þ²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_xuanwu2);

virtual void create()
{    
	set_name("Ø®Ç¿", "yu qiang");
	set("long","Ò»Ö»ÈËÃæÄñÉíµÄ¹ÖÊÞ£¬¶úÉÏ´©×ÅÁ½ÇàÉß¶ú×¹£¬½ÅÍóÉÏ»¹È¦×ÅÁ½³àÉß¡£");	
	
    set("title","ÐþÎäÊØÎÀ");

    set("str", 22); 
    set("int", 22);
    set("con", 22);
    set("dex", 22);

    set("icon",random(46)+1);

    set("max_hp", 12000);
    set("mp", 6000);
    set("max_mp", 6000);
    set("mp_factor", 70); 
    set("combat_exp", 3000000); 
	
	set("no_kill",1);

    set_skill("force", 100);
	set_skill("club", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

    set_skill("shenzhao_gong", 100);
	set_skill("duanhun_qiang", 100);
	set_skill("huanhua_bu", 100);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 120);
    set("apply/damage", 75);

	carry_object("changqiang")->wield();
}

NPC_END;




