// heimuya_xiang ������
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_xiang);

virtual void create()
{
	set_name("���ʵ�","xiang wendi");
	set("nickname", "��������");
	set("title",  "������̹�����ʹ" );
	set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��");
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);	//��������������
	set("str", 21);
	set("per", 18);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
 	set("icon",old_man1);
	
	set("hp", 4000);
	set("max_hp", 4000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 350);
	set("combat_exp", 2500000);
	set("shen_type", -1);

	set_skill("literate", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("changquan", 150);
	set_skill("xingxiu_duzhang", 150);
	set_skill("lingxu_bu", 150);
	set_skill("damo_jian", 150);
	set_skill("taiji_jian", 150);
	set_skill("huifeng_jian", 150);
	set_skill("taishan_sword", 150);
	set_skill("hengshan_jian", 150);
	set_skill("hengshan_sword", 150);
	set_skill("huashan_sword", 150);
	set_skill("songshan_sword", 150);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "xingxiu_duzhang");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");
	
	set("chat_chance", 5);

	set_inquiry("����ͤ", "�����ˣ���ɱ��");
	set_inquiry("��������", "��λ��ͽ���ҷ�ɱ�������ɣ�");
//	set_inquiry("ɱ��������", "ask_kill()");
	set_inquiry("������", "��������������ʮ��......");

	carry_object("changjian")->wield();

	create_family("�������", 2, "������ʹ");
}


NPC_END;