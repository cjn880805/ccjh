//junying42.h  左翼营帐2
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying42);

virtual void create()			
{
	set_name("左翼营帐");

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
	
	add_door("左翼营帐1", "关外左翼营帐1", "关外左翼营帐2");
	add_door("中军营帐4", "关外中军营帐4", "关外左翼营帐2");
	add_door("左翼营帐4", "关外左翼营帐4", "关外左翼营帐2");

	set("long","左翼士兵正在比赛骑术，骑手在场地上风驰电掣，上下翻腾，四周兵士叫好声一片。" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"中军营帐4") )
	{
		if(!me->query_temp("zhang/冯力强_jion"))
		{
			return notify_fail("$HIR整个中军大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破，你不由的吸了一口冷气。");
		}
	}
	return CRoom::valid_leave(me, dir);
}


ROOM_END;
