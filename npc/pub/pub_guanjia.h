NPC_BEGIN(CNpub_guanjia);

virtual void create()
{
	
	set_name("�����ܼ�","guanjia");
	
	set("icon", pawnshop_boss);
	set("long","����һλ����������Ϲܼң�һ��С�̶������ڲ�ͣ��ת���š�");
	set("gender", "����");
	set("age", 65);
	
	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", -1);
	
	carry_object("magua")->wear();
	add_money(200);
	
	
	
};


NPC_END;
