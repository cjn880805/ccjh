//yuanwai.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yuanwai);

virtual void create()
{
	set_name("��Ա��","yuan wai");

	set("icon", pawnshop_boss);
	set("long","��Ա���˵���ⳤ�����ϵ��׸���˭Ҳ��֪���������ж��ټҲơ�����Լ��ʮ��ͷ�����ĸ���̬̬��");
	set("gender", "����");
	set("age", 52);
	
	set("combat_exp", 12000);
	set_skill("unarmed", 45);
	set_skill("force", 42);
	set_skill("dodge", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/defense", 42);
	
	carry_object("jinduan")->wear();
	add_money(120);
	
};



NPC_END;
