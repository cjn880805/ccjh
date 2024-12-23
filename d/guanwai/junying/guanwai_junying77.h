//junying77.h  中军帅帐
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying77);

virtual void create()			
{
	set_name("中军帅帐");

	set("renwu", 1);
	set("boss", 1);

	add_npc("bj_ma");
	add_npc("bj_wangqiuren");

	add_door("中军营帐1", "关外中军营帐1", "关外中军帅帐");
	add_door("中军营帐2", "关外中军营帐2", "关外中军帅帐");
	add_door("中军营帐3", "关外中军营帐3", "关外中军帅帐");
	add_door("中军营帐4", "关外中军营帐4", "关外中军帅帐");
	add_door("中军营帐5", "关外中军营帐5", "关外中军帅帐");
	add_door("中军营帐6", "关外中军营帐6", "关外中军帅帐");

	set("long","整个大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破。看得出王求仁也是久读兵书，惯战沙场的骁将。" );

};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(!me->query_temp("zhang/冯力强_jion"))
	{
		me->move(load_room("佛山北帝庙"));
		return 1;
	}
	else 
	{
		CContainer * obj = Present(atol(target));
		if(EQUALSTR(obj->querystr("name"),"王求仁"))
		{
			if(!strcmp(comm, "kill")||!strcmp(comm, "fight")||!strcmp(comm, "cast"))
			{
				CContainer * ma=present("ma");
				if(ma||!query("ok"))
				{
					tell_object(me, "马甲伸手一拦：要想动手，先过我这一关！");
					return 1;
				}
			}
		}
	}
	return CRoom::handle_action(comm, me, arg, target);
}


ROOM_END;
