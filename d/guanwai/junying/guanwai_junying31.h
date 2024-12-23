//junying31.h  右先锋营帐1
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying31);

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
	
	add_door("军营", "关外军营", "关外右先锋营帐1");
	add_door("右先锋营帐2", "关外右先锋营帐2", "关外右先锋营帐1");
	add_door("中军先锋营帐4", "关外中军先锋营帐4", "关外右先锋营帐1");
	add_door("右先锋营帐3", "关外右先锋营帐3", "关外右先锋营帐1");

	set("long","此处乃右先锋营帐，帐下皆是劈山开路之精兵，喝水断桥的勇士。操练时旗摇遮天，鼓声动地。真是军容鼎盛。" );

};

ROOM_END;
