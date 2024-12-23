//neishufang.h

//Sample for room: ���鷿


ROOM_BEGIN(CRLingZhou_neishufang);

virtual void create()		
{
	set_name( "���鷿");

	add_door("���ݻʹ���������", "���ݻʹ���������", "���ݻʹ����鷿");
	add_door("���ݻʹ�����", "���ݻʹ�����", "���ݻʹ����鷿");

	set("no_fight",1);
	set("no_cast",1);
	add_npc("lj_gongnv");

};

int valid_leave(CChar * me, const char * dir)
{
	CContainer * env=me->environment();
	if(EQUALSTR(dir,"���ݻʹ�����"))
	{
		if(!me->query("lj/renwu11"))
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
			else if(!env->query("start"))
			{
				message_vision("$HIR��Ů��ס���㣬����λ����,���ڴ˵�������Ϣ������", me);
				return 0;
			}
			else
			{
				return CRoom::valid_leave(me, dir);
			}
		}
		else
		{
			message_vision("$HIR�һ裡�����еģ���ô���ܽӵ���������أ�����ǧѽ��", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
