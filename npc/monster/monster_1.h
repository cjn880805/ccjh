//monster1.h
//code by lanwood
//2001-2-3

//1������

MONSTER_BEGIN(CNMonster_1);

virtual void create()
{
	static struct{
		char name[20], id[20];		//��������
		int	 icon;			//ͼ��
		int  chance;		//���ּ���
	}mon[20] = {
		{"ɽҰ���", "chun fu", young_man2, 0,},
		{"С��å", "liu mang", young_man3, 8,},
		{"С��",	"xiao zei", cateran, 16,},
		{"С����", "tu fei", banditi, 24,},
		{"ɽ��",	"shan zei", cateran, 32,},
		{"��Ʀ",	"di pi", cateran, 40,},
		{"��å", "liu mang", young_man4, 48,},
		{"���",	"e gun", cateran, 56,},
		{"����", "tu fei", banditi, 61,},
		{"СͷĿ", "tou mo", banditi, 66,},
		{"����", "you min", young_man5, 71,},
		{"���", "e ba", banditi, 76,},
		{"����", "diao min", young_man1, 81,},
		{"��ͽ", "fei tu", banditi, 84,},
		{"��ͽ",	"bao tu", cateran, 88,},
		{"����", "yao dao", taoist_with_sword, 92,},
		{"����", "yao xian", taoist_with_sword, 94,},
		{"������", "hua heshang", old_monk, 96,},
		{"�������",	"jiurou heshang", old_monk, 98,},
		{"���ʿ", "gui daoshi", taoist_with_sword, 99,},
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

	set("age", 20 + lvl);
	set("gender", "����");

	set("monster_lvl", lvl + 1);
	
	set("max_hp", 3000 + lvl * 500);
	set("eff_hp", 3000 + lvl * 500);
	set("hp", 3000 + lvl * 500);

	set("max_mp", 1000 + lvl * 100);
	set("mp", 1000 + lvl * 100);

	set("mp_factor", 30 + lvl * 3);
	set("combat_exp", 100000 + lvl * 10000);

    set_skill("force",   50 + lvl * 3);
	set_skill("unarmed", 50 + lvl * 3);
	set_skill("sword",   50 + lvl * 3);
	set_skill("changquan",   50 + lvl * 3);
	set_skill("magic", 50 + lvl * 3);
	set_skill("taishan_sword", 50 + lvl * 3);
	set_skill("dodge", 50 + lvl * 3);
	set_skill("xiaoyaoyou", 50 + lvl * 3);
	set_skill("parry", 50 + lvl * 3);

	set("nkgain", 20 + lvl * 5);
		
	map_skill("unarmed", "changquan");
	map_skill("force", "magic");
	map_skill("sword", "taishan_sword");
	map_skill("parry", "taishan_sword");
	map_skill("dodge", "xiaoyaoyou");

	set("chat_chance", 5);
	set("chat_chance_combat", 10);

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
	if(query("hp") < query("max_hp") / 3)
	{
		if(random(2) == 0)
		{
			if(perform_action("force heal", 0))
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

	if(random(5) == 0)
		perform_action("force lieyan", 1);

	return 0;
}

virtual int accept_fight(CChar *me)
{
	char msg[20];

	say("�����˲��ǣ�");
	command(snprintf(msg, 20, "kill %ld", me->object_id()));
	return 0;
}


NPC_END;
