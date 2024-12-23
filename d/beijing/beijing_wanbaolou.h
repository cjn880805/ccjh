//wanbaolou.h ��¥

ROOM_BEGIN(CRBeiJing_wanbaolou);

virtual void create()
{
	set_name( "��¥");

	add_npc("pub_jianning");//��������
	add_npc("pub_shiwei1");//����������������
	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");

	set("no_fight",1);
	set("no_cast",1);
	
	add_door("��������", "��������", "������¥");

	set("long", "¥����������챦,�м���Ű�����������Ƕ���ɺ졢�̱�ʯ�Ľ��Σ�����ֺͿ������ɽ���������ɡ�����Ϊ�������磬�����������Կ��š������®С�� ��Ӱ��֪�ٴ� ���θ��Ǻ� �ֱ��������� ........����" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query("wei/renwu2"))
	{
		if(me->query("wei/renwu1") && !me->query_temp("wei/renwu2_1"))
		{
			tell_object(me, "\n$YEL�����ŭ�ȵ������󵨵��񣬼��˱�����Ϊ�β��¹����ң��������������£���");
			tell_object(me, "$YELһȺ������һӿ���ϣ����㰴���ڵأ��������Ӱ����������˸���ʵ��\n");
			me->disable_player("������");
			me->call_out(do_tanhua, 1);
		}
		else if(me->query("wei/renwu1") && me->query_temp("wei/renwu2_1") && me->query_temp("wei/renwu2_2"))
		{
			if(!me->query_temp("wei/renwu2_4"))
			{
				tell_object(me, "\n$YEL����������������������ԭ����װ������");
				//��������������������ҡ�ս�����������Ӯ���������������������ʧ�ܡ�
				CFightRoom * obj;
				CContainer * env = me->environment();
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name("��¥��ս��", "fight_room");		
				obj->move(env);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				
				for(int i=0;i<4;i++)
				{
					CContainer * wei=env->present("Shi Wei");
					if(!wei)
					{
						CChar * robber = load_npc("pub_shiwei1");
						robber->set("owner",me->id(1));
						robber->move(obj);
						obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
					}
					else
					{
						wei->set("owner",me->id(1));
						wei->move(obj);
						obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
					}
				}
				obj->Begin_Fight(0);
			}
			else
			{
				tell_object(me, "\n$YELֻ������������ݽǣ�һ�����ŵ�ģ����\n");
			}
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	int damage;
	if(me->query("pks")<10)
	{
		switch(me->query_temp("wei/tanhuan"))
		{
		case 0:
			tell_object(me, "\n�����������ٺٵؼ�Ц�˼�����");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 1:
			tell_object(me, "������ó�һ�Ѿ��µ�Сذ�ף��ÿ��ë�������ã��ְѵ��ӽ�����ˮ������һ�����Ȼ��������£���ذ������ı��ϻ�������");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 2:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n�������ذ������ı���бб�ػ���һ����");
			tell_object(me, snprintf(msg, 255,"$HIR���۵òҽ���һ������������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 3:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n�������ذ������ı��ϻ���һ��ֱ�ߡ�");
			tell_object(me, snprintf(msg, 255,"$HIR���۵òҽ���һ������������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 4:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n�������ذ������ı��Ͽ��ٵػ���һ��������");
			tell_object(me, snprintf(msg, 255,"$HIR���۵òҽ���һ������������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 5:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n�������ذ������ı��ϴ��˼��£�");
			tell_object(me, snprintf(msg, 255,"$HIR���۵òҽ���һ������������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 6:
			tell_object(me, "\n���������ܲ�����ˮ�Ӵ��˵���ʹ������һ�ڣ����˹�ȥ��\n");
			me->delete_temp("wei/tanhuan");
			me->enable_player();
			me->set_temp("wei/renwu2_1",1);//�Ѿ��ܹ����������ĥ
			me->unconcious();
			me->move(load_room("������¥ˮ��"));
			break;
		}
	}
	else if(me->query("pks")<100)
	{
		switch(me->query_temp("wei/tanhuan"))
		{
		case 0:
			tell_object(me, "\n�����������Ц��һ����");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 1:
			damage=500+random(500)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n������ֳ�һ�Ѹֵ���������������һ������������");
			tell_object(me, snprintf(msg, 255,"$HIR��ʹ�������ҽУ���������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 2:
			damage=500+random(500)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n������ֳ�һ�Ѹֵ�����������Ҷ���һ������������");
			tell_object(me, snprintf(msg, 255,"$HIR��ʹ�������ҽУ���������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 3:
			damage=500+random(500)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n������ֳ�һ�Ѹֵ���������ı��ӣ�һ������������");
			tell_object(me, snprintf(msg, 255,"$HIR��ʹ�������ҽУ���������%d����˺���",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 4:
			tell_object(me, "\n������̧��һ�澵�ӷŵ�����ĸ�ǰ���㿴���������Լ��ĹŹ�ģ�����ŵ����˹�ȥ��\n");
			me->delete_temp("wei/tanhuan");
			me->enable_player();
			me->set_temp("wei/renwu2_1",1);//�Ѿ��ܹ����������ĥ
			me->unconcious();
			me->move(load_room("������¥ˮ��"));
			break;
		}
	}
	else
	{
		switch(me->query_temp("wei/tanhuan"))
		{
		case 0:
			tell_object(me, "\n���������һ����");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 1:
			if(me->query("hp")<4444)
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
				me->add("apply/str",-1);
				me->add("apply/dex",-1);
			}
			else
				damage=4444;
			me->add("hp",-damage);
			tell_object(me, "\n���������һ�Ѵ�絶�������䣬���¾Ͱ��������ܿ��ĵط�ȫ����������");
			tell_object(me, snprintf(msg, 255,"$HIR�㻹û���ü����������Ѿ�ʧȥ��֪������������%d����˺���\n",damage));
			me->delete_temp("wei/tanhuan");
			me->enable_player();
			me->set_temp("wei/renwu2_1",1);//�Ѿ��ܹ����������ĥ
			me->unconcious();
			me->move(load_room("������¥ˮ��"));
			break;
		}
	}
}
ROOM_END;
