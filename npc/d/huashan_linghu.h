// huashan_linghu.c �����
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNhuashan_linghu);

virtual void create()
{
	set_name("����","ling huchong");
	set("nickname", "��ʦ��");
	set("long", "������Ľ��ݣ�����Ũü���ۣ������Ѱ�������ͬ���������ϴ��ǻ�ɽ������һ���еĶ�����֡�");
	set("gender", "����");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man2);
	
	set("hp", 2800);
	set("max_hp", 5400);
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 60);
	
	set("combat_exp", 800000);
	set("score", 100000);
	
	set_skill("unarmed",125);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 140);
	set_skill("sword", 190);
	set_skill("huashan_sword", 190);

	set_skill("huashan_shenfa", 150);
	set_skill("feiyan_huixiang",150);
	set_skill("lonely_sword",160);
	set_skill("literate", 120);
	set_skill("zhengqijue",120);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	set("card2_count",1);
	
	create_family("��ɽ��", 14, "����");
	
	set_inquiry("��ǰ��","�����Ѿ��ܾ�û�м��������˼��ˡ���������");
	set_inquiry("�δ�С��","������������Ϣ�� ");
	carry_object("ls_book", 1);	 	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"���ղ��ܼ���ӯӯ��!%s�������������Ϣ?",query_respect(ob) );
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->query_temp("ry/renwu2_2") && !who->query_temp("ry/renwu2_3"))
	{
		if (ob->query("ry/shoujuan") &&  EQUALSTR(ob->querystr("owner1"), who->id(1)))
		{
			say( "����忴���־������һ˿¶��˼��֮�顰��ô����ӯӯ���ڹ����ң��л�����һ��ȥ�������������ɽ�����񷱶࣬���Ȱ��Ұ�����Ÿ����ɡ���", who);
			destruct(ob);
			CContainer * obj = load_item("baozi");
			obj->set_name("��", "xin");
			obj->set_weight(500);
			obj->set("long", "����һ�����д��ӯӯ���š�");
			obj->set("owner1",who->id(1));
			obj->set("ry/xin",1);
			obj->move(who);
			who->set_temp("ry/renwu2_3",1);//�������Ÿ�ӯӯ������
			tell_object(who,"\n$HIC��õ�����1���š�\n");
		}
		else
			return notify_fail("����岻��Ҫ���������");
	}
	else
	{
		if (query("card2_count") == 0)
		{ 
			say( "���Ѿ�������ӯӯȥ�ˣ���л����!", who);
			SendMenu(who);
			return 1;
		}
		
		if ( DIFFERSTR(ob->querystr("base_name"), "huashan_letter"))
			return notify_fail("����岻��Ҫ���������");
		
		say( "ӯӯ����", who);
		say("���׻�����������ȥ����ӯӯ,�������Ҿ�ȥ����!", who);
		ob = load_item("card2");//�׻������� tested by lanwood 2000-12-28
		ob->move(who);
		set("card2_count",0l);
	}
	SendMenu(who);
	return 1;
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];

	if ( ob->query("repute") < 0)
	{
		say("�һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�", ob);
		say(snprintf(msg,255,"�ڵ��з��棬%s�Ƿ����ò�����",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	if ( ob->query_int() < 25) 
	{
		say(snprintf(msg,255,"���ҿ�%s�������ƺ����ʺ�ѧ�һ�ɽ���书��",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
	return;
}

NPC_END;