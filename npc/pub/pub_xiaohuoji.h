VENDOR_BEGIN(CNpub_xiaohuoji);

virtual void create()
{
	set_name("ҩ��С���","xiaohuoji");

	set("icon", waiter);
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "������������С���ӡ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");

	carry_good("yuchandan", 10);

	carry_object("cloth")->wear();

};


VENDOR_END;
