//xu_ming.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_xu_ming);

virtual void create()
{
	set_name("����", "xu ming");
	set("long",	"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ���൱�ýݣ������ƺ�ѧ��һ���书��");
	
	set("nickname", "֪��ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",101);
	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("max_hp", 1050);
	
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 20);
	set("combat_exp", 15000);
	
	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("strike", 30);
	set_skill("banruo_zhang", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_skill("damo_jian", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry", "damo_jian");
	map_skill("sword", "damo_jian");

	prepare_skill("strike", "banruo_zhang");

	create_family("������", 41, "����");

	carry_object("changjian")->wield();
    carry_object("xu_cloth")->wear();
};

NPC_END;
