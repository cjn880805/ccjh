//wyshangfan.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_wyshangfan);

virtual void create()
{
	set_name("�����̷�","shangfan");

	set("icon", drugstore_boss);
	set("gender", "����" );
	set("age", 22);
	set("long", "һλ��������̷�������һ��ƤëҰζ�ڷ�����");
	set("combat_exp", 5000);
    set("str", 22);
    set("dex", 11);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	carry_good("wdahui", 50);

	add_money(100);

};

VENDOR_END;
