//keshang.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_keshang);

virtual void create()
{
	set_name("ʢƤ�޿���","keshang");

	set("icon", pawnshop_boss);
	set("gender", "����" );
	set("age", 32);
	set("long","����һλ��ӡ�����Ŀ��̣�Ƥ����ڣ��ײ���ͷ�������ӡ���˽���ʢƤ�ޡ�");
	set("combat_exp", 7000);
    set("str", 17);
    set("dex", 25);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object("cloth")->wear();
	add_money(10);
};


NPC_END;
