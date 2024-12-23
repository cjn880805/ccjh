// wuguan_xiaofei.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwuguan_xiaofei);

virtual void create()
{
	set_name("孙俊", "xiao fei");
	set("title","金牛武馆教习");
	set("long", "孙教头是武馆的新来教习，但他的弟子也有在江湖出头的了。 ");
	set("gender", "男性");
	set("age", 35);
        set("icon",young_man4);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("finger", 80);
	set_skill("whip", 80);
	set_skill("throwing", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
}

virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

NPC_END;