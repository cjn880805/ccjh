//dy6_monster.h 地狱第6层怪物
//wuqing 2005-1-05
#define MAX_NPC_NUM 50

MONSTER_BEGIN(CNdy6_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",6);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"左令全", "zuo ling quan","男性",young_man3,22,},
		{"战浪", "zhan lang","男性",young_man1,34,},
		{"战狠", "zhan hen","男性",young_man2,31,},
		{"择生", "ze shen","男性",young_man3,34,},
		{"燕色", "yan shai","男性",young_man5,28,},
		{"雁飞飞", "yan fe fe","女性",young_woman6,41,},
		{"席竹同", "xi zhu tong","男性",young_man6,22,},
		{"西其", "xi qi","女性",young_woman1,36,},
		{"武元神", "wu yuan shen","男性",young_man2,41,},
		{"无师", "wu shi", "男性",young_man1,24,},
		{"田中", "tian zhong","男性",young_man3,31,},
		{"天鹰", "tian ying","男性",young_man2,39,},
		{"天眼", "tian yan","男性",young_man6,28,},
		{"神力往", "shen li wang","男性",young_man5,29,},
		{"山蛇", "shan she", "男性",young_man1,22,},
		{"上消", "shang xiao","男性",young_man5,29,},
		{"青野", "qin gye", "男性",young_man1,22,},
		{"祈悲", "qi bei","男性",young_man5,29,},
		{"呢雅", "ni ya", "女性",young_woman4,22,},
		{"宁素", "ning su","男性",young_man5,29,},
		{"年佳", "nian jia", "男性",young_man1,22,},
		{"纳名", "na min","男性",young_man5,29,},
		{"马愿", "ma yuan", "男性",young_man1,22,},
		{"路易丝", "lu yi si","女性",young_woman5,29,},
		{"洛蒂", "luo di", "女性",young_woman1,22,},
		{"龙灯", "long zhou","男性",young_man5,29,},
		{"龙衣", "long yi", "女性",young_woman10,22,},
		{"龙藤", "long teng","男性",young_man5,29,},
		{"丽青", "li qing", "女性",young_woman9,22,},
		{"灵智", "ling zhi","男性",young_man5,29,},
		{"连丽军", "lia li jun", "女性",young_woman1,22,},
		{"冷工名", "leng gong ming","男性",young_man5,29,},
		{"拉撒", "la sa", "男性",young_man2,22,},
		{"兰林", "lan lin","男性",young_man5,29,},
		{"巨玲", "ju lin", "男性",young_man1,22,},
		{"花云", "hun yun","男性",young_man5,29,},
		{"华西", "hua xi", "女性",young_woman1,22,},
		{"红跃", "hong yue","女性",young_woman5,29,},
		{"红师", "hong shi", "男性",young_man3,22,},
		{"红情", "hong qing","男性",young_man5,29,},
		{"嚎伸", "hao shen", "男性",young_man1,22,},
		{"寒山妹", "han shan mei","女性",young_woman5,29,},
		{"歌战", "ge zhan", "男性",young_man1,22,},
		{"高君", "gao jun","男性",young_man5,29,},
		{"飞血", "fa xue", "男性",young_man4,22,},
		{"林白", "lin bai", "男性",young_man1,22,},
		{"杜边", "dub ian","男性",young_man5,29,},
		{"采佬", "cai lao", "女性",young_woman1,22,},
		{"白蛋", "bai dan", "男性",young_man3,22,},
		{"阿黑", "a hai","女性",young_woman5,29,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
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
	
	create_family("古墓派", 5, "弟子");

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