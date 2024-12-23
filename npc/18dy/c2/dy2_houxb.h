//dy2_houxb.h
//lanwood 2001-11-04

MONSTER_BEGIN(CNdy2_houxb);

void create()
{
	CNmonsternpc::create();
	set("monster_level",2);
	set_name("��ϣ��", "huangquan_houxb");

	set("icon", young_man2);
	set("gender", "����");
	set("level", 79);

	set("max_hp", 15800);
	set("max_mp", 3950);
	set("mp_factor", 89);

	set("combat_exp", 2388700);

	set("chat_chance_combat", 20);
	

	set("str", 32);
	set("con", 38);
	set("int", 38);
	set("dex", 27);

	set_skill("shexing_diaoshou", 273);
	set_skill("hand", 273);
	set_skill("chanchu_bufa", 273);
	set_skill("dodge", 273);
	set_skill("hamagong", 273);
	set_skill("force", 273);

	map_skill("hand", "shexing_diaoshou");
	map_skill("dodge", "chanchu_bufa");
	map_skill("force", "hamagong");

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 158);
	set("apply/damage", 188);

	create_family("����ɽ��", 5, "����");


}

char * chat_msg_combat()
{
	switch(random(9))
	{
	case 0:
		perform_action("hand wugu", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force reserver", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	case 4:
		perform_action("force recover", 0);
		break;
	case 5:
		perform_action("force recover", 0);
		break;
	case 6:
		perform_action("force recover", 0);
		break;
	case 7:
		perform_action("force recover", 0);
		break;
	case 8:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

MONSTER_END;