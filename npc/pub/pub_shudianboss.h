//shudianboss.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_shudianboss);

virtual void create()
{
	set_name("����ϰ�","shudianboss");

	set("icon", drugstore_boss);
	set("gender", "����" );
	set("age", 62);
	set("long", "һ���ú�����һ���;��ÿ��׵����̡�");
	set("combat_exp", 3000);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	carry_good("parry_book",20);

    carry_object("cloth")->wear();
	add_money(100);


};

VENDOR_END;
