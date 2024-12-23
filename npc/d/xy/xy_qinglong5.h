//xy_qinglong5.h ÇàÁúËþÎå²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_qinglong5);

virtual void create()
{    
	set_name("ÏÄ¸ûÖ®Ê¬", "xiageng shi");
	set("long","ÎÞÊ×Ö®ÈË£¬²Ù¸ê¶ÜÁ¢¡£");	
	
    set("title","ÇàÁúÊØÎÀ");

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
	set_skill("blade", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);

    set_skill("shenzhao_gong", 250);
	set_skill("shengji_blade", 250);
	set_skill("feixian_bu", 250);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 160);
    set("apply/damage",110);

	carry_object("gangdao")->wield();
	carry_object("shield")->wield();

}

NPC_END;




