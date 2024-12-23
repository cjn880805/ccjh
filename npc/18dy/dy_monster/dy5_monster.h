//dy5_monster.h 地狱第5层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy5_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",5);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"财使", "cai shi","男性",young_woman8,28,},
		{"色使", "shai shi","男性", young_woman1,38,},
		{"气使", "qi shi","男性", young_woman8,18,},
		{"凤素素", "feng su su","女性", young_man3,32,},
		{"酒使", "jiu shi", "男性", young_woman8,21,},
		{"雷", "lei", "男性",young_woman1,37,},
		{"风", "feng", "男性",young_woman2,24,},
		{"云", "yun", "女性",young_man4,18,},
		{"雨", "yu", "男性",young_woman4,27,},
		{"楚丁", "chu ding", "男性",young_woman5,28,},
		{"欧阳血", "ou yang xue", "男性",young_woman2,34,},
		{"伍铝", "wu lv", "男性",young_woman6,24,},
		{"西西", "xi xi", "男性",young_woman4,16,},
		{"中使", "zhong shi", "男性",young_woman1,16,},
		{"东东", "dong dong", "男性",young_woman2,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 100+random(5));

	set("max_hp", 21000+random(1000));
	set("max_mp", 6500+random(200));
	set("mp_factor", 90);

	set("combat_exp", 5665600+random(100000));
	set("max_exp",70000000);

	set("str", 49+random(5));
	set("con", 40+random(5));
	set("int", 41+random(5));
	set("dex", 47+random(5));

	set_skill("dagou_bang", 353+random(10));
	set_skill("staff", 353+random(10));
	set_skill("xianglong_zhang", 353+random(10));
	set_skill("strike", 353+random(10));
	set_skill("xiaoyaoyou", 353+random(10));
	set_skill("dodge", 353+random(10));
	set_skill("huntian_qigong", 353+random(10));
	set_skill("force", 353+random(10));

	map_skill("staff", "dagou_bang");
	map_skill("strike", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian_qigong");

	prepare_skill("strike", "xianglong_zhang");

	set("apply/armor", 204+random(10));
	set("apply/damage", 234+random(10));

	create_family("丐帮", 3, "弟子");

	carry_object("shuzhi2")->wield();
	set("chat_chance_combat", 5);

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
		perform_action("force shengang", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM