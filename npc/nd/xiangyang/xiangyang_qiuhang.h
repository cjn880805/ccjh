// qiuhang.c �� 
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_qiuhang);

virtual void create()
{
	set_name("����", "qiu hang");
	set("title", "�����ϰ�");
	set("nickname", "�ϻ�ͷ");
	set("shen_type", 0l);

	set("gender", "����");
//	set_max_encumbrance(100000000);
	set("age", 55);
	set("str", 100);
	set("attitude", "pawnshop_boss");
	set("long", "һ���ϼ��̣���Ҫ�����ˣ�");
//	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
}
/*
void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
*/
NPC_END;