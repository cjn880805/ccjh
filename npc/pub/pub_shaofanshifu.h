NPC_BEGIN(CNPub_shaofanshifu);

virtual void create()
{
	set_name( "�շ�ʦ��");

	set("icon", pub_boss);
	set("str", 50);
	set("gender", "����");
	set("age", 18);
	set("long", "���Ǿ���ݳ������շ�ʦ����");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	carry_object("cloth")->Do_Action(DO_WIELD);
};

NPC_END;
