//dy7_monster.h ������7�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy7_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",7);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"ֱĥ", "zhi mao","����",young_man4,22,},
		{"����", "xuan fu","����",young_man1,34,},
		{"�ܾ�", "xiong ju","����",young_man2,31,},
		{"л��", "xie yun","����",young_man3,34,},
		{"л��", "xie wen","����",young_man5,28,},
		{"лʯ", "xie shi","����",young_man3,41,},
		{"л��", "xie jun","����",young_man6,22,},
		{"С��", "xiao die","Ů��",young_woman1,36,},
		{"����", "wu xin","Ů��",young_woman6,41,},
		{"κ��", "wei bo", "����",young_man1,24,},
		{"����", "shui yun","Ů��",young_woman3,31,},
		{"����", "long yi","Ů��",young_woman2,39,},
		{"����", "lang zi","����",young_man6,28,},
		{"���ٽ�", "li shao jie","����",young_man5,29,},
		{"�ͺ���", "ke heng sheng", "����",young_man1,22,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 120+random(5));

	set("max_hp", 30000+random(1000));
	set("max_mp", 6000+random(200));
	set("mp_factor", 120);

	set("combat_exp", 9733600+random(100000));
	set("max_exp",90000000);

	set("str", 44+random(5));
	set("con", 46+random(5));
	set("int", 40+random(5));
	set("dex", 48+random(5));

	set_skill("huashan_sword", 420+random(10));
	set_skill("sword", 420+random(10));
	set_skill("huashan_ken", 420+random(10));
	set_skill("cuff", 420+random(10));
	set_skill("huashan_shenfa", 420+random(10));
	set_skill("dodge", 420+random(10));
	set_skill("zixia_shengong", 420+random(10));
	set_skill("force", 420+random(10));

	map_skill("sword", "huashan_sword");
	map_skill("cuff", "huashan_ken");
	map_skill("dodge", "huashan_shenfa");
	map_skill("force", "zixia_shengong");

	prepare_skill("cuff", "huashan_ken");

	set("apply/armor", 244+random(10));
	set("apply/damage", 274+random(10));
	
	create_family("��ɽ��", 2, "����");

	carry_object("mujian")->wield();
	
	set("chat_chance_combat", 5);
}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword jianzhang", 1);
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