//dy11_monster.h 地狱第11层怪物
//wuqing 2005-1-05

#define MAX_NPC_NUM 14

MONSTER_BEGIN(CNdy11_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",11);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"无色", "wu shai","男性",old_monk,80,},
		{"无花", "wu hua","男性", old_monk,78,},
		{"无碍", "wu ai","男性", old_monk,68,},
		{"妄动", "wang dong","男性", old_monk,82,},
		{"普光", "pu guang", "男性", young_monk,21,},
		{"空闻", "kong wen", "男性",old_monk,77,},
		{"火头陀", "huo tou tu", "男性",old_monk,64,},
		{"惠赐","hui ci", "男性",young_monk,18,},
		{"广元", "guang yuan", "男性",old_monk,67,},
		{"飞鸟", "fei niao", "男性",old_monk,58,},
		{"渡佛", "du fu", "男性",old_monk,94,},
		{"道明", "dao ming", "男性",young_monk,24,},
		{"道光", "dao guang", "男性",young_monk,16,},
		{"不舍", "bu she", "男性",young_monk,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 150+random(5));

	set("max_hp", 62000+random(1000));
	set("max_mp", 14000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 24234500+random(100000));
	set("max_exp",130000000);

	set("str", 69+random(5));
	set("con", 63+random(5));
	set("int", 65+random(5));
	set("dex", 73+random(5));
	
	set_skill("finger", 550+random(10));
	set_skill("force", 550+random(10));
	set_skill("whip", 550+random(10));
	set_skill("parry", 550+random(10));
	set_skill("dodge", 550+random(10));
	set_skill("unarmed", 550+random(10));
	set_skill("buddhism", 550+random(10));
	set_skill("literate", 550+random(10));
	set_skill("nianhua_zhi", 550+random(10));
	
	set_skill("hunyuan_yiqi", 550+random(10));
	set_skill("riyue_bian", 550+random(10));
	set_skill("shaolin_shenfa", 550+random(10));
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("whip",  "riyue_bian");
	map_skill("parry", "riyue_bian");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");

	prepare_skill("finger", "nianhua_zhi");
	
	set("apply/armor", 320+random(10));
	set("apply/damage", 350+random(10));

	create_family("少林派", 2, "弟子");

	carry_object("changbian")->wield();
	set("chat_chance_combat", 5);


}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("whip chan", 1);
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