// shaolin_chuyuan.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_chuyuan);

virtual void create()
{
	set_name("�ҷ�", "chu yuan" );
	set("title", "��ǰ����");
	set("gender", "����");
	set("age", 34);
	set("long","�ҷ�ԭ�Ǻ��У������Ƿ���������Ϊ���淢������棬��׷�ɶ�뺣�������ţ������Ի����ף����˴���������");
	set("combat_exp", 350000);
	set("shen_type", -1);
	set("attitude", "heroism");
 	set("icon",young_man1);
	
	set_skill("unarmed", 55);
	set_skill("sword", 55);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("damo_jian", 50);
	set_skill("shaolin_shenfa", 50);
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");
	map_skill("dodge", "shaolin_shenfa");
	
	carry_object("tiejia")->wear();
	carry_object("changjian")->wield();
	
	add_money(1000);
}
NPC_END;