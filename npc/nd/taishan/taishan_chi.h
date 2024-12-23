//taishan_chi.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_chi);

virtual void create()
{
        set_name("³ÙÇ§¹ù", "chi baicheng");
        set("gender", "ÄÐÐÔ");
        set("class", "swordsman");
        set("age", 25);
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

        create_family("Ì©É½ÅÉ", 14, "µÜ×Ó");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;