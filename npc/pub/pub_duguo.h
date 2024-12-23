//pub_duguo.h
//wuqing 2002-02-15

NPC_BEGIN(CNpub_duguo);

virtual void create()
{
	set_name("�ɹ�",  "du guo");
	set("title", "������ͽ");
	set("gender", "����");
	set("age", 90);
	set("long",	"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�ݻƣ���ͬһ�ο�ľ��");
	set("icon",old_monk);
	set("foolid",87);
	set("attitude", "peaceful");
	set("combat_exp", 3000000);
	set("score", 200000);

	set("str", 40);
	set("int", 40);
	set("cor", 40);
	set("cps", 40);
	set("con", 40);

	set("hp", 18000);
	set("max_hp", 18000);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_factor", 100);
	
	set_skill("force", 250);
	set_skill("whip", 250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("unarmed", 250);
	set_skill("buddhism", 250);
	set_skill("literate", 200);

	set_skill("hunyuan_yiqi", 250);
	set_skill("riyue_bian", 250);
	set_skill("shaolin_shenfa", 250);

	map_skill("force", "hunyuan_yiqi");
	map_skill("whip",  "riyue_bian");
	map_skill("parry", "riyue_bian");
	map_skill("dodge", "shaolin_shenfa");
	set("no_kill",1);//����������ٹȵ�������

	carry_object("changbian")->wield();

}
	
virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("whip chan", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}

NPC_END;




