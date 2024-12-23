ITEM_BEGIN(CIgangsi);

virtual void create(int nFlag = 0)		
{
	set_name( "��˿");	
	set("no_get", "��˿��Ҳ�����ߣ�������Ҳ̫�����˰ɡ�");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("����һ�����������������ϸ����˿��������ָ���������ɣ�ż�������ڵ���", me);
	say("��˿�¾�����ʯ�ͱ����ļ���Ϫ�����㿴���Ա�̫�࣬��������������ƺ�Ҫȥ���鷿�ͱ��뾭�˶�����", me);
	if(me->query("lj/renwu11"))
	{
		say("������ֻ�����ϣ�jump����˿��ƾ�Լ��ı��²����ߵ����Ķ԰���", me);
		AddMenuItem("���ϸ�˿", "$9jump $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "jump") == 0)
		return do_jump(me, arg);
	return 0;
}

int do_jump(CChar *me, char * arg)
{
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;
	CContainer * env;
	int jump;
	while(p)
	{
		obj = list->GetNext(p);
		if(userp(obj) || EQUALSTR(obj->querystr("id"), "fight_room"))
		{
			me->move(load_room("��ɽ������"));
			return 1;
		}
	}
	if(!me->query("lj/renwu11") && !me->query("lj/renwu_����"))
	{
		message_vision("$HIR�ʹ���ʿ������ס���㣬���󵨿�ͽ���ʹ�Ҳ��������Ҵ��ĵط�����", me);
		return 0;
	}
	else if(EQUALSTR(me->querystr("gender"), "Ů��") )
	{
		if(DIFFERSTR(me->querystr_temp("apply/name"),"����"))
		{
			message_vision("$HIR�ʹ���ʿ������ס���㣬���������Ů�ˣ��α����μӱ��������أ�����", me);
			return 0;
		}
		else if(!me->query_temp("lj/renwu111"))
		{
			message_vision("$HIR�ʹ���ʿ������ס���㣬��������������δ���е�ǳ���ˡ�����", me);
			return 0;
		}
		else
		{
			int lvl=me->query_skill("dodge",1);
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
			if(jump==1 || me->query("lj/renwu_����"))
			{
				tell_object(me, "\n$HIR������һԾ�����ϸ�˿�����λ��˼��Σ���ǿ֧��סû�е��½�ȥ�� "); 
				me->add_temp("lj/renwu118",1); //���õ�һ��������˿����5000�㾭��Ľ�����־
				env = me->environment();
				if(EQUALSTR(env->querystr("name"), "������"))
					me->move(load_room("���ݻʹ���������"));
				else
					me->move(load_room("���ݻʹ�������"));
				if(me->query_temp("lj/renwu118")==1)
				{
					me->add("combat_exp",5000);
					me->UpdateMe();
					tell_object(me, "\n$HIR��ͨ���ˡ����Ļʹ������������Ṧ��Ŀ���Ŀ��飬�����5000��ľ��齱����\n");
				}
			}
			else
			{
				tell_object(me, "\n$HIR������һԾ����̤��˿��ȴ����ʧȥƽ�⣬�԰����ˤ�£����ò��޴󰭡� "); 
				tell_object(me, "$HIR��ʧȥ�������ʸ�"); 
				tell_object(me, "\n\n$HIR��μӱ�������ʧ�ܣ���Ե�������Ĺ��������޷���֤�ι��ڹ��ںδ�����֮̾��ֻ�з��� ��\n\n"); 
				me->del("lj");
				me->delete_temp("lj");
				env = load_room("���ݻʹ�����");
				if(env->query("start"))env->del("start");
				env = load_room("���ݻʹ�����");
				if(env->query("start"))env->del("start");
				me->move(load_room("���ݻʹ�����"));
			}
		}
	}
	else
		tell_object(me,"$HIR�һ裡������ô�쵽���������أ����˳���ǧѽ��");
	return 1;
}

ITEM_END;

