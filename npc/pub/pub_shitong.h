//shitong.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shitong);

virtual void create()
{
	set_name("��ͯ","shitong");
	
	set("icon", boy1);
	set("age", 8);
	set("gender", "����");
	set("long","����һ���һ����Խ�ͤ����ͯ��");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 80);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 80);
	
	carry_object("cloth")->wear();
};

NPC_END;
