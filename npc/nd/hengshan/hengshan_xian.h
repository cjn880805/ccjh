//hengshan_xian.h
//code by sound
//2001-07-11

NPC_BEGIN(CNhengshan_xian);

virtual void create()
{
        set_name("��æʦ̫", "dingxian shitai");
        set("gender", "Ů��");
        set("title", "��ɽ�ɵ�ʮ��������");
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",old_woman);

        set("mp", 2400);
        set("max_mp", 2400);
        set("mp_factor", 30);
        set("max_hp",2000);
        set("hp",2000);
        set("combat_exp", 1200000);
        set("shen_type", 1);

        set_skill("unarmed", 140);
        set_skill("sword", 140);
        set_skill("force", 140);
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("hengshan_jian", 140);
        set_skill("lingxu_bu", 140);

        map_skill("sword", "hengshan_jian");
        map_skill("parry", "hengshan_jian");
        map_skill("dodge", "lingxu_bu");

        create_family("��ɽ��", 13, "����");

        carry_object("changjian")->wield();
//	carry_object("xuan_cloth")->wear();
}

NPC_END;
