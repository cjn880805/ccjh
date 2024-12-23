// wei_ake.h ����
// �ز�	2002��12��25

NPC_BEGIN(CNwei_ake);

virtual void create()
{
	set_name("����","a ke");
	set("icon", young_woman3);
	set("long",  "�����ļ���������ɫ��Ө���񣬽��Ĳ��ɷ��");
	set("age", 17);
	set("per",40);
	
	set("gender","Ů��");
	set("help",1);
	
	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);
	
	set("hp",30000);
	set("eff_hp",30000);
	set("max_hp",30000);
	
	set("max_mp",300);
	set("mp",300);
	
	set("chat_chance", 30);
	carry_object("qinqin_sword")->wield();
	call_out(do_die, 900);
	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!query("ok") && me->query_temp("wei/renwu3_7") && !me->query_temp("wei/renwu3_8")
		&& EQUALSTR(environment()->querystr("base_name"),"��ٹ����׽���" ))
	{
		tell_object(me,"\n$YEL����վ��é��ǰ��ԥ��һ��������ڹ����������ƿ��������˽�ȥ��");
		call_out(do_fumu, 120);
		move(load_room("temp_ake"));
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!query("ok"))
	{
		//if(querystr("owner")[0] && EQUALSTR(querystr("owner"), me->id(1)))
		//{
			if(me->query_temp("wei/renwu3_9"))
			{
				say("����˵��������һ·���Ӣ��������ʹСŮ�������������һ�档��ȻС���ӽ��������ң�����������ȥ�ɣ���",me);
				SendMenu(me);
				return 1;
			}
			else if(me->query_temp("wei/renwu3_8"))
			{
				if(! strlen(ask))
				{
					AddMenuItem("ѯ�ʹ���С��","xiaobao",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "xiaobao") )
				{
					me->set_temp("wei/renwu3_9",1);//���ɴ�Ӧ�ؼ�
					tell_object(me,"$HIC����̾�˿�����");
					tell_object(me,"\n����˵��������һ·���Ӣ��������ʹСŮ�������������һ�档��ȻС���ӽ��������ң�����������ȥ�ɣ���");
					tell_object(me,"$HIC���ɾ����������ж���\n");
					
					CChar * wei = load_npc("wei_ake");
					wei->move(environment());
					wei->set("owner",me->id(1));
					wei->set_leader(me);
					destruct(this);
				}
				return 1;
			}
		//}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!query("ok") && !query("cry"))
	{
		if(EQUALSTR(ob->querystr("name"), "��Ѫ���ؼ�") && EQUALSTR(ob->querystr("id"), "xue shu jian") 
			&& me->query_temp("wei/renwu3_4"))
		{
			tell_object(me,"\n$HIC���ɿ���������");
			tell_object(me,"\n$HIC����˵������ԭ��������������ٹ����׽��ϣ�����ɶ�����������겻ɢ�������ڻ����Ź����ǡ���");
			tell_object(me,"$HIC���ɡ�ˢ����һ������һ�ѱ�Ѫ����\n");
			
			me->set_temp("wei/renwu3_5",1);//��ʼ��������
			destruct(ob);
			
			CChar * wei = load_npc("wei_ake");
			wei->set("owner",me->id(1));
			wei->set("cry",1);
			wei->move(load_room("������䶨��"));
			tell_object(me,"�����������䶨���뿪��");
			move(load_room("temp_ake"));
			//destruct(this);
			return 1;
		}
	}
	return 0;
}

virtual char * chat_msg()
{
	if(query("cry"))
	{
		switch(random(2))
		{
		case 0:
			bl_move();
			break;
		case 1:
			CFightRoom * obj;
			CContainer * env = environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set_name("���ɵ�ս��", "fight_room");		
			obj->move(env);
			
			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
			
			for(int i=0;i<random(2)+1;i++)
			{
				CChar * robber = load_npc("wei_canbing");
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
			}
			obj->Begin_Fight(0);
			break;
		}
	}
	return 0;
}

void bl_move()
{
	int i;
	i=query("teapot/bl");
	if (i==20)
	{
		set("chat_chance",0l);
		return ;	// ����Ŀ�ĵأ�
	}
	else
	{
		static char bnline[20][20]={"���������С·","�����ϲ�ݳ�","�����������","����Ǵ�·4","�����˫����","���������","�������","����Ǳ���","�����̫�ͳ�","�������گ�»���","����ǹٵ�3","����ǹٵ�2","����ǹٵ�1","������ʯ��","��ٹȽ���С·1","��ٹȽ���С·2","��ٹȽ���С·3","��ٹ����˶�","��ٹ�������","��ٹ����׽���"};
		CRoom * troom=load_room(bnline[i]);
		char msg[255];
		tell_room(environment(), snprintf(msg, 255, "������%s�뿪��",bnline[i]));
		move(troom);
		set("teapot/bl",i+1);
		return ;
	}
}

static void do_fumu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		npc->move(load_room("��ٹ����׽���"));
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			tell_object(me,"\n$YEL���ɺ���˫�����˳�����");
			me->set_temp("wei/renwu3_8",1);//���ɺ͸�ĸ�����
		}
		else
		{
			destruct(npc);
		}
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;