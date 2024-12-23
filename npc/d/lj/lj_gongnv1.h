//gongnv1.h
//�ز� 2002-08-01
#define FIGHTER_BEGIN(npc_name) class npc_name : public CNwiz_fighter	{	public:	npc_name(){};	virtual ~npc_name(){};
#define FIGHTER_END		};	

NPC_BEGIN(CNlj_gongnv1);

virtual void create()
{
	set_name("����Ů", "gong nv");
	set("gender", "Ů��");
	set("icon", 4);
	
	set("title", "���Ļʹ�");
	set("age", 15);
	set("attitude", "friendly");

	set("per",29);
	set("no_kill",1);

	set("channel", "f1");
	set("chname", "��������");
	set("grant", 80);
	set("chat_chance", 80);
	set("no_talk",1);
	set("no_kill",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	CContainer * r = load_room("���ݻʹ�����");

	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu116") && EQUALSTR(me->querystr_temp("apply/name"),"����"))
	{
		me->set_temp("lj/renwu116",1);
		message_vision("\n$HIR����Ů��Ц˵����ʣ�¼�λ���ӣ������Ա������ʤ����ʤ������ش������������⣡",me);
		set("player",atoi(me->id(1)));
		call_out(do_biwu, 10);	
	}
	if(me->query_temp("lj/biwu/win") && me->query_temp("lj/biwu/win") !=3 
		&& !query(snprintf(msg,255,"biwu%d",me->query_temp("lj/biwu/win"))) )
	{
		char msg[255];
		message_vision("\n$HIR����Ů˵������ϲ��λ����ʤ���˾֣��빫��������Ϣ�����Ͻ�Ҫ��ʼ��һ�ֱ����ˣ�",me);
		set(snprintf(msg,255,"biwu%d",me->query_temp("lj/biwu/win")) ,1);
	}
	if(me->query_temp("lj/biwu/win") ==3)
	{
		//����ʤ��
		tell_object(me, "\n$HIR��ͨ�����ֵĽ���������ˡ����Ļʹ��������ס���һ���������5000��ľ��齱����\n");
	
		message_vision("$HIR����Ů����˵������������������λ�������ģ�ԭ��Ҫ����ѿ͡����������������⣬������λ���ӻش�",me);
		message_vision("$HIR���Ǻ��˹������⣬�Ե��������",me);
		me->add("combat_exp",5000);
		me->UpdateMe();
		del("npc_count");
		del("quiz");
		del("player");
		del("npc");
	}
}


virtual char * chat_msg()
{
	if(query("biwu1")||query("biwu2"))
	{
		CContainer * env=(CChar *)environment();
		if(query("npc_count"))
			del("npc_count");
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(userp(target))	continue;
			if(DIFFERSTR(target->querystr("name"), "����Ů") )
			{
				add("npc_count",1);
			}
		}
		if(query("biwu1") && query("npc_count")>=3)
		{
			del("biwu1");
			call_out(do_biwu, 10);
		}
		if(query("biwu2") && query("npc_count")>=1)
		{
			del("biwu2");
			call_out(do_biwu, 10);
		}
	}
	return 0;
}

