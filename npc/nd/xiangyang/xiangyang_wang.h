// wang.c ����
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_wang);

virtual void create()
{
	set_name("����", "wang jian");
	set("gender", "����");
	set("title", "�����ر���");
	set("age", 40);
	set("str", 35);
	set("dex", 36);
	set("icon", general);
	set("long", "����һ�����������ر�����������������");
	set("combat_exp", 150000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("changquan", 80);
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 100);

	carry_object("gangjian")->wield();
	carry_object("tiejia")->wear();
}

NPC_END;