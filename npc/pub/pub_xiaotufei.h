//xiaotufei.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaotufei);

virtual void create()
{
	set_name("С����","xiao tufei");
	
	set("icon", banditi);
	set("gender", "����" );
	set("age", 22);
	set("long", "���Ǹ���������С���ˣ�ɱ��Խ������޶�����");
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("combat_exp", 750);
	set("shen_type", -1);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 15);
	set("attitude","aggressive");
	carry_object("cloth")->wear();
	add_money(130);
	
};

NPC_END;
