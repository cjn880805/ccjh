//dy4_monster.h 地狱第4层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy4_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"董成", "dong cheng","男性",young_woman8,28,},
		{"曹直", "cao zhi","男性", young_woman1,38,},
		{"董冥", "dong ming","男性", young_woman8,18,},
		{"孙娘", "sun niang","女性", young_man3,32,},
		{"董啄", "dong zhu", "男性", young_woman8,21,},
		{"公孙虎", "gong sun hu", "男性",young_woman1,37,},
		{"公孙远", "gong sun yuan", "男性",young_woman2,24,},
		{"公孙凤","gong sun feng", "女性",young_man4,18,},
		{"关雨", "guan yu", "男性",young_woman4,27,},
		{"公孙龙", "gong sun long", "男性",young_woman5,28,},
		{"公孙战", "gong sun zhan", "男性",young_woman2,34,},
		{"皇莆蛇", "huang pu she", "男性",young_woman6,24,},
		{"刘哀", "liu ai", "男性",young_woman4,16,},
		{"刘风", "liu feng", "男性",young_woman1,16,},
		{"刘云", "liu yun", "男性",young_woman2,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "鬼门关守护者");
	set("level", 95+random(5));

	set("max_hp", 19400+random(1000));
	set("max_mp", 6000+random(200));
	set("mp_factor", 90);

	set("combat_exp", 4665600+random(100000));
	set("max_exp",50000000);

	set("str", 47+random(5));
	set("con", 38+random(5));
	set("int", 39+random(5));
	set("dex", 45+random(5));

	set_skill("sun_finger", 316+random(10));
	set_skill("finger", 316+random(10));
	set_skill("tiannan_step", 316+random(10));
	set_skill("dodge", 316+random(10));
	set_skill("kurong_changong", 316+random(10));
	set_skill("force", 316+random(10));

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 190+random(10));
	set("apply/damage", 220+random(10));

	create_family("大理段家", 4, "弟子");
	set("chat_chance_combat", 5);

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("finger qiankun", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force reserver", 1);
		break;
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM