//dao_cheng.h
//Lanwood 2000-01-10

SHAOLINDAO_BEGIN(CNshaolin_dao_cheng);

virtual void create()
{
	set_name("������ʦ", "daocheng chanshi");
	set("long",	"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",80);
	set("age", 40);
	set("shen_type", 1);
	set("str", 21);
	set("int", 20);
	set("con", 19);
	set("dex", 24);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("claw", 52);
	set_skill("longzhua_gong", 52);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "longzhua_gong");

	prepare_skill("claw", "longzhua_gong");

	create_family("������", 39, "����");
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

SHAOLINDAO_END;
