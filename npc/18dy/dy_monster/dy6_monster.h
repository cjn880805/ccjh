//dy6_monster.h ������6�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 50

MONSTER_BEGIN(CNdy6_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",6);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"����ȫ", "zuo ling quan","����",young_man3,22,},
		{"ս��", "zhan lang","����",young_man1,34,},
		{"ս��", "zhan hen","����",young_man2,31,},
		{"����", "ze shen","����",young_man3,34,},
		{"��ɫ", "yan shai","����",young_man5,28,},
		{"��ɷ�", "yan fe fe","Ů��",young_woman6,41,},
		{"ϯ��ͬ", "xi zhu tong","����",young_man6,22,},
		{"����", "xi qi","Ů��",young_woman1,36,},
		{"��Ԫ��", "wu yuan shen","����",young_man2,41,},
		{"��ʦ", "wu shi", "����",young_man1,24,},
		{"����", "tian zhong","����",young_man3,31,},
		{"��ӥ", "tian ying","����",young_man2,39,},
		{"����", "tian yan","����",young_man6,28,},
		{"������", "shen li wang","����",young_man5,29,},
		{"ɽ��", "shan she", "����",young_man1,22,},
		{"����", "shang xiao","����",young_man5,29,},
		{"��Ұ", "qin gye", "����",young_man1,22,},
		{"��", "qi bei","����",young_man5,29,},
		{"����", "ni ya", "Ů��",young_woman4,22,},
		{"����", "ning su","����",young_man5,29,},
		{"���", "nian jia", "����",young_man1,22,},
		{"����", "na min","����",young_man5,29,},
		{"��Ը", "ma yuan", "����",young_man1,22,},
		{"·��˿", "lu yi si","Ů��",young_woman5,29,},
		{"���", "luo di", "Ů��",young_woman1,22,},
		{"����", "long zhou","����",young_man5,29,},
		{"����", "long yi", "Ů��",young_woman10,22,},
		{"����", "long teng","����",young_man5,29,},
		{"����", "li qing", "Ů��",young_woman9,22,},
		{"����", "ling zhi","����",young_man5,29,},
		{"������", "lia li jun", "Ů��",young_woman1,22,},
		{"�乤��", "leng gong ming","����",young_man5,29,},
		{"����", "la sa", "����",young_man2,22,},
		{"����", "lan lin","����",young_man5,29,},
		{"����", "ju lin", "����",young_man1,22,},
		{"����", "hun yun","����",young_man5,29,},
		{"����", "hua xi", "Ů��",young_woman1,22,},
		{"��Ծ", "hong yue","Ů��",young_woman5,29,},
		{"��ʦ", "hong shi", "����",young_man3,22,},
		{"����", "hong qing","����",young_man5,29,},
		{"����", "hao shen", "����",young_man1,22,},
		{"��ɽ��", "han shan mei","Ů��",young_woman5,29,},
		{"��ս", "ge zhan", "����",young_man1,22,},
		{"�߾�", "gao jun","����",young_man5,29,},
		{"��Ѫ", "fa xue", "����",young_man4,22,},
		{"�ְ�", "lin bai", "����",young_man1,22,},
		{"�ű�", "dub ian","����",young_man5,29,},
		{"����", "cai lao", "Ů��",young_woman1,22,},
		{"�׵�", "bai dan", "����",young_man3,22,},
		{"����", "a hai","Ů��",young_woman5,29,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 110+random(5));

	set("max_hp", 23600+random(1000));
	set("max_mp", 5900+random(200));
	set("mp_factor", 110);

	set("combat_exp", 8752800+random(100000));
	set("max_exp",80000000);

	set("str", 40+random(5));
	set("con", 49+random(5));
	set("int", 41+random(5));
	set("dex", 42+random(5));

	set_skill("meinv_quan", 409+random(10));
	set_skill("cuff", 409+random(10));
	set_skill("yunv_shenfa", 409+random(10));
	set_skill("dodge", 409+random(10));
	set_skill("yunv_xinjing", 409+random(10));
	set_skill("force", 409+random(10));

	map_skill("cuff", "meinv_quan");
	map_skill("dodge", "yunv_shenfa");
	map_skill("force", "yunv_xinjing");

	prepare_skill("cuff", "meinv_quan");

	set("apply/armor", 236+random(10));
	set("apply/damage", 266+random(10));
	
	create_family("��Ĺ��", 5, "����");

	set("chat_chance_combat", 5);
}

char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("cuff you", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	case 3:
		perform_action("force roar", 1);
		break;
	}

	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM