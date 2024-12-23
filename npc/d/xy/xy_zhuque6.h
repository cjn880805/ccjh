//xy_zhuque6.h ÖìÈ¸ËþÁù²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_zhuque6);

virtual void create()
{    
	set_name("óOÍ·", "huan tou");
	set("long","ÈËÃæÄñà¹£¬ÓÐÒí£¬Ê³º£ÖÐÓã£¬ÕÈÒí¶øÐÐ¡£");	
	
    set("title","ÖìÈ¸ÊØÎÀ");
	
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
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);

    set_skill("shenzhao_gong", 300);
	set_skill("hanxing_bada", 300);
	set_skill("fengyu_bu", 300);
	set_skill("douzhuan_xingyi", 300);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 170);
    set("apply/damage",120);

	carry_object("arrow1")->wield();

}

NPC_END;




