//dy2_monster.h ������2�����
//wuqing 2005-1-05

#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy2_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"����", "bi xuan","����",young_woman8,28,},
		{"�Ÿ���", "du fu wei","����", young_woman1,38,},
		{"���²�", "du guo che","����", young_woman8,18,},
		{"������", "fu cai lin","����", young_woman3,32,},
		{"������", "fu nan tuo", "����", young_woman8,21,},
		{"���", "hong fu", "Ů��",young_woman1,37,},
		{"�ܹ�", "guan guan", "Ů��",young_woman2,24,},
		{"����","hai bing", "����",young_woman4,18,},
		{"����", "hai lang", "����",young_woman4,27,},
		{"��ˮ", "hai shui", "����",young_woman5,28,},
		{"����", "hai feng", "����",young_woman2,34,},
		{"����", "hai yang", "����",young_woman6,24,},
		{"����", "hai yan", "����",young_woman4,16,},
		{"��ɳ", "hai sha", "����",young_woman1,16,},
		{"��ϣ��", "hou xi bai", "����",young_woman2,31,},
	};
	
	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);
	
	set("per",random(21)+10);
	set("title", "��Ȫ�ػ���");
	set("level", 63+random(5));
	
	set("max_hp", 17000+random(1000));
	set("max_mp", 5000+random(200));
	set("mp_factor", 90);
	
	set("combat_exp", 2489700+random(100000));
	set("max_exp",25000000);
	
	set("str", 30+random(5));
	set("con", 33+random(5));
	set("int", 31+random(5));
	set("dex", 29+random(5));
	
	set_skill("lingshe_zhangfa",276+random(10));
	set_skill("staff", 276+random(10));
	set_skill("shexing_diaoshou",276+random(10));
	set_skill("hand", 276+random(10));
	set_skill("chanchu_bufa", 276+random(10));
	set_skill("dodge", 276+random(10));
	set_skill("hamagong", 276+random(10));
	set_skill("force", 276+random(10));
	
	map_skill("staff", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");
	
	prepare_skill("hand", "shexing_diaoshou");
	
	set("apply/armor", 160+random(10));
	set("apply/damage", 190+random(10));
	
	create_family("����ɽ��", 5, "����");
	
	carry_object("shuzhi2")->wield();
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
		perform_action("hand wugu", 1);
		break;
	case 2:
		perform_action("force powerup", 0);
		break;
	case 3:
		perform_action("force reserver", 1);
		break;
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM