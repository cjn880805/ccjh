// yuyan.h ������
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_yuyan);

virtual void create()
{
	set("icon",young_man1);
	set_name("������", "yu renyan");
	set("gender", "����");
	set("age", 20);
	set("long", "�����ǡ�����ɡ��������㺣�׵Ķ������ӡ�������ʵ�ںܲ�������");

	set("combat_exp", 40000);
	set("shen_type", -1);

	set_skill("sword", 40);
	set_skill("pixie_sword", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	map_skill("parry", "pixie_sword");
	map_skill("sword", "pixie_sword");
	create_family("�����", 6, "����");

	carry_object("changjian")->wield();
	carry_object("bluecloth")->wear();
}

NPC_END;