//tshangfan.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tshangfan);

void create()
{
	set_name("̨���̷�","tshangfan");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 22);
	set("long", "һλ̨������̷������ڷ���һ��¨�մ������Ļ�����������㡣");
	set("combat_exp", 3000);
    set("per", 17);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");

	carry_object("ttoujin")->wear();
	carry_object("tduanqun")->wear();
	add_money(100);

};

NPC_END;
