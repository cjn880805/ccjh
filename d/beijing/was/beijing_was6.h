//beijing_was6.h  ���µ�����

RESIDENT_BEGIN(CRbeijing_was6);

virtual void create()
{
	set_name( "���µ�����");
	set("resident", "����");

	add_npc("was_lugunweng");
	add_npc("was_hemaoke");

	add_door("���µ����", "�������µ����", "�������µ�����");
	add_door("���µ��߲�", "�������µ��߲�", "�������µ�����");
};


int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query_temp("was/renwu2_5"))
		{
			me->move(load_room("��������"));
			return 0;
		}
		if(me->query_temp("was/master"))
		{
			//CChar * who=me->query_leader();
			CUser * player1=find_online(me->querystr_temp("was/����"));
			if(player1)
			//if(player1 && EQUALSTR(player1->name(1),who->name(1)))
			{
				CContainer * player2=present(player1->id(1));
				if(!player2)
					return notify_fail("$HIR������Ķ���ʧȥ����ϵ����������ȴ�����");
			}
		}
		else if(me->query_temp("was/leader"))
		{
			CUser * player3=find_online(me->querystr_temp("was/����"));
			if(player3)
			{
				CContainer * player4=present(player3->id(1));
				if(!player4)
					return notify_fail("$HIR������Ķ���ʧȥ����ϵ����������ȴ�����");
			}
		}
		CContainer * ShouWei=present("lu gun weng");
		CContainer * ShouWei1=present("he mao ke");
		if(ShouWei || ShouWei1)
			return notify_fail("\n$HIR�㿴����ڤ������һ�����е����ţ����ɵ�ͣ��������\n");
	}
	return CRoom::valid_leave(me, dir);
}
RESIDENT_END;
