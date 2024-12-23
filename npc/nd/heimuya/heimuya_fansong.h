//fansong.h
//code by zwb
//12-16
//inherit F_MASTER;


NPC_BEGIN(CNHeiMUYa_fansong);

virtual void create()
{
	
	set_name("����","fan song");
	
    set("nickname","������ħ" );
    set("title", "������̳���");
    set("gender", "����");
    set("age", 42);
    set("shen_type", -1);
    set("long","����������̳��ϡ�");
    set("attitude", "peaceful");
	set("icon",old_man1);
	
    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
	
    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3000);
    set("max_mp", 3000);
    set("mp_factore", 300);
	
    set("combat_exp", 1500000);
    
	
    set_skill("force", 150);
    set_skill("kuihua_xinfa", 150);
    set_skill("unarmed", 150);
    set_skill("changquan", 150);
    set_skill("dodge", 150);
    set_skill("lingxu_bu", 150);
    set_skill("parry", 150);
    set_skill("axe", 150);
    set_skill("duanyun_fu", 150);
	
    map_skill("force", "kuihua_xinfa");
    map_skill("axe", "duanyun_fu");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "lingxu_bu");
    map_skill("parry", "duanyun_fu");
	
    create_family("�������", 2, "����");
	
    carry_object("dafu")->wield();
    carry_object("cloth")->wear();
}

NPC_END;