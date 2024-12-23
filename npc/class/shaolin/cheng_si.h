//cheng_si.h
//Lanwood 2000-01-09

SHAOLINCHENG_BEGIN(CNshaolin_cheng_si);

virtual void create()
{
	set_name("��˼", "chengsi luohan");
	set("long",	"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�̫��Ѩ�߸߹����ƺ��������书��");

	set("title", "���ְ��������½���޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",71);
	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("strike", 90);
	set_skill("sanhua_zhang", 90);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "sanhua_zhang");
	map_skill("parry", "sanhua_zhang");

	prepare_skill("strike", "sanhua_zhang");

	create_family("������", 37, "����");

	carry_object("xuan_cloth")->wear();
	set("no_huan",1);
};

SHAOLINCHENG_END;
