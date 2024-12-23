//xy_baihu4.h °×»¢ËşËÄ²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_baihu4);

virtual void create()
{    
	set_name("Éİ±ÈÊ¬", "she bishi");
	set("long","ÈËÃæ¡¢È®¶ú¡¢ÊŞÉíÖ®Éñ¹Ö£¬¶úÉÏ×¹Á½ÇàÉß¡£");	
	
    set("title","°×»¢ÊØÎÀ");
	
	set("str", 26); 
    set("int", 26);
    set("con", 26);
    set("dex", 26);
	
    set("icon",random(46)+1);
	
    set("max_hp", 16000);
    set("mp", 8000);
    set("max_mp", 8000);
    set("mp_factor", 90); 
    set("combat_exp", 5000000); 
	
	set("no_kill",1);

    set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

    set_skill("shenzhao_gong", 200);
	set_skill("celestrike", 200);
	set_skill("tiexue_steps", 200);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 150);
    set("apply/damage",100);

}

NPC_END;




