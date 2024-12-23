//xu_tong.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_xu_tong);

virtual void create()
{
	set_name("��ͨ", "xu tong");
	set("long",	"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ���൱�ýݣ������ƺ�ѧ��һ���书��");
	
	set("nickname", "֪��ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",102);
	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1500);
	
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 2000);
	set("score", 100);

	set_skill("force", 20);
	set_skill("hunyuan_yiqi", 20);
	set_skill("dodge", 20);
	set_skill("shaolin_shenfa", 20);
	set_skill("strike", 20);
	set_skill("banruo_zhang", 20);
	set_skill("parry", 20);
	set_skill("sword", 20);
	set_skill("damo_jian", 20);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry", "damo_jian");
	map_skill("sword", "damo_jian");

	prepare_skill("strike", "banruo_zhang");

	create_family("������", 41, "����");

	carry_object("xu_cloth")->wear();
};

NPC_END;
