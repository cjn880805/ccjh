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
		message_vision("$YEL只见$N面色羞红，双眼紧闭，口中喃喃的呻吟着……", me);
	}
	else
	{
		DTItemList * list = where->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;

		string gen = me->querystr("gender");
		if(gen == "男性")
			gen = "女性";
		else
			gen = "男性";

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
							if(gen == "男性")
								me->command(snprintf(msg, 255, "mo %ld", obj->object_id()));
							else
								me->command(snprintf(msg, 255, "18mo %ld", obj->object_id()));
						}
						else
						{
							if(gen == "男性")
								me->command(snprintf(msg, 255, "new* mo %ld", obj->object_id()));
							else
								me->command(snprintf(msg, 255, "new* mo97 %ld", obj->object_id()));
						}
						flag = 1;
					}

					break;
				case 1:
					{
						message_vision("$HIR$N满面羞红，气息吁吁，含情脉脉的注视着$n。", me, obj);
						flag = 1;
					}
					break;
				case 2:
					{
						message_vision("$HIR$N奋力扑在$n身上，撕扯$p的衣服，大口喘气，显得十分痛苦。", me, obj);
						flag = 1;
					}
					break;
				case 3:
				case 4:
				case 5:
					{
						if(! where->query("sleep_room"))
						{
							where->set("sleep_room", 1);	//强迫此地可以睡觉
							where->call_out(do_nosleep, 30);	//30秒后不可睡
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
				message_vision("$HIR$N脸色灼红，浑身燥热难当，开始一件件丢弃衣服。", me);
				drop_equip(me);		
			}
			else
			{
				message_vision("$HIR$N嘶声喊叫，状极痛苦。", me);
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