// wuguan_longquan.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwuguan_longquan);

virtual void create()
{
	set_name("区豪", "long quan");
	set("title","金牛武馆教习");
	set("long", "这是一个英俊潇洒风流倜傥的武馆教习，一般的女生都十分喜欢拜他为师。 ");
	set("gender", "男性");
	set("age", 21);
        set("icon",young_man1);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("claw", 80);
	set_skill("blade", 80);
	set_skill("axe", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
        set_inquiry("爱情", "多情自古空余恨，此恨绵绵无绝期！");
}
virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

virtual char *chat_msg()
{
	return "区豪长叹一声：多情自古空余恨，此恨绵绵无绝期！";
}

NPC_END;