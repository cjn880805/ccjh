// shaofanshifu.c
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_shaofanshifu);

virtual void create()
{
	set_name("�շ�ʦ��", "shaofan shifu");
	set("str", 50);
	set("gender", "����");
	set("age", 18);
	set("attitude", "pub_boss");
	set("long", "���Ǿ���ݳ������շ�ʦ����");
	set("combat_exp", 2000);
	set("attitude", "friendly");

	carry_object("cloth")->wear();
}

NPC_END;