// hou.h ����Ӣ
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_hou);

virtual void create()
{
	set("icon",young_man3);
        set_name("��Ӣ��", "huo renying");
        set("gender", "����");
        set("age", 25);
        set("long", "�����ǡ�Ӣ�ۺ��ܣ�������㡹֮һ���书ҲԶ��ͬ�š�");

        set("combat_exp", 80000);
        set("shen_type", -1);

        set_skill("sword", 80);
        set_skill("pixie_sword", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        map_skill("parry", "pixie_sword");
        map_skill("sword", "pixie_sword");
        create_family("�����", 6, "����");

        carry_object("changjian")->wield();
        carry_object("bluecloth")->wear();
}

NPC_END;