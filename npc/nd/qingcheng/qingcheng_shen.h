// shen.h ���˿�
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_shen);

virtual void create()
{
	set("icon",young_man4);
        set_name("�꿡��", "shen renjun");
        set("gender", "����");
        set("age", 25);
        set("long", "�����Ǻͼ�ͨ�ʽ��ϲ�����꿡�ʡ�");

        set("combat_exp", 70000);
        set("shen_type", -1);

        set_skill("sword", 70);
        set_skill("pixie_sword", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        map_skill("parry", "pixie_sword");
        map_skill("sword", "pixie_sword");
        create_family("�����", 6, "����");

        carry_object("changjian")->wield();
        carry_object("bluecloth")->wear();
}

NPC_END;