//dy14_monster.h 地狱第14层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy14_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",14);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"许雪", "xu xue","男性",young_woman7,23,},
		{"左令", "zuo ling","男性", young_woman4,21,},
		{"钱三", "qian san","男性", young_woman3,18,},
		{"罗成", "luo cheng","男性", young_woman2,22,},
		{"宋近", "song jin", "男性", young_woman1,15,},
		{"茅塞", "mao sai", "男性",young_woman5,17,},
		{"温文", "wen wen", "男性",young_woman6,15,},
		{"周达", "zhou da", "男性",young_woman2,18,},
		{"上官南", "shang guan nan", "男性",young_woman4,17,},
		{"杜林", "du lin", "男性",young_woman1,17,},
		{"黄海", "huang hai", "男性",young_woman3,24,},
		{"冷战", "leng zhan", "男性",young_woman5,22,},
		{"吴德", "wu de", "男性",young_woman2,16,},
		{"张明", "zhang ming", "男性",young_woman3,16,},
		{"李胜", "li sheng", "男性",young_woman7,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 165+random(5));

	set("max_hp", 75000+random(1000));
	set("max_mp", 27000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 70234500+random(100000));
	set("max_exp",160000000);

	set("str", 80+random(5));
	set("con", 73+random(5));
	set("int", 71+random(5));
	set("dex", 79+random(5));
	
	set_skill("force", 640+random(10));                      
	set_skill("dodge", 640+random(10));
	set_skill("unarmed", 640+random(10));
	set_skill("strike", 640+random(10));
	set_skill("parry", 640+random(10));
	set_skill("staff", 640+random(10));
	set_skill("sword", 640+random(10));
	set_skill("literate", 640+random(10));
	
	set_skill("shenlong_xinfa", 640+random(10));
	set_skill("yixingbu", 640+random(10));
	set_skill("shenlong_bashi", 640+random(10));
	set_skill("huagu_mianzhang", 640+random(10));
	set_skill("shedao_qigong", 640+random(10));
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
	map_skill("sword", "shedao_qigong");

	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");
	
	set("apply/armor", 400+random(10));
	set("apply/damage", 430+random(10));

	create_family("神龙教", 2, "弟子");

	carry_object("changjian")->wield();
	set("chat_chance_combat", 5);

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword chang3", 1);
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