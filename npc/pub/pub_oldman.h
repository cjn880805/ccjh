NPC_BEGIN(CNPub_oldman);

virtual void create()
{
	set_name("��������","oldman");
	
	set("icon", old_man1);
	set("gender", "����" );
	set("age", 72);
	set("long","һ���������Ŵ�����ֵ�������������ſڣ�˦�����ĸ����ƴ��������Ҷ�����ŵ����������������ǣ���Ҳ������ڡ�");
	set_temp("apply/defense", 5);
	set("combat_exp", 700);
	set("shen_type", 1);
	set("per", 13);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
	
};


NPC_END;
