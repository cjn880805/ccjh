// quanzhen_zhangyao.c ��ҩ����

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhangyao);

virtual void create()
{
	set_name("��ҩ����", "zhangyao");
	set("gender", "����");
	set("age", 28);
	set("class", "taoist");
	set("long","����ȫ����е��ƹ�����ҩ��ĵ��ˡ�����Ͳ��󣬵��������Ե������ϳɡ�");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 21);
	set("int", 22);
	set("con", 23);
	set("dex", 22);
	set("icon",young_man6);
			set("foolid",50);	
	set("hp", 600);
	set("max_hp", 1800);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 0l);
	
	set("combat_exp", 30000);
	set("score", 20000);
	
	set_skill("force", 60);
	set_skill("xiantian_qigong", 50);    //��������
	set_skill("sword", 60);
	set_skill("quanzhen_jian",60);  //ȫ�潣
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 50);   //���㹦
	set_skill("parry", 60);
	set_skill("unarmed",60);
	set_skill("strike",60);
	set_skill("haotian_zhang", 50);    //�����
	set_skill("literate",50);
	set_skill("taoism",40);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 4, "����");
	
	set_inquiry("ȫ���","��ȫ��������µ����������ڡ�");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" �ðɣ��Ҿ����������ͽ���ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obj ;
	
	if ( !ob ) return 0;
	//        if ( !present(ob, who) ) return notify_fail("��û�����������");
	
	if (  DIFFERSTR(ob->querystr("name"), "�ڹ��")
		&& DIFFERSTR(ob->querystr("id"), "fuling") )
	{
		say("��ҩ����ҡͷ�����ⲻ����ҩ�Ĳ��ϡ�", who);
		SendMenu(who);
		return 0;
	}
	
	if  ( EQUALSTR(ob->querystr("name"), "�ڹ��"))
	{
		if(query_temp("fuling")) 
		{
			say("��׺����߶����ˣ��⸱���߸�������ˡ�", who);
			SendMenu(who);

			obj=load_item("guiling");//���߸�
			obj->move(who);
			delete_temp("guijia");
			delete_temp("fuling");
//			if(!(obj2=present("gui jia", me)))
//				destruct(obj2);
//			remove_call_out(destroying);
//			call_out(destroying, 1, me, ob->object_id() );
			return 1;
		}
		else
		{
			if(query_temp("guijia")) 
			{
				say("��������Ѿ����ˡ���", who);
				SendMenu(who);
				return 0;
			}
			else 
			{
				set_temp("guijia",1);
				say("������ˣ���ȱ�����ˡ�", who);
				SendMenu(who);
//				if(!(obj2=present("gui jia", me)))
//					destruct(obj2);
//				remove_call_out(destroying);
//				call_out(destroying, 1, me, ob->object_id() );
				return 1;
			}
		}
	}

	if (EQUALSTR(ob->querystr("id"), "fuling"))
	{
		if(query_temp("guijia")) 
		{
			say("��׺����߶����ˣ��⸱���߸�������ˡ�", who);
			SendMenu(who);

			obj=load_item("guiling");//���߸�
			obj->move(who);
			delete_temp("guijia");
			delete_temp("fuling");
//			if(!(obj1=present("fuling", me)))
//				destruct(obj1);
//			remove_call_out(destroying);
//			call_out(destroying, 1, me, ob->object_id() );
			return 1;
		}
		else 
		{
			if(query_temp("fuling"))
			{
				say("���������Ѿ����ˡ���", who);
				SendMenu(who);
				return 0;
			}
			else
			{
				set_temp("fuling",1);
				say("�������ˣ���ȱ����ˡ�", who);
				SendMenu(who);
//				if(!(obj2=present("fuling", me)))
//					destruct(obj2);
//				remove_call_out(destroying);
//				call_out(destroying, 1, me, ob->object_id() );
				return 1;
			}
		}
	}
	return 0;
}

NPC_END;