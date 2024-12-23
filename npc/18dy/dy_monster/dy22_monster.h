//dy22_monster.h 地狱第22层怪物
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy22_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",22);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[15] = {
		{"风清", "feng qing","男性",young_man4,28,},
		{"铁战甲", "tie zhan jia","男性", young_man1,38,},
		{"文藻", "wen zao","男性", young_man2,18,},
		{"妙善", "miao shan","女性", young_woman3,32,},
		{"兰西", "lan xi", "男性", young_man5,21,},
		{"向公", "xiang gong", "男性",young_man6,37,},
		{"项庄", "xiang zhuang", "男性",young_man2,24,},
		{"王西", "wang xi", "女性",young_woman11,18,},
		{"莫悲", "ma long", "男性",young_man4,27,},
		{"金不为", "jin bu wei", "男性",young_man5,28,},
		{"石不怒", "shi bu nu", "男性",young_man2,34,},
		{"杨不曲", "yang bu qu", "男性",young_man6,24,},
		{"张不智", "zhang bu zhi", "男性",young_man4,16,},
		{"方玉", "fang yu", "男性",young_man1,16,},
		{"紫风", "zi feng", "男性",young_man2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 210+random(5));

	set("max_hp", 131000+random(1000));
	set("max_mp", 67000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 286065600+random(100000));
	set("max_exp",600000000);

	set("str", 99+random(5));
	set("con", 99+random(5));
	set("int", 99+random(5));
	set("dex", 99+random(5));

	set_skill("force", 850+random(10));
	set_skill("taiji_shengong", 850+random(10));
	set_skill("dodge", 850+random(10));
	set_skill("tiyunzong", 850+random(10));
	set_skill("unarmed", 850+random(10));
	set_skill("taiji_quan", 850+random(10));
	set_skill("parry", 850+random(10));
	set_skill("sword", 850+random(10));
	set_skill("taiji_jian", 850+random(10));
	set_skill("blade", 850+random(10));
	set_skill("taiji_dao", 850+random(10));
	set_skill("taoism", 850+random(10));
	set_skill("literate", 850+random(10));
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");
	
	set("apply/armor", 630+random(10));
	set("apply/damage", 660+random(10));
	
	create_family("武当派", 2, "弟子");
	
    set("class", "taoist");

	carry_object("changjian")->wield();
	
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}
	return 0;
}

MONSTER_END;