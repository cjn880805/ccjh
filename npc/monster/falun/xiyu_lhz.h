//lihongzhi.h аħ���־
//Coded by Teapot 2000-02-06

NPC_BEGIN(CNxiyu_lhz);

virtual void create()
{
	set_name("��׳�", "li baichi");
	
	set("title", "����");
	set("gender", "����");
	set("age", 64);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("icon", old_man2);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("falun/know",100);

	set("hp", 12500);
	set("max_hp", 32500);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 350);

	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("force", 300);
	set_skill("strike", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 350);
	set_skill("literate", 80);

	set_skill("falun_step", 300);
	set_skill("falun_gong", 300);
	set_skill("falun_zhanfa", 300);
	set_skill("falun_daofa", 300);

	map_skill("force", "falun_gong");
	map_skill("dodge", "falun_step");
	map_skill("strike", "falun_zhanfa");
	map_skill("blade", "falun_daofa");
	map_skill("parry", "falun_daofa");

	create_family("���ֽ�",1, "����");
	set("chat_chance_combat", 60);
	set("nkgain", 4000);



    set_inquiry("�Է�", "�Է��˳��ִ���������߾���ıؾ���·��");
	//set_inquiry("�¹�", "�¹�MM���������ɣ�������");
	set_inquiry("������", ask_tgm);
	set_inquiry("����", ask_birthday);

	carry_object("falunblade")->wield();
	add_money(10000);
};

static char * ask_tgm(CNpc * me, CChar * who)
{
	if(!who->query("falun/know") || who->query("falun/know")<100)
	{
		me->say("α���Ǽٻ���˵�������Ϊ��α�ƣ���������޿��̡�");
		me->say("������ҳ��̵ֽ������̣���Ҫ�����ˡ�");
		who->add("falun/know",1);

		who->set("title","���ֽ̡��̡��ֱ�����");		//90~99
		if(who->query("falun/know")<30)
			who->set("title","���ֽ̽���");
		if(who->query("falun/know")<60)
			who->set("title","���ֽ̡��桹�ֱ�����");
		if(who->query("falun/know")<90)
			who->set("title","���ֽ̡��ơ��ֱ�����");

		return "�����������һ��ʲô��";
	}
	else
	{
		me->say("���Ѿ���ȫ�����˳��ִ󷨵����塣");
		who->set("title","���ִ󷨼̳���");
		return "���Ϊ���ֹ��󷨼̳��ˣ�";
	}
}

static char * ask_birthday(CNpc * me, CChar * who)
{
		me->say("�㿴���Ѿ�֪���ҵ������ˣ�");
		me->say("��Ȼ��ˣ����㲻�ã�");
		me->kill_ob(who);
        return "������׳���ɱ���㣡";
}


virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->query("per")<22 )
    {
        this->say("�㳤�ò����Ǹ����ˣ�û��ɿ���ԣ��Ҳ��գ�");
		SendMenu(me);
		return;
    }
	me->set("class","falun");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	return;
}


virtual int accept_fight(CChar *me)
{
	char msg[20];

	say("���ִ󷨵��ӽ����̣����������˱��ԣ�");
	say("������ֻ��ɱ���㣡");
	command(snprintf(msg, 20, "kill %ld", me->object_id()));
	return 0;
}


virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("blade zhuang", 1);
		break;
	case 1:
		perform_action("strike zhen", 1);
		break;
	case 2:
		perform_action("strike shan", 1);
		break;
	case 3:
		perform_action("strike ren", 1);
		break;
	}

	return 0;
}

NPC_END;
