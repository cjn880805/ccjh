// gongweishi.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_gongweishi);

virtual void create()
{
	set_name("�ʹ���ʿ", "wei shi");
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("icon",guarder);
	set("long", "���ǻʹ��Ĵ�����ʿ�������ּף���ִ������");
	set("combat_exp", 90000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);
	
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 10);
	
	carry_object("tiejia")->wear();
	carry_object("changjian")->wield();
}

NPC_END;