//monster2.h
//code by Teapot
//2001-2-3

//2������

MONSTER_BEGIN(CNMonster_2);

virtual void create()
{
	static struct{
		char name[20], id[20];		//��������
		int	 icon;			//ͼ��
		int  chance;		//���ּ���
	}mon[20] = {
		{"��ͽ��", "deng tuzi", young_man2, 0,},
		{"�ڤ���", "hei meng", young_man3, 8,},
		{"����ʹ��",	"youming shizhe", cateran, 16,},
		{"����ħ��", "ciyan moling", banditi, 24,},
		{"���ؿ�",	"shenmi ke", cateran, 32,},
		{"���ݽ�ʬ",	"silin jiangsi", cateran, 40,},
		{"������å", "dongyang liumang", young_man4, 48,},
		{"����",	"e ren", cateran, 56,},
		{"����", "e kou", banditi, 61,},
		{"����ͷĿ", "ekou toumu", banditi, 66,},
		{"���ܴ�ͷĿ", "ekou datoumu", young_man5, 71,},
		{"������ʿ", "dongyang wushi", banditi, 76,},
		{"������ʿ����", "wushi shouling", young_man1, 81,},
		{"��������", "renzhe", banditi, 84,},
		{"һ��ʮ����",	"yi wan shi ge lang", cateran, 88,},
		{"��Сѩ", "huang xiao xue", taoist_with_sword, 92,},
		{"ҹ��ɱ", "ye sha", taoist_with_sword, 94,},
		{"��С��", "yan xiao qi", old_monk, 96,},
		{"��С��",	"wu xiao hui", old_monk, 98,},
		{"��С��", "chen xiao guang", taoist_with_sword, 99,},
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
	set("gender", "����");

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

	set("present_msg", "һ�������ӹ���$n��֪��������ð�˳�������ס$N��ȥ·��");

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

	say("������������������");
	command(snprintf(msg, 20, "kill %ld", me->object_id()));
	return 0;
}


MONSTER_END;
