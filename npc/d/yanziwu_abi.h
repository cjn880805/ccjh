// yanziwu_abi.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNyanziwu_abi);

virtual void create()
{
	set_name("��ɺ",  "abi");
	set("long","���Ǹ������µ�Ů�ɣ�Լʮ��������ͣ������������ᣬ ");
	set("gender", "Ů��");
	set("age", 16);
        set("icon",girl1);

	set("shen_type", 1);
	
	set("mp", 200);
	set("max_mp", 200);
	set("max_hp", 480);
	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);
	
	set("combat_exp", 10000);
	set_inquiry("����ɽׯ","�ҲŲ���ȥ����ɽׯ��������̫�Ե���! ");
	set_inquiry("������","����ֻ��������������ǹ��ӣ�Ҳ��֪��������ô����! ");
	set_inquiry("����","��С����ֻ����һ�꣬�����ϲ��������档 ");
	
	carry_object("goldring")->wear();
	carry_object("necklace")->wear();
	carry_object("changjian")->wield();
	carry_object("green_cloth")->wear();
	carry_object("flower_shoe")->wear();
}

NPC_END;