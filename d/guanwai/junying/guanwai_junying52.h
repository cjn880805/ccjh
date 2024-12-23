//junying52.h  右翼营帐2
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying52);

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
	
	add_door("右翼营帐1", "关外右翼营帐1", "关外右翼营帐2");
	add_door("右先锋营帐4", "关外右先锋营帐4", "关外右翼营帐2");
	add_door("右翼营帐4", "关外右翼营帐4", "关外右翼营帐2");

	set("long","右翼营帐正在观摩营中新配备的佛朗机火炮与火枪队射击表演。炮声隆隆，枪声阵阵，间歇还有如雷的掌声。" );

};

ROOM_END;
