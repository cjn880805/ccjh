//yilin.h
//code by zwb
//12-25


NPC_BEGIN(CNHengShan_yilin);

virtual void create()
{

		set_name("����","yi lin");
	set("foolid",150);
        set("gender", "Ů��" );
        set("age", 16);
        set("long","�����Ǻ�ɽ�ɶ���ʦ̫���İ����ӡ�");
		set("combat_exp", 40000);
		set("shen_type", 1);
		set("class", "bonze");
        set("str", 30);
        set("dex", 30);
        set("per", 30);
        set("con", 30);
        set("int", 30);
 	set("icon",young_woman12);

        set("max_hp", 900);
        set("hp", 300);
        set_skill("sword", 30);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("attitude", "friendly");
		create_family("��ɽ��", 14, "����");

        carry_object("cloth")->wear();
        carry_object("changjian")->wield();
}

NPC_END;