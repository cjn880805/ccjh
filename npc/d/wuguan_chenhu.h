// wuguan_chenhu.c

//code by Fisho
//date:2000-12-22

VENDOR_BEGIN(CNwuguan_chenhu);

virtual void create()
{
	set_name("邹文斌", "chen hu");
	set("title","金牛武馆教习");
	set("long", "邹老爷子在武馆也忙了几十年了，仍勇于提携后生，老当益壮。 ");
	set("gender", "男性");
	set("age", 24);
        set("icon",young_man6);
	
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("cuff", 80);
	set_skill("staff", 80);
	set_skill("club", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);

	carry_good("quanpu", 1);
}

virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied") != 1) return 0;
	return 1;
}

VENDOR_END;