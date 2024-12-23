//xy_zhuque1.h ÖìÈ¸ËþËþµ×ÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_zhuque1);

virtual void create()
{    
	set_name("ÇàÄñ", "qing niao");
	set("long","³àÊ×ºÚÄ¿Ö®ÉñÄñ¡£");	
	
    set("title","ÖìÈ¸ÊØÎÀ");

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
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

    set_skill("shenzhao_gong", 50);
	set_skill("hanxing_bada", 50);
	set_skill("fengyu_bu", 50);
	set_skill("douzhuan_xingyi", 50);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 100);
    set("apply/damage", 50);
	carry_object("arrow1")->wield();
}

NPC_END;




