// honghua1.h
//zhangdn 2001-07-19

NPC_BEGIN(CNhangzhou_honghua1);

virtual void create()
{
	set_name("�컨����", "hong hua");
	set("gender", "����");
	set("age", 25);
	set("long","����λ����׳����������������ǰ���һ���컨��");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("icon", young_man1);

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	
	//carry_object("changjian")->wield();

/*	
}
void init()
{
	object ob;
	if (random(2) == 1)
	message_vision(HIY "�컨�����˷ܵ����ĸ���$N���ܶ����ѹ��ʵۿ������������ˣ�\n" NOR, 
		this_player());
	else
	message_vision(HIY "�컨���ڳ���$N˵��ʮ�������ҵķֲ���أ����ʵ��ܲ��˵ģ�\n" NOR, 
		this_player());
}
*/
}
NPC_END;