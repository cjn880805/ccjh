//dy21_monster.h 地狱第21层怪物
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy21_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",21);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[15] = {
		{"苏三", "sun san","男性",young_man1,28,},
		{"聋丐", "long gai","男性", young_man2,38,},
		{"哑丐", "ya gai","男性", young_man3,18,},
		{"王大娘", "wang da niang","女性", young_woman3,32,},
		{"流书", "liu shu", "男性", young_man4,21,},
		{"惊雷", "jing lei", "男性",young_man5,37,},
		{"骤风", "zhou feng", "男性",young_man6,24,},
		{"流云", "liu yun", "女性",young_woman4,18,},
		{"薄雨", "bao yu", "男性",young_man4,27,},
		{"甲士", "jia shi", "男性",young_man5,28,},
		{"忘却", "wang que", "男性",young_man2,34,},
		{"伍穷", "wu qio", "男性",young_man6,24,},
		{"幻影", "huan ying", "男性",young_man4,16,},
		{"神行", "shen xing", "男性",young_man1,16,},
		{"向东", "xiang dong", "男性",young_man2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 200+random(5));

	set("max_hp", 121000+random(1000));
	set("max_mp", 11500+random(200));
	set("mp_factor", 90);

	set("combat_exp", 256656000+random(100000));
	set("max_exp",500000000);

	set("str", 49+random(5));
	set("con", 40+random(5));
	set("int", 41+random(5));
	set("dex", 47+random(5));

	set_skill("dagou_bang", 830+random(10));
	set_skill("staff", 830+random(10));
	set_skill("xianglong_zhang", 830+random(10));
	set_skill("strike", 830+random(10));
	set_skill("xiaoyaoyou", 830+random(10));
	set_skill("dodge", 830+random(10));
	set_skill("huntian_qigong", 830+random(10));
	set_skill("force", 830+random(10));

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 600+random(10));
	set("apply/damage", 630+random(10));

	create_family("丐帮", 3, "弟子");

	carry_object("shuzhi2")->wield();

}

char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("staff zhuang", 1);
		break;
	case 1:
		perform_action("force poweruop", 0);
		break;
	case 2:
		perform_action("force shengang", 0);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

MONSTER_END;