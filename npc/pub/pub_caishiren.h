NPC_BEGIN(CNPub_caishiren);

virtual void create()
{
	set_name("��ʯ��","caishiren");

	set("icon", banditi);
	set("gender", "����");
	set("age", 22);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "����һ����׳���ӡ�");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	carry_object("tieqiao")->wield();
	carry_object("cloth")->wear();



};

NPC_END;
