//junying23.h  中军先锋营帐3
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying23);

virtual void create()			
{
	set_name("中军先锋营帐");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	add_npc("bj_hunaliangjin");
	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("中军先锋营帐1", "关外中军先锋营帐1", "关外中军先锋营帐3");
	add_door("中军营帐2", "关外中军营帐2", "关外中军先锋营帐3");
	add_door("中军先锋营帐4", "关外中军先锋营帐4", "关外中军先锋营帐3");

	set("long","此处乃中军先锋营帐，领兵者系蛮族勇士先锋官呼那两斤土司，所率部下皆是同族壮男，只见军内正在操练的士兵人人面涂赤血，赤裸上身，左手纹青龙，右手纹白虎，老牛在腰间，龙头在胸口。人挡杀人，佛挡杀佛，煞是可怕。" );

};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"中军营帐2") )
	{
		if(!me->query_temp("zhang/冯力强_jion"))
		{
			return notify_fail("$HIR整个中军大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破，你不由的吸了一口冷气。");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
