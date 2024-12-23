//dy22_monster.h ������22�����
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy22_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",22);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[15] = {
		{"����", "feng qing","����",young_man4,28,},
		{"��ս��", "tie zhan jia","����", young_man1,38,},
		{"����", "wen zao","����", young_man2,18,},
		{"����", "miao shan","Ů��", young_woman3,32,},
		{"����", "lan xi", "����", young_man5,21,},
		{"��", "xiang gong", "����",young_man6,37,},
		{"��ׯ", "xiang zhuang", "����",young_man2,24,},
		{"����", "wang xi", "Ů��",young_woman11,18,},
		{"Ī��", "ma long", "����",young_man4,27,},
		{"��Ϊ", "jin bu wei", "����",young_man5,28,},
		{"ʯ��ŭ", "shi bu nu", "����",young_man2,34,},
		{"���", "yang bu qu", "����",young_man6,24,},
		{"�Ų���", "zhang bu zhi", "����",young_man4,16,},
		{"����", "fang yu", "����",young_man1,16,},
		{"�Ϸ�", "zi feng", "����",young_man2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
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