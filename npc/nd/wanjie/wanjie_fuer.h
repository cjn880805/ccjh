// fuer.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_fuer);

virtual void create()
{
        set_name("来福儿", "lai fuer");
        set("gender", "男性" );
        set("age", 45);
        set("str", 16);
        set("con", 24);
        set("dex", 21);
        set("per", 17);
        set("int", 14);
        set("icon",waiter);
        set("long", "来福儿是万劫谷的下人。");
        set("attitude", "friendly");

        set("max_mp", 200);
        set("mp", 200);
        set("mp_factor", 10);

        set("combat_exp", 5000);

        set_skill("unarmed", 30);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("force", 50);

        carry_object("cloth")->wear();
//	carry_object("bu-shoes")->wear();
}
NPC_END;
