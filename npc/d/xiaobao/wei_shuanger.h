// wei_shuanger.h ˪��
// �ز�	2002��12��25

NPC_BEGIN(CNwei_shuanger);

virtual void create()
{
	set_name("˪��", "shuang er" );
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("long",  "�����ļ���������ɫ��Ө���񣬽��Ĳ��ɷ��");
	set("age", 17);
	set("per",36);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",5000);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	add_money((1+random(5))*1000);
	call_out(do_die, 900);	
	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!querystr("owner")[0] && !query("ok") && me->query_temp("wei/renwu9_3") && !me->query_temp("wei/renwu9_4"))
	{
		tell_object(me,"$HIC\n˪�����Ż����̲�ס���ĵؿ���������");
		tell_object(me,"$HIC˪�������������ж���\n");
		me->set_temp("wei/renwu9_4",1);//˪���ؼҿ�С��
		
		CChar * wei = load_npc("wei_shuanger");
		wei->move(me->environment());
		wei->set("owner",me->id(1));
		wei->set_leader(me);
		destruct(this);
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query("wei/renwu1"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ�ʹ���С��","xiaobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				if(!is_fighting())
				{
					tell_object(me,"\n$HIC˪����ɫ��Ȼһ�䣬���Ŷ��䣬���ܱ߿�������ȥ��");
					int index=random(MAX_ROOM_NUM);
					CContainer * env = load_room(global_room_name[index]);
					move(env);
					g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "˪���ܵ���%s��",env->querystr("base_name")));
				}
				else
				{
					me->set_temp("wei/renwu9_1",1);//ս����ѯ��˪������С������
					tell_object(me,"\n$HIC˪����ɫ���˱䣬˵������ֻҪ������ƽ���ͺ��ˡ��㲻�ö��������ˣ����ǲ����ȥ�����ġ�\n");
				}
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "С��ī��") && EQUALSTR(ob->querystr("id"), "xiaobao hua")
		&& who->query("wei/renwu1") && who->query_temp("wei/renwu9_1") && !who->query_temp("wei/renwu9_3") 
		&& is_fighting() && query_temp("fight/ap")>30)
	{
		destruct(ob);
		who->set_temp("wei/renwu9_3",1);//��˪��С���Ļ�
		tell_object(who,"$HIC\n˪���Ż����ŵ�������ս����\n");
		CFightRoom * obj=(CFightRoom *)environment();
		obj->End_Fight();
		return 1;
	}
	return 0;
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