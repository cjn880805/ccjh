//任务用标准NPC 可生成强度为玩家N倍的怪物。
//lanwood 2001-04-12

MIRROR_BEGIN(CNmonster_jieyu);

void create()
{
	set_name("妖怪", "monster");
	
	set("icon", young_man1);
	set("shen_type", -1);
	
	set("chat_chance_combat", 25);
	set("monster_lvl", 10);
};

void reward_killer(CChar * me)
{
	if(me->query_temp("fool/doing") == query("foolid"))
	{
		me->delete_temp("fool/doing");
		me->set_temp("fool/finish", 1);	
	}
}

MIRROR_END;

