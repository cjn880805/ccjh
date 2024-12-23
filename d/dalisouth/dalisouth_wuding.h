//wuding.h

//Sample for room: 武定镇
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_wuding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武定镇");

	set("resident", "喜州");

	//add npcs into the room
	add_npc("pub_guniang");
	add_npc("pub_shiwei3");
	
	add_door("大理城农田", "大理城农田", "大理城武定镇");
	add_door("大理城竹楼下", "大理城竹楼下", "大理城武定镇");
	add_door("大理城青竹林", "大理城青竹林", "大理城武定镇");
	add_door("大理城竹林小路", "大理城竹林小路", "大理城武定镇");

	set("long", "这里是台夷分支卢鹿族罗蝥部的治府，罗蝥部除了这武定州外还辖元谋、禄定两镇。此镇不大，正处山中竹林深处，显得格外清幽。卢鹿族人的竹楼四散分布在竹林中。" );
	
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
				tell_object(me, "\n$HIR吴三桂军残余部众对侍卫喝道：“哪里跑！”");
				tell_object(me, "$HIR吴三桂军残余部众对侍卫发动了攻击。\n");
				me->set_temp("wei/renwu3_1",1);//触发小宝任务阿可情节

				CFightRoom * obj;
				obj = (CFightRoom *)load_item("fight_room");		
				obj->set_name("吴三桂军残余部众的战斗", "fight_room");		
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
