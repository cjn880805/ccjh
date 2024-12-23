//junying33.h  右先锋营帐3
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying33);

virtual void create()			
{
	set_name("右先锋营帐");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	if(random(2))
	{
		add_npc("pub_songbing1");
		add_npc("pub_songjiang1");
	}
	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("右先锋营帐1", "关外右先锋营帐1", "关外右先锋营帐3");
	add_door("中军营帐3", "关外中军营帐3", "关外右先锋营帐3");
	add_door("右先锋营帐4", "关外右先锋营帐4", "关外右先锋营帐3");

	set("long","此处乃右先锋营帐，帐下皆是劈山开路之精兵，喝水断桥的勇士。操练时旗摇遮天，鼓声动地。真是军容鼎盛。" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"中军营帐3") )
	{
		if(!me->query_temp("zhang/冯力强_jion"))
		{
			return notify_fail("$HIR整个中军大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破，你不由的吸了一口冷气。");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
