//dy16_monster.h 地狱第16层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15
MONSTER_BEGIN(CNdy16_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",16);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"丁铃", "ding ling","女性",young_man4,28,},
		{"曹花", "cao hua","女性", young_man1,38,},
		{"兰心", "lan xin","女性", young_man3,18,},
		{"李飞", "li fei","女性", young_man3,32,},
		{"纯纯", "chun chun", "女性", young_man1,21,},
		{"杜月", "du yue", "女性",young_man1,37,},
		{"花花", "hua hua", "女性",young_man2,24,},
		{"王雅", "wang ya", "女性",young_man4,18,},
		{"梅子", "mei zi", "女性",young_man4,27,},
		{"阿雅", "a ya", "女性",young_man5,28,},
		{"黄君", "huang jun", "女性",young_man2,34,},
		{"蒋雨", "jiang yu", "女性",young_man6,24,},
		{"吕四娘", "lv si niang", "女性",young_man4,16,},
		{"蓝色", "lan shai", "女性",young_man1,16,},
		{"圆圆", "yuan yuan", "女性",young_man2,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 175+random(5));

	set("max_hp", 100000+random(1000));
	set("max_mp", 40000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 133709700+random(100000));
	set("max_exp",200000000);

	set("str", 45+random(5));
	set("con", 36+random(5));
	set("int", 37+random(5));
	set("dex", 44+random(5));

	set_skill("yanxing_dao", 700+random(10));
	set_skill("blade", 700+random(10));
	set_skill("jiuyin_zhua", 700+random(10));
	set_skill("claw", 700+random(10));
	set_skill("zhutian_bu", 700+random(10));
	set_skill("dodge", 700+random(10));
	set_skill("linji_zhuang", 700+random(10));
	set_skill("force", 700+random(10));

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 450+random(10));
	set("apply/damage", 480+random(10));

	create_family("峨嵋派", 4, "弟子");

	carry_object("caidao")->wield();

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("blade huanying", 1);
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