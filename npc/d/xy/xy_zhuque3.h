//xy_zhuque3.h ÖìÈ¸ËþÈý²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_zhuque3);

virtual void create()
{    
	set_name("¿ñÄñ", "kuang niao");
	set("long","Îå²ÉÖ®Äñ£¬Í·¶¥ÓÐ¹Ú¡£");	
	
    set("title","ÖìÈ¸ÊØÎÀ");
	
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
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);

    set_skill("shenzhao_gong", 150);
	set_skill("hanxing_bada", 150);
	set_skill("fengyu_bu", 150);
	set_skill("douzhuan_xingyi", 150);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 130);
    set("apply/damage", 80);

	carry_object("arrow1")->wield();

}

NPC_END;




