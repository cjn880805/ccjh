//dao_jue.h
//Lanwood 2000-01-10

SHAOLINDAO_BEGIN(CNshaolin_dao_jue);

virtual void create()
{
	set_name("������ʦ", "daojue chanshi");
	set("long",	"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",82);
	set("age", 40);
	set("shen_type", 1);
	set("str", 22);
	set("int", 20);
	set("con", 21);
	set("dex", 22);
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
	set_skill("hand", 53);
	set_skill("fengyun_shou", 53);
	set_skill("cuff", 55);
	set_skill("jingang_quan", 55);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "fengyun_shou");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");

	prepare_skill("cuff", "jingang_quan");
	create_family("������", 39, "����");

	carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

SHAOLINDAO_END;
