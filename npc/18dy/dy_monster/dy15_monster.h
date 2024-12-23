//dy15_monster.h 地狱第15层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy15_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",15);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"飘雪", "piao xue","男性",young_woman7,23,},
		{"左权", "zuo quan","男性", young_woman4,21,},
		{"钱麻子", "qian ma zi","男性", young_woman3,18,},
		{"罗东", "luo dong","男性", young_woman2,22,},
		{"李近", "li jin", "男性", young_woman1,15,},
		{"茅度", "mao du", "男性",young_woman5,17,},
		{"温菱", "wen ling", "男性",young_woman6,15,},
		{"周同", "zhou tong", "男性",young_woman2,18,},
		{"林南天", "ling nan tian", "男性",young_woman4,17,},
		{"杜中", "du zhong", "男性",young_woman1,17,},
		{"黄何", "huang he", "男性",young_woman3,24,},
		{"冷月", "leng yue", "男性",young_woman5,22,},
		{"吴明", "wu ming", "男性",young_woman2,16,},
		{"张军", "zhang jun", "男性",young_woman3,16,},
		{"李光", "li guang", "男性",young_woman7,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 170+random(5));

	set("max_hp", 95000+random(1000));
	set("max_mp", 37000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 100234500+random(100000));
	set("max_exp",170000000);

	set("str", 90+random(5));
	set("con", 83+random(5));
	set("int", 81+random(5));
	set("dex", 84+random(5));
	
	set_skill("force", 670+random(10));                      
	set_skill("dodge", 670+random(10));
	set_skill("unarmed", 670+random(10));
	set_skill("strike", 670+random(10));
	set_skill("parry", 670+random(10));
	set_skill("staff", 670+random(10));
	set_skill("sword", 670+random(10));
	set_skill("literate", 670+random(10));
	
	set_skill("shenlong_xinfa", 670+random(10));
	set_skill("yixingbu", 670+random(10));
	set_skill("shenlong_bashi", 670+random(10));
	set_skill("huagu_mianzhang", 670+random(10));
	set_skill("shedao_qigong", 670+random(10));
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
	map_skill("sword", "shedao_qigong");

	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");
	
	set("apply/armor", 430+random(10));
	set("apply/damage", 450+random(10));

	create_family("神龙教", 2, "弟子");

	carry_object("changjian")->wield();

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("parry chang3", 1);
		break;
	case 1:
		perform_action("unarmed yingxiong", 1);
		break;
	case 2:
		perform_action("strick hua", 1);
		break;
	}
	return 0;
}

MONSTER_END;
#undef MAX_NPC_NUM