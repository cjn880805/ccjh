// wei_mujianping.h �彣��
// �ز�	2002��12��25

NPC_BEGIN(CNwei_mujianping);

virtual void create()
{
	set_name("�彣��","mujian ping");
	set("title","������С����");
	set("icon", young_woman3);
	set("long",  "�����ĺ��������ǿ��������ŵ�����һ�����ˡ�");
	set("age", 17);
	set("per",32);
	
	set("gender","Ů��");
	
	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);
	
	set("hp",30000);
	set("eff_hp",30000);
	set("max_hp",30000);
	
	set("max_mp",300);
	set("mp",300);
	
	call_out(do_die, 900);
	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!query("ok") && me->query_temp("wei/renwu5_8") && EQUALSTR(environment()->querystr("base_name"),"���������" )
		&& !me->query_temp("wei/renwu5_16") )
	{
		tell_object(me,"\n$YEL�彣Ƽ�������������������ô��ҩ����ô���������ɣ������һ�ȱʲô�أ���\n");
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		CContainer * mianjue=me->present("mian ju");
		if(mianjue && EQUALSTR(me->querystr_temp("apply/name"),"��������"))
		{
			if(me->query_temp("wei/renwu5_17"))
			{
				if(! strlen(ask))
				{
					AddMenuItem("ѯ�ʹ���С��","xiaobao",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "xiaobao") )
				{
					me->set_temp("wei/renwu5_18",1);//�彣Ƽ���Իؼ���
					tell_object(me,"\n$HIC�彣Ƽһ�ѳ����������ϵ���Ƥ��ߡ�");
					tell_object(me,"$HIC�彣Ƽ������İ�����������һ�£�");
					tell_object(me,"$HIC�彣Ƽ���ۣ�����һ�����³�һ�����Ѫ��ˤ���ڵأ����˹�ȥ��");
					
					//�������
					destruct(mianjue);
					me->delete_temp("apply/name");
					//me->delete_temp("apply/id");
					me->delete_temp("apply/icon");
					me->delete_temp("apply/short");
					me->delete_temp("apply/long");
					me->delete_temp("apply/title");
					me->UpdateMe();
					
					CChar * wei = load_npc("wei_mujianping");
					wei->move(environment());
					wei->set("owner",me->id(1));
					wei->disable_player("������");
					destruct(this);
				}
				return 1;
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query("wei/renwu1") && !me->query("wei/renwu5"))
		{
			CContainer * mianjue=me->present("mian ju");
			if(mianjue && EQUALSTR(me->querystr_temp("apply/name"),"��������"))
			{
				if(EQUALSTR(ob->querystr("name"), "�ϳ���") && EQUALSTR(ob->querystr("id"), "duanchang") 
					&& me->query_temp("wei/renwu5_10"))
				{
					me->set_temp("wei/renwu5_14",1);//�յ��ϳ���
					destruct(ob);
					return 1;
				}
				else if(EQUALSTR(ob->querystr("name"), "ţƤ�ƴ�") && EQUALSTR(ob->querystr("owner1"), me->id(1)) 
					&& me->query_temp("wei/renwu5_12"))
				{
					me->set_temp("wei/renwu5_15",1);//�յ����֮ˮ
					destruct(ob);
					return 1;
				}
				if(me->query_temp("wei/renwu5_14") && me->query_temp("wei/renwu5_15"))
				{
					tell_object(me,"\n$HIC�彣Ƽ���ϳ�������һЩ��֪����ҩ��һ��Ž�һ��ҩ���У�����ЩС���֮ˮ���ŵ���¯��ϸϸ������������");
					tell_object(me,"$HICһ�ԵĽ�������˵��������Ű���һ���ӾͿ����ˣ���\n");
					me->set_temp("wei/renwu5_16",1);//��ʼ��������ɢ����Ҫ�ȴ�15����
					set("owner",me->id(1));
					call_out(do_jiagong, 360);
				}
			}
		}
	}
	return 0;
}

static void do_jiagong(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			tell_object(me,"\n$HIC�彣Ƽ�����õ�ҩ֭����һ��С���ڣ�һ�����ᣬһ��һ��һ�ڵ�������ȥ��");
			tell_object(me,"$HIC�彣Ƽ��ɫͻȻ�к�������\n");
			me->set_temp("wei/renwu5_17",1);//�ȹ�����ɢ
		}
		npc->del("owner");
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