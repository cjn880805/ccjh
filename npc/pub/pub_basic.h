NPC_BEGIN(CNPub_basic);

virtual void create()
{
	set_name("����ȱ","basic");

	set("icon", young_man1);
	set("nickname", "���ƽ���");
	set("gender", "����");
	set("age", 20);
	set("long","�����Ǵ�������ȱ��");

	set("combat_exp", 500000);
	
	carry_object("jinduan")->wear();
};

NPC_END;
