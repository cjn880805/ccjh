//monster2.h
//code by Teapot
//2001-2-3

//2级怪物

MONSTER_BEGIN(CNMonster_2);

virtual void create()
{
	static struct{
		char name[20], id[20];		//怪物名称
		int	 icon;			//图标
		int  chance;		//出现几率
	}mon[20] = {
		{"登徒子", "deng tuzi", young_man2, 0,},
		{"黑の梦", "hei meng", young_man3, 8,},
		{"幽明使者",	"youming shizhe", cateran, 16,},
		{"赤焰魔灵", "ciyan moling", banditi, 24,},
		{"神秘客",	"shenmi ke", cateran, 32,},
		{"死凛僵尸",	"silin jiangsi", cateran, 40,},
		{"东洋流氓", "dongyang liumang", young_man4, 48,},
		{"倭人",	"e ren", cateran, 56,},
		{"倭寇", "e kou", banditi, 61,},
		{"倭寇头目", "ekou toumu", banditi, 66,},
		{"倭寇大头目", "ekou datoumu", young_man5, 71,},
		{"东洋武士", "dongyang wushi", banditi, 76,},
		{"东洋武士首领", "wushi shouling", young_man1, 81,},
		{"东洋忍者", "renzhe", banditi, 84,},
		{"一晚十个郎",	"yi wan shi ge lang", cateran, 88,},
		{"黄小雪", "huang xiao xue", taoist_with_sword, 92,},
		{"夜の杀", "ye sha", taoist_with_sword, 94,},
		{"严小其", "yan xiao qi", old_monk, 96,},
		{"吴小辉",	"wu xiao hui", old_monk, 98,},
		{"陈小光", "chen xiao guang", taoist_with_sword, 99,},
		};

	int lvl = query("index");
	
	if(lvl < 1 || lvl > 20)
	{
		lvl = random(100);

		for(int i=20; i > 0; i--)
		{
			if(mon[i - 1].chance <= lvl)
			{
				lvl = i;
				break;
			}
		}
	}

	set("index", lvl);

	lvl = lvl - 1;

	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("attitude", "aggressive");

	set("age", 40 + lvl);
	set("gender", "男性");

	set("monster_lvl", 10 + lvl);

	set("max_hp", 3000 + lvl * 500);
	set("max_mp", 1000 + lvl * 150);
	set("mp_factor", 30 + lvl * 4);
	set("combat_exp", 200000 + lvl * 10000);

    set_skill("force",   80 + lvl * 3);
	set_skill("unarmed", 80 + lvl * 3);
	set_skill("sword",   80 + lvl * 3);
	set_skill("changquan",  80 + lvl * 3);
	set_skill("magic", 80 + lvl * 3);
	set_skill("jinshe_jian", 80 + lvl * 3);
	set_skill("dodge", 80 + lvl * 3);
	set_skill("parry", 80 + lvl * 3);
	set_skill("xiaoyaoyou", 80 + lvl * 3);

	set("nkgain", 30 + lvl * 5);
		
	map_skill("unarmed", "changquan");
	map_skill("force", "magic");
	map_skill("sword", "jinshe_jian");
	map_skill("parry", "jinshe_jian");
	map_skill("dodge", "xiaoyaoyou");

	set("chat_chance", 5);
	set("chat_chance_combat", 10);

	set("present_msg", "一道黑烟掠过，$n不知道从哪里冒了出来，挡住$N的去路。");

	carry_object("sword_1")->wield();	
};

void eat_yao(char * yaopin)
{
	char msg[40];
	CContainer * yao = load_item(yaopin);
	yao->move(this);
	command(snprintf(msg, 40, "use %ld", yao->object_id()));
}

virtual char * chat_msg_combat()
{
	if(query("hp") /2 < query("max_hp") / 3)
	{
		if(random(2) == 0)
		{
			if(perform_action("force powerheal", 0))
				return 0;
		}

		if(random(3) == 0)
		{
			eat_yao("yaopin_1");
			return 0;
		}

		if(random(3) == 0)
		{
			eat_yao("yaopin_2");
			return 0;
		}		
	}

	if(random(8) == 0)
	{
		perform_action("force oildown", 1);
		return 0;
	}

	if(random(8) == 0)
		perform_action("force meteor", 1);

	return 0;
}

virtual int accept_fight(CChar *me)
{
	char msg[20];

	say("哈哈哈哈哈哈啊哈！");
	command(snprintf(msg, 20, "kill %ld", me->object_id()));
	return 0;
}


MONSTER_END;
