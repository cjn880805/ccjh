//dy8_monster.h ������8�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy8_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",8);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"��ӯ", "yany ing","Ů��",young_woman2,22,},
		{"����ӥ", "wei tian ying","����",young_man1,34,},
		{"����", "song zhong","����",young_man2,31,},
		{"ŷ����", "ou yang fu","����",young_man3,34,},
		{"�ϰ���", "nan ba tian","����",young_man5,28,},
		{"������", "liu san bian","����",young_man3,41,},
		{"������", "liu han yan", "Ů��",young_woman1,22,},
		{"�", "li huai", "����",young_man6,36,},
		{"�", "li han","����",young_man2,41,},
		{"����", "leng yu", "����",young_man1,24,},
		{"��ʮ��", "jian shi san","����",young_man3,31,},
		{"����", "jiang wu","����",young_man4,39,},
		{"��", "gui hu","����",young_man5,29,},
		{"����", "da luo","����",young_man6,28,},
		{"��ʤ", "bai sheng", "����",young_man1,22,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 130+random(5));

	set("max_hp", 40000+random(1000));
	set("max_mp", 8000+random(200));
	set("mp_factor", 130);

	set("combat_exp", 13234500+random(100000));
	set("max_exp",100000000);


	set("str", 46+random(5));
	set("con", 48+random(5));
	set("int", 42+random(5));
	set("dex", 50+random(5));

	set_skill("force", 450+random(10));
	set_skill("unarmed", 450+random(10));
	set_skill("dodge", 450+random(10));
	set_skill("parry", 450+random(10));
	set_skill("hand",450+random(10));
	set_skill("staff", 450+random(10));
	set_skill("hamagong", 450+random(10));
	set_skill("chanchu_bufa", 450+random(10));
	set_skill("shexing_diaoshou", 450+random(10));
	set_skill("lingshe_zhangfa", 450+random(10));
	set_skill("xunshou_shu",450+random(10));

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	set("apply/armor", 260+random(10));
	set("apply/damage", 290+random(10));
	
	create_family("����ɽ��", 2, "����");
	
	carry_object("shezhang")->wield();
	set("chat_chance_combat", 5);

}
char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("staff pili", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	case 3:
		perform_action("unarmed wugu", 0);
		break;
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM