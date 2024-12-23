//junying13.h  左先锋营帐3
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying13);

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
	
	add_door("左先锋营帐1", "关外左先锋营帐1", "关外左先锋营帐3");
	add_door("左翼营帐1", "关外左翼营帐1", "关外左先锋营帐3");
	add_door("左先锋营帐4", "关外左先锋营帐4", "关外左先锋营帐3");

	set("long","此处乃左先锋营帐，兵列列，旗行行，刀锋生出漫天杀气，枪尖闪耀万丈寒光。常人到此，腿不软也得打个哆嗦。" );

};

ROOM_END;
