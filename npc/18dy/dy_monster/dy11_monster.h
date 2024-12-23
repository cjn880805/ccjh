//dy11_monster.h ������11�����
//wuqing 2005-1-05

#define MAX_NPC_NUM 14

MONSTER_BEGIN(CNdy11_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",11);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"��ɫ", "wu shai","����",old_monk,80,},
		{"�޻�", "wu hua","����", old_monk,78,},
		{"�ް�", "wu ai","����", old_monk,68,},
		{"����", "wang dong","����", old_monk,82,},
		{"�չ�", "pu guang", "����", young_monk,21,},
		{"����", "kong wen", "����",old_monk,77,},
		{"��ͷ��", "huo tou tu", "����",old_monk,64,},
		{"�ݴ�","hui ci", "����",young_monk,18,},
		{"��Ԫ", "guang yuan", "����",old_monk,67,},
		{"����", "fei niao", "����",old_monk,58,},
		{"�ɷ�", "du fu", "����",old_monk,94,},
		{"����", "dao ming", "����",young_monk,24,},
		{"����", "dao guang", "����",young_monk,16,},
		{"����", "bu she", "����",young_monk,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 150+random(5));

	set("max_hp", 62000+random(1000));
	set("max_mp", 14000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 24234500+random(100000));
	set("max_exp",130000000);

	set("str", 69+random(5));
	set("con", 63+random(5));
	set("int", 65+random(5));
	set("dex", 73+random(5));
	
	set_skill("finger", 550+random(10));
	set_skill("force", 550+random(10));
	set_skill("whip", 550+random(10));
	set_skill("parry", 550+random(10));
	set_skill("dodge", 550+random(10));
	set_skill("unarmed", 550+random(10));
	set_skill("buddhism", 550+random(10));
	set_skill("literate", 550+random(10));
	set_skill("nianhua_zhi", 550+random(10));
	
	set_skill("hunyuan_yiqi", 550+random(10));
	set_skill("riyue_bian", 550+random(10));
	set_skill("shaolin_shenfa", 550+random(10));
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("whip",  "riyue_bian");
	map_skill("parry", "riyue_bian");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");

	prepare_skill("finger", "nianhua_zhi");
	
	set("apply/armor", 320+random(10));
	set("apply/damage", 350+random(10));

	create_family("������", 2, "����");

	carry_object("changbian")->wield();
	set("chat_chance_combat", 5);


}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("whip chan", 1);
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