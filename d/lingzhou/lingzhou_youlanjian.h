//youlanjian.h

//Sample for room: ������


ROOM_BEGIN(CRLingZhou_youlanjian);

virtual void create()		
{
	set_name( "������");

	add_door("���ݻʹ���԰", "���ݻʹ���԰", "���ݻʹ�������");
	add_door("���ݻʹ���������", "���ݻʹ���������", "���ݻʹ�������");

	set("no_fight",1);
	set("no_cast",1);
	add_item("gangsi");
	add_npc("lj_taijian");

};


int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"���ݻʹ���������"))
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
			else
			{
				message_vision("$HIRֻ���˴�����ʮ�����࣬����ˮ�����ǲ�����ȴֻ����һ��ϸ��˿��ϵ��", me);
				return 0;
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
