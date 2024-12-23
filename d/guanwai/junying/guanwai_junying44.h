//junying44.h  左翼营帐4
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying44);

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
	
	add_door("左翼营帐2", "关外左翼营帐2", "关外左翼营帐4");
	add_door("左翼营帐3", "关外左翼营帐3", "关外左翼营帐4");
	add_door("后军营帐1", "关外后军营帐1", "关外左翼营帐4");

	set("long","左翼士兵正在比赛骑术，骑手在场地上风驰电掣，上下翻腾，四周兵士叫好声一片。" );

};

ROOM_END;
