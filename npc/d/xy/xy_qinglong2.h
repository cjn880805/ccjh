//xy_qinglong2.h ÇàÁúËþ¶þ²ãÊØÎÀ
//ÇØ²¨ 2002¡¢12¡¢12

NPC_BEGIN(CNxy_qinglong2);

virtual void create()
{    
	set_name("òâÈË", "yu ren");
	set("long","ÉÃ³¤¹­Éä»ÆÉß£¬Òò´ËÎÅÃû£¬ÆäÐÔÐ×ÃÍÒì³£¡£");	
	
    set("title","ÇàÁúÊØÎÀ");

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
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

    set_skill("shenzhao_gong", 100);
	set_skill("shengji_blade", 100);
	set_skill("feixian_bu", 100);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 120);
    set("apply/damage", 75);

	carry_object("gangdao")->wield();
}

NPC_END;




