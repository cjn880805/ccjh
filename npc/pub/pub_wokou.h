//wokou.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_wokou);

virtual void create()
{
	set_name("����","wokou");
	
	set("icon", young_man4);
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "�������쳯����̨����ձ����ˣ�����ͨ����ʿ�����쳯��֮���ܡ�");
	set("combat_exp", 50000);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/armor", 35);
	set_temp("apply/damage", 35);
	set_skill("blade", 35);
	set_skill("dodge", 35);
	set_skill("unarmed", 35);
	set_skill("tangshoudao", 35);
	set_skill("dongyangdaofa", 3);
	map_skill("unarmed","tangshoudao");
	map_skill("blade","dongyangdaofa");
	set("chat_chance", 1);
	carry_object("wodao")->wield();
	carry_object("cycle")->wear();
	carry_object("tiebeixin")->wear();
	
	
};

virtual char * chat_msg()
{
	return "����̧�۴�ŭ��������������˸���·����ģ���˵̨�������ǵģ����������ģ�";
}


NPC_END;
