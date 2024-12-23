//xy_qinglong4.h ÇàÁúËþËÄ²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_qinglong4);

virtual void create()
{    
	set_name("ÆÁÅî", "ping peng");
	set("long","¾ÞÐÍ¹ÖÊÞ£¬×óÓÒÓÐÊ×¡£");	
	
    set("title","ÇàÁúÊØÎÀ");

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
	set_skill("blade", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

    set_skill("shenzhao_gong", 200);
	set_skill("shengji_blade", 200);
	set_skill("feixian_bu", 200);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 150);
    set("apply/damage",100);

	carry_object("gangdao")->wield();
}

NPC_END;




