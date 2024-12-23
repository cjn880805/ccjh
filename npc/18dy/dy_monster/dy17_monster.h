//dy17_monster.h 地狱第17层怪物
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy17_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",17);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[15] = {
		{"王东", "wang dong","男性",young_woman8,28,},
		{"铁中堂", "tie zhong tang","男性", young_woman1,38,},
		{"朱藻", "zhu zao","男性", young_woman8,18,},
		{"凤妙", "feng miao","女性", young_man3,32,},
		{"绝天", "jun tian", "男性", young_woman8,21,},
		{"灭地", "mie di", "男性",young_woman1,37,},
		{"银瓶", "ying ping", "男性",young_woman2,24,},
		{"铁奇", "tie qi", "女性",young_man4,18,},
		{"马龙", "ma long", "男性",young_woman4,27,},
		{"楚元", "chu yuan", "男性",young_woman5,28,},
		{"卫悲血", "wei bei xue", "男性",young_woman2,34,},
		{"伍西", "wu xi", "男性",young_woman6,24,},
		{"何东", "he dong", "男性",young_woman4,16,},
		{"中州", "zhong zhou", "男性",young_woman1,16,},
		{"白狼", "bai lang", "男性",young_woman2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 180+random(5));

	set("max_hp", 121000+random(1000));
	set("max_mp", 65000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 156065600+random(100000));
	set("max_exp",250000000);

	set("str", 99+random(5));
	set("con", 90+random(5));
	set("int", 91+random(5));
	set("dex", 97+random(5));

	set_skill("force", 730+random(10));
	set_skill("taiji_shengong", 730+random(10));
	set_skill("dodge", 730+random(10));
	set_skill("tiyunzong", 730+random(10));
	set_skill("unarmed", 730+random(10));
	set_skill("taiji_quan", 730+random(10));
	set_skill("parry", 730+random(10));
	set_skill("sword", 730+random(10));
	set_skill("taiji_jian", 730+random(10));
	set_skill("blade", 730+random(10));
	set_skill("taiji_dao", 730+random(10));
	set_skill("taoism", 730+random(10));
	set_skill("literate", 730+random(10));
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");
	
	set("apply/armor", 480+random(10));
	set("apply/damage", 510+random(10));
	
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