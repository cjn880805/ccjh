// pub_herdsman.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_herdsman);


virtual void create()
{
	set_name("������","herds man");

	set("icon", old_man2);
	set("gender", "����");
	set("age", 60 + random(10));
	set("long", "һ��ά������Ϻ������ż�ʮֻ��");
	set("attitude", "friendly");
	set("combat_exp", 1000);
	set("shen_type", 1);
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("whip", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set_inquiry ("������" , "���Ƕ������޺���");
	set_inquiry ("���޺�" , "���޺�������ߡ�");


	set("chat_chance", 10);
	
	carry_object("wcloth")->wear();
	carry_object("changbian")->wield();
}

virtual char * chat_msg()
{
	switch (random(2) )
	{
	case 0:
		return "�����Ϻ����ĵ�˵�����ǰ������ɵ���������������һֻ��";
	case 1:
		return "�����Ϻ�������������Ⱥ��������ˡ�";
	}
	return "";
}

NPC_END;