static void do_biwu(CContainer * ob, LONG param1, LONG param2)
{
	CNlj_gongnv1 * npc = (CNlj_gongnv1 *)ob;
	CContainer * env=(CChar *)(ob->environment());
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			CChar * target1;
			CChar * target2;
			CChar * target3;
			CChar * target4;
			CChar * target5;
			CChar * target6;
			CChar * target7;
			DTItemList * list = env->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj = list->GetNext(p);
				if(! obj->is_character()) continue; 
				CChar * target = (CChar *)obj;  
				if(userp(target))	continue;
				if(DIFFERSTR(target->querystr("name"), "����Ů") )
				{
					switch(npc->query("npc"))
					{
					case 0:
						if(target->query("lj"))
						{
							target1= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 1:
						if(target->query("lj"))
						{
							target2= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 2:
						if(target->query("lj"))
						{
							target3= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 3:
						if(target->query("lj"))
						{
							target4= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 4:
						if(target->query("lj"))
						{
							target5= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 5:
						if(target->query("lj"))
						{
							target6= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 6:
						if(target->query("lj"))
						{
							target7= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					}
				}
			}
			int man_num=1;
			for(int num=0;num<3-me->query_temp("lj/biwu/win");num++)
			{
				man_num=2*man_num;
			}
			if(npc->query("npc")>=man_num-1)
			{
				npc->del("npc");
				CContainer * oldenv;
				if(me->query_temp("lj/biwu/win")<2)
				{
					message_vision("\n$HIY$N��$n��ȭ����һ���񣺼�Ȼ��ˣ�$n�֣����ˡ�",target2,target3);
					message_vision("$HIY$nЦ�����ѵ������������$N����̣��Ǻǣ��롣",target2,target3);
					target2->set_temp("biwu/team", 0l);		
					target3->set_temp("biwu/team", 1);
					CContainer * env_biwu1 = Do_BiShi(target2,target3, "��������", 0);
					npc->set_biwu(env_biwu1);
					oldenv = find_object(npc->query_temp("is_boardcast"));
					if(! oldenv) npc->do_snoop(env_biwu1);
				}
				if(me->query_temp("lj/biwu/win")<1)
				{
					message_vision("\n$HIY$N��$n��ȭ����һ���񣺼�Ȼ��ˣ�$n�֣����ˡ�",target4,target5);
					message_vision("$HIY$nЦ�����ѵ������������$N����̣��Ǻǣ��롣",target4,target5);
					target4->set_temp("biwu/team", 0l);		
					target5->set_temp("biwu/team", 1);
					CContainer * env_biwu2 = Do_BiShi(target4,target5, "��������", 0);
					npc->set_biwu(env_biwu2);
					oldenv = find_object(npc->query_temp("is_boardcast"));
					if(! oldenv) npc->do_snoop(env_biwu2);
					
					message_vision("\n$HIY$N��$n��ȭ����һ���񣺼�Ȼ��ˣ�$n�֣����ˡ�",target6,target7);
					message_vision("$HIY$nЦ�����ѵ������������$N����̣��Ǻǣ��롣",target6,target7);
					target6->set_temp("biwu/team", 0l);		
					target7->set_temp("biwu/team", 1);
					CContainer * env_biwu3 = Do_BiShi(target6,target7, "��������", 0);
					npc->set_biwu(env_biwu3);
					oldenv = find_object(npc->query_temp("is_boardcast"));
					if(! oldenv) npc->do_snoop(env_biwu3);
				}

				message_vision("\n$HIY$N����$nЦ�����������Լ���Ӳ��ͷƤ���˹�ȥ������һ����ȭ��$n�֣����������顣",me,target1);
				me->set_temp("biwu/team", 0l);
				me->set_temp("no_fei",1);
				target1->set_temp("biwu/team", 1);
				CContainer * env_biwu4 = Do_BiShi(me,target1, "��������", 0);
				env_biwu4->set("room_locked", FIGHT_LOCKED);
				npc->set_biwu(env_biwu4);
				oldenv = find_object(npc->query_temp("is_boardcast"));
				if(! oldenv) npc->do_snoop(env_biwu4);
			}
		}
	}
}

void set_biwu(CContainer * ob)
{
	char msg[40];

	snprintf(msg, 40, snprintf(msg, 40, "%ld", ob->object_id()));

	if( m_biwulist.find(msg) == m_biwulist.end() )
		m_biwulist.append(msg);
}

void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	//�����Ǳ����ʤ�ߵĴ���
	winner->add_temp("lj/biwu/win",1);
	winner->delete_temp("biwu");
	if(winner->query("no_fei"))
		winner->delete_temp("no_fei");
	failer->delete_temp("biwu");
	if(failer->query("no_fei"))
		failer->delete_temp("no_fei");

	winner->revive(1);
	failer->revive(1);

	CContainer * env = winner->environment();
	remove_biwu(env);
}

void remove_biwu(CContainer *ob)
{
	char msg[80];
	m_biwulist.remove(snprintf(msg, 40, "%ld", ob->object_id()));
}

void do_snoop(CContainer * env)
{
	const char * ch = querystr("channel");
	if(! ch[0])	return;
		
	env->set("channel_cast", ch);
	env->set("channel_id", querystr("chname"));
	set_temp("is_boardcast", env->object_id());			
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("lj/biwu/win")==3 && !me->query_temp("lj/quiz"))
	{
		say("����Ů�ʵ�����������������������̡�", me);
		switch(query("quiz"))
		{
		case 0:
			say("����Ů�ʵ�����һ�ʣ�����һ��֮�У���ʲô�ط����ǿ�����ң��", me);
			break;
		case 1:
			say("����Ů�ʵ����ڶ��ʣ�����ƽ���֮�ˣ���ʲô���֣�", me);
			break;
		case 2:
			say("����Ů�ʵ��������ʣ���������������ò��Σ�", me);
			break;
		}
		AddMenuItem("�ش�", "$2flatter $1 $2", me);
		SendMenu(me);
		return 1;
	}
	
	return CNpc::do_talk(me,ask);
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
		return notify_fail("��ʲô�� ");

	if(!query("quiz"))
	{
		message_vision(snprintf(msg,255,"$N��̾һ����˵����%s", arg), me);
		if(strstr(arg, "��һ���ڰ��ı���֮�С�"))
		{
			message_vision("\n$HIR������һ��Ů��������������һ���ͺ�������Ǻ�һ���죬һֻ�ɱ��������£���÷��顣",me);
			set("quiz",1);
			me->set_temp("lj/quiz_y",1);
		} 
		else
		{
			message_vision("\n$HIY�ǹ�Ů�������Ƿ���ʽ����Ӳ�֪���ɹ������¾�����",me);
			set("quiz",1);
		}
	}
	else if(query("quiz")==1)
	{
		message_vision(snprintf(msg,255,"$N����%s", arg), me);
		if(strstr(arg, "�����ҡ����Ҳ�֪����λ�����ʲô���֡�") )
		{
			message_vision("\n$HIR�ǹ�Ů��������֪��λ�������������Ҳ�������£�����Т�Ӷ�������������Ů�·�������֪����������ϸ���Ͱ�����������",me);
			set("quiz",2);
			me->add_temp("lj/quiz_y",1);
		} 
		else
		{
			message_vision("\n$HIY�ǹ�Ů�������Ƿ���ʽ����Ӳ�֪���ɹ������¾�����",me);
			set("quiz",2);
		}
	}
	else if(query("quiz")==2)
	{
		message_vision(snprintf(msg,255,"$N����%s", arg), me);
		if(strstr(arg, "����ò���")
		&& strstr(arg, "��Ҳ�Ǵ���û������") )
		{
			set("quiz",3);
			me->add_temp("lj/quiz_y",1);
			
		} 
		else
		{
			set("quiz",3);
		}
		if(me->query_temp("lj/quiz_y")==3)
		{
			CNpc * yinchuan = load_npc("lj_yinchuan");
			yinchuan->set("owner",me->id(1));
			yinchuan->move(load_room("���ݻʹ���������"));
			message_vision("\n$HIR������һ��Ů�������͵��ʣ����㡭������ǡ����ɡ�ô����",me);
			message_vision("\n$HIY��������ת���뵽���ղ�ֻ��һ�������飬��������鳣��������ߵİ���˵�˳�ȥ��",me);
			message_vision("$HIYû�뵽����Ȼ��һλŮ�ӽ��Լ������ɡ����ѵ������ǡ��ιá�ô��������̤����Ь���ٴ�������ȫ���ѹ���",me);
			message_vision("\n$HIR�����������һ��״�������������㡭���㡭������ǡ��ιá�ô������������ˡ���",me);
			message_vision("$HIR�㲻����������ǰ���˼�����ֻ�ŵ�һ��ܰ�㣬һֻ�����Ử����������ס������֡�",me);
			message_vision("$HIRһ��������������������������������ɣ��ұ������㲻��������븸�����°��ģ����㵽����",me);
			message_vision("$HIR���ǵ�����˵��ȥ�����ɣ�������ҹҹ�������д�ʱ�˿̡�����",me);
			message_vision("$HIRһ��ϸ�����һ����������֣���û���Ĵ����Ļ��̤�ź��ĵ�̺���������á�\n",me);
			
			me->set_temp("lj/quiz",1);//�Ի����
			me->move(load_room("���ݻʹ���������"));
		}
		else
		{
			message_vision("\n$HIY����Ů��$N���˸�����λ�������Ժ������ȥ�����Ĵ𰸸��߹�����",me);
			message_vision("\n$HIRƬ�̺�ֻ�������д���һ�����ĵ�̾Ϣ�����ƺ���λŮ�ӵ�������",me);
			message_vision("\n$HIY����һ�ᣬ����Ů�������߳�����$N���˸�������Ǹ���˵����",me);
			message_vision("$HIY����λ���ӣ����칫��������Щ���ˣ����ܺ͹����������ˣ�����������ӱ�ʾǸ�⡣",me);
			message_vision("$HIY���͹���һЩСС����˼�����빫��Ц�ɡ���",me);
			CContainer * RMB=load_item("coin");
			RMB->set_amount(500000);
			RMB->move(me);
			
			message_vision("\n$HIR��ʧȥ�������ʸ�",me); 
			message_vision("$HIR��μӱ�������ʧ�ܣ���Ե�������Ĺ��������޷���֤�ι��ڹ��ںδ�����֮̾��ֻ�з��� ��\n\n",me); 
			me->del("lj");
			me->delete_temp("lj");
			me->enable_player();
			CContainer * env = load_room("���ݻʹ�����");
			if(env->query("start"))env->del("start");
			env = load_room("���ݻʹ�����");
			if(env->query("start"))env->del("start");
			env = load_room("���ݻʹ����鷿");
			if(env->query("start"))env->del("start");
			me->move(load_room("���ݻʹ�����"));
		}
		
	}
	return 1;
}


protected:
	CVector		m_biwulist;

NPC_END;

