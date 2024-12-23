// pub_yuzu.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_yuzu);

virtual void create()
{
	set_name("�̲�����",  "yu zu");

	set("icon", tipstaff);
	set("title", "��Ʒ��������" );
	set("gender", "����" );
	set("age", 32);
	set("str", 22);
	set("con", 25);
	set("dex", 20);
	set("int", 30);
	set("long","���ӽ��±����ǵ��̲��춥���䣬�������⣬��ݿ������㿴��ҪС���ˡ�");
	set("combat_exp", 2000000);
	set("attitude", "heroism");
	
	set("max_hp", 3000);
	set("max_mp", 2000);
	set("mp", 2000);
	set("mp_factor", 100);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("blade", 200);
	
	set_inquiry("����","�ٺٺٺ٣����������ûʥ�ϵ�ּ�⣬����ûָ��ඡ�");

	carry_object("yayi_cloth")->wear();
	carry_object("gangdao")->wield();
}

/*
virtual char * greeting(CChar * ob)
{
	char msg[255];
	command(snprintf(msg,255,"rumor ������%s�ѱ��̲����������ù鰸��",ob->name() ));
	ob->set("startroom","/d/city2/jail");
	return "";
}


virtual void init(CChar *me)
{
	CChar * ob;
	CNpc::init(me);
	add_action("do_chat","chat");
	add_action("do_chat","rumor");
	add_action("do_chat","party");
	add_action("do_chat","xkx");
	add_action("do_chat","sing");
	add_action("do_chat","to");
	add_action("do_chat","chat*");
	add_action("do_chat","tell");
	add_action("do_chat","reply");
	add_action("do_chat","exert");
	add_action("do_chat","yun");
	add_action("do_chat","dazuo");
	add_action("do_chat","exercise");
	add_action("do_chat","tuna");
	add_action("do_chat","meditate");
	add_action("do_chat","lian");
	add_action("do_chat","practice");
	add_action("do_chat","du");
	add_action("do_chat","study");
	add_action("do_chat","xue");
	add_action("do_chat","learn");
	add_action("do_chat","vote");
	add_action("do_chat","finger");
	add_action("do_chat","suicide");
}

int do_chat(string arg)
{
	CChar * ob = me;
	switch(random(3))
	{
	case 1:
        say(" "+ob->query("name")+"������ٶ�һ�����ٶ��͸���һͰ����");
		break;
	case 2:
        say(" "+ob->query("name")+"������Ƥ���������ﲻˬ��");
        message_vision("�̲�������ͷ���Ծ���һ��Ƥ�ޣ����$NƤ���������ò���ˬ��" ,ob);
		ob -> receive_damage("hp",10);
		break;
	default:
        say(" "+me->query("name")+"�����ǲ��Ǿ�������������࿪�ļ��죿");
		break;
	}
	return 0;
}
*/
NPC_END;