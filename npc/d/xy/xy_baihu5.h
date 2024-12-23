//xy_baihu5.h °×»¢ËşÎå²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_baihu5);

virtual void create()
{    
	set_name("ÌìÎâ", "tian wu");
	set("long","ÈËÃæ¡¢È®¶ú¡¢ÊŞÉíÖ®Éñ¹Ö£¬¶úÉÏ×¹Á½ÇàÉß¡£");	
	
    set("title","°×»¢ÊØÎÀ");
	
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
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);

    set_skill("shenzhao_gong", 250);
	set_skill("celestrike", 250);
	set_skill("tiexue_steps", 250);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 160);
    set("apply/damage",110);

}

NPC_END;




