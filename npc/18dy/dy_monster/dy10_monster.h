//dy10_monster.h 地狱第10层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy10_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",10);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"云清", "yun qing","女性",young_woman1,18,},
		{"夜色", "ye shai","女性",young_woman2,21,},
		{"叶铃", "ye ling","女性",young_woman3,23,},
		{"香儿", "xiang er","女性",young_woman6,18,},
		{"温碧", "wen bi","女性",young_woman7,18,},
		{"青霜", "qing shuang","女性",young_woman8,18,},
		{"李媚", "li mei", "女性",young_woman9,18,},
		{"兰香", "lan xiang", "女性",young_woman11,18,},
		{"花语", "hua yu","女性",young_woman12,18,},
		{"红颜", "hong yan", "女性",young_woman1,18,},
		{"白莲", "bai lian","女性",young_woman2,18,},
		{"白蝴蝶", "bai hudie","女性",young_woman3,18,},
		{"雁非非", "yan fei fei","女性",young_woman4,18,},
		{"虚月叶", "xu yue ye","女性",young_woman5,18,},
		{"冷冰儿", "leng bing er", "女性",young_woman10,18,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 145+random(5));

	set("max_hp", 60000+random(1000));
	set("max_mp", 12000+random(200));
	set("mp_factor", 140);

	set("combat_exp", 21234500+random(100000));
	set("max_exp",120000000);

	set("str", 67+random(5));
	set("con", 60+random(5));
	set("int", 61+random(5));
	set("dex", 71+random(5));
	
	set_skill("force", 520+random(10));
	set_skill("unarmed", 520+random(10));
	set_skill("dodge", 520+random(10));
	set_skill("parry", 520+random(10));
	set_skill("hand",520+random(10));
	set_skill("strike", 520+random(10));
	set_skill("sword",520+random(10));
	
	set_skill("zhemei_shou",520+random(10));
	set_skill("liuyang_zhang",520+random(10));
	set_skill("tianyu_qijian",520+random(10));
	set_skill("yueying_wubu",520+random(10));
	set_skill("bahuang_gong", 520+random(10));
	
	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword","tianyu_qijian");
	
	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand", "zhemei_shou");
	
	set("apply/armor", 300+random(10));
	set("apply/damage", 330+random(10));

	create_family("灵鹫", 2, "弟子");

	carry_object("changjian")->wield();
	set("chat_chance_combat", 5);

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword san", 1);
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