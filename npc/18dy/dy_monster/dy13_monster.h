//dy13_monster.h ������13�����
//wuqing 2005-1-05

#define MAX_NPC_NUM 14

MONSTER_BEGIN(CNdy13_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",13);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"�𲻻�", "jin bu huan","����",begger,26,},
		{"���԰", "ma da yuan","����", begger,28,},
		{"������", "he ren wo","����", begger,38,},
		{"����", "li sheng","����", begger,22,},
		{"�Ϲ���", "lao gui qi", "����", begger,55,},
		{"������", "hong ri qing", "����",begger,37,},
		{"����", "hou si", "����",begger,44,},
		{"�ܽ�", "zhou jiu", "����",begger,18,},
		{"����", "liu feng", "����",begger,67,},
		{"�Կ�", "zhao kai", "����",begger,17,},
		{"����", "hua da", "����",begger,44,},
		{"������", "wang ma zi", "����",begger,24,},
		{"Ī��", "mo wen", "����",begger,36,},
		{"�ķ�", "wen fan", "����",begger,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 160+random(5));

	set("max_hp", 70000+random(1000));
	set("max_mp", 20000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 40234500+random(100000));
	set("max_exp",150000000);

	set("str", 77+random(5));
	set("con", 70+random(5));
	set("int", 69+random(5));
	set("dex", 77+random(5));
	
	set_skill("force", 610+random(10));                      
	set_skill("huntian_qigong", 610+random(10));    
	set_skill("unarmed", 610+random(10));           
	set_skill("xianglong_zhang", 610+random(10)); 
	set_skill("dodge", 610+random(10));      	     
	set_skill("xiaoyaoyou",610+random(10));        
	set_skill("parry", 610+random(10));             
	set_skill("staff", 610+random(10));             
	set_skill("dagou_bang", 610+random(10));        
	set_skill("begging", 610+random(10));          
	set_skill("xunshou_shu", 610+random(10));         
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	map_skill("staff", "dagou_bang");
	
	set("apply/armor", 370+random(10));
	set("apply/damage", 400+random(10));

	create_family("ؤ��", 2, "����");

	carry_object("gangzhang")->wield();
	set("chat_chance_combat", 5);

}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("gangzhang", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(3))
		{
		case 0:
			perform_action("staff zhuang", 1);
			break;
		case 1:
			perform_action("staff linglong", 1);
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
			perform_action("unarmed xianglong", 1);	//�����Ƶľ���
			break;
		}
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM