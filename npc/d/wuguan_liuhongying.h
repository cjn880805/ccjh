// wuguan_liuhongying.c

//code by Fisho
//date:2000-12-22

VENDOR_BEGIN(CNwuguan_liuhongying);

void create()
{
	set_name("谢平静", "xie pingjing");
	set("title","金牛武馆教习");
	set("long", "谢教头是武馆的新来教习，你可别小看她哦。 ");
	set("gender", "女性");
	set("age", 17);
        set("icon",girl2);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("hammer", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
    set_inquiry("爱情", "多情自古空余恨，此恨绵绵无绝期！");
	carry_good("book2", 3);
}

int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

VENDOR_END;