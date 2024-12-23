//dy1_monster.h ������1�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy1_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",1);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"��", "dou e","����",young_woman8,28,},
		{"�ܶ���", "cao dong dao","����", young_woman1,38,},
		{"����", "cheng xu","����", young_woman8,18,},
		{"�����", "chun shen jun","����", young_woman3,32,},
		{"��а", "guang xie", "����", young_woman8,21,},
		{"����", "ji ming", "����",young_woman1,37,},
		{"�ں�", "hei hu", "����",young_woman2,24,},
		{"������","hei lian shen", "����",young_woman4,18,},
		{"����", "lian jin", "����",young_woman4,27,},
		{"����", "li mu", "����",young_woman5,28,},
		{"�Ś�", "liao du", "����",young_woman2,34,},
		{"����", "liao bo", "����",young_woman6,24,},
		{"������", "long ying ke", "����",young_woman4,16,},
		{"��˹", "li si", "����",young_woman1,16,},
		{"����Τ", "lv bu wei", "����",young_woman2,31,},
	};
	
	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);
	
	set("per",random(21)+10);
	set("title", "�Թ��ػ���");
	set("level", 63+random(5));
	
	set("max_hp", 16200+random(1000));
	set("max_mp", 4000+random(200));
	set("mp_factor", 150);
	
	set("combat_exp", 1123900+random(100000));
	set("max_exp",12000000);
	
	set("str", 39+random(5));
	set("con", 29+random(5));
	set("int", 36+random(5));
	set("dex", 26+random(5));
	
	set_skill("zhanjiang_jue", 227+random(10));
	set_skill("club", 227+random(10));
	set_skill("changquan", 227+random(10));
	set_skill("cuff", 227+random(10));
	set_skill("guimei_shenfa", 227+random(10));
	set_skill("dodge", 227+random(10));
	set_skill("hunyuan_yiqi", 227+random(10));
	set_skill("force", 227+random(10));
	
	map_skill("club", "zhanjiang_jue");
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	
	prepare_skill("cuff", "changquan");
	
	set("apply/armor", 138+random(10));
	set("apply/damage", 168+random(10));
	
	carry_object("tieqiao")->wield();
	set("chat_chance_combat", 5);
	
}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("club killyou", 1);
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