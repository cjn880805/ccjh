// ji.c 吉人通
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_ji);

virtual void create()
{
	set("icon",young_man5);
        set_name("吉通仁");
        set("gender", "男性");
        set("age", 25);
        set("long", "他就是和申俊仁焦孟不离的吉通仁。");

        set("combat_exp", 70000);
        set("shen_type", -1);

        set_skill("sword", 70);
        set_skill("pixie_sword", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        map_skill("parry", "pixie_sword");
        map_skill("sword", "pixie_sword");
        create_family("青城派", 6, "弟子");

        carry_object("changjian")->wield();
        carry_object("bluecloth")->wear();
}

NPC_END;