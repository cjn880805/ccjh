//gongnv.h
//�ز� 2002-08-01

NPC_BEGIN(CNlj_gongnv);

virtual void create()
{
	set_name("��Ů", "gong nv");
	set("gender", "Ů��");
	set("icon", 4);
	
	set("title", "���Ļʹ�");
	set("age", 15);
	set("attitude", "friendly");

	set("per",23);
	set("no_kill",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("���ݻʹ�����");

	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu114"))
	{
		message_vision("\n$HIR$Nһ���鷿��ֻ���鷿���������������漣�Ļ��ᡣ",me);
		message_vision("$HIR�����ܲ�ͨ��ʶ�������Ȼ̽�ֽ�����ȡ����ˣ������ͻȻ���ֻ������ڸǵ�ʯ���Ͼ�Ȼ��������书�伮���˵����ޱ���󣬰������",me);
		message_vision("$HIR��ϲ֮�����˾����˴��е�Ŀ�ģ�������һһ˺�£���ʼ����ʯ���ϵ��书��",me);
		message_vision("\n$HIR$NҲ�̲�ס���棬Ҳ���˹�ȥ����ϸ�ۿ���ʯ���ϵ�ͼ��������",me);
		me->set_temp("lj/renwu114",1);
		me->disable_player("������");
		set("player",atoi(me->id(1)));
		call_out(do_shibi, 10);	
	}
}

static void do_shibi(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CContainer * env=(CChar *)(ob->environment());
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))	continue;
		if(DIFFERSTR(target->querystr("name"), "��Ů") )
		{
			if(EQUALSTR(target->querystr("name"), "������")|| EQUALSTR(target->querystr("name"), "����")||
				EQUALSTR(target->querystr("name"), "���˻�")|| EQUALSTR(target->querystr("name"), "����")||
				EQUALSTR(target->querystr("name"), "Ԭ��־"))
			{
				message_vision("\n$N�о��书�߻���ħ����ʱ���ԣ�ʧȥ�˱������׵��ʸ�", target);
				message_vision("$HIR�鷿�ڵļ���̫�����˹�����С������Ľ�$N������鷿�Ե������С�", target);
				//target->move(load_room("���ݻʹ����鷿����"));
				destruct(target);
			}
		}
	}
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			me->add("combat_exp",5000);
			me->UpdateMe();
			message_vision("\n$HIR$N���������ƺ��е��ĵá�����",me);
		}
	}
	npc->call_out(do_shibi1, 10);	
}

static void do_shibi1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CContainer * env;
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			if(EQUALSTR(me->querystr("gender"), "Ů��") )
			{
				if(DIFFERSTR(me->querystr_temp("apply/name"),"����"))
				{
					message_vision("$HIR�ʹ���ʿ������ס���㣬���������Ů�ˣ��α����μӱ��������أ�����", me);
				}
				else if(!me->query_temp("lj/renwu111"))
				{
					message_vision("$HIR�ʹ���ʿ������ס���㣬��������������δ���е�ǳ���ˡ�����", me);
				}
				else
				{
					int lvl=me->query_skill("force",1);
					int jump;
					if(lvl>=300)
						jump=1;
					else if(lvl>=200 )
					{
						if(random(100)>20)	jump=1;
					}
					else if(lvl>=100 )
					{
						if(random(100)>30)	jump=1;
					}
					else if(lvl>=50 )
					{
						if(random(100)>50)	jump=1;
					}
					if(jump==1)
					{
						message_vision( "\n$HIR�㿴��ǽ�ϰ���͹͹��ǧ��ٹֵ�ͼ�Σ���Լ��������һ�Ÿ������ѧ����һ������е�Ŀ�ģ���ǿ�н�Ŀ���ʯ�����ƿ���",me); 
						npc->call_out(do_shibi2, 10);
					}
					else
					{
						message_vision("\n$HIR�㿴��ǽ�ϰ���͹͹��ǧ��ٹֵ�ͼ�Σ�ͻȻ�о�ͷʹ���ѣ������쳣�������������ڵء� ",me); 
						message_vision("$HIR��ʧȥ�������ʸ�",me); 
						message_vision("\n$HIR��μӱ�������ʧ�ܣ���Ե�������Ĺ��������޷���֤�ι��ڹ��ںδ�����֮̾��ֻ�з��� ��\n\n",me); 
						me->del("lj");
						me->delete_temp("lj");
						me->enable_player();
						env = load_room("���ݻʹ�����");
						if(env->query("start"))env->del("start");
						env = load_room("���ݻʹ�����");
						if(env->query("start"))env->del("start");
						me->move(load_room("���ݻʹ�����"));
					}
				}
			}
			else
				message_vision("$HIR�һ裡������ô�쵽���������أ����˳���ǧѽ��",me);
		}
	}
}

static void do_shibi2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			CContainer * env=me->environment();
			me->enable_player();
			message_vision("\n$HIR��ŮЦ�Ŷ��ڳ�����˵��������ϲ��λ����˳��ͨ����ǰ���صĿ��飡����",me);
			message_vision("$HIR˵�գ����ֽҿ��鷿�ϲ��һϯ������˵���������λ�����Ʋ�����������Ϣ���ٽ�����һ�ֵı��ԡ���",me);
			DTItemList * list = env->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj = list->GetNext(p);
				if(! obj->is_character()) continue; 
				CChar * target = (CChar *)obj;  
				if(userp(target))	continue;
				if(DIFFERSTR(target->querystr("name"), "��Ů") )
				{
					target->set("lj",1);
					target->move(load_room("���ݻʹ�����"));
				}
			}
			env->set("start",1);
			me->add("combat_exp",5000);
			me->UpdateMe();
			tell_object(me, "\n$HIR��ͨ���ˡ����Ļʹ������������ڹ���Ŀ���Ŀ��飬�����5000��ľ��齱����\n");
			npc->del("player");
		}
	}
}

NPC_END;

