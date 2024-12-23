//trade.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_trade);

virtual void create()
{
	set_name("��˹����","trade");
	
	set("icon", pub_boss);
	set("gender", "����");
	set("age", 40 + random(10));
	
	set("long", "һ���߱����۵Ĳ�˹���ˡ�������������¶���ƻ���Ц�ݡ�");
	
	set("attitude", "friendly");
	set("combat_exp", 6000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 40);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);
	
	set("chat_chance", 1);
	
	carry_object("wandao")->wield();
	carry_object("changpao")->wear();
	add_money(20);
	
};

virtual char * chat_msg(CChar *me )
{
	switch(random(2))
	{
	case 0:
		return "��˹���˶��㼷��һ���۾�";
	case 1:
		return "��˹����˵�����������ɰͣ��º�Ĭ�����ذ����� ��û������";
	}
	return "";
}
NPC_END;
