//wuding.h

//Sample for room: �䶨��
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_wuding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䶨��");

	set("resident", "ϲ��");

	//add npcs into the room
	add_npc("pub_guniang");
	add_npc("pub_shiwei3");
	
	add_door("�����ũ��", "�����ũ��", "������䶨��");
	add_door("�������¥��", "�������¥��", "������䶨��");
	add_door("�����������", "�����������", "������䶨��");
	add_door("���������С·", "���������С·", "������䶨��");

	set("long", "������̨�ķ�֧¬¹�����������θ����������������䶨���⻹ϽԪı��»�����򡣴��򲻴�����ɽ����������Եø������ġ�¬¹���˵���¥��ɢ�ֲ��������С�" );
	
};


void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query("wei/renwu3"))
	{
		if(me->query("wei/renwu1") && !me->query_temp("wei/renwu3_1"))
		{
			CContainer * env = me->environment();
			CContainer * wei=env->present("shi wei");
			if(wei)
			{
				tell_object(me, "\n$HIR����������ಿ�ڶ������ȵ����������ܣ���");
				tell_object(me, "$HIR����������ಿ�ڶ����������˹�����\n");
				me->set_temp("wei/renwu3_1",1);//����С�����񰢿����

				CFightRoom * obj;
				obj = (CFightRoom *)load_item("fight_room");		
				obj->set_name("����������ಿ�ڵ�ս��", "fight_room");		
				obj->move(env);
				
				wei->move(obj);
				wei->set("owner",me->id(1));
				wei->set("hp",100);
				obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_B);
				
				for(int i=0;i<4;i++)
				{
					CNpc * robber = load_npc("wei_canbing");
					((CChar * )robber)->set("owner",me->id(1));
					((CChar * )robber)->move(obj);
					obj->Join_Team(((CChar * )robber), CFightRoom::FIGHT_TEAM_A);
				}
				obj->Begin_Fight(0);
			}
		}
	}
}

RESIDENT_END;
