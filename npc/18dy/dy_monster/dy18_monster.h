//dy18_monster.h 地狱第18层怪物
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy18_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",18);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[15] = {
		{"无相", "wu xiang","男性",old_monk,80,},
		{"无劫", "wu jie","男性", old_monk,78,},
		{"无尘", "wu cheng","男性", old_monk,68,},
		{"渡笑", "du xiao","男性", old_monk,82,},
		{"渡佛", "du fu", "男性", young_monk,21,},
		{"渡天", "du tian", "男性",old_monk,77,},
		{"渡铁", "du tie", "男性",old_monk,64,},
		{"抱风", "bao feng", "男性",young_monk,18,},
		{"抱花", "bao hua", "男性",old_monk,67,},
		{"抱雪", "bao xue", "男性",old_monk,58,},
		{"抱月", "bao yue", "男性",old_monk,94,},
		{"抱缺", "bao que", "男性",young_monk,24,},
		{"空见", "kong jian", "男性",young_monk,16,},
		{"空闻", "kong wen", "男性",young_monk,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 185+random(5));

	set("max_hp", 100000+random(1000));
	set("max_mp", 70000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 174234500+random(100000));
	set("max_exp",300000000);

	set("str", 99+random(5));
	set("con", 99+random(5));
	set("int", 99+random(5));
	set("dex", 99+random(5));
	
	set_skill("finger", 750+random(10));
	set_skill("force", 750+random(10));
	set_skill("whip", 750+random(10));
	set_skill("parry", 750+random(10));
	set_skill("dodge", 750+random(10));
	set_skill("unarmed", 750+random(10));
	set_skill("buddhism", 750+random(10));
	set_skill("literate", 750+random(10));
	set_skill("nianhua_zhi", 750+random(10));
	
	set_skill("hunyuan_yiqi", 750+random(10));
	set_skill("riyue_bian", 750+random(10));
	set_skill("shaolin_shenfa", 750+random(10));
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("whip",  "riyue_bian");
	map_skill("parry", "riyue_bian");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");

	prepare_skill("finger", "nianhua_zhi");
	
	set("apply/armor", 500+random(10));
	set("apply/damage", 550+random(10));

	create_family("少林", 2, "弟子");

	carry_object("changbian")->wield();

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