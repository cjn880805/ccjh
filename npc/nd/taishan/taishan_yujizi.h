//taishan_yujizi.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_yujizi);

virtual void create()
{
        set_name("玉击子", "yuji zi");
        set("gender", "男性");
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",taoist_with_sword);

        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_factor", 30);
        set("max_hp",2000);
        set("hp",2000);
        set("combat_exp", 800000);
        set("shen_type", -1);

        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("taishan_sword", 100);
        set_skill("lingxu_bu", 100);

        map_skill("sword", "taishan_sword");
        map_skill("parry", "taishan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("泰山派", 12, "弟子");

        carry_object("changjian")->wield();
        carry_object("greyrobe")->wear();
}

NPC_END;