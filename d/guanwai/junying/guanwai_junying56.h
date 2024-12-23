//junying56.h  中军先锋营帐56
//秦波 2002、12、9

ROOM_BEGIN(CRGuanWai_junying56);

virtual void create()			
{
	set_name("中军先锋营帐");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	if(random(2))
	{
		add_npc("pub_songbing1");
		add_npc("pub_songjiang1");
	}

	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("关外中军先锋营帐", "关外中军先锋营帐41", "关外中军先锋营帐56");
	add_door("关外中军先锋营帐", "关外中军先锋营帐42", "关外中军先锋营帐56");
	add_door("关外中军先锋营帐", "关外中军先锋营帐55", "关外中军先锋营帐56");
	add_door("关外中军先锋营帐", "关外中军先锋营帐57", "关外中军先锋营帐56");
	add_door("关外中军大寨", "关外中军大寨65", "关外中军先锋营帐56");
	add_door("关外中军大寨", "关外中军大寨66", "关外中军先锋营帐56");


	set("long","此处乃中军先锋营帐，领兵者系蛮族勇士先锋官呼那两斤土司，所率部下皆是同族壮男，只见军内正在操练的士兵人人面涂赤血，赤裸上身，左手纹青龙，右手纹白虎，老牛在腰间，龙头在胸口。人挡杀人，佛挡杀佛，煞是可怕。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
