//xy_zhuque4.h ÖìÈ¸ËþËÄ²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_zhuque4);

virtual void create()
{    
	set_name("¾Å·ï", "jiou feng");
	set("long","¾ÅÊ×¹ÖÄñ£¬ÈËÃæÄñÉí¡£");	
	
    set("title","ÖìÈ¸ÊØÎÀ");
	
	set("str", 26); 
    set("int", 26);
    set("con", 26);
    set("dex", 26);
	
    set("icon",young_woman11);
	
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
	set_skill("hanxing_bada", 200);
	set_skill("fengyu_bu", 200);
	set_skill("douzhuan_xingyi", 200);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 150);
    set("apply/damage",100);

	carry_object("arrow1")->wield();

}

NPC_END;




