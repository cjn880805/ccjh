//xueboss.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_xueboss);

virtual void create()
{
	set_name("Ѧ�ϰ�","xueboss");

	set("icon", pawnshop_boss);
	set("gender", "����" );
	set("age", 32);
	set("long","����һ�������ϵ��������ˣ�һ˫�������۾���ͣ�Ĵ������㡣");
	set("combat_exp", 300);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");

	carry_good("shoes",20);
	carry_good("doupeng",20);
	carry_good("guazi",20);
	carry_good("kenao",20);
	carry_good("qun",20);

	carry_object("cloth")->wear();
	add_money(100);

};



VENDOR_END;
