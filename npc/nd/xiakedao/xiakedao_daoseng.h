// daoseng.c

//code by sound
//2001-07-12

NPC_BEGIN(CNxiakedao_daoseng);

virtual void create()
{
        set_name("刀僧", "daoseng");
        set("title", "少林刀僧");
	set("icon", young_monk);
        set("long", "他是一位云游四方的行者，风霜满面，行色匆匆，似乎正在办一件急事。");

        set("gender", "男性");
        set("attitude", "heroism");
        set("class", "bonze");

        set("age", 35);
        set("shen_type", 1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_hp", 2000);
        set("hp", 1000);
        set("mp", 1500);
        set("max_mp", 1500);
        set("mp_factor", 50);
        set("combat_exp", 200000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("shaolin_shenfa", 100);
        set_skill("xiuluo_dao", 100);
        set_skill("hunyuan_yiqi", 100);

        map_skill("force", "hunyuan_yiqi");
        map_skill("dodge", "shaolin_shenfa");
        map_skill("blade", "xiuluo_dao");
        map_skill("parry", "xiuluo_dao");

        carry_object("gangdao")->wield();
        carry_object("cloth")->wear();
//		add_money("silver", 50);
}

/*void init()
{
        object me,ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob)
        && !environment(ob)->query("no_fight") && ob->query("gender")=="男性"
        && ( (fam = ob->query("family")) && fam["family_name"] != "少林派" && ob->query("class") == "bonze") )
        {
                command("say 你这个无耻少林叛徒，纳命来吧！！！\n");
                me->set_leader(ob);
                me->kill_ob(ob);
                ob->fight_ob(me);
        }
}
*/
NPC_END;