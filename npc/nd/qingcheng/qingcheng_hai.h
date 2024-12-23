// yu.h 余沧海
//code by sound
//2001-07-11

NPC_BEGIN(CNqingcheng_hai);

virtual void create()
{
	set("icon",taoist);
        set_name("鱼海沧", "yu canghai");
        set("gender", "男性");
        set("age", 52);
        set("long", "他身形矮小，可是神情凝重，俨然一派大宗师气。");
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
        create_family("青城派", 7, "掌门");

        carry_object("changjian")->wield();
        carry_object("bluecloth")->wear();
}

NPC_END;

