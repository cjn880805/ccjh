//junying21.h  中军先锋营帐1
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying21);

virtual void create()			
{
	set_name("中军先锋营帐");

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
	
	add_door("军营", "关外军营", "关外中军先锋营帐1");
	add_door("左先锋营帐2", "关外左先锋营帐2", "关外中军先锋营帐1");
	add_door("中军先锋营帐2", "关外中军先锋营帐2", "关外中军先锋营帐1");
	add_door("中军先锋营帐3", "关外中军先锋营帐3", "关外中军先锋营帐1");

	set("long","此处乃中军先锋营帐，领兵者系蛮族勇士先锋官呼那两斤土司，所率部下皆是同族壮男，只见军内正在操练的士兵人人面涂赤血，赤裸上身，左手纹青龙，右手纹白虎，老牛在腰间，龙头在胸口。人挡杀人，佛挡杀佛，煞是可怕。" );

};

ROOM_END;
