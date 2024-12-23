//hui_se.h
//Lanwood 2000-01-10

SHAOLINHUI_BEGIN(CNshaolin_hui_se);

virtual void create()
{	
	set_name("��ɫ����", "huise zunzhe");
	set("long",	"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�̫��Ѩ΢͹��˫Ŀ��������");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",90);
	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 18);
	set("con", 28);
	set("dex", 25);
	set("max_hp", 1450);
	
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 70);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan_yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("claw", 74);
	set_skill("longzhua_gong", 74);
	set_skill("strike", 70);
	set_skill("sanhua_zhang", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("claw", "longzhua_gong");
	map_skill("strike", "sanhua_zhang");
	map_skill("parry", "longzhua_gong");

	prepare_skill("strike", "sanhua_zhang");

	create_family("������", 38, "����");

    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

SHAOLINHUI_END;
