//dy1_monster.h 地狱第1层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy1_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",1);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"窦恶", "dou e","男性",young_woman8,28,},
		{"曹东道", "cao dong dao","男性", young_woman1,38,},
		{"成需", "cheng xu","男性", young_woman8,18,},
		{"春申君", "chun shen jun","男性", young_woman3,32,},
		{"管邪", "guang xie", "男性", young_woman8,21,},
		{"吉明", "ji ming", "男性",young_woman1,37,},
		{"黑胡", "hei hu", "男性",young_woman2,24,},
		{"黑脸神","hei lian shen", "男性",young_woman4,18,},
		{"连进", "lian jin", "男性",young_woman4,27,},
		{"李牧", "li mu", "男性",young_woman5,28,},
		{"僚毐", "liao du", "男性",young_woman2,34,},
		{"廉颇", "liao bo", "男性",young_woman6,24,},
		{"龙阴客", "long ying ke", "男性",young_woman4,16,},
		{"李斯", "li si", "男性",young_woman1,16,},
		{"吕不韦", "lv bu wei", "男性",young_woman2,31,},
	};
	
	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);
	
	set("per",random(21)+10);
	set("title", "迷宫守护者");
	set("level", 63+random(5));
	
	set("max_hp", 16200+random(1000));
	set("max_mp", 4000+random(200));
	set("mp_factor", 150);
	
	set("combat_exp", 1123900+random(100000));
	set("max_exp",12000000);
	
	set("str", 39+random(5));
	set("con", 29+random(5));
	set("int", 36+random(5));
	set("dex", 26+random(5));
	
	set_skill("zhanjiang_jue", 227+random(10));
	set_skill("club", 227+random(10));
	set_skill("changquan", 227+random(10));
	set_skill("cuff", 227+random(10));
	set_skill("guimei_shenfa", 227+random(10));
	set_skill("dodge", 227+random(10));
	set_skill("hunyuan_yiqi", 227+random(10));
	set_skill("force", 227+random(10));
	
	map_skill("club", "zhanjiang_jue");
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	
	prepare_skill("cuff", "changquan");
	
	set("apply/armor", 138+random(10));
	set("apply/damage", 168+random(10));
	
	carry_object("tieqiao")->wield();
	set("chat_chance_combat", 5);
	
}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("club killyou", 1);
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