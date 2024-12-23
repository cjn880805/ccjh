// shaolin_longjun.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_longjun);

virtual void create()
{
	set_name("��", "long jun");
	set("title", "��ǰ����");
	set("gender", "����");
	set("age", 32);
	set("long","���Ǵ��ڸ��֣�һ��ι��������������ƥ��");
	set("combat_exp", 300000);
	set("shen_type", -1);
	set("attitude", "heroism");
        set("icon",young_man1);
	
	set_skill("unarmed", 65);
	set_skill("throwing", 65);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("mantian_xing", 60);
	set_skill("shaolin_shenfa", 60);
	map_skill("throwing", "mantian_xing");
	map_skill("parry", "mantian_xing");
	map_skill("dodge", "shaolin_shenfa");
	
	carry_object("tiejia")->wear();
	carry_object("jili")->wield();
	
	add_money(1000);
}
NPC_END;