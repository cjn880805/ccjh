// keshang.c
//sound 2001-07-19

NPC_BEGIN(CNdali_keshang);

virtual void create()
{
	set("icon",young_man4);
	set_name("ʢƤ�޿���", "ke shang");
	set("gender", "����" );
	set("age", 32);
	set("long","����һλ��ӡ�����Ŀ��̣�Ƥ����ڣ��ײ���ͷ�������ӡ���˽���ʢƤ�ޡ�");
	set("combat_exp", 7000);
        set("str", 17);
        set("dex", 25);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
//	add_money("silver", 10);
}

NPC_END;