// wuguan_mawude.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwuguan_mawude);

virtual void create()
{
	set_name("潘飞洪", "lao pan");
	set("title","金牛武馆馆长");
	set("long", "潘老爷子是武馆的缔造者，辛苦一辈子了，仍勇于提携后生，老当益壮。 ");
	set("gender", "男性");
	set("age", 95);
        set("icon",old_man2);

	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("hand", 80);
	set_skill("blade", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
   set_inquiry("手机", "手机用充值的太不划算了！");
}

virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

NPC_END;