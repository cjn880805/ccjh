//fusigui.h
//Lanwood 2000-01-05

DALIWEISHI_BEGIN(CNdali_fusigui);

virtual void create()
{
	set_name("��˼Զ", "fu siyuan");
	set("title",  "������" );
	set("long", "���Ǵ�����Ĵ���֮һ��");
	set("gender", "����");
	set("icon", young_man1);

	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 350000);
	set("score", 105000);

    set_skill("force", 55);
    set_skill("dodge", 55);
    set_skill("parry", 50);
    set_skill("cuff", 55);
    set_skill("sword", 50);
    set_skill("staff", 50);
	set_skill("kurong_changong", 50);
    set_skill("tiannan_step", 55);
    set_skill("jinyu_quan", 55);
    set_skill("duanjia_sword", 50);
	set_skill("literate", 40);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");

	set_inquiry("ָ���书", ask_me );

	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	add_money(1000);

	create_family("����μ�",19,"����");
};

DALIWEISHI_END;
