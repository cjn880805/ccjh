//dy17_monster.h ������17�����
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy17_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",17);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[15] = {
		{"����", "wang dong","����",young_woman8,28,},
		{"������", "tie zhong tang","����", young_woman1,38,},
		{"����", "zhu zao","����", young_woman8,18,},
		{"����", "feng miao","Ů��", young_man3,32,},
		{"����", "jun tian", "����", young_woman8,21,},
		{"���", "mie di", "����",young_woman1,37,},
		{"��ƿ", "ying ping", "����",young_woman2,24,},
		{"����", "tie qi", "Ů��",young_man4,18,},
		{"����", "ma long", "����",young_woman4,27,},
		{"��Ԫ", "chu yuan", "����",young_woman5,28,},
		{"����Ѫ", "wei bei xue", "����",young_woman2,34,},
		{"����", "wu xi", "����",young_woman6,24,},
		{"�ζ�", "he dong", "����",young_woman4,16,},
		{"����", "zhong zhou", "����",young_woman1,16,},
		{"����", "bai lang", "����",young_woman2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
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
	
	create_family("�䵱��", 2, "����");
	
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