//dy8_monster.h 地狱第8层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy8_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",8);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"颜盈", "yany ing","女性",young_woman2,22,},
		{"卫天鹰", "wei tian ying","男性",young_man1,34,},
		{"宋钟", "song zhong","男性",young_man2,31,},
		{"欧阳复", "ou yang fu","男性",young_man3,34,},
		{"南霸天", "nan ba tian","男性",young_man5,28,},
		{"刘三变", "liu san bian","男性",young_man3,41,},
		{"柳含烟", "liu han yan", "女性",young_woman1,22,},
		{"李怀", "li huai", "男性",young_man6,36,},
		{"李寒", "li han","男性",young_man2,41,},
		{"冷玉", "leng yu", "男性",young_man1,24,},
		{"剑十三", "jian shi san","男性",young_man3,31,},
		{"蒋武", "jiang wu","男性",young_man4,39,},
		{"鬼虎", "gui hu","男性",young_man5,29,},
		{"大洛", "da luo","男性",young_man6,28,},
		{"白胜", "bai sheng", "男性",young_man1,22,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 130+random(5));

	set("max_hp", 40000+random(1000));
	set("max_mp", 8000+random(200));
	set("mp_factor", 130);

	set("combat_exp", 13234500+random(100000));
	set("max_exp",100000000);


	set("str", 46+random(5));
	set("con", 48+random(5));
	set("int", 42+random(5));
	set("dex", 50+random(5));

	set_skill("force", 450+random(10));
	set_skill("unarmed", 450+random(10));
	set_skill("dodge", 450+random(10));
	set_skill("parry", 450+random(10));
	set_skill("hand",450+random(10));
	set_skill("staff", 450+random(10));
	set_skill("hamagong", 450+random(10));
	set_skill("chanchu_bufa", 450+random(10));
	set_skill("shexing_diaoshou", 450+random(10));
	set_skill("lingshe_zhangfa", 450+random(10));
	set_skill("xunshou_shu",450+random(10));

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	set("apply/armor", 260+random(10));
	set("apply/damage", 290+random(10));
	
	create_family("白驼山派", 2, "弟子");
	
	carry_object("shezhang")->wield();
	set("chat_chance_combat", 5);

}
char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("staff pili", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	case 3:
		perform_action("unarmed wugu", 0);
		break;
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM