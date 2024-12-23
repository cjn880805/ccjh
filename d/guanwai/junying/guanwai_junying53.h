//junying53.h  右翼营帐3
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying53);

virtual void create()			
{
	set_name("右翼营帐");

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
	
	add_door("右翼营帐1", "关外右翼营帐1", "关外右翼营帐3");
	add_door("中军营帐5", "关外中军营帐5", "关外右翼营帐3");
	add_door("右翼营帐4", "关外右翼营帐4", "关外右翼营帐3");

	set("long","右翼营帐正在观摩营中新配备的佛朗机火炮与火枪队射击表演。炮声隆隆，枪声阵阵，间歇还有如雷的掌声。" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"中军营帐5") )
	{
		if(!me->query_temp("zhang/冯力强_jion"))
		{
			return notify_fail("$HIR整个中军大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破，你不由的吸了一口冷气。");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
