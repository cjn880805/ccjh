//junying32.h  右先锋营帐2
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying32);

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
	
	add_door("右先锋营帐1", "关外右先锋营帐1", "关外右先锋营帐2");
	add_door("右先锋营帐4", "关外右先锋营帐4", "关外右先锋营帐2");

	set("long","此处乃右先锋营帐，帐下皆是劈山开路之精兵，喝水断桥的勇士。操练时旗摇遮天，鼓声动地。真是军容鼎盛。" );

};

ROOM_END;
