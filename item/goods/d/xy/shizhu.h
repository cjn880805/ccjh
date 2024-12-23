//shizhu.h ʯ��
ITEM_BEGIN(CIshizhu)

virtual void create(int nFlag = 0)		
{
	set_name("ʯ��","shi zhu");
	set("unit", "��");
	set("no_get", "");
	set_weight(1);
};


virtual int do_look(CChar * me)
{
	say("����һ����ʯ�Ͼ��ĵ������ɵ����ӣ����д��и�͹�𣬿������ƺ����Ǹ����ذ�Ť��", me);
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6") && me->query_temp("xy/renwu6_3")==9)
	{
		AddMenuItem("���»���", "$9an $1", me);
	}
	SendMenu(me);
	
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6") && me->query_temp("xy/renwu6_3")==9)
	{
		if(!strcmp(comm, "an")  )
			return do_an(me, arg);
	}
	return 0;
}

int do_an(CChar *me, char * arg)
{
	char msg[255];
	int i;
	CContainer * env=me->environment();
	if(env->query("index")==5)
	{
		CContainer * XyNpc;
		if(me->query_temp("xy/renwu6_5"))
			XyNpc=env->present("li qiou heng");
		else
			XyNpc=env->present("li cang hai");
		//����Ź�֮��
		if(me->query_temp("xy/renwu6_3_1")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_9")==15 &&
			me->query_temp("xy/renwu6_3_2")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_8")==15 &&
			me->query_temp("xy/renwu6_3_3")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_7")==15 &&
			me->query_temp("xy/renwu6_3_4")+me->query_temp("xy/renwu6_3_5")+me->query_temp("xy/renwu6_3_6")==15 &&
			me->query_temp("xy/renwu6_3_1")+me->query_temp("xy/renwu6_3_2")+me->query_temp("xy/renwu6_3_3")==15 &&
			me->query_temp("xy/renwu6_3_1")+me->query_temp("xy/renwu6_3_4")+me->query_temp("xy/renwu6_3_7")==15 &&
			me->query_temp("xy/renwu6_3_3")+me->query_temp("xy/renwu6_3_6")+me->query_temp("xy/renwu6_3_9")==15 &&
			me->query_temp("xy/renwu6_3_7")+me->query_temp("xy/renwu6_3_8")+me->query_temp("xy/renwu6_3_9")==15
			&& XyNpc )
		{
			for(i=1;i<10;i++)
			{
				snprintf(msg, 255,"xy/renwu6_3_%d",i);
				me->delete_temp(msg);
			}
			if(me->query_temp("xy/renwu6_4"))
				me->set_temp("xy/renwu6_6",1);//�ڶ����ƽ�Ź�֮��,������۽�����ߧ����
			else
				me->set_temp("xy/renwu6_4",1);//��һ���ƽ�Ź�֮��,����׺�������ߧ����
			tell_object(me,"\n$HIC��ֻ���ý��µ���һ�����Ҳ�������Χ������¡¡�Ĵ��죬������ã����ڰ���������\n");
			me->move(load_room("��ң����ߧ���ض���"));
			XyNpc->move(load_room("��ң����ߧ���ض���"));
			me->del("xy/renwu6_lost");
			destruct(this);
		}
		else
		{
			CChar * robber;
			for(i=1;i<10;i++)
			{
				snprintf(msg, 255,"xy/renwu6_3_%d",i);
				me->delete_temp(msg);
			}
			me->delete_temp("xy/renwu6_3");
			tell_object(me,"\n$HIC��Χһ�ɴ�������Ϯ������ֻ����һ��ͷ��Ŀѣ���ؿ�Ϊ֮���ᡣ\n");
			//ʧ�ܣ�����ս��
			
			if(XyNpc && me->query_temp("xy/renwu6_1") && EQUALSTR(XyNpc->querystr("owner"),me->id(1)) && me->query_temp("xy/renwu6_2"))
			{
				CFightRoom * obj = (CFightRoom *)load_item("fight_room");
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name( "���������֮ս", "fight_room_feiling");		
				obj->move(env);
				
				(CChar * )XyNpc->move(obj);
				obj->Join_Team((CChar * )XyNpc, CFightRoom::FIGHT_TEAM_B);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				
				robber = load_npc("xy_shiwushi");
				robber->move(obj);
				robber->set("owner",me->id(1));
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);

				obj->Begin_Fight(0);
			}
			else
			{
				tell_object(me,"$HIC����ǰһ�ڣ����˹�ȥ��\n");
				me->unconcious();
				me->set("hp",me->query("eff_hp"));
				me->move(load_room("��ң�ȷ������������"));
				if(me->query_temp("xy/renwu6_5"))
					me->delete_temp("xy/renwu6_4");
				else
					me->delete_temp("xy/renwu6_1");
				me->delete_temp("xy/renwu6_2");
			}
			destruct(this);
		}
	}	
	else
	{
		tell_object(me,"\n$YEL�������ף����治֪��������ô����������������񣬾��棡������\n");
	}
	return 1;
}

ITEM_END;




