//junying14.h  左先锋营帐4
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying14);

virtual void create()			
{
	set_name("左先锋营帐");

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
	
	add_door("左先锋营帐2", "关外左先锋营帐2", "关外左先锋营帐4");
	add_door("中军营帐1", "关外中军营帐1", "关外左先锋营帐4");
	add_door("左先锋营帐3", "关外左先锋营帐3", "关外左先锋营帐4");

	set("long","此处乃左先锋营帐，兵列列，旗行行，刀锋生出漫天杀气，枪尖闪耀万丈寒光。常人到此，腿不软也得打个哆嗦。" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"中军营帐1") )
	{
		if(!me->query_temp("zhang/冯力强_jion"))
		{
			return notify_fail("$HIR整个中军大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破，你不由的吸了一口冷气。");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
