//dy20_monster.h 地狱第20层怪物
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy20_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",20);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[15] = {
		{"东一剑", "dong yi jian","男性",young_man3,28,},
		{"西一剑", "xi yi jian","男性", young_man1,38,},
		{"残金", "can jin","男性", young_man2,18,},
		{"断玉", "dua yu","女性", young_woman3,32,},
		{"赵泪", "zhao lei", "男性", young_man5,21,},
		{"田虎", "tian hu", "男性",young_man6,37,},
		{"关远", "guan yuan", "男性",young_man2,24,},
		{"陈凤","chen feng", "女性",young_woman4,18,},
		{"关雨", "guan yu", "男性",young_man4,27,},
		{"田龙", "tian long", "男性",young_man5,28,},
		{"左战", "zuo zhan", "男性",young_man2,34,},
		{"皇莆高", "huang pu gao", "男性",young_woman6,24,},
		{"悲哀", "bei ai", "男性",young_man4,16,},
		{"沉风", "chen feng", "男性",young_man1,16,},
		{"惊云", "jing yun", "男性",young_man2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 195+random(5));

	set("max_hp", 109000+random(1000));
	set("max_mp", 9000+random(200));
	set("mp_factor", 90);

	set("combat_exp", 246650600+random(100000));
	set("max_exp",400000000);

	set("str", 99+random(5));
	set("con", 99+random(5));
	set("int", 99+random(5));
	set("dex", 95+random(5));

	set_skill("sun_finger", 800+random(10));
	set_skill("finger", 800+random(10));
	set_skill("tiannan_step", 800+random(10));
	set_skill("dodge", 800+random(10));
	set_skill("kurong_changong", 800+random(10));
	set_skill("force", 800+random(10));

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 560+random(10));
	set("apply/damage", 600+random(10));

	create_family("大理段家", 4, "弟子");
	

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