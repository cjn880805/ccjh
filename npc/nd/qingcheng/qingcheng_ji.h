// ji.c ����ͨ
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_ji);

virtual void create()
{
	set("icon",young_man5);
        set_name("��ͨ��");
        set("gender", "����");
        set("age", 25);
        set("long", "�����Ǻ��꿡�ʽ��ϲ���ļ�ͨ�ʡ�");

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