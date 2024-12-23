//xiaoguiz.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaoguizi);

virtual void create()
{
	set_name("С����","xiaoguiz");

	set("icon", young_man3);
	set("gender", "����" );
	set("age", 13);
	set("long","��λС̫����һ��С���̺��ţ���������һ��ҩ��");
	set("combat_exp", 1000);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);

	set("attitude", "friendly");
	set("rank_info/respect", "С����");
    set("chat_chance", 5);


    carry_object("cloth")->wear();
	carry_object("yaofen");
	add_money(10);


};

virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "С����˵�����������ٷ�һ��ҩ���ò��ã�";
	case 1:
		return "С����˵�����ٷ��������벻�����";
	}
	return "";
}

NPC_END;
