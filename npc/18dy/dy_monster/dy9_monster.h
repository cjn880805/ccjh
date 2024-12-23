//dy9_monster.h ������9�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy9_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",9);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"��˼", "zuo shi","Ů��",young_woman2,22,},
		{"Ԭָ", "yuan zhi","����",young_man1,34,},
		{"ϧ����", "xi hua la","Ů��",young_woman3,31,},
		{"�Ϲٷ�", "shang guan fei","����",young_man3,34,},
		{"������", "qin meng you","Ů��",young_woman7,28,},
		{"Ǯ��", "qian luo","����",young_man3,41,},
		{"Ĳ��", "mu xian", "����",young_man5,42,},
		{"��ս", "ling zhan", "����",young_man6,36,},
		{"�˷���", "lang fan yu","����",young_man2,41,},
		{"����", "han bai", "����",young_man1,24,},
		{"����", "feng lie","����",young_man3,31,},
		{"�⺮", "feng han","����",young_man4,39,},
		{"��ҹ��", "fang ye yu","����",young_man5,29,},
		{"�޶�", "cui du","����",young_man6,28,},
		{"��ʫ", "chus hi", "Ů��",young_woman10,22,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 140+random(5));

	set("max_hp", 45000+random(1000));
	set("max_mp", 9000+random(200));
	set("mp_factor", 130);

	set("combat_exp", 18234500+random(100000));
	set("max_exp",110000000);


	set("str", 47+random(5));
	set("con", 50+random(5));
	set("int", 44+random(5));
	set("dex", 51+random(5));

	set_skill("force", 480+random(10));
	set_skill("dodge", 480+random(10));
	set_skill("parry", 480+random(10));
	set_skill("claw", 480+random(10));
	set_skill("unarmed", 480+random(10));
	set_skill("jiuyang_shengong", 480+random(10));
	set_skill("sougu", 480+random(10));
	set_skill("lingfa", 480+random(10));
	set_skill("shenghuo_lingfa", 480+random(10));
	set_skill("qiankun_danuoyi", 480+random(10));
	set_skill("shenghuo_xinfa", 480+random(10));
	
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	map_skill("finger", "xuantian_zhi");

	prepare_skill("claw", "sougu");
	
	set("apply/armor", 280+random(10));
	set("apply/damage", 310+random(10));
	
	create_family("����", 2, "����");
	
	carry_object("shenghuo_ling")->wield();
	set("chat_chance_combat", 5);

}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("shenghuo_ling", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("lingfa duo", 1);
			break;
		case 1:
			perform_action("lingfa xiyanling", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(2))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("claw muye", 1);
			break;
		}
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM