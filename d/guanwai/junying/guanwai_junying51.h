//junying51.h  右翼营帐1
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying51);

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
	
	add_door("右翼营帐2", "关外右翼营帐2", "关外右翼营帐1");
	add_door("右翼营帐3", "关外右翼营帐3", "关外右翼营帐1");

	set("long","右翼营帐正在观摩营中新配备的佛朗机火炮与火枪队射击表演。炮声隆隆，枪声阵阵，间歇还有如雷的掌声。" );

};

ROOM_END;
