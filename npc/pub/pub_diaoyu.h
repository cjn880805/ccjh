NPC_BEGIN(CNPub_diaoyu);

virtual void create()
{
	set_name("������","diaoyu");

	set("icon", old_man1);
	set("gender", "����" );
	set("age", 58);
	set("long","һ��������˸�����ߣ������ֳֵ��ͣ����������ϣ����н�̫��֮�硣");
	set("shen_type", 1);
	set("combat_exp", 4000);
	set("str", 15);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	carry_object("tie_gan")->wield();
	
	
};

NPC_END;
