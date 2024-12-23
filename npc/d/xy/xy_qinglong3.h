//xy_qinglong3.h ÇàÁúËþÈý²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_qinglong3);

virtual void create()
{    
	set_name("ÌìÓÝ", "tian yu");
	set("long","Æä×´ÓëÈËÎÞÒì£¬Î©Ë«±Û·´Éú¡£");	
	
    set("title","ÇàÁúÊØÎÀ");

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
	set_skill("blade", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);

    set_skill("shenzhao_gong", 150);
	set_skill("shengji_blade", 150);
	set_skill("feixian_bu", 150);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 140);
    set("apply/damage", 90);

	carry_object("gangdao")->wield();
}

NPC_END;




