//wei_jhlz.h ��������
//С������

NPC_BEGIN(CNwei_jhlz);

virtual void create()
{
	set_name("��������", "jianghulangzhong");
	set("title","������");
	set("long","��������");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man5); 
	set("env/wimpy", 100);      
	
	set("max_hp", 4500);
	set("hp",  1500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("score", 80000);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed",180);
	set_skill("parry", 180);
	set("no_kill",1);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("wei/renwu1") && !me->query("wei/renwu5"))
	{
		if(me->query_temp("wei/renwu5_8") && !me->query_temp("wei/renwu5_10"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ�ʹ�������ɢ������","wang",me);
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "wang") )
			{
				if(!me->query_temp("wei/renwu5_9"))
				{
					say("��������˵������˵�������֮ˮ�����������ȴ���գ�",me);
					me->set_temp("wei/renwu5_9",1);//��֪����ɢ�䷽֮���֮ˮ
					SendMenu(me);
					return 1;
				}
				else
				{
					say("��������˵��������һ������һ�ֶϳ�����ʹ�ú������������������ȴ��ǰ��һ�У�",me);
					me->set_temp("wei/renwu5_10",1);//��֪����ɢ�䷽֮�ϳ���
					SendMenu(me);
					return 1;
				}
			}
		}
		else if(me->query_temp("wei/renwu5_1") && !me->query_temp("wei/renwu5_3"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ�ʹ����彣Ƽ������","mu",me);
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "mu") )
			{
				say("�������Ұ�������ɽ����������",me);
				me->set_temp("wei/renwu5_2",1);//����ɽ�θ���������
				SendMenu(me);
				return 1;
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(environment()->querystr("base_name"),"����é�Ҳ�" ))
	{
		if(EQUALSTR(ob->querystr("name"), "��ɽ��") && EQUALSTR(ob->querystr("id"), "shanshen")
			&& me->query_temp("wei/renwu5_2") && !me->query_temp("wei/renwu5_3"))
		{
			destruct(ob);
			tell_object(me,"\n�������дҴ�ææ�ܵ��ˡ�\n");
			me->set_temp("wei/renwu5_3",1);//������������ɽ��
			move(load_room("temp_lz"));
			return 1;
		}
	}
	return 1;
}

NPC_END;