// yu.h ��׺�
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_hai);

virtual void create()
{
	set("icon",taoist);
        set_name("�㺣��", "yu canghai");
        set("gender", "����");
        set("age", 52);
        set("long", "�����ΰ�С�������������أ�ٲȻһ�ɴ���ʦ����");
        set("class", "taoist");

        set("combat_exp", 800000);
        set("shen_type", -1);

        set_skill("sword", 80);
        set_skill("pixie_sword", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        map_skill("parry", "pixie_sword");
        map_skill("sword", "pixie_sword");
        create_family("�����", 7, "����");

        carry_object("changjian")->wield();
        carry_object("bluecloth")->wear();
}

NPC_END;

