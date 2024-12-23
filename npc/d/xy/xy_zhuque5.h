//xy_zhuque5.h ÖìÈ¸ËþÎå²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_zhuque5);

virtual void create()
{    
	set_name("Å®³óÖ®Ê¬", "nvchou shi");
	set("long","ÇàÒÂÅ®Ê¬£¬³£ÒÔñÇ±ÎÃæ£¬ÄËÒò³óÖ®¹Ê¡£");	
	
    set("title","ÖìÈ¸ÊØÎÀ");
	
	set("str", 28); 
    set("int", 28);
    set("con", 28);
    set("dex", 28);
	
	set("icon",young_woman10);

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
	set_skill("hanxing_bada", 250);
	set_skill("fengyu_bu", 250);
	set_skill("douzhuan_xingyi", 250);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 160);
    set("apply/damage",110);

	carry_object("arrow1")->wield();

}

NPC_END;




