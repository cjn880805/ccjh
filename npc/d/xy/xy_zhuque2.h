//xy_zhuque2.h ÖìÈ¸Ëþ¶þ²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_zhuque2);

virtual void create()
{    
	set_name("úž", "zhu");
	set("long","ÒìÄñ£¬Éí»Æ£¬³à×ã£¬ÓÐÁùÊ×¡£");	
	
    set("title","ÖìÈ¸ÊØÎÀ");

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
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

    set_skill("shenzhao_gong", 100);
	set_skill("hanxing_bada", 100);
	set_skill("fengyu_bu", 100);
	set_skill("douzhuan_xingyi", 100);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 120);
    set("apply/damage", 70);

	carry_object("arrow1")->wield();

}

NPC_END;




