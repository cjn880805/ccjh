// gaosan.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_gaosan);

virtual void create()
{
	set_name("����ɩ��", "gao san");
	set("title", "����ׯŮׯ��");
	set("long", "��Ů�����м�����ɫ��������ȹ����ϵ���廨����������������������Ŷ̵���");
	set("gender", "Ů��");
	set("age", 31);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon", young_woman11);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("throwing", 50);
	set_skill("feixing_shu", 50);
	set_skill("lingxu_bu",50);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "feixing_shu");
	map_skill("throwing", "feixing_shu");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	
	carry_object("shortblade")->wield();
	carry_object("cloth")->wear();
}

NPC_END;