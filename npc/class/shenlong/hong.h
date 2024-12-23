//hong.h
//code by zwb
//12-16
//inherit F_UNIQUE;
//inherit F_MASTER;

ZUSHI_BEGIN(CNshenlong_hong);

virtual void create()
{
	set_name("�鰲˳","hong anshun");
	set("title",  "�����̽���" );
	set("nickname", "�����ɸ�" );
	set("long", "�������书����������˵�̸֮ɫ��������̽����鰲˳��");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	set("icon",young_man4);	
	
	set("max_hp", 16000);
	set("hp", 10000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_farce",100);
	set("combat_exp", 1600000);
	set("score", 400000);

    set_skill("force", 240);
    set_skill("dodge", 220);
    set_skill("unarmed", 240);
    set_skill("strike",400);
    set_skill("parry", 220);
    set_skill("staff", 200);
    set_skill("sword", 200);
	set_skill("literate", 150);
	
	set_skill("shenlong_xinfa", 220);
	set_skill("yixingbu", 220);
	set_skill("shenlong_bashi", 240);
	set_skill("huagu_mianzhang", 240);
	set_skill("shedao_qigong", 240);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("������",1,"����");

	carry_object("cloth")->wear();
	add_money(5000);
	set("no_talk",1);
	set("no_huan",1);

}

virtual char * chat_msg_combat(CChar * player)
{
	static char msg[255];
	
	switch(random(6))
	{
	case 0:
		g_Channel.do_emote(this,player, "smile", 0);
		break;
	case 1:
		g_Channel.do_emote(this,player, "haha", 0);
		break;
	case 2:
		return snprintf(msg,255,"ƾ����%sҲ����̫��үͷ�϶���?",query_respect(player));
	case 3:
		return "���ò��ͷ�����������";
	case 4:
		perform_action("strick hua", 1);
		break;
	case 5:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		say("����ʲô��˼������˼��������㲻������ô֪��������ô������", me);
		AddMenuItem("�����", "$2flatter $1 $2", me);
		AddMenuItem("����","", me);
		if(me->query_temp("wei/renwu4_1"))
			AddMenuItem("���������뿪������","likai", me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "likai") && !me->query("wei/renwu4") )
	{
		if(me->query_temp("wei/renwu4_6"))
		{
			tell_object(me,"�Һ鰲˳�ݺὭ������һ���ƿ�С����Ȼ������̸����������");
			set("owner",me->id(1));

			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name( "�鰲˳��ս��", "fight_room");	
			obj->set("room_locked", FIGHT_LOCKED);
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
			//��������Ƿ��ڳ�����û�����NPC���һ��
			env = load_room("�����̿յ�");
			CContainer * wei=env->present("su quan");
			if(!wei)
			{
				CChar * robber;
				robber = load_npc("shenlong_su");
				robber->set("owner",me->id(1));
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_B);
			}
			else
			{
				wei->set("owner",me->id(1));
				wei->move(obj);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_B);
			}
			obj->Begin_Fight(0);
			return 1;
		}
		else if(me->query_temp("wei/renwu4_2") && me->query_temp("wei/renwu4_3"))
		{
			say("�������ɫ���ã�������ʵ���Ѿ��������ۣ����������̵Ķ�ʹ��ʮ�����ɢ�ϳ������������ڱ���Ҫ������һ��ޭ�ߵĵ����ɻ��⣬��������Ƥ����ɢ��������֪����λӢ���Ƿ��ܰ��Ϸ����æ����",me);
			SendMenu(me);
			me->set_temp("wei/renwu4_4",1);
			return 1;
		}
		else if(me->query_temp("wei/renwu4_1"))
		{
			tell_object(me, "$HIR\n�鰲˳��ŭ����������Ȼ�������������Ҫ�����¡���");
			tell_object(me, "$HIR�޵ù��������������������\n");
			
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name( "�����̴�����ս��", "fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			//����޵ù��Ƿ񳡣���û�����NPC���һ��
			CContainer * wei=env->present("luo degui");
			CChar * robber;
			if(!wei)
			{
				robber = load_npc("shenlong_yin");
				robber->set("owner",me->id(1));
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			else
			{
				wei->set("owner",me->id(1));
				wei->move(obj);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
			}
			
			//�����������Ƿ񳡣���û�����NPC���һ��
			wei=env->present("tianyu daozhang");
			if(!wei)
			{
				robber = load_npc("shenlong_wugeng");
				robber->set("owner",me->id(1));
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			else
			{
				wei->set("owner",me->id(1));
				wei->move(obj);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
			}
			
			obj->Begin_Fight(0);
		}
		return 1;
	}
	return CNpc::do_talk(me, ask);
}  

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("��˵��ʲô�� ");

	message_vision(snprintf(msg,255,"$N����˵����%s", arg), me);

	if( strstr(arg, "���겻��")
		&&( strstr(arg, "�����ɸ�") 
		|| strstr(arg, "��������") 
		|| strstr(arg, "������ʥ") ))
	{
		command("smile");
		me->add_temp("tmark/��", 10);
		AddMenuItem("��ѧЩʲô������˵��","", me);
		SendMenu(me);
		DownLoad(me);
	} 
	else
	{
		say(" ����˲����ҷ�����������������㣿!");
		kill_ob(me); 
	}
	return 1;
}

virtual int prevent_learn(CChar * me, const char * arg)
{

	if (! me->querymap("family"))
	{
		say("��ɻ�û�ݹ�ʦ����Ҫѧ�������Ȱݸ�ʦ����˵�ɡ�");
		return 1;
	}

	if ( me->query_temp("tmark/��") == 1 )
	{
		me->delete_temp("tmark/��");
		DownLoad(me);

		say("���ܽ���Ķ�������Ϊֹ����Ҳ��Ҫ������ѧ�����ˡ�", me);
		SendMenu(me);
		return 1;
	}
	if(EQUALSTR(arg, "strike"))
	{
		if(me->query_skill("strike",1)>200 && DIFFERSTR(me->querystr("family/family_name"), "������"))
		{
			say("�����书���ܽ����ֻ�ܵ���Ϊֹ���㻻��Ĺ�����ѧ�ɣ���", me);
			return 1;
		}
	}
	me->add_temp("tmark/��", -1);
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if (! me->query_temp("tmark/��"))
		return 0;
	return 1;
}

virtual void die()
{
	message_vision("$N���������,��Ȼ������ɱ����,....��˵���������۵������ˡ�", this);
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));
		CContainer * suqing =env->present("su quan");
		if(me && suqing)
			me->set_temp("wei/renwu4_7",1);//ɱ���鰲˳
	}
	CNpc::die();
}


virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "������") ) 
	{
		say("�㲻�Ǳ��̽���, ����������!",player);
		SendMenu(player);
		return;
	}

	if (player->query_skill("shenlong_xinfa",1) < 100 ) 
	{
		say("��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°�!",player);
		SendMenu(player);
		return;
	}

	if(player->query_skill("shedao_qigong",1) < 100 ) 
	{
		say("��ı����ȷ�̫���ˣ�����ŬŬ�������һ�°�!",player);
		SendMenu(player);
		return;
	}

	if (player->query("repute") > -50000  ) 
	{
		say("�������������������������������ְ׵�����򽻵�������ذɣ�",player);
		SendMenu(player);
		return;
	}

	say("�ܺã��ܺá�");
	command(snprintf(msg,255,"recruit %ld", player->object_id()) );
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!me->querymap("wei")) return 0;

	if(EQUALSTR(ob->querystr("name"), "ޭ�ߵ�") && EQUALSTR(ob->querystr("id"), "qishe dan") 
		&& me->query_temp("wei/renwu4_5"))
	{
		tell_object(me,"\n$YEL�鰲˳��������1��ޭ�ߵ���ɲʱ�䣬һ�ɺ�����ͷ��ӿ����ֻ���ú鰲˳�Ĺ���һ���죬�����Ѿ���ȫ�ָ�!");
		me->set_temp("wei/renwu4_6",1);//���ƺú鰲˳
		destruct(ob);
	}

	return 1;
}
ZUSHI_END;