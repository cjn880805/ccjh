//muguniang.h
//code by zwb
//12-16

NPC_BEGIN(CNDaLi_muguniang);

virtual void create()
{
	set_name("ľ����","mu gu niang");

    set("gender", "Ů��" );
    set("age", 17);
    set("long", "���������������Σ��绨����ѩ��һ�����������ף�ֻ�ǹ��ڲ԰ף�û���Ѫɫ����������ʱ��Ļ����֮�ʣ���Ƭ�������촽��Ҳ��Ѫɫ�������������������������ת��");
 	set("icon",girl2);

	set("combat_exp", 200000);
	set("shen_type", 1);
    set("per", 29);
    set("str", 30);
    set("dex", 30);
    set("con", 30);
    set("int", 30);
    set("attitude", "friendly");
	set("max_hp", 1500);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 100);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("cuff", 100);
	set_skill("strike", 100);
	set_skill("whip", 100);
	set_skill("sword", 100);
	set_skill("kurong_changong", 100);
	set_skill("tiannan_step", 100);
	set_skill("jinyu_quan", 100);
	set_skill("duanjia_sword", 100);
	set_skill("wuluo_zhang", 100);
	set_skill("feifeng_whip", 100);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("sword", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

    carry_object("whitecloth1")->wear();
    carry_object("changjian")->wield();
};




NPC_END;
