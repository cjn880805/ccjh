CONDITION_BEGIN(CCnantianzhu);

virtual int update_condition(CChar *me, LONG & duration)
{
	if (duration < 1)
		return 0;

	char msg[255];
	CContainer * where = me->environment();

	if(! where) return 0;

	if(! living(me))
	{
		message_vision("$YELֻ��$N��ɫ�ߺ죬˫�۽��գ������૵������š���", me);
	}
	else
	{
		DTItemList * list = where->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;

		string gen = me->querystr("gender");
		if(gen == "����")
			gen = "Ů��";
		else
			gen = "����";

		int flag = 0;

		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) && obj->querystr("gender") == gen)
			{
				switch(random(8))
				{
				case 0:
					{
						if(random(3))
						{
							if(gen == "����")
								me->command(snprintf(msg, 255, "mo %ld", obj->object_id()));
							else
								me->command(snprintf(msg, 255, "18mo %ld", obj->object_id()));
						}
						else
						{
							if(gen == "����")
								me->command(snprintf(msg, 255, "new* mo %ld", obj->object_id()));
							else
								me->command(snprintf(msg, 255, "new* mo97 %ld", obj->object_id()));
						}
						flag = 1;
					}

					break;
				case 1:
					{
						message_vision("$HIR$N�����ߺ죬��Ϣ����������������ע����$n��", me, obj);
						flag = 1;
					}
					break;
				case 2:
					{
						message_vision("$HIR$N��������$n���ϣ�˺��$p���·�����ڴ������Ե�ʮ��ʹ�ࡣ", me, obj);
						flag = 1;
					}
					break;
				case 3:
				case 4:
				case 5:
					{
						if(! where->query("sleep_room"))
						{
							where->set("sleep_room", 1);	//ǿ�ȴ˵ؿ���˯��
							where->call_out(do_nosleep, 30);	//30��󲻿�˯
						}

						me->command(snprintf(msg, 255, "sleep %ld", obj->object_id()));
						flag = 1;
					}
					break;				
				}

				if(flag) break;
			}
		}

		if(! flag)
		{
			if(random(2))
			{
				message_vision("$HIR$N��ɫ�ƺ죬���������ѵ�����ʼһ���������·���", me);
				drop_equip(me);		
			}
			else
			{
				message_vision("$HIR$N˻�����У�״��ʹ�ࡣ", me);
				me->receive_damage("hp", -10);
			}
		}
	}
		
	duration --;	
	return CND_CONTINUE;
}

void drop_equip(CChar * me)
{
	char msg[40];
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;

	while(p)
	{
		obj = list->GetNext(p);
		if(obj->query("equipped"))
		{
			if(! random(2))
			{
				me->command(snprintf(msg, 40, "drop %ld", obj->object_id()));
				return;
			}
		}
	}
}

static void do_nosleep(CContainer * ob, LONG param1, LONG param2)
{
	ob->del("sleep_room");
}

CONDITION_END;