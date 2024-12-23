//dy7_monster.h 地狱第7层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy7_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",7);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"直磨", "zhi mao","男性",young_man4,22,},
		{"悬浮", "xuan fu","男性",young_man1,34,},
		{"熊巨", "xiong ju","男性",young_man2,31,},
		{"谢云", "xie yun","男性",young_man3,34,},
		{"谢问", "xie wen","男性",young_man5,28,},
		{"谢石", "xie shi","男性",young_man3,41,},
		{"谢绝", "xie jun","男性",young_man6,22,},
		{"小蝶", "xiao die","女性",young_woman1,36,},
		{"无心", "wu xin","女性",young_woman6,41,},
		{"魏拨", "wei bo", "男性",young_man1,24,},
		{"随云", "shui yun","女性",young_woman3,31,},
		{"龙依", "long yi","女性",young_woman2,39,},
		{"浪子", "lang zi","男性",young_man6,28,},
		{"李少杰", "li shao jie","男性",young_man5,29,},
		{"客横声", "ke heng sheng", "男性",young_man1,22,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 120+random(5));

	set("max_hp", 30000+random(1000));
	set("max_mp", 6000+random(200));
	set("mp_factor", 120);

	set("combat_exp", 9733600+random(100000));
	set("max_exp",90000000);

	set("str", 44+random(5));
	set("con", 46+random(5));
	set("int", 40+random(5));
	set("dex", 48+random(5));

	set_skill("huashan_sword", 420+random(10));
	set_skill("sword", 420+random(10));
	set_skill("huashan_ken", 420+random(10));
	set_skill("cuff", 420+random(10));
	set_skill("huashan_shenfa", 420+random(10));
	set_skill("dodge", 420+random(10));
	set_skill("zixia_shengong", 420+random(10));
	set_skill("force", 420+random(10));

	map_skill("sword", "huashan_sword");
	map_skill("cuff", "huashan_ken");
	map_skill("dodge", "huashan_shenfa");
	map_skill("force", "zixia_shengong");

	prepare_skill("cuff", "huashan_ken");

	set("apply/armor", 244+random(10));
	set("apply/damage", 274+random(10));
	
	create_family("华山派", 2, "弟子");

	carry_object("mujian")->wield();
	
	set("chat_chance_combat", 5);
}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword jianzhang", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM