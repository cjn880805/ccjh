// hou.h 侯人英
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_hou);

virtual void create()
{
	set("icon",young_man3);
        set_name("侯英仁", "huo renying");
        set("gender", "男性");
        set("age", 25);
        set("long", "他就是「英雄豪杰，青城四秀」之一，武功也远高同门。");

        set("combat_exp", 80000);
        set("shen_type", -1);

        set_skill("sword", 80);
        set_skill("pixie_sword", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        map_skill("parry", "pixie_sword");
        map_skill("sword", "pixie_sword");
        create_family("青城派", 6, "弟子");

        carry_object("changjian")->wield();
        carry_object("bluecloth")->wear();
}

NPC_END;