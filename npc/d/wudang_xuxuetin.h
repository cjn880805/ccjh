// wudang_xuxuetin.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_xuxuetin);

virtual void create()
{
	set_name("����",  "xu xueting" );
	set("title", "����������ʹ");
	set("nickname",  "��Ѫ����" );
	set("gender", "����" );
	set("age", 55);
        set("icon",old_man2);

	set("long","���Ǹ���ʮ����ĸ��ݺ��ӣ���һϮ���£���Ȼͦ���� ");
	
	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set("hp",3000);
	set("max_hp", 9000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 150);
	set("combat_exp", 500000);
	set("score", 250000);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 90);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taoism", 150);
	set_skill("literate", 60);
	set_skill("tiyunzong", 80);
	set_skill("taiji_quan", 80);
	set_skill("taiji_shengong", 80);
	set_skill("taiji_jian", 90);
	set_skill("shedao_qigong", 100);
	set_skill("shenlong_xinfa", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	set_inquiry("�ٻ����߸�", "����Ǳ��̽��ﰡ����һ����Ѫ������Ũ�㣬 ����ס�������ߵ��ϣ����˶��������ۻƾƣ��Աܶ��ߣ�������� һ�����ۻƾƣ���ʹ�˽���������ܶ��������ˣ�����ôҲ֪���� ");
	set_inquiry("����", "����Ƣ������,Ҫ�������Ĳźá� ");
	set_inquiry("���", ask_join);
	set_inquiry("�ں�","���겻��!�����ɸ�!��������!������ʥ! ");
	
	set("chat_chance", 3);
	
	carry_object("duanjian")->wield();
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "��ѩͤ��Ȼһ���Դ���˵�����ˣ������ðٻ����߸࣡ ";
	case 1:
		return "��ѩͤŭ��������ټ��һ�������̣�������һ����ô�����ˣ� ";
	case 2:
		return "��ѩͤ̾������˵����������ɱ�˺鰲ͨ��˭Ҳ��ˡ� ";
	}
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obn;

	if ( DIFFERSTR(ob->querystr("name"), "���ߵ�")
		&& DIFFERSTR(ob->querystr("name"), "���㻨" ) )
		return notify_fail("��ѩͤҡͷ�������ɱ���˺鰲ͨ������ʲôҲû�ð������� ");

	if ( EQUALSTR(ob->querystr("name"), "���ߵ�" ))
	{
		if(query_temp("baixianghua"))
		{
			say("��ѩͤ���Ǹ��ߵ�����ϲ�������ߵ����㻨������,�ٻ����߸�������! ",who);
			SendMenu(who);
			obn=load_item("baihua");//�ٻ����߸�
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("fushedan"))
			{
				say("��ѩͤ���Ǹ��ߵ�������ҡͷ�������ߵ������ˣ��Ͳ���㻨�ˡ� ",who);
				SendMenu(who);
				return 0;
			}
			else	  
			{
				say("��ѩͤ�������㻨����ϲ�������˰��㻨��ֻ��ߵ��ˡ� ", who);
				SendMenu(who);
				set_temp("fushedan",1);	
				return 1;
			}
		}
	}

	if ( EQUALSTR(ob->querystr("name"), "���㻨" ))
	{
		if(query_temp("fushedan"))
		{
			say("��ѩͤ���ǰ��㻨����ϲ�������ߵ����㻨������,�ٻ����߸�������! ",who);
			SendMenu(who);
			obn=load_item("baihua");//�ٻ����߸�
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("baixianghua"))
			{
				say(" ��ѩͤ���ǰ��㻨����$Nҡͷ�������㻨�����ˣ��Ͳ�ߵ��ˡ� ",who);
				SendMenu(who);
				return 0;
			}
			else	  
			{
				say("��ѩͤ�������㻨����ϲ�������˰��㻨��ֻ��ߵ��ˡ� ", who);
				SendMenu(who);
				set_temp("baixianghua",1);	
				return 1;
			}
		}	
	}

	return 0;
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp (comm,"join") == 0)
		return do_join(me,arg);

	return 0;
}

static char * ask_join(CNpc * me, CChar * who)
{
	me->say("һ�������벻���������̵ġ��������ô��", who);
	me->AddMenuItem("�Ҿ�����̡�", "$0join $1", who);
	me->AddMenuItem("�����ҿ��ǿ��ǡ���", "", who);
	me->SendMenu(who);
	return "";
}

int do_join(CChar *ob,char * arg)
{
	if(ob->query("shenlongjiao")) 
	{
		say("���Ѿ��������̵����ˡ� " , ob);
		SendMenu(ob);
		return 1;
	}

	if (ob->query("repute")>-1000)
	{
		message_vision( "��ѩͤ��$N��ŭ�����������?һ����Ͳ��Ǻ���! ", ob);
		kill_ob(ob); 
		return 1;
	}

	if (ob->query_combat_exp() < 20000)
	{
		say( "��ѩͤ����ҡͷ�������ʵս����̫�͡� " , ob);
		SendMenu(ob);
		return 1;
	}

	if ( ob->query_skill("bibo_shengong",1)
		|| ob->query_skill("hamagong",1)
		|| ob->query_skill("huagong_dafa",1))
	{
		ob->set("shenlongjiao",1);
		say("�����ھ��������̵�����. ", ob);
		SendMenu(ob);
		return 1;	
	}
	else 
	{
		message_vision( "��ѩͤ��$N��ŭ�����������?һ����Ͳ��Ǻ���! " ,ob);
 		kill_ob(ob); 
		return 1;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("shenlong_xinfa",1) < 40 ) 
	{
		say("��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!", ob);
	}else if (ob->query_skill("shedao_qigong",1) < 40 )
	{
		say("��ı����ȷ�̫����,����ŬŬ�������һ�°�!", ob);
	}
	else if (ob->query("repute") > -5000  ) 
	{
		say("�������������������������������ְ׵�����򽻵�������ذɣ�", ob);
	}
	else
	{
		say("�ܺã��ܺá�");
		command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
		return;
	}

	SendMenu(ob);
}

NPC_END;