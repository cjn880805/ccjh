VENDOR_BEGIN(CNpub_huoji);

virtual void create()
{
	set_name("ҩ�̻��","huoji");

	set("icon", waiter);
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书����ҩ�������ƺ������ں���");
	set("combat_exp", 15000);
	set("attitude", "friendly");

	carry_good("jinchuang",500);
	carry_good("yangjing",500);
	carry_good("gaoyao",500);
	carry_good("yuchandan", 10);
	carry_good("hongzao", 1);
	carry_good("xinren", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	carry_object("cloth")->wear();

	add_money(5);


};


VENDOR_END;
