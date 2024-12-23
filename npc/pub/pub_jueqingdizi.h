//pub_jueqingdizi.h

NPC_BEGIN(CNpub_jueqingdizi);

void create()
{
	set_name("����ȵ���", "JueQingGu dizi");
    set("gender", "Ů��");
	set("icon", girl1);

    set("age", 20);
    
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill",1);//����������ٹȵ�������

}

void init(CChar * me)
{
	CNpc::init(me);

	if(!me->query_temp("gumu/jq_y"))	
	{
		CContainer * env = me->environment();
		if(!me->query_temp("gumu/jq_count"))
			me->set_temp("gumu/jq_count",random(22)+10);
		me->set_temp("gumu/jq_y",1);
		me->add_temp("gumu/jq_count",-1);
		if(me->query_temp("gumu/jq_count")<2)
		{
			me->set_temp("gumu/jq_count",1);
			me->move(load_room("����ȴ���"));
		}
		else
		{
			CChar * robber;
			CFightRoom * obj;

			obj = (CFightRoom *)load_item("fight_room");		
			obj->set("room_locked", FIGHT_LOCKED);
			obj->set_name( "�����ս��", "fight_room_jueqing");		
			obj->move(env);
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

			static char tufei[18][20]={"pub_gaoming","pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao","pub_sangyuan","pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};
			int j=random(2);
			for(int i=0;i<j+1;i++)
			{
				robber = load_npc(tufei[random(18)]);
				robber->set_name("����ȵ���", "jue qing dizi");
				robber->set("title", "��ɽʹ��");
				robber->move(obj);
				obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
			}
			obj->Begin_Fight(0);
		}
	}
}


int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N������üͷ����Ҫ���ң���������һֱ���á�", me, this);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




