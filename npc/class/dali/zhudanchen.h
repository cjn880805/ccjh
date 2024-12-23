//zhudanchen.h
//Lanwood 2000-01-05

DALIWEISHI_BEGIN(CNdali_zhudanchen);

virtual void create()
{
	set_name("���೼",  "zhu qingchen");
	set("title",  "������" );
	set("long", "���Ǵ�����Ĵ���֮һ��һ������������Ĵ����ͷ��");
	set("gender", "����");
	set("icon", young_man1);

	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 350000);
	set("score", 110000);

    set_skill("force", 55);
    set_skill("dodge", 50);
    set_skill("parry", 55);
    set_skill("cuff", 50);
    set_skill("sword", 55);
    set_skill("staff", 55);
	set_skill("kurong_changong", 55);
    set_skill("tiannan_step", 50);
    set_skill("jinyu_quan", 50);
    set_skill("duanjia_sword", 55);
	set_skill("literate", 90);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");

	set_inquiry("ָ���书", ask_me);
	
	carry_object("junfu")->wear();
	carry_object("zheshan")->wield();
	add_money(1000);

	create_family("����μ�",19,"����");
};

DALIWEISHI_END;
