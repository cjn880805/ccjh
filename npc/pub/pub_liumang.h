//liumang.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_liumang);

virtual void create()
{
	set_name("��å","liumang");

	set("icon", cateran);
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ֺ��е���å�����õ��ǰװ����ֵģ�Ҳ����ǰ�й�Ǯ��");
	
	set("combat_exp", 1000);
	set("shen_type", -1);
	set("score", -20);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	carry_object("cloth")->wear();
	add_money(20);


};

NPC_END;
