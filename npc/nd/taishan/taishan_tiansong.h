//taishan_tiansong.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_tiansong);

virtual void create()
{
        set_name("地树道人", "tiansong daoren");
        set("gender", "男性");
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",taoist_with_sword);

        set("mp", 1400);
        set("max_mp", 1400);
        set("mp_factor", 30);
        set("max_hp",1200);
        set("hp",1200);
        set("combat_exp", 600000);
        set("shen_type", 1);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("taishan_sword", 80);
        set_skill("lingxu_bu", 80);

        map_skill("sword", "taishan_sword");
        map_skill("parry", "taishan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("泰山派", 13, "弟子");

        carry_object("changjian")->wield();
        carry_object("greyrobe")->wear();
}

NPC_END;